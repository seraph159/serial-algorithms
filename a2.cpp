#include <iostream>
#include <random>
#include <string>

int Rand() {
    // Use the C++11 random number generation facilities to generate a random
    // number in the range [1000, 9999].
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);
    return dis(gen);
}

std::string Key(const std::string& StringIn) {
    // Generate the random numbers.
    int a = Rand();
    int b = Rand();
    int c = Rand();

    // Compute the key parts.
    int d = (a * b - 3751) % 10000;
    int e = ((c + 117) * b - 501) % 10000;

    // Concatenate the key parts into a string with dashes as separators.
    return std::to_string(a) + "-" + std::to_string(b) + "-" + std::to_string(c) + "-" + std::to_string(d) + "-" + std::to_string(e);
}

int main() {
    // Get a string from the user.
    std::string StringIn;
    std::cout << "Enter a string: ";
    std::cin >> StringIn;

    // Generate and print the key for the string.
    std::string key = Key(StringIn);
    std::cout << "Key: " << key << std::endl;

    return 0;
}