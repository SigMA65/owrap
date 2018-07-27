#ifndef REGEX_H
#define REGEX_H

#include <string>

#include <boost/regex.hpp>

namespace sigma {

/** regex оболочка для внешнего класса регулярных выражений */
class regex : public boost::regex
{
public:
    regex(std::string);
    std::string getShablon();
    bool match(std::string);
//    void assign(std::string s);
private:
//    boost::regex _regex;
    std::string _shablon;
};


}



#endif // REGEX_H
