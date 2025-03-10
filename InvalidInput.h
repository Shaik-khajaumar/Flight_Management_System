#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H



#include <cstring>

class InValidInput
{
private:
    /* data */
    char *_msg;

public:
    InValidInput() = delete;
    InValidInput(const char * rhs){
        _msg = new char[strlen(rhs) + 1];
        strcpy(_msg, rhs);


    }
    InValidInput(const InValidInput &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    InValidInput &operator=(const InValidInput &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    InValidInput(InValidInput &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    InValidInput &operator=(InValidInput &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    ~InValidInput()
    {
        delete[] _msg;
    }
    char * what() {
        return _msg;
    }
};
#endif // INVALIDINPUT_H
