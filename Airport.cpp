#include "Airport.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include "Airline.h"

using namespace std;
Airport::Airport(){
    id = "";
    city = "";
    date = "00/00/0000";
    country = "";
    totDailyIn = 0;
    totTransac = 0;
        /*vector<string>tripulacionP;
        tripulacionP.push_back("Eugenio");
        tripulacionP.push_back("Faus");
        tripulacionP.push_back("Humberto");
        Flight vuelo1 {"12/12/2012", "12:30", 1500, "JABC", "CUN", 10000, tripulacionP}
        */
        Airline volaris{"CDMX","Volaris", "VOI"};
        Airline Aeromexico{"CDMX","Aeromexico", "AMX"};
        Airline viva{"CDMX","Viva Aerobus", "VAB"};
        airlines.push_back(volaris);
        airlines.push_back(Aeromexico);
        airlines.push_back(viva);

}

Airport::Airport(string id_val, string city_val, string date_val, string country_val){
    id = id_val;
    city = city_val;
    date = date_val;
    country = country_val;
    totDailyIn = 0;
    totTransac = 0;

    Airline volaris{"CDMX","Volaris", "VOI"};
        Airline Aeromexico{"CDMX","Aeromexico", "AMX"};
        Airline viva{"CDMX","Viva Aerobus", "VAB"};


        airlines.push_back(volaris);
        airlines.push_back(Aeromexico);
        airlines.push_back(viva);
}
        

        

 

void Airport::agregarVuelo(){
    string vuelo;
    cout << "Nombre de Aerolinea" << endl;
    cin >> vuelo;
    for(int i = 0; i < airlines.size(); i++){
        if(airlines.at(i).getAirName() == vuelo){
            airlines.at(i).scheduleFlight();
        }
    }

}
string Airport::getId(){
    return id;
}
void Airport::setId(string id_val){
    id = id_val;

}

string Airport::getCity(){
    return city;
}
void Airport::setCity(string city_val){
    city = city_val;
}
string Airport::getDate(){
    return date;
}
void Airport::setDate(string date_val){
    city = date_val;
}
string Airport::getCountry(){
    return country;
}
void Airport::setCountry(string country_val){
    country = country_val;
}

void Airport::printAllFlights() {
    for (auto airline: airlines)
        airline.printFlights();
}

void Airport::printFlightSchedule(){
    for(auto airline: airlines)
        airline.printschedule();


}

void Airport::printAllFlights(string n){

    for (auto airline: airlines){
        if(airline.getAirName() == n)
        airline.printFlights();
    }


}

void Airport::buscaFlight(string f, string d){

    string fecha, destino;
    fecha = f;
    destino = d;
    for(auto airline : airlines){
       
        airline.printFlight(fecha, destino);
    }
    

}
void Airport::buscaReserFlight(string f, string d){

    string fecha, destino;
    fecha = f;
    destino = d;
    for(auto airline : airlines){
       
        airline.reserveSeat(fecha, destino);
    }
        

}

/*void Airport::startOperation(string d){
    date = d;

    cout << "Ingrese ID: " << endl;
    cin >> id;
    cout << "Ingrese Ciudad: " << endl;
    cin >> city;
    cout << "Ingrese Pais: " << endl;
    cin >> country;
}*/
/*void Airport::closeOperation(){
    double total{}, ingresos{};
    for(size_t i = 0; i < airlines.size(); i ++){
        ingresos += airlines.at(i).getIncome();
        vector<Flight> flights = flights.at(i).getVuelos();

        for(size_t j = 0; j < flights.size(); i++)
            if(flights.at(j).getDate() == date)
                totalVuelos ++;

         //Flight f = airlines.at(i).buscarVueloporfecha(date);

        }
        cout << "Total de vuelos al dia: " << TotalVuelos << endl;
        cout << "Total de ingresos al dia" << IngresosTotales << endl;
}
    vector<Flight>Airline::getFlights(){
    return flights;
}  
*/
void Airport::closeOperation() {
    for(int i = 0; i <= totTransac; i = i+1)
    cout << "En el vuelo número "<<i<< "los ingresos fueron:" << endl;
    cin >> money; 
    totDailyIn=totDailyIn + money;
    cout <<"El total de ingresos generados por todos los vuelos programados es de: "<<totDailyIn << endl;
    }