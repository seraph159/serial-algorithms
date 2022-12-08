#include <iostream>
#include <random>
#include <string>

std::string Key(const std::string& MessageIn)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    std::string Serial = "12345678901234567";
    std::string A = "0123456789";

    do
    {
        for (int i = 0; i < 20; ++i)
        {
            Serial[i] = A[dis(gen)];
        }

        Serial[0] = '2';
        Serial[2] = '8';
        Serial[3] = '3';
        Serial[4] = '3';
        Serial[7] = '6';
        Serial[8] = '8';
        Serial[10] = '1';

        int S = 0;
        for (int i = 0; i < 17; ++i)
        {
            int n = 0;
            switch (Serial[i])
            {
                case '0': n = 1; break;
                case '1': n = 27874; break;
                case '2': n = 47853; break;
                case '3': n = 100; break;
                case '4': n = 69887; break;
                case '5': n = 6798; break;
                case '6': n = 7099; break;
                case '7': n = 23432; break;
                case '8': n = 50; break;
                case '9': n = 499; break;
            }

            S += n;
        }

        int K = S % 999;
        return Serial + std::to_string(K);
    } while (result.size() != 20);
}

int main()
{
    // Test the Key function with a sample message
    std::string message = "Sample message";
    std::cout << "Key for message: " << message << " is " << Key(message) << std::endl;

    return 0;
}