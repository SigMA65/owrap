#ifndef REGEXMY_H
#define REGEXMY_H

#include <string>

#include <boost/regex.hpp>

/** regex оболочка для внешнего класса регулярных выражений */
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

/** regex_match проверить на удовлетворение регулярному выражению*/
//inline bool regex_match(std::string s, regex r) {
//    boost::regex rr = r;
////    return boost::regex_match(s, rr);
//    return 0;
//}


#endif // REGEXMY_H
