#include"Functionalities.h"
#include<iostream>
int main(){

    AirplaneContainer airplaneData;
    FlightContainer flightData;

    //creating objects
    createObjects(airplaneData, flightData);

    //finding instances of airplane
    try{
        AirplaneContainer instance = FindInstanceOfAirplane(flightData, FlightOperationType::DOMESTIC);
        std::cout << "\nAirplane instances of Type DOMESTIC are :"  << std::endl;
        for(auto &airplane : instance){
            std::cout << airplane << std::endl;
        }
    }
    catch(NoDataFound& err){
        std::cout << err.what() << std::endl;
    }
    catch(NoInstanceFound& err){
        std::cout << err.what() << std::endl;
    }

    //finding airplanetype of lowest seat count
    try{
        AirPlaneType type = FindAirplaneTypeOfLowestSeatCount(flightData);
        std::cout << "\nAirplane type of lowest seats : " <<static_cast<int>(type) << std::endl;
    }
    catch(NoDataFound& err){
        std::cout << err.what() << std::endl;
    }
    
    //function to find intances of airplane above tthreshold seat count
    try{
        AirplaneContainer instances = FindInstanceOfAirplaneBySeatCount(airplaneData, 100);
        std::cout << "\nAirplane instances of seats greater than 100 are :"  << std::endl;
        for(auto &airplane : instances){
            std::cout << airplane << std::endl;
        }

    }
    catch(NoDataFound& err){
        std::cout << err.what() << std::endl;
    }
    catch(NoInstanceFound& err){
        std::cout << err.what() << std::endl;
    }
    catch(InValidInput& err){
        std::cout << err.what() << std::endl;
    }


    //function to return all seats count in datacontainer
    try{
        int seatCount = CountOfAllSeats(flightData);
        std::cout << "\nCount of all the seats : " << seatCount << std::endl;
    }
    catch(NoDataFound& err){
        std::cout << err.what() << std::endl;
    }
    
}