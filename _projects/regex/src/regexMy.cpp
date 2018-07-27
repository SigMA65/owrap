#include "regexMy.h"

regexMy::regexMy(std::string s)
    :_regex(s), _shablon(s) {}

std::string regexMy::getShablon()
{
    return _shablon;
}

/** regex_match ��������� �� �������������� ����������� ���������*/
bool regexMy::match(std::string s)
{
    return boost::regex_match(s, _regex);
}

/** assign �������� ������ ����������� ���������*/
void regexMy::assign(std::string s)
{
    _regex.assign(s);
    _shablon=s;
}




