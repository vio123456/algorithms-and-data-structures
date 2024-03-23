#include <iostream>

void printUnsignedIntInBinary(unsigned int number) {
    
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

    bool leadingZero = true;

    for (int i = 0; i < sizeof(unsigned int) * 8; ++i) {
        if ((number & mask) == 0) {
            
            if (!leadingZero) {
                std::cout << "0";
            }
        } else {
            std::cout << "1";
            leadingZero = false; 
        }
        mask >>= 1; 
    }
  
    if (leadingZero) {
        std::cout << "0";
    }
}

int main() {
    unsigned int number;
    std::cout << "Enter an unsigned integer: ";
    std::cin >> number;

    std::cout << "The binary representation is: ";
    printUnsignedIntInBinary(number);
    std::cout << std::endl;

    return 0;
}
