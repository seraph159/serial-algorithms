#include <random>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include "md5.h"

uint32_t HexToInt(const std::string& HexNum) {
  // Parse the hexadecimal number as an unsigned integer
  uint32_t result;
  std::stringstream ss;
  ss << std::hex << HexNum;
  ss >> result;
  return result;
}

uint32_t Asm1(uint32_t S) {
  uint32_t result;
  __asm {
    // The inline assembly is equivalent to the following C++ code:
    // uint32_t tmp = 38E38E39;
    // result = (S * tmp) >> 0x3;
    // tmp = (result >> 0x1F) + result;
    // result = tmp * tmp * 0x24;
    // S -= result;
    // result = static_cast<int32_t>(static_cast<int8_t>(S));
    MOV ECX, S
    MOV EAX, 0x38E38E39
    IMUL ECX
    SAR EDX, 0x3
    MOV EAX, EDX
    SHR EAX, 0x1F
    ADD EAX, EDX
    IMUL EAX, EAX, 0x24
    SUB ECX, EAX
    MOVSX EAX, cl
  }
  return result;
}

std::string GetSerial(const std::string& Name) {
  const std::string str = "2\"F¢Â¡NSÁÄ-oÔ–c;";
  const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  // Generate a random serial number with 5 random characters
  std::string serial = "ABCDEABCDEABCDEABCDE";
  std::mt19937 rng;
  std::uniform_int_distribution<> dist(0, chars.length() - 1);
  for (int i = 0; i < 5; i++) {
    serial[i] = chars[dist(rng)];
  }

  // Generate the next 10 characters of the serial number
  for (int i = 6; i <= 15; i++) {
    int S = 0;
    for (int j = i - 1; j >= i - 5; j--) {
      S += serial[j];
    }
    serial[i] = chars[Asm1(S) + 1];
  }

  // Generate the final 5 characters of the serial number using MD5
  std::string P = md5(str + serial.substr(0, 15));
  int j = 0;
  for (int i = 0; i < 5; i++) {
    uint32_t n = HexToInt(P.substr(j, 2)) + HexToInt(P.substr(j + 2, 2)) + HexToInt(P.substr(j + 4, 2));
serial[15 + i] = chars[Asm1(n) + 1];
j += 6;
}

// Return the serial number in the format "XXXXX-XXXXX-XXXXX-XXXXX"
return serial.substr(0, 5) + "-" + serial.substr(6, 5) + "-" +
serial.substr(11, 5) + "-" + serial.substr(16, 5);
}

int main() {
  std::string name;
  std::cout << "Enter your name: ";
  std::getline(std::cin, name);

  std::string serial = GetSerial(name);
  std::cout << "Your serial number is: " << serial << std::endl;
  return 0;
}