#include <iostream>
#include <random>
#include <istream>
#include <fstream>
#include <array>
#include <string>

int main(int argc, char** argv)
{
    std::ifstream ifs {"dataset"};
    std::ofstream ofs2 {"binary_dataset.txt"};
    char byte{};
    int byteNum = 1;
    while( ifs.get(byte))
    {
        std::string binaryString {"Byte at : " + std::to_string(byteNum) + " is: " + std::to_string(byte) + "\n"};
        std::cout << (int)byte << std::endl;
        byteNum++;
        ofs2 << binaryString;
    }

    return 0;
}