#include "Syracuse.hpp"
#include <fstream>
#include <iostream>
#include <chrono>

bool Syracuse::loopProcess(StringNum startingNumber) {


    while (1) {
        if (Syracuse::process(startingNumber)) {
            break;
        }
        startingNumber.add(1);
    }
    return true;
}

bool Syracuse::process(StringNum number) {

    std::fstream file;
    std::clock_t start = std::clock();
    std::clock_t end;

    if (_output == OUTPUT_FILE) {
        file.open("./output/" + number.toString() + ".txt", std::ios::out);
        file << "Starting number: " << number.toString() << std::endl;
    } else {
        std::cout << number.toString() << ": ";
    }
    while (1) {
        std::string tmp = number.toString();
        if (!number.isEven()) {
            number.multiply(3);
            number.add(1);
            if (_output == OUTPUT_FILE) {
                file << tmp << ": odd -> " << number.toString() << std::endl;
            }
        } else {
            number.divide(2);
            if (_output == OUTPUT_FILE) {
                file << tmp << ": even -> " << number.toString() << std::endl;
            }
        }
        if (number.toLong() == 4 || number.toLong() == 2 || number.toLong() == 1) {
            end = clock();
            if (_output == OUTPUT_FILE) {
                file << "syracuse conjecture failed. (time: " << ((float)end - start) / CLOCKS_PER_SEC << " s)" << std::endl;
                file.close();
            } else {
                std::cout << "failed. (time: " << ((float)end - start) / CLOCKS_PER_SEC << " s)" << std::endl;
            }
            return false;
        }
    }
    return true;
}

Syracuse::Syracuse(bool output) : _output(output) {}
Syracuse::~Syracuse() {}