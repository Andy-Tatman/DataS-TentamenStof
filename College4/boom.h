#ifndef BOOMH
#define BOOMH

#include <iostream> 

class knoop {
    public:
        knoop();
        knoop(int const & nieuw);
        ~knoop();
        void verwijderKinderen();
        void insertK(int const & nieuw, bool & checkBalans);
        bool isElementK(int const & num) const;
        void deleteCopyK(int const & num);
        void deleteMergeK(int const & num);


        void printInorderSubboom() const;
        void printDotNotK(std::ofstream & uitvoer) const;
        void zetDotNK(long long & teller);
    // private:
        int nummer;
        int dotN;
        int balans;
        knoop* linker;
        knoop* righter;

};

class boom {
    public:
        boom();
        ~boom();
        void insert(int const & nieuw);
        bool isEmpty() const { return (beginKnoop == nullptr); }
        bool isElement(int const & num) const;

        void print() const { if (beginKnoop != nullptr) { beginKnoop->printInorderSubboom(); std::cout << std::endl; }}
        void printDotNot() const;
        
    private:
        knoop* beginKnoop;
        bool isDotNGoed;
};


#endif 