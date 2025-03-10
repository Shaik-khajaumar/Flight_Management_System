#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<limits.h>
#include"Flight.h"
#include"NoDataFound.h"
#include"InvalidInput.h"
#include"NoInstanceFound.h"

using FlightPointer = std::shared_ptr<Flight>;
using FlightContainer = std::vector<FlightPointer>;

using AirplaneContainer = std::vector<Airplane>;

extern std::function<void(AirplaneContainer&, FlightContainer&)> createObjects;

extern std::function<AirplaneContainer(FlightContainer&, FlightOperationType)> FindInstanceOfAirplane;

extern std::function<AirPlaneType(FlightContainer&)> FindAirplaneTypeOfLowestSeatCount;

extern std::function<AirplaneContainer(AirplaneContainer& , int)> FindInstanceOfAirplaneBySeatCount;

extern std::function<int(FlightContainer&)> CountOfAllSeats;
#endif // FUNCTIONALITIES_H
