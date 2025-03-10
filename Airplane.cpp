#include "Airplane.h"
std::ostream &operator<<(std::ostream &os, const Airplane &rhs) {
    os << "_airplaneManufacturer: " << rhs._airplaneManufacturer
       << " _airplaneType: " <<static_cast<int>(rhs._airplaneType)
       << " _seatCount: " << rhs._seatCount;
    return os;
}
Airplane::Airplane(std::string manufacturer, AirPlaneType airplaneType, int seatCount)
    :_airplaneManufacturer(manufacturer), _airplaneType(airplaneType), _seatCount(seatCount)
{
}
