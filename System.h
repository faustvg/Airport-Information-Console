#ifndef _SYSTEM_H_
#define _SYSTEM_H_
#include "Usuario.h"
#include "Airline.h"
#include "Flight.h"
#include <string>
#include <vector>
#include "Airport.h"
class System {
    private:
        Airport airport;
        std::vector<Usuario> usuarios;
        Usuario currentUser;
    public:
        System();

        void crearUsuario();
        bool login(std::string email, std::string password);
        void logout();
        void desplegarMenu();
        void reservarVuelo(std::string nombre,std::string destino );
        void comenzarOperaciones();
        void terminarOperaciones();
        void agendarvuelos(Airline);
        void actualizarAerolinea(Airline);
        void buscarVuelo(Flight);
        void desplegarNuevo();
        void despliegaLogin();
        //void 
        Usuario getCurrentUser();

        void muestraInicial();
        
};

#endif