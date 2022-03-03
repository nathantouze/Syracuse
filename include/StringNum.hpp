/*
** EPITECH PROJECT, 2022
** Syracuse
** File description:
** StringNum
*/

#ifndef STRINGNUM_HPP_
#define STRINGNUM_HPP_

#include <string>

class StringNum {
    public:
        StringNum(const std::string &number);
        StringNum(const unsigned long long int &number);
        ~StringNum();
        bool isEven() const;
        const std::string &toString() const;
        const unsigned long long int &toLong() const;
        void assign(const unsigned long long int &number);
        void assign(const std::string &number);
        void multiply(const int &product);
        void add(const int &num);
        std::string add(std::string str, int num) const;
        void divide(const int &divider);
        const bool &isOutOfRange() const;
    protected:
    private:
        void updateOutOfRange();
        std::string _numberStr;
        unsigned long long int _numberLong;
        bool _outOfRange;
};

#endif /* !STRINGNUM_HPP_ */
