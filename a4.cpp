#include <iostream>
#include <random>
#include <string>

const int x[] = {0x0c, 0x12, 0x18, 0x04};

void key(int hwnd)
{
    std::string k = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    std::string serial = "ABCD-EFGH-IJKL-OPMN-XYZW";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25);

    serial[0] = k[dis(gen)];
    serial[5] = k[dis(gen)];
    serial[10] = k[dis(gen)];
    serial[15] = k[dis(gen)];

    int s = x[0] + (int)serial[0] + (int)serial[5] + (int)serial[10] + (int)serial[15] - 0x104;
    int n = s % 0x1a;
    serial[20] = (char)(n + 0x41);

    serial[1] = k[dis(gen)];
    serial[6] = k[dis(gen)];
    serial[11] = k[dis(gen)];
    serial[16] = k[dis(gen)];

    s = x[1] + (int)serial[1] + (int)serial[6] + (int)serial[11] + (int)serial[16] - 0x104;
    n = s % 0x1a;
    serial[21] = (char)(n + 0x41);

    serial[2] = k[dis(gen)];
    serial[7] = k[dis(gen)];
    serial[12] = k[dis(gen)];
    serial[17] = k[dis(gen)];

    s = x[2] + (int)serial[2] + (int)serial[7] + (int)serial[12] + (int)serial[17] - 0x104;
    n = s % 0x1a;
    serial[22] = (char)(n + 0x41);

    serial[3] = k[dis(gen)];
    serial[8] = k[dis(gen)];
    serial[13] = k[dis(gen)];
    serial[18] = k[dis(gen)];

    s = x[3] + (int)serial[3] + (int)serial[8] + (int)serial[13] + (int)serial[18] - 0x104;
    n = s % 0x1a;
    serial[23] = (char)(n + 0x41);

    // SetDlgItemText(hwnd, 6, pchar(serial));
    std::cout << serial << std::endl;
}

int main()
{
    key(0);
    return 0;
}