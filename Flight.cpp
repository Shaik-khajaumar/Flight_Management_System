#include "Flight.h"

Flight::Flight(std::string company, FlightOperationType type, AirplaneRef associatedPlane)
: _flightOperationCompany(company), _operationType(type), _associatedPlane(associatedPlane)
{
}
std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_flightOperationCompany: " << rhs._flightOperationCompany
       << " _operationType: " <<static_cast<int>(rhs._operationType)
       << " _associatedPlane: " << rhs._associatedPlane;
    return os;
}
