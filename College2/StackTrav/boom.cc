#include <iostream>
#include "boom.h"


knoop::knoop() {
    linker = nullptr;
    righter = nullptr;
    nummer = -1;
    bezocht = false;
}

knoop::~knoop() { 

}

void knoop::verwijderKinderen() {
    if (this->linker != nullptr) {
        this->linker->verwijderKinderen();
        delete this->linker;
    } 
    if (this->righter != nullptr) {
        this->righter->verwijderKinderen();
        delete this->righter;
    }
}

void knoop::onbezochtSubboom() {
    this->bezocht = false;
    if (this->linker != nullptr) {
        this->linker->onbezochtSubboom();
    } 
    if (this->righter != nullptr) {
        this->righter->onbezochtSubboom();
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

bool knoop::IsAllesBezocht() const {
    if (!bezocht) {
        return false;
    }
    if (this->linker != nullptr) {
        if ( !this->linker->IsAllesBezocht() ) {
            return false;
        }
    }
    if (this->righter != nullptr) { 
        if ( !this->righter->IsAllesBezocht() ) {
            return false;
        }
    }

    // Niks gevonden?
    return true;
}

//-----------------
// Stack traversal:


void knoop::inorderTrav(knoop* const begin) {
    knoop * hulp = begin;
    std::stack<knoop*> stapel;
    while( !stapel.empty() ) {
        stapel.pop(); 
    }
    // init done

    while (hulp != nullptr) {
        stapel.push(hulp);
        hulp = hulp->linker;
    }

    while ( !stapel.empty() ) {
        hulp = stapel.top(); stapel.pop();
        hulp->bezocht = true;
        hulp = hulp->righter;
        while (hulp != nullptr) {
            stapel.push(hulp);
            hulp = hulp->linker;
        }
    }
}

void knoop::preorderTrav(knoop* const begin) { 
    knoop * hulp = begin;
    std::stack<knoop*> stapel;
    while( !stapel.empty() ) {
        stapel.pop(); 
    }
    // init done

    stapel.push(begin);
    while ( !stapel.empty() ) {
        hulp = stapel.top();  stapel.pop();
        if (hulp != nullptr) {
            hulp->bezocht = true;
            stapel.push(hulp->righter); stapel.push(hulp->linker); 
        }
    }
}

void knoop::postorderTrav(knoop* const begin) { 
    knoop * hulp = begin;
    std::stack<knoop*> stapel;
    while( !stapel.empty() ) {
        stapel.pop(); 
    }
    // init done

   
}


//------------------------------------------------------------------------------
boom::boom() {
    beginKnoop = new knoop;
    beginKnoop->stelOpBoom(9);
    // this->printBoomIno();
}

boom::~boom() {
    beginKnoop->verwijderKinderen();
    delete beginKnoop;
}

// void boom::printBoomIno() const {
//     beginKnoop->printInorderSubboom();
//     std::cout << std::endl;
// }

void boom::testIsBezocht() const {
    if ( beginKnoop->IsAllesBezocht() ) {
        std::cout << "Alles bezocht => OK" << std::endl;
    }
    else {
        std::cout << "Error: niet alles bezocht." << std::endl;
    }
}