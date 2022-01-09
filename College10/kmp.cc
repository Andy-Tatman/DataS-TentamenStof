#include <iostream>
#include <vector>

// Pre: flink.size = patroon.size
void stelopFlink(std::vector<int> & flink, std::string const & patroon) {
    flink[0] = -1; // Default waarde.
    for (size_t i = 1; i < patroon.size(); i++) {
        flink[i] = flink[i-1];
        while (flink[i] > -1 && patroon[i-1] != patroon[ flink[i] ]) {
            flink[i] = flink[ flink[i] ];
        }
        flink[i] += 1; // -1 wordt 0, de A op pos 3 krijgt flink(3) = 1 etc
    }
}

bool findPatr(std::string const & input, std::string const & patroon, std::vector<int> & flink) {
    size_t posT = 0; // Pos in input (T=text)
    size_t posP = 0; // Pos in patroon

    while ( (posP < patroon.size() ) && (posT < input.size() )) {
        if (patroon[posP] == input[posT]) {
            posP++; posT++;
        }
        else { // Use FLinks
            posP = flink[posP];

            if (posP == -1) {
                posP = 0;
                posT++; 
            }

        }
    }

    if (posP >= patroon.size() ) {
        std::cout << "Pattern found at " << posT-patroon.size() << std::endl;
        return true;
    }
    else {
        if (posT < input.size()) {
            std::cout << "Huh??" << std::endl;
        } 
        return false;
    }
}

int main() {
    std::string input = "ABABCABCABABCC";
    std::string patroon = "ABCABABC";

    std::vector<int> flink; flink.resize( patroon.size() );

    stelopFlink(flink, patroon);
    // for (size_t i = 0; i < patroon.size(); i++) { 
    //     std::cout << patroon[i] << " heeft flink[" << i << "] = " << flink[i] << std::endl;
    // }
    if (findPatr(input, patroon, flink) ) {
        std::cout << "Found it" << std::endl;
    }
    else {
        std::cout << "Failed." << std::endl;
    }



    return 0;
}