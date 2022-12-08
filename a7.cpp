#include <string>
#include <random>
#include <sstream>
#include <iostream>

std::string Key(const std::string& Name)
{
    std::string Serial = "1234567890123456789012";
    int S = 0;
    Serial[0] = '1' + std::rand() % 9; // Generate a random number from 1 to 9 and assign it to the first character of the serial key.
    
    // Generate the remaining 21 digits of the serial key.
    for (int i = 1; i < 22; ++i)
        Serial[i] = '0' + std::rand() % 10; // Generate a random number from 0 to 9 and assign it to the current character of the serial key.

    // Calculate the checksum.
    for (int i = 0; i < 22; ++i)
    {
        int n = (i + 1) + (Serial[i] - '0') + 4; // Calculate the value of the current digit, based on its position in the serial key and a constant value of 4.
        S += n * (Serial[i] - '0'); // Add the value of the current digit to the checksum.
    }
    S %= 1000; // Take the checksum modulo 1000 to get the final value.

    // Concatenate the serial key and the checksum and return the result.
    std::stringstream ss;
    ss << Serial << S;
    return ss.str();
}

int main()
{
    std::string name = "John Doe";
    std::string serial = Key(name);

    std::cout << "The serial key for " << name << " is " << serial << std::endl;

    return 0;
}