#ifndef SYRACUSE_HPP_
#define SYRACUSE_HPP_

#define OUTPUT_TERM true
#define OUTPUT_FILE false

#include "StringNum.hpp"

class Syracuse {
    public:
        Syracuse(bool output);
        ~Syracuse();
        bool process(StringNum number);
        bool loopProcess(StringNum startingNumber);
    protected:
    private:
        bool _output;
};

#endif /* !SYRACUSE_HPP_ */
