#include <iostream>
#include <string>

std::string Key(const std::string& Name)
{
    std::string Serial, K = "012345789ABCDEFABCDEF01234987634";
    int s = 0, n1, n2;

    for (int i = 0; i < Name.size(); ++i)
    {
        if (Name[i] == '@')
        {
            ++s;
        }
    }

    if (s > 0)
    {
        for (int i = 0; i < Name.size(); ++i)
        {
            n1 = Name[i] / 8;
            Serial += K[n1 + 1];

            n2 = (Name[i] & 7) * 4 + (n1 % 3);
            Serial += K[n2 + 1];
        }

        return Serial;
    }
    else
    {
        return "Please Type a Valid E-mail !";
    }
}

int main()
{
    std::string email = "example@domain.com";
    std::string serial = Key(email);
    std::cout << "Serial: " << serial << std::endl;

    return 0;
}