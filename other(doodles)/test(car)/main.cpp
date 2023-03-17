#include <iostream>
#include <string>
using namespace std;

struct Car;

struct Engine {
    Car* car{};
    unsigned short power_m;
    unsigned short fuel_consumption_m;
    
    Engine()
    {
        
    }
    
    Engine (Car* car, unsigned short power_m, unsigned short fuel_consumption_m) {
        this -> power_m = power_m;
        this -> fuel_consumption_m = fuel_consumption_m;
        this -> car = car;
    }
};

struct Car {
    
    Engine engine;
    string brand_m;
    int year_of_production_m;
    
    Car()
    {
        
    }
    
    Car (Engine engine, string brand_m, int year_of_production_m) {
        this -> brand_m = brand_m;
        this -> year_of_production_m = year_of_production_m;
        this -> engine = engine;
    }
};

string to_string (Engine engine, Car car) {
    string output;
    output += "Car's year of production: ";
    output += car.year_of_production_m;
    output += "\n";
    
    output += "Car's brand: ";
    output += car.brand_m;
    output += "\n";
    
    output += "Engine's power: ";
    output += engine.power_m;
    output += "\n";
    
    output += "Engine's fuel consumption: ";
    output += engine.fuel_consumption_m;
    output += "\n";
    
    output += "Car's engine's power: ";
    output += car.engine.power_m;
    output += "\n";
    
    output += "Car's engine's fuel consumption: ";
    output += car.engine.fuel_consumption_m;
    output += "\n";
    
    output += "Engine's car's year of production: ";
    output += "\n";
    
    output += "Engine's brand: ";
    output += "\n";
    
    return output;
}


int main() {
    Engine silnik;
    Car samochod(silnik, "Audi", 2007);
    
    //silnik (samochod, 400, 20);
    
    cout << to_string (silnik, samochod) << "\n";
    
    return 0;
}
