# Flight_Management_System
A Flight Management system made using object oriented programming and many Modern C++ features.

The purpose of this project is to utilize my knowledge in oops and Modern c++ features like Lambda functions, reference wrapper, shared pointers, enum classes and exception handling to build a Flight management system.

Structure of the project: 
The class for Flights is the Flight.h class. This class has information about the flight (Name and type of the flight) and it has a reference to the Airplane instance that is associated whith the flight.
The class for Airplanes is the Airplane.h class. This class has properties like the Manmufacturer of the Airplane, Type of Airplane and number of seats in the Airplane.
There are enum classes like AirPlaneType.h whose instance is used in Airplane class and FlightOperationType.h whose instance is used in Flight class.
There are exception handling classes like NoDataFound.h and NoInstanceFound.h to handle exceptions.

This project can be used as a management system for Flights by adding required functionalities. 
Some functionalities which I have addded are: 
-> CreateObjects(): lambda function that creates the instances of Flight and stores their reference (shared pointers) in a container(vector). 
-> FindInstanceOfAirplane(): lambda function that returns a vector of shared_pointer of Airplane objects that match the FlightOperationType given by the user in the FlightContainer(vector of shared_pointer of Flight objects). 
-> FindAirplaneTypeOfLowestSeatCount(): lambda function that returns the airplanetype(enum class) instance that has the lowest seat count in the flightContainer(vector of shared_pointer of Flight objects).
-> FindInstanceOfAirplaneBySeatCount(): lambda function that returns a vector of shared_pointer of Airplane objects whose seat_count match the input given by the user.
-> CountOfAllSeats(): returns the total number of seats in all the Flights.

For all the functionalities I have used Lambdas and implemented exception handling also. To ensure proper and safe memory management I have used shared pointers.
