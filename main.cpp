#include <iostream>

#include "Airport.h"
#include "System.h"

#include <vector>
using namespace std;

/* Descripción breve del programa. 
• Una línea con el/los autor/autores: nombre(s) y matrícula(s). 
• Una línea con la fecha de creación/modificación.  */

//Este programa tiene como objetivo, simular un aeropuerto, a partir de 6 clases que se graficaron en un diagram UML, el 
//El usuario deberia ser capas de registrar, ingresar y salir, ademas poder reservar un vuelo, ver los vuelos y buscarlos


// Autores : Faustino Vázquez Gabino A01369023, Eugenio Herrera Garza A01721377

//Este trabajo se trabajo durante las ultimas dos semanas del tercer periodo de la clase


int main() {
    // Empieza a funcionar el sistema, desplegando el menu
    cout << "Bienvenido al aeropuerto de la ciudad de mexico" << endl;
    System a;
    a.desplegarMenu();
    



    return 0;
}
