#include "Passenger.h"
#include <iostream>

using namespace std;

Passenger::Passenger(string name_val, string phone_val)
    : name {name_val}, phone {phone_val} {

    }

//Getters y settters aqui empezamos definiendo todas las funciones de getters y setters, pidiendo los valores de los metodos, donde nos regresara el valor dependiendo de que se pida, ejemplo getName, regresa name
string Passenger::getName(){
    return name;
}
void Passenger::setName(string name_val){
    name = name_val;
}

string Passenger::getPhone(){
    return phone;
}
void Passenger::setPhone(string phone_val){
    phone = phone_val;
}