#ifndef BOOMH
#define BOOMH

#include <iostream>
#include <stack> 

class knoop {
    public:
        knoop();
        ~knoop();
        void verwijderKinderen();
        void onbezochtSubboom();
        void stelOpBoom(int const & n);
        void printInorderSubboom() const;
        bool IsAllesBezocht() const;

        // Stack traversal:
        void inorderTrav( knoop* const begin );
        void preorderTrav( knoop* const begin );
        void postorderTrav( knoop* const begin );

    private:
        int nummer;
        knoop* linker;
        knoop* righter;

        bool bezocht;
};

class boom {
    public:
        boom();
        ~boom();
        
        void printBoomIno() const;
        void zetallesOnbezocht(){ beginKnoop->onbezochtSubboom(); }
        
        void boomInOrder() { beginKnoop->inorderTrav( beginKnoop ); } 
        void boomPreOrder() { beginKnoop->preorderTrav( beginKnoop ); }
        void boomPostOrder() { beginKnoop->postorderTrav( beginKnoop ); }
        void testIsBezocht() const;
    private:
        knoop* beginKnoop;
};


#endif 