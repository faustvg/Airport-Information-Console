#include "Usuario.h"
#include "Flight.h"
#include <iostream>

using namespace std;
Usuario::Usuario(){
    nombre = "";
    apellido = "";
    email = "";
    password = "";
    edad = 0;
    kilometros = 0;
}
Usuario::Usuario(string nombre_vals, string apellido_vals, string email_vals, string password_vals){
    nombre = nombre_vals;
    apellido = apellido_vals;
    email = email_vals;
    password = password_vals;
    edad = 0;
    kilometros = 0;

}

/*Usuario::Usuario(
    string nombre_val, 
    string apellido_val,
    string email_val,
    string password_val,
    int edad_val,
    int kilometros_val)    
    : 
    nombre {nombre_val}, 
    apellido {apellido_val},
    password {password_val},
    kilometros{kilometros_val},
    edad{edad_val}
    {
}
*/

string Usuario::getNombre(){
    return nombre;
}
void Usuario::setnombre(string nombre_val){
    nombre = nombre_val;
}

string Usuario::getApellido(){
    return apellido;
}
void Usuario::setApellido(string apeliido_val){
    apellido = apeliido_val;
}   

string Usuario::getEmail(){
    return email;
}
void Usuario::setEmail(string email_val){
    email = email_val;
}  

string Usuario::getPassword(){
    return password;
}

void Usuario::setPassword(string password_val){
    password = password_val;
}

int Usuario::getEdad(){
    return edad;
}

void Usuario::setEdad(int edad_val){
    edad = edad_val;
}   

double Usuario::getKilometros(){
    return kilometros;
}

void Usuario::setKilometros(double kilometros_val){
    kilometros = kilometros_val;
}   

void Usuario::nuevousuario(string nombre, string apellido, string email, string password){
  

}

/* void Usuario::incrementarKilometros() {
    int totalkm {};
    for (auto km : totalkm){

    }
} */