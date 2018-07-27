#include <string>
#include <iostream>
#include <clocale>

#include <windows.h>

#include "message.h"

using std::cerr;
using std::cout;
using std::endl;

/** ���������� ��������� */
void dMessage(std::string s) {
    cout << "#DEBUG# " << s << endl;
}

/** C�������� */
void message(std::string s) {
    cout << "#MESS# " << s << endl;
}
/** ��������� �� ������ */
void error(std::string s) {
    cerr << "#ERROR# " << s << endl;
}

/** ��������� ������� ������ ��� ������ �� �������� */
void setRusLocale() {

    setlocale(LC_ALL,"Russian");
    setlocale(LC_ALL,"russian_russia");
    // ��� ���������� ��� windows 7
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}



