#include <iostream>
#include "boom.h"


int main() {

    boom* testBoom = new boom;

    std::cout << "In order: " << std::endl;
    testBoom->zetallesOnbezocht();
    testBoom->boomInOrder();
    testBoom->testIsBezocht();

    std::cout << "Pre order: " << std::endl;
    testBoom->zetallesOnbezocht();
    testBoom->boomPreOrder();
    testBoom->testIsBezocht();

    std::cout << "Post order: " << std::endl;
    testBoom->zetallesOnbezocht();
    testBoom->boomPostOrder();
    testBoom->testIsBezocht();
    
    delete testBoom;  


    return 0;
}