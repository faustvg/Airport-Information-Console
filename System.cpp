    #include "System.h"
    #include "Usuario.h"
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>
    #include "Airport.h"
    #include "Flight.h"
    using namespace std;

    System::System(){


        airport = Airport();
        currentUser = Usuario("Eugenio", "Herrera", "eugeh13@aeropuerto.mx", "12345");
        //Usuario inicial("Eugenio", "Herrera", "eugeh13@aeropuerto.mx", "12345");
        Usuario inicial("Faustino", "Vazquez", "fausdiablos@gmail.com", "123");

        usuarios.push_back(inicial);
    

    }

    void System::muestraInicial(){

    }



    void System::crearUsuario(){
        string nombre{}, email{}, apellido{}, password{}; 
        bool usuariosino{false};

        cout << "Nombre: " << endl;
        cin >> nombre;
        cout << "\nApellido: " << endl;
        cin >> apellido;
        cout << "\nEmail: " << endl;
        cin >> email;
        cout << "\nContrasena : " << endl;
        cin >> password;
        
        for(int i = 0; i < usuarios.size(); i++) {
            if (usuarios.at(i).getEmail() == email){
                usuariosino = true;
            }
        }
        if(usuariosino == false){
            Usuario nuevo(nombre, apellido, email, password);
        usuarios.push_back(nuevo);
        cout << "usuario creado" << endl;
        cout << nuevo.getEmail() << endl;
        }
        else if(usuariosino == true){
            cout << "El usario ya existe" << endl;
        }
    
    
        
    }

    bool System::login(string email, string password){
        
        for (auto usuario: usuarios){
            if (usuario.getEmail() == email  && usuario.getPassword() == password){
                currentUser = usuario;
                return true;
            }
        }
        cout << "Permiso denegado, usuario inexistente " << endl; 
        return false;
    }

  

    void System::logout(){

    }

    void System::desplegarNuevo(){
        bool menunuevo{true};
        while(menunuevo == true){
            string opcnueva;
            cout << "1. Log out " << endl;
            cout << "2. Agendar Nuevo Vuelo " << endl;
            cout << "3. Comenzar Operaciones " << endl;
            cout << "4. Mostrar Todos los Vuelos del Aeropuerto  " << endl;
            cout << "5. Mostrar Todos los Vuelos de una Aerolinea " << endl;
            cout << "6. Reservar Asiento " << endl;
            cout << "7. Buscar vuelo por destino y fecha " << endl;
            cout << "8.  " << endl;
            cout << "9. Terminar Progama " << endl;
            cout << "10. Cerrar Operaciones " << endl;
            cin >> opcnueva;
            if(opcnueva == "1"){
                menunuevo = false;
            }
            else if(opcnueva == "2"){
                airport.agregarVuelo();
                

            }
            else if(opcnueva == "3"){
                
            }
            else if(opcnueva == "4"){
                airport.printAllFlights();

            }
            else if(opcnueva == "5"){
                string n;
                cout << "Ingrese nombre de Aerolinea: " <<endl;
                cin >> n;

                airport.printAllFlights(n);
            }
            else if(opcnueva == "6"){
                string f, d;
                cout << "Ingrese fecha: " <<endl;
                cin >> f;
                cout << "Ingrese Destino: ";
                cin >> d;
                airport.buscaReserFlight(f, d);
            }
            else if(opcnueva == "7"){
                string f, d;
                cout << "Ingrese fecha: " <<endl;
                cin >> f;
                cout << "Ingrese Destino: ";
                cin >> d;

                airport.buscaFlight(f, d);
        }
            else if(opcnueva == "10"){
                airport.closeOperation();
    }
    }
    }

    void System::desplegarMenu(){
        bool menudesp{true};
        while(menudesp == true){
            string opcionEscogida{};
            cout << "Menu : " << endl;
            cout << "--------------------------" << endl;
            cout << "1. Registrar " << endl;
            cout << "2. Log In " << endl;
                /*cout << "3. Log out " << endl;
            cout << "4. Desplegar Menu " << endl;
            cout << "5. Reservar Vuelo " << endl;
            cout << "6. Comenzar Operaciones " << endl;
            cout << "7. Terminar Operaciones  " << endl;
            cout << "8. Agendar Vuelos " << endl;
            cout << "10. Actualizar Aerolinea " << endl;
            cout << "11. Buscar vuelo por destino " << endl;
            cout << "12. Buscar Vuelo por fecha " << endl;
            cout << "13. Terminar Progama " << endl;*/
            cin >> opcionEscogida;
            if (opcionEscogida == "1"){
                crearUsuario();
                
            }
            else if(opcionEscogida == "2"){
                string email, password;
                cout << "Email: " << endl;
                cin >> email;
                cout << "Password: " << endl;
                cin >> password;
    
                if(login(email,password)== true){
                    cout << "Exito" << endl;
                    desplegarNuevo();
                }
                else{
                    cout << "El usuario no existe" << endl;
                }

            }
            else if(opcionEscogida == "13"){
                menudesp = false;

            }


        }
    }