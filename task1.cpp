#include <iostream>
#include <string>

unsigned int convertStringToUnsignedInt(const std::string& str) {
    unsigned int result = 0;
    for (char digit : str) {
        
        result = result * 10 + (digit - '0');
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string of numbers ending with a space: ";

   
    std::getline(std::cin, input, ' ');

   
    unsigned int number = convertStringToUnsignedInt(input);

    std::cout << "The corresponding unsigned integer is: " << number << std::endl;

    return 0;
}
