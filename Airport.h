#ifndef _AIRPORT_H_
#define _AIRPORT_H_
#include <list>
#include "Airline.h"
#include <vector>

#include <string>

class Airport {
    private:
        std::string id;
        std::string city;
        std::string date;
        std::string country;
        double totTransac;
        double totDailyIn;
        std::vector<Airline> airlines;
        double money;
       //possible vector
        

    public:
        Airport();
        Airport(std::string, std::string, std::string, std::string);
        
        void agregarVuelo();
        std::string getId();
        void setId(std::string);
        std::string getCity();
        void setCity(std::string);
        std::string getDate();
        void setDate(std::string);
        std::string getCountry();
        void setCountry(std::string);
        double getTotalT();
        void setTotalT(double);
        double getTotalD();
        double setTotalD(double);
        void printAllFlights();
        void printFlightSchedule();
        void printAllFlights(std::string);

        void startOperation(std::string);
        void closeOperation();

        void buscaFlight(std::string, std::string);
        void buscaReserFlight(std::string, std::string);
};
 
        





        

#endif
