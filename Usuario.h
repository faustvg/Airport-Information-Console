#ifndef _USUARIO_H_
#define _USUARIO_H_
#include <string>

class Usuario {
    private:
        std::string nombre;
        std::string apellido;
        std::string email;
        std::string password;
        int edad;
        int kilometros;
    public:
        Usuario();
        Usuario(std::string, std::string, std::string, std::string);

        /*Usuario(std::string , 
        std::string ,
        std::string ,
        std::string ,
        int  ,
        int );
        */

        //Getters and setter
        std::string getNombre();
        void setnombre(std::string);


        std::string getApellido();
        void setApellido(std::string);


        std::string getEmail();
        void setEmail(std::string);


        std::string getPassword();
        void setPassword(std::string);


        int getEdad();
        void setEdad(int);


        double getKilometros();
        void setKilometros(double);

        //Functions
        void incrementarKilometros(double kilometros);
        void nuevousuario(std::string nombre, std::string apellido, std::string email, std::string password);
};

#endif