#include "regex.h"

sigma::regex::regex(std::string s)
    :boost::regex(s), _shablon(s) {}

std::string sigma::regex::getShablon()
{
    return _shablon;
}

/** regex_match проверить на удовлетворение регулярному выражению*/
bool sigma::regex::match(std::string s)
{
    return boost::regex_match(s, *this);
}
