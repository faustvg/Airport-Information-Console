#ifndef _FLIGHT_H_
#define _FLIGHT_H_
#include <string>
#include <vector>
#include "Passenger.h"

class Flight {
    private:
        std::string date;
        std::string hour;
        double price;
        std::string airplaneModel;
        std::string fromTo;
        double distance;
        std::vector<std::string> crew;
        double fuel;
        std::vector<Passenger> passengers; //Considerar que tengo vuelos de 30 
//filas, 4 asientos por fila
        void calculateFuel();
        void initPassengers();
    public:
        Flight(
            std::string date_val = "01/01/9999", 
            std::string hour_val = "00:00",
            double price_val = 0.0,
            std::string model_val = "",
            std::string fromTo_val = "",
            double distance_val = 0.0,
            std::string crew_val = ""
        );
        std::string getDate();
        void setDate(std::string);

        std::string getHour();
        void setHour(std::string);

        double getPrice();
        void setPrice(double);

        std::string getAirplaneModel();
        void setAirplaneModel(std::string);

        std::string getFromTo();
        void setFromTo(std::string);

        double getDistance();
        void setDistance(double);

        std::string getCrew();
        void setCrew(std::string);

        double getFuel();
        void setFuel(double);
        
        void reservaAsiento();
        int getNumberPassengers();

        void muestraDatos();
        void muestraSchedule();
        void printFlightSchedule();
};
#endif