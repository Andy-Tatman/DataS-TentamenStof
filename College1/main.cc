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
    std::cout << "1: Add a word to the trie." << std::endl
              << "2: Test to see if a word is in the trie." << std::endl
              << "3 (or \"end\"): End" << std::endl
              << "!! All words can only contains letters in [a-z]." << std::endl;
    std::string invoer = "";
    std::string word = "";
    while (invoer != "end" && std::cin.eof() != 1) {
        std::cout << "New option: ";
        std::cin >> invoer;
        if (invoer == "end") {
            break;
        }
        else if (invoer == "1") {
            std::cout << "Submit the word: ";
            std::cin >> word;
            if (!inspect(word)) {
                std::cout << "Inspection failed." << std::endl;
            }
            else {
                woordBoom->addString(word);
            }
            
        }
        else if (invoer == "2") {
            std::cout << "Submit the word: ";
            std::cin >> word;
            if (!inspect(word)) {
                std::cout << "Inspection failed." << std::endl;
            }
            else {
                if( woordBoom->zitStringInBoom(word) )
                    std::cout << "Yes" << std::endl;
                else 
                    std::cout << "No" << std::endl;
            }
            
        }
        else {
            std::cout << "Bruh idk that option" << std::endl;
        }
    }


    delete woordBoom;
    return 0;
}