#include <iostream>
#include <clocale>

//#include <boost/regex.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <windows.h>
#include <stdio.h>

//#include <bits/basic_string.h>
#include <string>

#include "message/message.h"
#include "regex/regex.h"

#include "wrap.h"
#include "constants.h"
#include "property.h"

void gogo(const Property);
void wrapOracle(wchar_t *);
void makeFinalFile (std::ofstream &, std::string src);
void switchOffTu();

int main(int argc, char *argv[])
{
//    setlocale(LC_ALL,"Russian");
//    setlocale(LC_ALL,"russian_russia");
//    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc<2) {
        error("В параметрах запуска не задан исходный файл для рапования");
        return 1;
    }


    try {
        Property prop;
        prop.setSrcFileName(std::string(argv[1]));
        gogo(prop);
    }
    catch (boost::property_tree::ini_parser::ini_parser_error &e) {
        error(e.message());
        return 1;
    }
    catch (...) {
        error("Неизвестная ошибка");
        return 1;
    }


    return 0;
}



void gogo(Property prop) {

    std::string srcFileName = prop.getSrcFileName();
    std::ifstream ifsSrcFile(srcFileName.c_str());
    if (!ifsSrcFile) {
        error("Ошибка открытия файла '" + srcFileName + "'");
        throw new std::exception;
    }

    dMessage(srcFileName);
    system("pause");

    std::ofstream ofsTmpSql; //Временный файл для исходного кода
//    std::ifstream ifsTmpPlb; //Временный файл для рэпленного кода

    std::ofstream ofsCntrlTuSql(fileCntrlTuSqlName.c_str());
    ofsCntrlTuSql << "set define off" << std::endl;

    std::ofstream ofsCntrlSql(fileCntrlSqlName.c_str());
    ofsCntrlSql << "set define off" << std::endl;

    std::ofstream ofsPlbTu(filePlbTuName.c_str());
//    ofsPlbTuFile.open(filePlbTuName);
    ofsPlbTu << "set define off" << std::endl;

    std::ofstream ofsPlb(filePlbName.c_str());
//    ofsPlbFile.open(filePlbName);
    ofsPlb << "set define off" << std::endl;



    unsigned int nStartLine = 0; // Номер строки Начало создания объекта (процедуры, функции, пакета)
    unsigned int nEndLine = 0; // Номер строки Конец создания объекта
    unsigned int nCurrLine = 0; // Номер Текущей строки

    sigma::regex regCreate(ptrnCreateOrRepl);
    sigma::regex regEnd(ptrnEnd);
    sigma::regex regTuPkg(ptrnTuPkg);

    std::string sCurrStr(""); // Значение текущей строки
    std::string sStartStr(""); // Значение  строки  c началом команды

    bool isPckgBodyTu = false; // это тело пакета TU
    bool isPckgBodyTuFound = false; // пакет TU уже был обнаружен



    while (ifsSrcFile.good()) { // Чтение исходного файла с начала до конца
        ++nCurrLine;
        getline(ifsSrcFile, sCurrStr);
        if (regCreate.match(sCurrStr)) { // Обнаружено начало команды
            nStartLine = nCurrLine;
            sStartStr = sCurrStr;

            if (!isPckgBodyTuFound && regTuPkg.match(sCurrStr)) { // Это пакет TU
                // Определяем только в том случае, если пакет ТУ ещё не был обнаружен
                isPckgBodyTuFound = true;
                isPckgBodyTu = true;
            }

            ofsTmpSql.open(fileTmpSqlName);
        }

        ofsTmpSql << sCurrStr << std::endl;
        if (regEnd.match(sCurrStr)) { // Обнаружен конец команды
            if (nStartLine != 0) {
                nEndLine = nCurrLine;

                message(sStartStr + (isPckgBodyTu ? "**--ТУ-***" : "") + ": " + \
                  std::to_string(nStartLine) + " - " + std::to_string(nEndLine));

                nStartLine = 0;
                nEndLine = 0;
                sStartStr = "";
//                if (isPckgBodyTu) isPckgBodyTu = false; //Сбросим флаг, он больше не нужен
            }

            else
                error("Есть конец команды, нет начала команды. Строка " + nCurrLine);

            ofsTmpSql.close();
            wrapOracle(prop.getwrapCmd_w());

            makeFinalFile(ofsPlbTu, fileTmpPlbName);
            makeFinalFile(ofsCntrlTuSql, fileTmpSqlName);

            if (isPckgBodyTu) {
                switchOffTu();
                wrapOracle(prop.getwrapCmd_w());
                isPckgBodyTu = false; //Сбросим флаг, он больше не нужен
            }

            makeFinalFile(ofsPlb, fileTmpPlbName);
            makeFinalFile(ofsCntrlSql, fileTmpSqlName);



        }
    }
// WinExec("c:\\windows\\system32\\calc.exe",SW_SHOW);
    ifsSrcFile.close();
    ofsPlb.close();
    ofsPlbTu.close();

}

void wrapOracle(wchar_t* wrapCmd_) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    if (CreateProcess(NULL, wrapCmd_, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ))
    {
//        dMessage("Запущен wrap++++++++++++++");
        WaitForSingleObject( pi.hProcess, INFINITE );
//        dMessage("Завершён wrap-------------");
//        system("pause");

        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
    }
    else
        error("Ошибка запуска wrap");

}

/** Копирование из временного файла в основной
    @param out - входной поток временного файла (plb или sql)
    @param src - имя исходного файла
*/
void makeFinalFile (std::ofstream& out, std::string src) {
    std::ifstream inp(src.c_str());
    std::string str;

    while(inp.good()) {
        getline(inp, str);

        out << str << std::endl;

    }

    inp.close();
}

/** Выключение флага ТУ во временном файле */
void switchOffTu() {
    std::ifstream ifs(fileTmpSqlName.c_str());

    std::string fileTmp(fileTmpSqlName); //Промежуточный файл
    fileTmp.append("0");
    std::ofstream ofs(fileTmp.c_str());

    std::string str;
    sigma::regex ptrn(ptrnTuFlag);

    while(ifs.good()) {
        getline(ifs, str);

        if (ptrn.match(str)) {
            std::string strNew("--");
            strNew += str;
            str.assign(strNew);
        }


        ofs << str << std::endl;

    }

    ifs.close();
    ofs.close();

    remove(fileTmpSqlName.c_str());

    if (rename(fileTmp.c_str(), fileTmpSqlName.c_str())) { //0 - good
        error("Ошибка переименования файла " + fileTmp + " в " + fileTmpSqlName);
    }

}



