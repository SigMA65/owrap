#include <string>
#include <iostream>
#include <clocale>

#include <windows.h>

#include "message.h"

using std::cerr;
using std::cout;
using std::endl;

/** Отладочное сообщение */
void dMessage(std::string s) {
    cout << "#DEBUG# " << s << endl;
}

/** Cообщение */
void message(std::string s) {
    cout << "#MESS# " << s << endl;
}
/** Сообщение об ошибке */
void error(std::string s) {
    cerr << "#ERROR# " << s << endl;
}

/** Установка русской локали для вывода на консолль */
void setRusLocale() {

    setlocale(LC_ALL,"Russian");
    setlocale(LC_ALL,"russian_russia");
    // Это специально для windows 7
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}



