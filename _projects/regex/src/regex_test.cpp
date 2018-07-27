//#include <iostream>


#include "regexMy.h"
#include "regex.h"
#include "message/message.h"

/** printResult Печать строки результата выполнения сравнения */
void printResult(const std::string, const bool);
/** printString Печать исходной строки */
void printString(const std::string&);
int main()
{
    message("Validate my regular expression lib\n\n");
    message("class regexMy\n");

    std::basic_ostringstream<char> strOut;
    std::string str1("Hello World!");
    printString(str1);

    try {
        regexMy r(".*\\sw.*");
        printResult(r.getShablon(), r.match(str1));

        regexMy r1(".*\\sW.*");
        printResult(r1.getShablon(), r1.match(str1));

        r.assign(".*to.*");

        str1.assign("Go to scool");
        printString(str1);
        printResult(r.getShablon(), r.match(str1));

        str1.assign("Go To scool");
        printString(str1);
        printResult(r.getShablon(), r.match(str1));

    }
    catch (std::exception& e) {
        error("Ошибка :");
        error(e.what());
    }

    message("\n\nclass regex\n");

    str1.assign("Hello World!");
    printString(str1);
    sigma::regex r(".*\\sw.*");
    printResult(r.getShablon(), r.match(str1));

    sigma::regex r1(".*\\sW.*");
    printResult(r1.getShablon(), r1.match(str1));

    r.assign(".*to.*");

    str1.assign("Go to scool");
    printString(str1);
    printResult(r.getShablon(), r.match(str1));

    str1.assign("Go To scool");
    printString(str1);
    printResult(r.getShablon(), r.match(str1));




    return 0;
}

void printResult(const std::string shablon, const bool res) {
    std::ostringstream strOut;
    strOut << "Template " << "\"" << shablon << "\"  Result: " << \
              std::boolalpha << res;
    message(strOut.str());
}

void printString(const std::string& str) {
    std::ostringstream strOut;
    message("");
    strOut << "String \"" << str << "\"";
    message(strOut.str());
}
