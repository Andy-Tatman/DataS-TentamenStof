#ifndef BOOMH
#define BOOMH

#include <iostream>

class knoop {
    public:
        knoop();
        ~knoop();
        void verwijderKinderen();

        void stelOpBoom(int const & n);
        void printInorderSubboom() const;
        void knoopThreads(knoop* const threadAdres);
        void testThreadsIter(knoop * const beginKnoop) const;
        bool IsAllesBezocht() const;
    private:
        int nummer;
        knoop* linker;
        knoop* righter;

        bool rightIsThread;
        bool bezocht;
};

class boom {
    public:
        boom();
        ~boom();
        
        void printBoomIno() const;
        void setupThreads();
        void controlThreads() const;
    private:
        knoop* beginKnoop;
};


#endif 