#include <string>
#include <sstream>
#include <array>
#include <cmath>
#include <iostream>

double key(const std::string& Name)
{
    std::array<std::uint8_t, 50> K1{}, K2{}, K3{}, K4{}, K5{}, T{};
    std::string Serial;

    // Initialize the T array with constant values.
    T[0] = 0xAA;
    T[1] = 0x89;
    T[2] = 0xC4;
    T[3] = 0xFE;
    T[4] = 0x46;

    // Fill the T array with the ASCII values of the characters in the name.
    for (std::size_t i = 0; i < Name.size(); ++i)
        T[5 + i] = static_cast<std::uint8_t>(Name[i]);

    // Calculate the K1 array using the T array.
    for (std::size_t i = 0; i < Name.size(); ++i)
        K1[i] = static_cast<std::uint8_t>(Name[i]) ^ T[i];

    // Re-initialize the T array with new constant values.
    T[0] = 0x78;
    T[1] = 0xF0;
    T[2] = 0xD0;
    T[3] = 0x03;
    T[4] = 0xE7;

    // Fill the T array with the values from the K1 array, in reverse order.
    for (std::size_t i = 0; i < Name.size(); ++i)
        T[5 + i] = K1[Name.size() - i - 1];

    // Calculate the K2 array using the T array.
    for (std::size_t i = 0; i < Name.size(); ++i)
        K2[i] = K1[Name.size() - i - 1] ^ T[i];

    // Re-initialize the T array with new constant values.
    T[0] = 0xF7;
    T[1] = 0xFD;
    T[2] = 0xF4;
    T[3] = 0xE7;
    T[4] = 0xB9;

    // Fill the T array with the values from the K2 array, in reverse order.
    for (std::size_t i = 0; i < Name.size(); ++i)
        T[5 + i] = K2[Name.size() - i - 1];

    // Calculate the K3 array using the T array.
    for (std::size_t i = 0; i < Name.size(); ++i)
        K3[i] = K2[Name.size() - i - 1] ^ T[i];

    // Re-initialize the T array with new constant values.
    T[0] = 0xB5;
    T[1] = 0x1B;
    T[2] = 0xC9;
    T[3] = 0x50;
    T[4] = 0x73;


    // Fill the T array with the values from the K3 array, in reverse order.
    for (std::size_t i = 0; i < Name.size(); ++i)
        T[5 + i] = K3[Name.size() - i - 1];

    // Calculate the K4 array using the T array.
    for (std::size_t i = 0; i < Name.size(); ++i)
        K4[i] = K3[Name.size() - i - 1] ^ T[i];

    // Re-initialize the T array with zeros.
    T.fill(0);

    // Calculate the K5 array using the K4 array.
    for (std::size_t i = 0; i < Name.size(); ++i)
    {
        std::size_t j = i & 3;
        std::uint8_t n = T[j];
        std::uint8_t m = K4[Name.size() - i - 1];
        K5[j] = n + m;
        T[j] = m + n;
    }

    // Concatenate the values from the K5 array and convert them to a hexadecimal string.
    for (std::size_t i = 0; i < 4; ++i)
    {
        std::stringstream ss;
        ss << std::hex << static_cast<int>(K5[4 - i]);
        Serial += ss.str();
    }

    // Convert the hexadecimal string to an integer and return the result.
    return std::stoul(Serial, nullptr, 16);
}

int main()
{
    std::string name = "John Doe";
    double serial = key(name);

    std::cout << "The serial key for " << name << " is " << serial << std::endl;

    return 0;
}