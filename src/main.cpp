#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av) {

    if (ac < 2) {
        std::cerr << "No argument: please insert a starting number." << std::endl;
        return 1;
    }
    std::string arg = std::string(av[1]);
    std::istringstream is(arg);
    unsigned long long num;

    is >> num;

    std::fstream file;
    file.open("output.txt", std::ios::out);
    

    file << "Starting number: " << num << std::endl;
    while (1) {
        unsigned long long tmp = num;
        if (num % 2 == 1) {
            num = num * 3 + 1;
            file << tmp << ": odd -> " << num << std::endl;
        } else {
            num /= 2;
            file << tmp << ": even -> " << num << std::endl;
        }
        if (num == 4) {
            file << "num = 4, syracuse conjecture failed." << std::endl;
            std::cout << "syracuse failed." << std::endl;
            break;
        }
    }
    file.close();
    return 0;
}