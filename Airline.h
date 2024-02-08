#ifndef _AIRLINE_H_
#define _AIRLINE_H_
#include <string>
#include <list>
#include "Flight.h"
#include <vector>

class Airline {
    private:
        std::string boardingCity;
        std::string name;
        std::string  shortName;
        double incomes;
        std::vector<Flight> flights;
        void initFlights();

    public:
        Airline();
        Airline(std::string boardingCity_val = "", std::string name_val = "", std::string shortName_val = "");
        void updateAirline();    
        void scheduleFlight();
        void currentIncome();

        void printFlights();
        void printSchedules();
        
        void setBoardingCity(std::string);
        std::string getBoardingCity();
        void setShortName(std::string);
        std::string getShortName();
        void setIncomes(double);
        double getIncome();

        std::string getAirName();
        

        void closeOperation();
        void printschedule();
        void muestraAirline();
        void printFlight(std::string, std::string);
        void reserveSeat(std::string, std::string);
        
};
    


#endif