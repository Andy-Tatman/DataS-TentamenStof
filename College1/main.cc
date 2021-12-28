#include <iostream>
#include "trie.h"

bool inspect(std::string const & str) {
    for (size_t i = 0; i < str.size(); i++) {
        if ( !(str[i] >= 'a' && str[i] <= 'z' ) ) {
            std::cout << "Foei, str = " << str << "mag niet." << std::endl;
            return false; 
        }
    }
    // No error:
    return true;
}

int main() {
    trie* woordBoom = new trie;
    if ( woordBoom->zitStringInBoom("") ) {
        std::cout << "Henlo" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    if ( woordBoom->zitStringInBoom("aaa") ) {
        std::cout << "Henlo" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    

    woordBoom->addString("a");
    if ( woordBoom->zitStringInBoom("a") ) {
        std::cout << "Henlo" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    delete woordBoom;
    return 0;
}