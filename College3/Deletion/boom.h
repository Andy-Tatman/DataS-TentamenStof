#ifndef BOOMH
#define BOOMH

#include <iostream> 

class knoop {
    public:
        knoop();
        knoop(int const & nieuw);
        ~knoop();
        void verwijderKinderen();
        void insertK(int const & nieuw);
        bool isElementK(int const & num) const;
        void deleteCopyK(int const & num);
        void deleteMergeK(int const & num);


        void printInorderSubboom() const;
    private:
        int nummer;
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
        void deleteCopy(int const & num);
        void deleteMerge(int const & num);

        void print() const { if (beginKnoop != nullptr) { beginKnoop->printInorderSubboom(); std::cout << std::endl; }}

    private:
        knoop* beginKnoop;
};


#endif 