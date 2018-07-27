#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

/** Свойства */
class Property {
public:
    Property();
    std::string getWrapPath();
    std::string getwrapCmd();
    wchar_t* getwrapCmd_w();
    void setSrcFileName(std::string);
    std::string getSrcFileName();
private:
    /** Путь доступа к утилите рапования wrap */
    std::string _wrapPath;
    /** Полная команда для рапования */
    std::string _wrapCmd;
    wchar_t* _wrapCmd_w;
    /** Имя исходного файла, который нужно зарапить */
    std::string _srcFileName;
};


#endif // PROPERTY_H
