#include <iostream>
#include "boom.h"


knoop::knoop() {
    linker = nullptr;
    righter = nullptr;
    nummer = -1;
}

knoop::knoop(int const & nieuw) {
    linker = nullptr;
    righter = nullptr;
    nummer = nieuw;
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



/**
 * Pre: num is een element in de boom.
 *      num is NIET het element in de wortel.
*/
void knoop::deleteCopyK(int const & num) {
    if (num == this->nummer) {
        // special stuff voor de wortel
        std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
    }
    else {
        knoop* toDelete = this;
        knoop* ouder = nullptr;
        while (toDelete->nummer != num) {
            ouder = toDelete;
            if (num < toDelete->nummer) {
                toDelete = toDelete->linker;
            }
            else { // >
                toDelete = toDelete->righter;
            }
        }

        // Als toDelete 0 kinderen heeft, kun je hulp gewoon verwijderen.
        if (toDelete->linker == nullptr && toDelete->righter == nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = nullptr;
                }
                else {
                    ouder->righter = nullptr;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }
        
        // Als 1 kind, zet dat kind op de plek van toDelete in ouder
        // (probleem als toDelete = wortel)
        else if (toDelete->linker == nullptr &&  toDelete->righter != nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = toDelete->righter;
                }
                else {
                    ouder->righter = toDelete->righter;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }
        else if (toDelete->linker != nullptr &&  toDelete->righter == nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = toDelete->linker;
                }
                else {
                    ouder->righter = toDelete->linker;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }

        // 2 kinderen: Pas copying methode toe:
        else {
            knoop* hulp = toDelete->linker; // je weet dat dit != nullptr.
            knoop* ouderHulp = nullptr;
            while (hulp->righter != nullptr) {
                ouderHulp = hulp;
                hulp = hulp->righter;
            }

            swap(hulp->nummer, toDelete->nummer);
            // Als hulp nog een linkersubboom heeft, moet je deze netjes opruimen:
            if (hulp->linker != nullptr) {
                if (ouderHulp == nullptr) {
                    // hulp = toDelete->linker
                    toDelete->linker = hulp->linker;
                }
                else {
                    // hulp = ouderHulp->righter
                    ouderHulp->righter = hulp->linker;
                }
            }
            else {
                if (ouderHulp == nullptr) {
                    // hulp = toDelete->linker
                    toDelete->linker = nullptr;
                }
                else {
                    // hulp = ouderHulp->righter
                    ouderHulp->righter = nullptr;
                }
            }
            delete hulp;


        }

    }
}

/**
 * Pre: num is een element in de boom.
 *      num is NIET het element in de wortel.
*/
void knoop::deleteMergeK(int const & num) {
    if (num == this->nummer) {
        // special stuff voor de wortel
        std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
    }
    else {
        knoop* toDelete = this;
        knoop* ouder = nullptr;
        while (toDelete->nummer != num) {
            ouder = toDelete;
            if (num < toDelete->nummer) {
                toDelete = toDelete->linker;
            }
            else { // >
                toDelete = toDelete->righter;
            }
        }

        // Als toDelete 0 kinderen heeft, kun je hulp gewoon verwijderen.
        if (toDelete->linker == nullptr && toDelete->righter == nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = nullptr;
                }
                else {
                    ouder->righter = nullptr;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }
        
        // Als 1 kind, zet dat kind op de plek van toDelete in ouder
        // (probleem als toDelete = wortel)
        else if (toDelete->linker == nullptr &&  toDelete->righter != nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = toDelete->righter;
                }
                else {
                    ouder->righter = toDelete->righter;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }
        else if (toDelete->linker != nullptr &&  toDelete->righter == nullptr) {
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = toDelete->linker;
                }
                else {
                    ouder->righter = toDelete->linker;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }
            delete toDelete;
        }

        // 2 kinderen: Pas merging methode toe:
        else {
            knoop* komtOpPlekToDel = toDelete->linker;// je weet dat dit != nullptr.
            knoop* hulp = komtOpPlekToDel; 
            while (hulp->righter != nullptr) {
                hulp = hulp->righter;
            }

            hulp->righter = toDelete->righter;
            if (ouder != nullptr) {
                if (ouder->linker == toDelete) {
                    ouder->linker = komtOpPlekToDel;
                }
                else if (ouder->righter == toDelete) {
                    ouder->righter = komtOpPlekToDel;
                }
                else {
                    std::cout << "ERROR" << std::endl;
                }
            }
            else {
                std::cout << "Error: Undefined behaviour for deleting wortel." << std::endl;
            }

        }

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

void boom::deleteCopy(int const & num) {
    if (beginKnoop != nullptr && beginKnoop->isElementK(num)) {
        beginKnoop->deleteCopyK(num);
    }
}

void boom::deleteMerge(int const & num) {
    if (beginKnoop != nullptr && beginKnoop->isElementK(num)) {
        beginKnoop->deleteMergeK(num);
    }
}