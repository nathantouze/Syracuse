#include "StringNum.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

void StringNum::divide(const int &divider) {

    std::string dividerStr = std::to_string(divider);
    std::string tmpNumberStr = _numberStr.substr(0, 1);
    std::string result;
    int tmpNumber;
    int rest = 0;
    int toSubtract = 0;
    int toSkip = 0;


    for (int i = 0; std::string::size_type(i) < _numberStr.length(); i += toSkip) {
        toSkip = 1;
        tmpNumberStr = rest == 0 ? _numberStr.substr(i, 1) : std::to_string(rest) + _numberStr.substr(i, 1);
        for (int k = 2, tmp = std::stoi(tmpNumberStr); tmp < divider && tmp != 0; k++, tmp = std::stoi(tmpNumberStr)) {
            tmpNumberStr = rest == 0 ? _numberStr.substr(i, k) : std::to_string(rest) + _numberStr.substr(i, k);
            toSkip += 1;
            if (std::string::size_type(i + k) > _numberStr.length()) {
                break;
            }
        }
        tmpNumber = std::stoi(tmpNumberStr);
        for (int k = 10; k >= 0; k--) {
            toSubtract = k * divider;
            if (toSubtract <= tmpNumber) {
                result.append(std::to_string(k));
                break;
            }
        }
        rest = tmpNumber - toSubtract;
    }
    if (rest > 0) {
        result = add(result, 1);
    }
    assign(result);
}

std::string StringNum::add(std::string str, int num) const {
    int toAdd = 0;
    int tmp = 0;
    std::string newVal;

    for (int i = str.length() - 1; i >= 0; i--) {
        if ((std::size_t)i == str.length() - 1) {
            tmp = std::stoi(str.substr(i, 1)) + num;
            toAdd = (tmp - tmp % 10) / 10;
            newVal.append(std::to_string(tmp % 10));
            
        } else {
            if (toAdd == 0) {
                newVal += str.at(i);
            } else {
                tmp = std::stoi(str.substr(i, 1)) + toAdd;
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
    }
    std::reverse(newVal.begin(), newVal.end());
    return newVal;
}


void StringNum::add(const int &num) {
    int toAdd = 0;
    int tmp = 0;
    std::string newVal;

    for (int i = _numberStr.length() - 1; i >= 0; i--) {
        if ((std::size_t)i == _numberStr.length() - 1) {
            tmp = std::stoi(_numberStr.substr(i, 1)) + num;
            toAdd = (tmp - tmp % 10) / 10;
            newVal.append(std::to_string(tmp % 10));
            
        } else {
            if (toAdd == 0) {
                newVal += _numberStr.at(i);
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
    }
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
    return last % 2 == 0;
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