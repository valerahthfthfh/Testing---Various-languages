#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

/*
* @brief Represents a simulation
*        of an airline management system,
*        which includes managing a fleet of aircraft,
*        scheduling flights, and simulating flights.
*
* @class contains the model of the aircraft,
*        maximum speed,
*        altitude, and fuel level.
*/
class Aircraft {
protected:
    string model;
    double maxSpeed;
    double currentAltitude;
    double fuelLevel;

public:
    Aircraft(string model, double maxSpeed) : model(model), maxSpeed(maxSpeed), currentAltitude(0), fuelLevel(100) {}

    /* @brief Function for aircraft takeoff
    * Sets currentAltitude and outputs along with model
    */
    void takeOff() {
        cout << model << " is taking off." << endl;
        currentAltitude = 1000;
    }
    /* @brief Function for aircraft landing
    * Sets currentAltitude and outputs along with model
    */
    void land() {
        cout << model << " is landing." << endl;
        currentAltitude = 0;
    }
    /* @brief Function to change altitude
    * @param newAltitude
    * Checks for non-negative altitude
    * and assigns the new altitude if successful
    */
    void changeAltitude(double newAltitude) {
        if (newAltitude >= 0) {
            cout << model << " changing altitude to " << newAltitude << " meters." << endl;
            currentAltitude = newAltitude; // update altitude
        }
    }
    /* @brief Function to refuel the aircraft
    * Sets fuelLevel to a specific value
    * Outputs model with description
    */
    void refuel() {
        cout << model << " is refueling." << endl;
        fuelLevel = 100;
    }
    // Method to get the aircraft model @return - model | relates to getModel() with its data types
    string getModel() { return model; }
    // Method to get the current altitude @return - currentAltitude | relates to getAltitude() with its data types
    double getAltitude() { return currentAltitude; }
    // Method to get the fuel level @return - fuelLevel | relates to getFuelLevel() with its data types
    double getFuelLevel() { return fuelLevel; }
};

class PassengerAircraft : public Aircraft {
private:
    int passengerCapacity;  // maximum passenger capacity
    int currentPassengers;  // current number of passengers

public:
    PassengerAircraft(string model, double maxSpeed, int capacity)
        : Aircraft(model, maxSpeed), passengerCapacity(capacity), currentPassengers(0) {}

    /* @brief Function to board passengers
    * @param count number of passengers to board
    * Checks if the specified number of passengers can be boarded
    */

    void boardPassengers(int count) {
        if (currentPassengers + count <= passengerCapacity) {
            currentPassengers += count; // increase passenger count
            cout << count << " passengers boarded " << model << "." << endl;
        }
        else {
            cout << "Not enough seats on " << model << "!" << endl;
        }
    }

    /* @brief Function to disembark passengers
    * Outputs message about disembarking all passengers
    */

    void disembarkPassengers() {
        cout << "All passengers disembarked from " << model << "." << endl;
        currentPassengers = 0;
    }

    // Method to get the current number of passengers @return - currentPassengers

    int getPassengerCount() { return currentPassengers; }
};

class CargoAircraft : public Aircraft {
private:
    double maxCargoWeight; // maximum cargo weight
    double currentCargoWeight; // current cargo weight

public:
    CargoAircraft(string model, double maxSpeed, double cargoCapacity)
        : Aircraft(model, maxSpeed), maxCargoWeight(cargoCapacity), currentCargoWeight(0) {}

    /* @brief Function to load cargo
    * @param weight weight of cargo to load
    * Checks if the specified weight can be loaded
    */

    void loadCargo(double weight) {
        if (currentCargoWeight + weight <= maxCargoWeight) {
            currentCargoWeight += weight;
            cout << weight << " tons loaded onto " << model << "." << endl;
        }
        else {
            cout << "Cargo exceeds capacity!" << endl;  // exceeds maximum weight
        }
    }

    /* @brief Function to unload cargo
    * Outputs message about unloading cargo
    */

    void unloadCargo() {
        cout << "Cargo unloaded from " << model << "." << endl;
        currentCargoWeight = 0;
    }

    // Method to get the current cargo weight @return - currentCargoWeight

    double getCargoWeight() { return currentCargoWeight; }
};

class Airline {
private:
    string name;   // airline name
    vector<Aircraft*> fleet;   // fleet of aircraft

public:
    Airline(string name) : name(name) {}

    /* @brief Function to add an aircraft to the fleet
    * @param aircraft pointer to aircraft to add
    */

    void addAircraft(Aircraft* aircraft) {
        fleet.push_back(aircraft);   // add aircraft to fleet
    }

    /* @brief Function to list the fleet
    * Outputs the list of aircraft in the airline
    */

    void listFleet() {
        cout << "Fleet of " << name << " airline:" << endl;
        for (auto& aircraft : fleet) {
            cout << aircraft->getModel() << endl;
        }
    }
};

class Flight {
private:
    string flightNumber;     // flight number
    Aircraft* aircraft;      // aircraft performing the flight
    string departure;        // departure location
    string destination;      // destination location
    string departureTime;    // departure time
    string arrivalTime;      // arrival time

public:
    Flight(string flightNumber, Aircraft* aircraft, string departure, string destination, string departureTime)
        : flightNumber(flightNumber), aircraft(aircraft), departure(departure), destination(destination), departureTime(departureTime) {}

    /* @brief Function to set arrival time
    * @param arrivalTime arrival time
    */

    void setArrivalTime(string arrivalTime) {
        this->arrivalTime = arrivalTime;
    }

    /* @brief Function to display flight details
   * Outputs information about the flight
   */

    void displayFlightDetails() {
        cout << "Flight " << flightNumber << " details:" << endl;
        cout << "Aircraft: " << aircraft->getModel() << endl;
        cout << "Departure: " << departure << " at " << departureTime << endl;
        cout << "Destination: " << destination << endl;
        if (!arrivalTime.empty()) {
            cout << "Arrival: " << arrivalTime << endl;
        }
    }
};

class Airport {
private:
    string name;             // airport name
    vector<Flight*> flights; // scheduled flights

public:
    Airport(string name) : name(name) {}

    /* @brief Function to schedule a flight
    * @param flight pointer to flight to schedule
    */

    void scheduleFlight(Flight* flight) {
        flights.push_back(flight);
    }

    /* @brief Function to list scheduled flights
    * Outputs the list of flights at the airport
    */

    void listScheduledFlights() {
        cout << "Scheduled flights at " << name << " airport:" << endl;
        for (auto& flight : flights) {
            flight->displayFlightDetails();
        }
    }
};

class FlightSimulator {
public:

    /* @brief Function to simulate a flight
    * @param aircraft reference to aircraft for simulation
    */

    static void simulateFlight(Aircraft& aircraft) {
        cout << "Simulating flight for " << aircraft.getModel() << "." << endl;
        aircraft.takeOff();
        aircraft.changeAltitude(10000);
        aircraft.land();
    }
};

int main() {
    Airline airline("SkyHigh Airlines");

    PassengerAircraft boeing737("Boeing 737", 850, 180);
    CargoAircraft antonov124("Antonov An-124", 865, 150);
    PassengerAircraft airbusA320("Airbus A320", 800, 160);

    airline.addAircraft(&boeing737);
    airline.addAircraft(&antonov124);
    airline.addAircraft(&airbusA320);

    airline.listFleet();

    Flight flight1("SH101", &boeing737, "New York", "Los Angeles", "10:00 AM");
    Flight flight2("SH102", &airbusA320, "Los Angeles", "Chicago", "2:00 PM");

    flight1.setArrivalTime("12:30 PM");
    flight2.setArrivalTime("4:30 PM");

    Airport airport("JFK International");
    airport.scheduleFlight(&flight1);
    airport.scheduleFlight(&flight2);

    airport.listScheduledFlights();

    boeing737.boardPassengers(100);
    antonov124.loadCargo(80);

    FlightSimulator::simulateFlight(boeing737);
    FlightSimulator::simulateFlight(antonov124);

    boeing737.disembarkPassengers();
    antonov124.unloadCargo();

    return 0;
}
