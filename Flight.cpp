#include "Flight.h"
#include "Airline.h"
#include "Airport.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


Flight::Flight(
    string date_val, 
    string hour_val,
    double price_val,
    string model_val,
    string fromTo_val,
    double distance_val,
    string crew_val
) 
    : date{date_val}, 
    hour {hour_val}, 
    price{price_val}, 
    airplaneModel{model_val}, 
    fromTo {fromTo_val}, 
    distance{distance_val} {
    
    string crewMember;
    stringstream input_stringstream(crew_val);
    while (getline(input_stringstream, crewMember, ',')) {
        crew.push_back(crewMember);
    }
    initPassengers();
}

//Getters y settters aqui empezamos definiendo todas las funciones de getters y setters, donde nos regresara el valor dependiendo de que se pida, ejemplo getDate, regresa date
string Flight::getDate() {
    return date;
}
void Flight::setDate(string d) {
    date = d;
}
string Flight::getHour() {
    return hour;
}
void Flight::setHour(string h) {
    hour = h;
}
double Flight::getPrice() {
    return price;
}
void Flight::setPrice(double p) {
    price = p;
}
string Flight::getAirplaneModel() {
    return airplaneModel;
}
void Flight::setAirplaneModel(string am) {
    airplaneModel = am;
}
string Flight::getFromTo() {
    return fromTo;
}
void Flight::setFromTo(string ft) {
    fromTo = ft;
}
double Flight::getDistance() {
    return distance;
}
void Flight::setDistance(double d) {
    distance = d;
}

//Aqui se inicializa la funcion de getCrew donde se crea un ciclo for que mientra el numero no sea mayor al tamaño del crew guardara el miembtro y regresa una string c
string Flight::getCrew() {
    string a;
    for (size_t i = 0; i < crew.size(); i++)
        a += crew.at(i) + ",";
    string c = a.substr(0, a.size() - 1);
    return c;
}

// Aqui se inicializa la funcion para setCrew donde se recibe la string c, la cual mientras un ciclo while, almacenara los miembros que se vayan almacenandos
void Flight::setCrew(string c) {
    crew.clear();
    string crewMember;
    stringstream input_stringstream(c);
    while (getline(input_stringstream, crewMember, ',')) {
        crew.push_back(crewMember);
    }
}
// Getter y setter de fuel
double Flight::getFuel() {
    return fuel;
}
void Flight::setFuel(double f) {
    fuel = f;
}

//Funcion de initPassenger que sirve para indicar que mientras el numero de pasajeros no sea mayor a 120, se podran seguir agregando pasajeros
void Flight::initPassengers() {
    for (size_t i = 0; i < 120; i++) {
        Passenger nuevo;
        passengers.push_back(nuevo);
    }
}
//funcion de calculateFuel la cual funciona para calcular la cantidad de gasolina que sera necesarioa dependiendo de la distancia
void Flight::calculateFuel() {
    //1200l por cada 100km
    double fuelLitros = (distance * 1200) / 100;
    fuel = fuelLitros / 4.546;
    cout << "El combustible requerido para viajar " << fromTo << " es de " << fuel 
<< " galones." << endl;
}

//Funcion de reservar asiento que a partir de los int de fila y asiento, mientras fila no sea menor a 1 o mayor a 30 y asiento mayor a 4 o menor a 1 podra continuar
//Despues se crea una condicional que dependiendo si la posicion esta vacia podra asignar un lugar con el nombre y telefono, pero si no esta vacio, imprimira que ya esta reservado
void Flight::reservaAsiento() {
    int fila{}, asiento{};
    cout << "Cual fila quieres reservar (1-30): " << endl;
    cin >> fila;
    if (fila < 1 || fila > 30) {
        cout << "La fila " << fila << " no esta disponible." << endl;
        return;
    }
    cout << "Cual asiento quieres reservar (1-4): " << endl;
    cin >> asiento;
    if (asiento < 1 || asiento > 4) {
        cout << "El asiento " << asiento << " no esta disponible." << endl;
        return;
    }
    int posicion = 4 * (fila - 1) + (asiento - 1);
    string nombre, telefono;
    if (passengers.at(posicion).getName() == "") {
        cout << "Asiento disponible" << endl;
        cout << "Cual es su nombre: " << endl;
        cin >> nombre;
        cout << "Cual es su telefono: " << endl;
        cin >> telefono;
        passengers.at(posicion).setName(nombre);
        passengers.at(posicion).setPhone(telefono);
        
    } else {
        cout << "El asiento ya está reservado" << endl;
    }
}

// La funcion funciona a partir de los pasajeros donde va ir sumando a result, y regresa el total
int Flight::getNumberPassengers(){
    int result{};
    for(auto pasajero : passengers) {
        if (pasajero.getName()!= "")
        result++;
    }
    return result;
}

//Esta funcion muestra los strings de los metodos de date,hour,price,etc al final tambien imprime los miembros, ademas calcula el total de combustible
void Flight::muestraDatos(){
    cout << "Fecha: " << date << endl;
    cout << "Hora: " << hour << endl;
    cout << "Precio: " << price << endl;
    cout << "Modelo: " << airplaneModel << endl;
    cout << "Destino: " << fromTo << endl;
    cout << "Distancia: " << distance << endl;
    cout << "Tripulación: ";
    for(auto score : crew){
        cout << score << ",";

    }
    cout << endl;
    calculateFuel();
    cout << endl;
}

//Esta funcion muestra el schedule de los vuelos que se deseen conocer
void Flight::muestraSchedule(){
    cout << date << " | " <<fromTo << " | " << hour << " | " << endl; 
}


