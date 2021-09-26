#include <iostream>
#include "src/Identifiers.h"

int main() {
    std::cout << Identifiers::nextIdent("A2")  << '\n';
    std::cout << Identifiers::nextIdent("A9")  << '\n';
    std::cout << Identifiers::nextIdent("C9")  << '\n';
    std::cout << Identifiers::nextIdent("C9-A1-Z9")  << '\n';
    std::cout << Identifiers::nextIdent("Z9-Z9-Z9")  << '\n';
    return 0;
}
