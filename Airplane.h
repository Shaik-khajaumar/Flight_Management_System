#ifndef AIRPLANE_H
#define AIRPLANE_H

#include<string>
#include <ostream>
#include"AirplaneType.h"
class Airplane
{
private:
    const std::string _airplaneManufacturer;
    const AirPlaneType _airplaneType;
    int _seatCount;
public:

    //special member functions
    Airplane() = delete;
    Airplane(const Airplane&) = default;
    Airplane& operator=(const Airplane&) = delete;
    Airplane(Airplane&&) = default;
    Airplane& operator=(Airplane&&) = delete;
    ~Airplane() = default;

    //paramter constructor
    Airplane(std::string manufacturer, AirPlaneType airplaneType, int seatCount);

    //getters and setters
    std::string airplaneManufacturer() const { return _airplaneManufacturer; }
    AirPlaneType airplaneType() const { return _airplaneType; }
    int seatCount() const { return _seatCount; }
    void setSeatCount(int seatCount) { _seatCount = seatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Airplane &rhs);

    
};

#endif // AIRPLANE_H
