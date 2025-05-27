#include <iostream>
#include <random>
#include <istream>
#include <fstream>
#include <array>
#include <cmath>
#include <bitset>

int main(int argc, int** argv)
{
    std::random_device rd;
    const size_t size = 100000;

    std::mt19937 gen(rd());
    std::normal_distribution<> range(50, 100);

    
    std::string filename {"dataset.txt"};

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
        //ofs.write(parameter.c_str(), parameter.size());
        ofs << parameter << std::endl;
        sequence.at(i) = parameter;
    }
    std::cout << "List of integers using: " << sequence.size() * 4 << " bytes." << std::endl;

    std::ifstream ifs {filename};
    int n;
    ifs >> n;
    // std::cout << n << std::endl;

    int blocksize = 64;
    int bitsIndex = 4;
    int lastValue = 0;
    int highInt, lowInt;
    highInt |= 2 << 32 - bitsIndex;
    int bitsInt = highInt >> blocksize / 2 - bitsIndex;
    std::cout << "Bits per block: " << bitsInt << std::endl;
    std::cout << std::bitset<32>(bitsInt) << std::endl;
    for (int i{}; i < 1; i += 2)
    {
        int value = sequence.at(i);

        highInt = sequence.at(i);
        lowInt = sequence.at(i+1);

        switch (value)
        {
        case :
            /* code */
            break;
        
        default:
            break;
        }

    }

    return 0;
}