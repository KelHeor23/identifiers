#include "Identifiers.h"

std::string Identifiers::nextIdent(std::string strIdent)
{
    checkFormat(strIdent);
    auto it_begin = strIdent.begin();
    auto it = strIdent.end() - 2;
    std::string result;
    result.reserve(strIdent.length());

    if (changeIdent(it_begin, it, result) == 1)
    {
        if (result.size() + 3 > MAX_COUNT_GROUPS * 2 + MAX_COUNT_GROUPS - 1)
            throw std::runtime_error("Too much groups");
        result.reserve(strIdent.length() + 3);
        result.append("-A1");
    }
    return result;
}

bool Identifiers::changeIdent(std::string::iterator it_begin, std::string::iterator it, std::string &result)
{
    static bool fullChange = 0; //whether the identifier has moved to the next digit
    if (*(it + 1) != '9') //digit increment
    {
        if (it != it_begin)
            copyNotChangeIdent(it_begin, it, result);
        result.push_back(*it);
        result.push_back(*(it + 1) + 1);
    }
    else if (*it != 'Z') //increment letter
    {
        if (it != it_begin)
            copyNotChangeIdent(it_begin, it, result);
        result.push_back(getNextSymbol(*it));
        result.push_back('1');
    }
    else if (*it == 'Z') //transition to the next order
    {
        if (it != it_begin)
        {
            it -= 3;
            changeIdent(it_begin, it, result);
            result.append("-A1");
        }
        else if (it == it_begin)
        {
            result.append("A1");
            fullChange = 1;
        }
    }
    else
        throw std::runtime_error("Format error");
    return fullChange;
}

char Identifiers::getNextSymbol(char c)
{
    c++;
    while (expt.find(c) != expt.end()) //checking if the suggested letter is in the blacklist
        c++;
    return c;
}

void Identifiers::copyNotChangeIdent(std::string::iterator it_begin, std::string::iterator it_end, std::string& result)
{
    for (auto it = it_begin; it != it_end; it++)
        result.push_back(*it);
    return;
}

bool Identifiers::checkFormat(std::string& str)
{
    int position = 1;

    if (!(*(str.end() - 1) >= '1' && *(str.end() - 1) <= '9'))
        throw std::runtime_error("Invalid last characters");

    for (auto it = str.begin(); it < str.end(); it++)
    {
        if(position % 3 == 1 && !(*it >= 'A' && *it <= 'Z'))
            throw std::runtime_error("Format error");
        else if (expt.find(*it) != expt.end())
            throw std::runtime_error("Invalid characters used");
        else if (position % 3 == 2 && !(*it >= '1' && *it <= '9'))
            throw std::runtime_error("Format error");
        else if (position % 3 == 0 && *it != '-')
            throw std::runtime_error("Format error");
        position++;
    }
    return true;
}
