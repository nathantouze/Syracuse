#include "Syracuse.hpp"
#include <fstream>
#include <iostream>

bool Syracuse::loopProcess(StringNum startingNumber) {


    while (1) {
        if (Syracuse::process(startingNumber)) {
            break;
        }
        startingNumber.add(1);
        std::cout << startingNumber.toString() << std::endl;
    }
    return true;
}

bool Syracuse::process(StringNum number) {

    std::fstream file;

    file.open("./output/" + number.toString() + ".txt", std::ios::out);
    file << "Starting number: " << number.toString() << std::endl;
    while (1) {
        std::string tmp = number.toString();
        if (!number.isEven()) {
            number.multiply(3);
            number.add(1);
            file << tmp << ": odd -> " << number.toString() << std::endl;
        } else {
            number.divide(2);
            file << tmp << ": even -> " << number.toString() << std::endl;
        }
        if (number.toLong() == 4 || number.toLong() == 2 || number.toLong() == 1) {
            file << "syracuse conjecture failed." << std::endl;
            file.close();
            return false;
        }
    }
    return true;
}