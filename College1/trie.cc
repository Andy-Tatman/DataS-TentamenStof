#include <iostream>
#include <vector>
#include "trie.h"


knoop::knoop() {
    for(size_t i = 0; i < 26; i++) {
        kinderen[i] = nullptr;
        hebKind[i] = false;
    }
    isEindWoord = false; // Default
}

knoop::~knoop() { 

}

void knoop::verwijderKinderen() { 
    for(size_t i = 0; i < 26; i++) {
        if (hebKind[i]) {
            kinderen[i]->verwijderKinderen();
            delete kinderen[i];
            //kinderen[i] = nullptr;
        }
    }
}

void knoop::stelInEind() {
    this->isEindWoord = true;
}

bool knoop::zitStrSubboom(std::string const & str) const {
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

void knoop::addStrSubboom(std::string const & str) {
    if (str.size() == 0) { // Empty string -> This is the end of the word.
        this->isEindWoord = true;
    }
    // ELSE:

    int index = str[0] - 'a'; // 0 <= Index <= 25
    if ( !(hebKind[index]) ) {
        kinderen[index] = new knoop;
        hebKind[index] = true;
    }

    if (str.size() > 1) {
        kinderen[index]->addStrSubboom( str.substr(1, (str.size()-1) ) );
    }
    else { // This was the last letter.
        kinderen[index]->stelInEind();
    }
    
}


//------------------------------------------------------------------------------

trie::trie() {
    beginKnoop = new knoop;
    beginKnoop->stelInEind(); // Definitie: de lege string zit in de boom.
}

trie::~trie() {
    beginKnoop->verwijderKinderen();
    delete beginKnoop;
}

bool trie::zitStringInBoom(std::string const & str) const {
    return beginKnoop->zitStrSubboom(str);
}

void trie::addString(std::string const & str) {
    beginKnoop->addStrSubboom(str);
}