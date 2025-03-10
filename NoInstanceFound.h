#ifndef NOINSTANCEFOUND_H
#define NOINSTANCEFOUND_H

#include <cstring>

class NoInstanceFound
{
private:
    /* data */
    char *_msg;

public:
    NoInstanceFound() = delete;
    NoInstanceFound(const char * rhs){
        _msg = new char[strlen(rhs) + 1];
        strcpy(_msg, rhs);


    }
    NoInstanceFound(const NoInstanceFound &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    NoInstanceFound &operator=(const NoInstanceFound &rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    NoInstanceFound(NoInstanceFound &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
    }
    NoInstanceFound &operator=(NoInstanceFound &&rhs)
    {
        _msg = new char[strlen(rhs._msg) + 1];
        strcpy(_msg, rhs._msg);
        return *this;
    }
    ~NoInstanceFound()
    {
        delete[] _msg;
    }
    char * what() {
        return _msg;
    }
};

#endif // NOINSTANCEFOUND_H
