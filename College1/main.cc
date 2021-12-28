#include <iostream>
#include "trie.h"



int main() {
    trie* woordBoom = new trie;
    if ( woordBoom->zitStringInBoom("") ) {
        std::cout << "Henlo" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    if ( woordBoom->zitStringInBoom("AAA") ) {
        std::cout << "Henlo" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    


    return 0;
}