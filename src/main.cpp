#include "StringNum.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "No argument: please insert a starting number." << std::endl;
        return 1;
    }
    StringNum number = StringNum(std::string(av[1]));

    std::cout << number.toString() << " + 6 = ";
    number.add(6);
    std::cout << number.toString() << std::endl;

    // std::fstream file;
    // file.open("output.txt", std::ios::out);
    

    // file << "Starting number: " << number.toString() << std::endl;
    // while (1) {
    //     unsigned long long int tmp = number.toLong();
    //     if (!number.isEven()) {
    //         number.assign(number.toLong() * 3 + 1);
    //         file << tmp << ": odd -> " << number.toString() << std::endl;
    //     } else {
    //         number.assign(number.toLong() / 2);
    //         file << tmp << ": even -> " << number.toString() << std::endl;
    //     }
    //     if (number.toLong() == 4) {
    //         file << "num = 4, syracuse conjecture failed." << std::endl;
    //         std::cout << "syracuse failed." << std::endl;
    //         break;
    //     }
    // }
    // file.close();
    return 0;
}