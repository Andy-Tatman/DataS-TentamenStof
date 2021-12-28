#ifndef TRIEH
#define TRIEH

/**ADT for storing strings in a trie.
 * Pre for all functions:
 *      Strings may only contain the letters [a-z]. (And not e.g. [A-Z].)
*/

#include <iostream>
#include <vector>

class knoop {
    public:
        knoop();
        ~knoop();
        void verwijderKinderen();

        void stelInEind(); //Dit is het einde van een woord. 
        bool zitStrSubboom(std::string const & str) const;
        void addStrSubboom(std::string const & str);
        void Report() { if (eenKind) std::cout << "True" << std::endl;
                        else std::cout << "False" << std::endl;  }
    private:
        knoop* kinderen[26]; // Voor elke letter a-z 1
        bool hebKind[26]; // Is dit kind al aangemaakt?
        bool isEindWoord;
        bool eenKind;
        // geen letter nodig: De plek in de array geeft al wat de letter is.
};

class trie {
    public:
        trie();
        ~trie();
        
        bool zitStringInBoom(std::string const & str) const;
        void addString(std::string const & str);


    private:
        knoop* beginKnoop;
};

#endif 