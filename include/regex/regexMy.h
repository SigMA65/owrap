#ifndef REGEXMY_H
#define REGEXMY_H

#include <string>

#include <boost/regex.hpp>

/** regex �������� ��� �������� ������ ���������� ��������� */
class regexMy
{
public:
    regexMy(std::string);
    std::string getShablon();
    bool match(std::string);
    void assign(std::string s);
private:
    boost::regex _regex;
    std::string _shablon;
};

/** regex_match ��������� �� �������������� ����������� ���������*/
//inline bool regex_match(std::string s, regex r) {
//    boost::regex rr = r;
////    return boost::regex_match(s, rr);
//    return 0;
//}


#endif // REGEXMY_H
