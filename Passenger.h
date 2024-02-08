#ifndef _PASSENGER_H_
#define _PASSENGER_H_
#include <string>

class Passenger {
    private: 
    std::string name;
    std::string phone;
    public:
    Passenger(std::string name_val = "", std::string phone_val = "");
    std::string getName();
    void setName(std::string);
    std::string getPhone();
    void setPhone(std::string);
};

#endif
