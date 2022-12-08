#include <string>
#include <random>
#include <sstream>
#include <iostream>

std::string GetSerial()
{
    std::string Serial, Str1, Str2, K = "0123456789ABCDEF";
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1, 16);

    // Generate a random 8-character string using the K string as a character set.
    for (int i = 0; i < 8; ++i)
        Str1[i] = K[uni(rng)];

    // Calculate the MD5 hash of the random string and convert it to a hexadecimal string.
    Str2 = CalculateMD5(Str1);

    // Concatenate the random string and the MD5 hash to form the serial key.
    for (int i = 0; i < 8; ++i)
    {
        Serial += Str1[i];
        Serial += Str2[33 - i];
    }

    // Format the serial key and return the result.
    return "ACM" + Serial.substr(0, 1) + "-" + Serial.substr(1, 5) + "-" + Serial.substr(6, 5) + "-" + Serial.substr(11, 5);
}



int main()
{
    std::string serial = GetSerial();
    std::cout << "The generated serial key is: " << serial << std::endl;

    return 0;
}