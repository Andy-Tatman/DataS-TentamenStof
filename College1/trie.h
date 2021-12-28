#ifndef TRIEH
#define TRIEH

#include <iostream>
#include <vector>

class knoop {
    public:
        knoop();
        ~knoop();
        void stelInEind(); //Dit is het einde van een woord. 
        bool zitStrSubboom(std::string const & str);
    private:
        knoop* kinderen[26]; // Voor elke letter a-z 1
        bool hebKind[26]; // Is dit kind al aangemaakt?
        bool isEindWoord;
        // geen letter nodig: De plek in de array geeft al wat de letter is.
};

class trie {
    public:
        trie();
        ~trie();
        
        bool zitStringInBoom(std::string const & str);
        void addString(std::string const & str);


    private:
        knoop* beginKnoop;
};

#endif 