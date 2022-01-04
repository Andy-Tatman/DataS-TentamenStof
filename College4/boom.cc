#include <iostream>
#include <fstream> // Voor printdotnot
#include "boom.h"


knoop::knoop() {
    linker = nullptr;
    righter = nullptr;
    nummer = -1;
    dotN = -1;
}

knoop::knoop(int const & nieuw) {
    linker = nullptr;
    righter = nullptr;
    nummer = nieuw;
    dotN = -1;
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


void knoop::insertK(int const & nieuw) {
    if (nieuw == this->nummer) {
        return;
    }
    else if (nieuw < this->nummer) {
        // zoek links
        if (this->linker == nullptr) {
            this->linker = new knoop(nieuw);
        }
        else {
            this->linker->insertK(nieuw);
        }
    }
    else { // >
        // zoek rechts
        if (this->righter == nullptr) {
            this->righter = new knoop(nieuw);
        }
        else {
            this->righter->insertK(nieuw);
        }
    }

}

bool knoop::isElementK(int const & num) const {
    if (this->nummer == num) {
        return true;
    }
    else if (num < this->nummer) {
        // zoek links
        if (this->linker == nullptr) {
            return false;
        }
        else {
            return this->linker->isElementK(num);
        }
    } 
    else { // >
        // zoek rechts
        if (this->righter == nullptr) {
            return false;
        }
        else {
            return this->righter->isElementK(num);
        }
    } 
}

void swap(int & A, int & B) {
    int temp = A; A = B; B = temp;
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

void knoop::printDotNotK(std::ofstream & uitvoer) const {
    uitvoer << dotN << " [label=\"" << nummer << "\"] \n";

    if (this->linker!=nullptr){ 
        this->linker->printDotNotK(uitvoer);
        uitvoer << this->dotN << " -> " << this->linker->dotN << std::endl; 
    }


    if (this->righter!=nullptr){ 

        this->righter->printDotNotK(uitvoer);
        uitvoer << this->dotN << " -> " << this->righter->dotN << std::endl; 
    }
}

void knoop::zetDotNK(long long & teller) {
    dotN = teller;
    teller++;

    if (this->linker != nullptr) {
        this->linker->zetDotNK(teller);
    }
    if (this->righter != nullptr) {
        this->righter->zetDotNK(teller);
    }
}

//------------------------------------------------------------------------------
boom::boom() {
    beginKnoop = nullptr;

}

boom::~boom() {
    beginKnoop->verwijderKinderen();
    delete beginKnoop;
}

void boom::insert(int const & nieuw) {
    if (beginKnoop == nullptr) {
        beginKnoop = new knoop(nieuw);
    }
    else {
        beginKnoop->insertK(nieuw);
    }
}

bool boom::isElement(int const & num) const {
    if (beginKnoop == nullptr) {
        return false;
    }
    else {
        return beginKnoop->isElementK(num);
    }
}


void boom::printDotNot() const {
    if (beginKnoop != nullptr) {
        long long teller = 0;
        beginKnoop->zetDotNK(teller);

        std::ofstream uitvoer;
        uitvoer.open("dotnot.txt");
        uitvoer << "  digraph G {" << std::endl;

        beginKnoop->printDotNotK(uitvoer);

        uitvoer << "}" << std::endl;
        uitvoer.close(); 
    }
}