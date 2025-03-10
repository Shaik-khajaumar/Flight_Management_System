#include"Functionalities.h"
#include<iostream>

//lambda function returns void and takes flight data and airplane data by reference as parameter
std::function<void(AirplaneContainer&, FlightContainer&)> createObjects =
    [](AirplaneContainer& airplaneData, FlightContainer& flightData) -> void {

    airplaneData.emplace_back(Airplane("BOIENG", AirPlaneType::CRUISELINER, 200));
    airplaneData.emplace_back(Airplane("VISTARA", AirPlaneType::NEO, 50));
    airplaneData.emplace_back(Airplane("JETAIR", AirPlaneType::JUMBO, 70));

    flightData.emplace_back(
        std::make_shared<Flight>(
        Flight("VIJAY", FlightOperationType::INTERNATIONAL, std::ref(airplaneData[0])))
        );
    flightData.emplace_back(
        std::make_shared<Flight>(
        Flight("VARMA", FlightOperationType::DOMESTIC, std::ref(airplaneData[1])))
        );
    flightData.emplace_back(
        std::make_shared<Flight>(
        Flight("KUMAR", FlightOperationType::INTERNATIONAL, std::ref(airplaneData[0])))
        );
};

//lambda that returns AirplaneContainer and takes FlightContainer and FlightOperationType
std::function<AirplaneContainer(FlightContainer&, FlightOperationType)> FindInstanceOfAirplane = {
    [](FlightContainer& flightData, FlightOperationType flightOperationType) -> AirplaneContainer {

        //case 1 no data found
        if(flightData.empty()){
            throw NoDataFound("No flight Data is present!!");
        }

        //search and find data
        AirplaneContainer result;
        for(auto& flight : flightData){
            if(flight.get()->operationType() == flightOperationType){
                result.emplace_back(flight.get()->associatedPlane());
            }
        }

        //if no instance is present
        if(result.empty()){
            throw NoInstanceFound("No instances of airplane is found");
        }
        return result;
    }
};

//lambda function returns airplanetype and takes flightContainer data by referece
std::function<AirPlaneType(FlightContainer&)> FindAirplaneTypeOfLowestSeatCount = {
    [](FlightContainer& flightData) -> AirPlaneType {

         //case 1 no data found
        if(flightData.empty()){
            throw NoDataFound("No flight Data is present!!");
        }

        //search and find data
        int lowSeatCount{INT_MAX};
        AirPlaneType result;
        for(auto& flight : flightData){
            if(flight.get()->associatedPlane().get().seatCount() < lowSeatCount){
                lowSeatCount = flight.get()->associatedPlane().get().seatCount();
                result = flight.get()->associatedPlane().get().airplaneType();
            }
        }

        return result;
    }
};

//lambda function returns int and takes airplane container data by reference
std::function<AirplaneContainer(AirplaneContainer& , int)> FindInstanceOfAirplaneBySeatCount = []
    (AirplaneContainer& airplaneData, int count) -> AirplaneContainer {

          //case 1 no data found
        if(airplaneData.empty()){
            throw NoDataFound("No flight Data is present!!");
        }


        if(count <= 0){
            throw InValidInput("N value is not correct");
        }

        //search and find data
        AirplaneContainer result;
        for(auto& plane : airplaneData){
            if(plane.seatCount() > count){
                result.emplace_back(plane);
            }
        }

        //if no instance is found
        if(result.size() == 0){
            throw NoInstanceFound("No instance found for airplane data");
        }
        return result;

};

std::function<int(FlightContainer&)> CountOfAllSeats = 
    [](FlightContainer& flightData) -> int {
          //case 1 no data found
        if(flightData.empty()){
            throw NoDataFound("No flight Data is present!!");
        }

        //else return all the seats in the flight data
        int seatCount{0};
        for(auto& flight : flightData){
            seatCount += flight.get()->associatedPlane().get().seatCount();
        }
        return seatCount;

    };