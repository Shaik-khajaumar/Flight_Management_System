#ifndef NODATAFOUND_H
#define NODATAFOUND_H

#include <cstring>

class NoDataFound
{
private:
    /* data */
    char *_msg;

public:
    NoDataFound() = delete;
    NoDataFound(const char * rhs){
        _msg = new char[strlen(rhs) + 1];
        strcpy(_msg, rhs);


    }
    NoDataFound(const NoDataFound &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    NoDataFound &operator=(const NoDataFound &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    NoDataFound(NoDataFound &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    NoDataFound &operator=(NoDataFound &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    ~NoDataFound()
    {
        delete[] _msg;
    }
    char * what() {
        return _msg;
    }
};

#endif // NODATAFOUND_H
