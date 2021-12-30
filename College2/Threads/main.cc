#include <iostream>
#include "threads.h"


int main() {

    boom* testBoom = new boom;
    testBoom->setupThreads();
    testBoom->controlThreads(); 
    
    delete testBoom;  


    return 0;
}