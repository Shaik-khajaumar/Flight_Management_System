#ifndef FLIGHT_H
#define FLIGHT_H

#include<memory>
#include<functional>
#include <ostream>
#include"Airplane.h"
#include"FlightOperationType.h"

using AirplaneRef = std::reference_wrapper<Airplane>;
class Flight
{
private:
    std::string _flightOperationCompany;
    FlightOperationType _operationType;
    AirplaneRef _associatedPlane;
public:
    //getters and setters
   Flight() = delete;
   Flight(const Flight&) = delete;
   Flight& operator=(const Flight&) = delete;
   Flight(Flight&&) = default;
   Flight& operator=(Flight&&) = delete;
   ~Flight() = default;

   //parameter constructor
   Flight(std::string company, FlightOperationType type, AirplaneRef associatedPlane);

    //getters and setters
   std::string flightOperationCompany() const { return _flightOperationCompany; }
   void setFlightOperationCompany(const std::string &flightOperationCompany) { _flightOperationCompany = flightOperationCompany; }
   FlightOperationType operationType() const { return _operationType; }
   void setOperationType(const FlightOperationType &operationType) { _operationType = operationType; }
   AirplaneRef associatedPlane() const { return _associatedPlane; }
   void setAssociatedPlane(const AirplaneRef &associatedPlane) { _associatedPlane = associatedPlane; }

   //output stream overloading
   friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);

};

#endif // FLIGHT_H
