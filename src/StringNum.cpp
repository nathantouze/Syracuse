#include "StringNum.hpp"
#include <sstream>
#include <algorithm> //std::reverse(v.begin(), v.end())
#include <iostream>

//bugué
void StringNum::add(const int &num) {
    int toAdd = 0;
    int tmp = 0;
    std::string newVal;

    for (int i = _numberStr.length() - 1; i >= 0; i--) {
        if ((std::size_t)i == _numberStr.length() - 1) {
            tmp = std::stoi(_numberStr.substr(i, 1)) + num;
            toAdd = (tmp - tmp % 10) / 10;
            std::cout << "first line: tmp = " << tmp << ", toAdd = " << toAdd << std::endl;
            newVal.append(std::to_string(tmp % 10));
            
        } else {
            if (toAdd == 0) {
                newVal.append(std::to_string(_numberStr.at(i)));
                std::cout << _numberStr.at(i) << std::endl;
            } else {
                tmp = std::stoi(_numberStr.substr(i, 1)) + toAdd;
                toAdd = (tmp - tmp % 10) / 10;
                if (i == 0) {
                    std::string last = std::to_string(tmp);
                    std::reverse(last.begin(), last.end());
                    newVal.append(last);
                } else {
                    newVal.append(std::to_string(tmp % 10));
                }
            }
        }
        //std::cout << newVal << std::endl;
    }
    std::cout << newVal << std::endl;
    std::reverse(newVal.begin(), newVal.end());
    assign(newVal);
}

void StringNum::multiply(const int &product) {
    int toAdd = 0;
    int tmp = 0;
    std::string newVal;

    for (int i = _numberStr.length() - 1; i >= 0; i--) {
        tmp = (std::stoi(_numberStr.substr(i, 1)) * product) + toAdd;
        toAdd = (tmp - tmp % 10) / 10;
        if (i == 0) {
            std::string last = std::to_string(tmp);
            std::reverse(last.begin(), last.end());
            newVal.append(last);
        } else {
            newVal.append(std::to_string(tmp % 10));
        }
    }
    std::reverse(newVal.begin(), newVal.end());
    assign(newVal);
}

void StringNum::assign(const unsigned long long int &number) {
    _numberLong = number;
    _numberStr = std::to_string(number);
    updateOutOfRange();
}

void StringNum::assign(const std::string &number) {
    _numberStr = number;
    std::istringstream in(number);
    in >> _numberLong;
    updateOutOfRange();
}

const unsigned long long int &StringNum::toLong() const {
    return _numberLong;
}

const std::string &StringNum::toString() const {
    return _numberStr;
}

bool StringNum::isEven() const {
    
    int last = std::stoi(_numberStr.substr(_numberStr.length() - 1));
    return last % 2;
}

void StringNum::updateOutOfRange() {
    if (toString() != std::to_string(_numberLong)) {
        _outOfRange = true;
    } else {
        _outOfRange = false;
    }
}

const bool &StringNum::isOutOfRange() const {
    return _outOfRange;
}

StringNum::StringNum(const unsigned long long int &number) : _numberLong(number)
{
    _numberStr = _numberLong;
    updateOutOfRange();
}

StringNum::StringNum(const std::string &number) : _numberStr(number)
{
    std::istringstream in(_numberStr);
    in >> _numberLong;
    updateOutOfRange();
}

StringNum::~StringNum()
{
}