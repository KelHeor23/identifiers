#include <string>
#include <set>
#include <exception>
#ifndef IDENTIFIERS_IDENTIFIERS_H
#define IDENTIFIERS_IDENTIFIERS_H

#define MAX_COUNT_GROUPS 10

//black list symbols
const std::set<char> expt {'D', 'F', 'G', 'J', 'M', 'Q', 'V'};

class Identifiers {
private:
    //recursive method handling identifiers
    static int changeIdent(std::string::iterator, std::string::iterator, std::string&);
    //get next valid character
    static char getNextSymbol(char);
    //copies an immutable identifier
    static void copyNotChangeIdent(std::string::iterator, std::string::iterator, std::string&);
    //check if the format is correct
    static bool checkFormat(std::string&);
public:
    //main method accepting an identifiers string
    static std::string nextIdent(std::string);
};


#endif //IDENTIFIERS_IDENTIFIERS_H
