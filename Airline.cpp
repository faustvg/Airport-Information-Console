#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

const int NUMF = 5;


Airline::Airline(){

}
Airline::Airline(string boardingCity_val, string name_val, string shortName_val) 
    : boardingCity{boardingCity_val}, name{name_val}, shortName{shortName_val} {
    initFlights();

}

//Funcion para actualizar la aerolinea, donde pregunta el codigo de la aerlinea y el nombre
void Airline::updateAirline() {
    cout << "Cual es el codigo de la aerolinea: " << endl;
    cin >> shortName;
    cout << "Cual es el nombre de la aerolinea: " << endl;
    cin >> name;
}

//Esta funcion muestra el codigo de la aerolinea
void Airline::muestraAirline(){
    cout << "CODIGO: " << shortName << endl;

}

//La siguiente funcion  a partir de un ciclo for, registra los nuevos vuelos dentro del vector de vuelos
void Airline::initFlights(){
    for (size_t i = 0; i < NUMF; i++){
    Flight nuevo;
    flights.push_back(nuevo);
    }
}

//Esta funcion reservara un nuevo vuelo, a partir de un ciclo for del vector de vuelos, si el string esta vacio cerrara el ciclo, y sumara al c++, despues se define una condicional
// que si el indice es -1 mostrara que no hay naves disponibles, despues pedira fecha, hora, modelo,etc, y esto los ira almacenando al vector de flights
void Airline::scheduleFlight(){
    int index{-1};
    int counter{};
    for (auto vuelo: flights){
        if(vuelo.getAirplaneModel() ==  ""){
            index = counter;
            break;
        }
        counter++;
    }

    if (index == -1){
        cout << "No naves disponibles" << endl;
        return;

    }

    string fecha{}, hour{}, model{}, destino{}, crew{};
    double price{}, distance{};
    cout << "Cual es la fecha del vuelo (dd/mm/yyyy): " << endl;
    cin >> fecha;
    cout << "Cual es la hora del vuelo (hh:mm): " << endl;
    cin >> hour;
    cout << "Cual es el modelo de la aeronave: " << endl;
    cin >> model;
    cout << "Cual es el destino del vuelo: " << endl;
    cin >> destino;
    cout << "Cual es el precio del vuelo: " << endl;
    cin >> price;
    cout << "Cual es la distancia de vuelo:  " << endl;
    cin >> distance;
    cout << "Cuales son los nombres de la tripulacion (separados por comas): " << endl;
    cin >> crew;

    Flight nuevoVuelo{fecha, hour, price, model, destino, distance, crew};
    flights.insert(next(flights.begin(), index), nuevoVuelo);
    flights.erase(next(flights.begin(), index + 1));

}

//Getters y settters aqui empezamos definiendo todas las funciones de getters y setters, pidiendo los valores de los metodos, donde nos regresara el valor dependiendo de que se pida, ejemplo getIncome, regresa income
string Airline::getBoardingCity(){
    return boardingCity;
}

string Airline::getAirName(){
    return name;
}
void Airline::setBoardingCity(string Board_City){
    boardingCity = Board_City;
}
string Airline::getShortName(){
    return shortName;
}

void Airline::setShortName(string short_Name){
    shortName = short_Name;
}
double Airline::getIncome(){
    return incomes;
}

void Airline::setIncomes(double income_val){
    incomes = income_val;
}


// Con esta funcion a partir del vector de vuelos, si el string de modelo de avion NO esta vacio, el income aumentara al precio multiplocadp por numero de pasajeros
void Airline::currentIncome(){
    double finalIncome{};
    for(auto vuelo : flights) {
        if(vuelo.getAirplaneModel()!= ""){
            finalIncome += vuelo.getPrice() * static_cast<double>(vuelo.getNumberPassengers());
        }
    }
    incomes = finalIncome;
    cout << "El income en este momento es de $" << incomes << endl;
}

//Con esta funcion se imprimira los vuelo, a partir de un ciclo for donde a partir del modelo de avion este vacio mostrara los vuelos

void Airline::printFlights(){
    for(auto vuelo : flights){
        if(vuelo.getAirplaneModel() != ""){
            vuelo.muestraDatos();
            cout << endl;
        }
    }
}
//Con esta funcion se imprimira los vuelo, a partir de un ciclo for donde a partir del modelo de avion este vacio mostrara el schedule
void Airline::printschedule(){
    cout << boardingCity << "Schedule" << endl;
    for (auto vuelo : flights){
        if(vuelo.getAirplaneModel() != ""){
            vuelo.muestraSchedule();
            cout << endl;
        }
    }
}


// COn esta funcion mostrara cuales fueron los ingresos de cada aerloniea
void Airline::closeOperation(){
    cout<< "El ingreso de hoy es: " << incomes << endl;
}

void Airline::printFlight(string date, string destino){
    for(auto vuelo : flights){
        if(vuelo.getDate() == date && vuelo.getFromTo() == destino){

            vuelo.muestraDatos();
            cout << endl;
        }
    }
}

// COn esta funcion a partir que si el dia y el destino buscara en el vector de vuelos para reservar un asiento

void Airline::reserveSeat(string date, string destino){
    for(auto vuelo : flights){
        if(vuelo.getDate() == date && vuelo.getFromTo() == destino){

            vuelo.reservaAsiento();
            cout << endl;
        }

        }
    }