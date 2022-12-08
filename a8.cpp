#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

std::string GetSerial(const std::string& Name)
{
    if (Name.empty())
        return "";

    std::string Serial;
    std::string P = Name + "Fk2yB$P30jH";
    std::string P1 = P.substr(0, P.size() / 2);
    std::string P2 = P.substr(P1.size());
    std::string P3 = P2 + P1;
    std::string P4 = P3.substr(5);
    P4 = P4 + P4 + P4 + P4 + P4;
    std::string P5 = P3.substr(0, 10);
    int S = 256;
    for (int i = 0; i < 10; ++i)
    {
        S += static_cast<unsigned char>(P5[i]);
        S %= 0xFF;
        int m = S ^ static_cast<unsigned char>(P4[i]);
        S = m;
        std::stringstream ss;
        ss << std::hex << m;
        Serial += ss.str();
    }
    std::transform(Serial.begin(), Serial.end(), Serial.begin(), ::toupper); // Convert all characters in the serial key to uppercase.
    Serial = "100" + Serial.substr(0, 2) + "-" + Serial.substr(2, 5) + "-" + Serial.substr(7, 5); // Format the serial key.
    return Serial;
}

int main()
{
    std::string name = "John Doe";
    std::string serial = GetSerial(name);

    std::cout << "The serial key for " << name << " is " << serial << std::endl;

    return 0;
}