#include <iostream>
#include <random>
#include <istream>
#include <fstream>
#include <array>
#include <cmath>
#include <bitset>

int main(int argc, char** argv)
{
    std::random_device rd;
    const size_t size = 100;

    std::mt19937 gen(rd());
    std::normal_distribution<> range(50, 100);

    
    std::string filename {"dataset"};

    std::ofstream ofs {filename};
    std::array<int, size> sequence{};

    for (int i{}; i < size; i++)
    {
        int parameter{};
        parameter = range(gen);
        if (parameter < 0)
        {
            parameter *= -1;
        }
        ofs.write(reinterpret_cast<const char*>(&parameter), sizeof(parameter));
        //ofs << parameter << std::endl;
        sequence.at(i) = parameter;
    }
    std::cout << "List of integers using: " << sequence.size() * 4 << " bytes." << std::endl;

    std::ifstream ifs {filename};
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
    // int n;
    // ifs >> n;
    // // std::cout << n << std::endl;

    // int blocksize = 64;
    // int bitsIndex = 4;
    // int lastValue = 0;
    // int highInt, lowInt;
    // highInt |= 2 << 32 - bitsIndex;
    // uint64_t bitsInt = highInt & (15 << 32 - bitsIndex);
    // bitsInt = bitsInt >> 32 - bitsIndex;
    // std::cout << "Bits per block: " << bitsInt << std::endl;
    // std::cout << std::bitset<32>(highInt) << std::endl;
    // for (int i{}; i < 1; i += 2)
    // {
    //     int value = sequence.at(i);

    //     highInt = sequence.at(i);
    //     lowInt = sequence.at(i+1);

    // }

    return 0;
}