#include <iostream>
#include "boom.h"


int main() {

    boom* testBoom = new boom;
    std::string invoer = "";
    int number;

    std::cin >> invoer;
    while (invoer != "end" && std::cin.eof() != 1) {
        if (invoer == "insert") {
            std::cin >> number;
            testBoom->insert(number);
        }
        else if (invoer == "dot") {
            testBoom->printDotNot();
        }
        else if (invoer == "print") {
            testBoom->print();
        }
        else { std::cout << "Idk what " << invoer << " is" << std::endl; }
        std::cin >> invoer;
    }
    
    delete testBoom;  


    return 0;
}