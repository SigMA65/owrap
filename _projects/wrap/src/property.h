#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

/** �������� */
class Property {
public:
    Property();
    std::string getWrapPath();
    std::string getwrapCmd();
    wchar_t* getwrapCmd_w();
    void setSrcFileName(std::string);
    std::string getSrcFileName();
private:
    /** ���� ������� � ������� ��������� wrap */
    std::string _wrapPath;
    /** ������ ������� ��� ��������� */
    std::string _wrapCmd;
    wchar_t* _wrapCmd_w;
    /** ��� ��������� �����, ������� ����� �������� */
    std::string _srcFileName;
};


#endif // PROPERTY_H
