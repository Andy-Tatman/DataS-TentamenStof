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
        else if (invoer == "deleteCopy") {
            std::cin >> number;
            testBoom->deleteCopy(number);
        }
        else if (invoer == "deleteMerge") {
            std::cin >> number;
            testBoom->deleteMerge(number);
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