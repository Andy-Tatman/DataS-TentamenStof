#include <iostream>
#include "threads.h"


knoop::knoop() {
    linker = nullptr;
    righter = nullptr;
    nummer = -1;
    rightIsThread = false;
    bezocht = false;
}

knoop::~knoop() { 

}

void knoop::verwijderKinderen() {
    if (this->linker != nullptr) {
        this->linker->verwijderKinderen();
        delete this->linker;
    } 
    // Verwijder dit kind alleen als het geen thread is. 
    //  (dus alleen als het echt een kind is.)
    if (this->righter != nullptr && !rightIsThread) {
        this->righter->verwijderKinderen();
        delete this->righter;
    }
}

/**Maak de boom zoals in slide 24 van college 2 van DataStr 2020. */
void knoop::stelOpBoom(int const & n) {
    this->nummer = n;
    switch (n){ // Default: Elke knoop is een blad.
        case 1:
            break;

        case 2:
            this->linker = new knoop;
            this->linker->stelOpBoom(1);
            break;

        case 3:
            this->linker = new knoop;
            this->linker->stelOpBoom(2);
            this->righter = new knoop;
            this->righter->stelOpBoom(4);
            break;

        case 4:
            break;
        
        case 5:
            this->linker = new knoop;
            this->linker->stelOpBoom(3);
            this->righter = new knoop;
            this->righter->stelOpBoom(7);
            break;
        
        case 6:
            break;

        case 7:
            this->linker = new knoop;
            this->linker->stelOpBoom(6);
            this->righter = new knoop;
            this->righter->stelOpBoom(8);
            break;
        
        case 8:
            break;

        case 9:
            this->linker = new knoop;
            this->linker->stelOpBoom(5);
            this->righter = new knoop;
            this->righter->stelOpBoom(12);
            break; 
        
        case 10:
            this->righter = new knoop;
            this->righter->stelOpBoom(11);
            break;

        case 11:
            break;

        case 12:
            this->linker = new knoop;
            this->linker->stelOpBoom(10);
            break;
        
        default:
            std::cout << "Unknown n = " << n << std::endl;
            break;
    }
}

void knoop::printInorderSubboom() const {
    if (this->linker != nullptr) {
        this->linker->printInorderSubboom();
    }
    std::cout <<  nummer << " " ;
    if (this->righter != nullptr) {
        this->righter->printInorderSubboom();
    }
}


//---------
// Threads

void knoop::knoopThreads(knoop* const threadAdres) { 
    knoop * hulp;
    if (this->linker != nullptr) {
        if (this->linker->linker != nullptr) {
            this->linker->knoopThreads(this);
        }
        else {
            hulp = this->linker;
            while (hulp->righter != nullptr) {
                hulp = hulp->righter;
            }
            hulp->righter = this;
            hulp->rightIsThread = true;
        }
    }
    
    if (this->righter == nullptr) {
        this->righter = threadAdres;
        this->rightIsThread = true;
    }
    else { // Geef het adres voor de thread door.
        this->righter->knoopThreads(threadAdres); 
    }

}

void knoop::testThreadsIter(knoop * const beginKnoop) const {
    knoop* hulp = beginKnoop;
    bool threadGenommen = false;
    while (hulp != nullptr) {
        if (threadGenommen) { // De linker van deze (indien hij bestaat) is al genomen.
            hulp->bezocht = true;
            
            threadGenommen = hulp->rightIsThread;// Onthoud of we nu een thread nemen.
            if (!threadGenommen) { std::cout << " n = " << hulp->nummer << std::endl; }
            hulp = hulp->righter;

            if (!threadGenommen) {
                std::cout << "2 Ik denk dat ik jou niet zie???" << std::endl;
            }
        }
        else if (hulp->linker != nullptr) {
            hulp = hulp->linker;
            threadGenommen = false;
        }
        else {
            hulp->bezocht = true; 
            // Als de threads goed staan, dan is elke righter != nullptr behalve de laatste.
            // Alleen de righter van knoop 12 is nullptr.
            threadGenommen = hulp->rightIsThread;// Onthoud of we nu een thread nemen.
            if (!threadGenommen) { std::cout << " n = " << hulp->nummer << std::endl; }
            hulp = hulp->righter;
            if (!threadGenommen) {
                std::cout << "1 Ik denk dat ik jou niet zie???" << std::endl;
            }
        }
    }
    std::cout << "End of testThreadsIter." << std::endl;
}

bool knoop::IsAllesBezocht() const {
    if (!bezocht) {
        return false;
    }
    if (this->linker != nullptr) {
        if ( !this->linker->IsAllesBezocht() ) {
            return false;
        }
    }
    // Ga alleen rechts af als het GEEN thread is.
    if (this->righter != nullptr && !this->rightIsThread) { 
        if ( !this->righter->IsAllesBezocht() ) {
            return false;
        }
    }

    // Niks gevonden?
    return true;
}

//------------------------------------------------------------------------------
boom::boom() {
    beginKnoop = new knoop;
    beginKnoop->stelOpBoom(9);
    this->printBoomIno();
}

boom::~boom() {
    beginKnoop->verwijderKinderen();
    delete beginKnoop;
}

void boom::printBoomIno() const {
    beginKnoop->printInorderSubboom();
    std::cout << std::endl;
}

void boom::setupThreads() {
    beginKnoop->knoopThreads(nullptr);
}

void boom::controlThreads() const {
    beginKnoop->testThreadsIter(beginKnoop);

    if ( beginKnoop->IsAllesBezocht() ) {
        std::cout << "Alles bezocht => OK" << std::endl;
    }
    else {
        std::cout << "Error: niet alles bezocht." << std::endl;
    }
}

void boom::zetallesOnbezocht() {
    beginKnoop->onbezochtSubboom();
}