#include <iostream>
#include <vector>
#include "trie.h"


knoop::knoop() {
    for(size_t i = 0; i < 26; i++) {
        kinderen[i] = nullptr;
        hebKind[i] = false;
    }
}

knoop::~knoop() { 
    for(size_t i = 0; i < 26; i++) {
        if (kinderen[i] != nullptr) {
            delete kinderen[i];
            kinderen[i] = nullptr;
        }
    }
}

void knoop::stelInEind() {
    this->isEindWoord = true;
}

bool knoop::zitStrSubboom(std::string const & str) {
    if (str.size() == 0) { // Empty string -> This is the end of the word.
        return isEindWoord;
    }
    // ELSE:

    int index = str[0] - 'a'; // 0 <= Index <= 25
    if (hebKind[index]) {
        return kinderen[index]->zitStrSubboom( str.substr(1, (str.size()-1) ) );
    } 
    else {
        return false;
    }

}


//------------------------------------------------------------------------------

trie::trie() {
    beginKnoop = new knoop;
    beginKnoop->stelInEind(); // Definitie: de lege string zit in de boom.
}

trie::~trie() {
    delete beginKnoop;
}

bool trie::zitStringInBoom(std::string const & str) {
    return beginKnoop->zitStrSubboom(str);
}