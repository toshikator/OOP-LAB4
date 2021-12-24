#include <iostream>
#include <Windows.h>

using namespace std;

class Carriage {
public:
    struct Entity {

        string manufacturer = "defaulManufacturer";
        int yearOfConstruction = 1900;
        int ownWeigth = 0;

        Carriage::Entity& SetManufacturer(const string& manufacturer);
        Carriage::Entity& SetYearOfConstruction(const int& yearOfConstruction);
        Carriage::Entity& SetOwnWeigth(const int& yearOwnWeigth);
    };

protected:
    Carriage::Entity _entity;
    int const GetCurrentYear();


public:
    Carriage();
    Carriage(const Carriage::Entity& entity);

    void Print();
};

Carriage::Entity& Carriage::Entity::SetManufacturer(const string& manufacturer) {

    this->manufacturer = manufacturer;
    return *this;
}

Carriage::Entity& Carriage::Entity::SetYearOfConstruction(const int& yearOfConstruction) {

    this->yearOfConstruction = yearOfConstruction;
    return *this;
}

Carriage::Entity& Carriage::Entity::SetOwnWeigth(const int& ownWeigth) {
    this->ownWeigth = ownWeigth;
    return *this;
}

int const Carriage::GetCurrentYear() {
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    return timeinfo.tm_year + 1900;
}

Carriage::Carriage() : _entity(Carriage::Entity()) {}
Carriage::Carriage(const Carriage::Entity& entity) : _entity(entity) {}


void Carriage::Print() {

    cout << endl;
    cout << "Carriage:" << endl;
    cout << "\t" << "Manufacturer: " << _entity.manufacturer << endl;
    cout << "\t" << "Year of construction: " << _entity.yearOfConstruction << endl;
    cout << "\t" << "Own weigth: " << _entity.ownWeigth << endl;

}



class CarsCarriage : public Carriage {
public:
    struct Entity : Carriage::Entity {

        int amountOfCars = 0;
        int eachCarWeigth = 0;
    };

private:
    CarsCarriage::Entity _entity;

public:

    CarsCarriage(CarsCarriage::Entity& entity);

    void Print();
    int GetYearsOfUsage();

    CarsCarriage& SetAmountOfCars(const int& amount);
    CarsCarriage& SetEachCarWeigth(const int& carWeight);

};

CarsCarriage::CarsCarriage(CarsCarriage::Entity& entity) : _entity(entity), Carriage::Carriage(entity) {}

void CarsCarriage::Print() {

    Carriage::Print();

    cout << "\t" << "Cars:" << endl;
    cout << "\t\t" << "Amount of cars: " << _entity.amountOfCars << endl;
    cout << "\t\t" << "Each car weigth: " << _entity.eachCarWeigth << endl;
}

CarsCarriage& CarsCarriage::SetAmountOfCars(const int& amount) {

    _entity.amountOfCars = amount;

    return *this;
}

CarsCarriage& CarsCarriage::SetEachCarWeigth(const int& carWeight) {

    _entity.eachCarWeigth = carWeight;

    return *this;
}

int CarsCarriage::GetYearsOfUsage(){

    return (this->GetCurrentYear() - this->_entity.yearOfConstruction);
}





class RailwayTank : public Carriage {
public:
    struct Entity : Carriage::Entity {

        string cargoClass = "Default cargo";
        int cargoWeigth = 0;
    };

private:
    RailwayTank::Entity _entity;

public:

    RailwayTank(RailwayTank::Entity& entity);

    void Print();
    int GetYearsOfUsage();

    RailwayTank& SetCargoClass(const string& cargoClass);
    RailwayTank& SetCargoWeigth(const int& cargoWeight);

};

RailwayTank::RailwayTank(RailwayTank::Entity& entity) : _entity(entity), Carriage::Carriage(entity) {}

void RailwayTank::Print() {

    Carriage::Print();

    cout << "\t" << "RailwayTank:" << endl;
    cout << "\t\t" << "Class of cargo: " << _entity.cargoClass << endl;
    cout << "\t\t" << "Cargo weigth: " << _entity.cargoWeigth << endl;
}

RailwayTank& RailwayTank::SetCargoClass(const string& cargoClass) {

    _entity.cargoClass = cargoClass;

    return *this;
}

RailwayTank& RailwayTank::SetCargoWeigth(const int& cargoWeigth) {

    _entity.cargoWeigth = cargoWeigth;

    return *this;
}

int RailwayTank::GetYearsOfUsage() {

    return ( this->GetCurrentYear() - this->_entity.yearOfConstruction);
}




int main() {

    setlocale(LC_ALL, "russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);



    CarsCarriage::Entity carsCarriageEntity;
    carsCarriageEntity
        .SetManufacturer("ZAO_RZD_ZAPAD")
        .SetYearOfConstruction(1979)
        .SetOwnWeigth(26665);

    carsCarriageEntity.amountOfCars = 14;
    carsCarriageEntity.eachCarWeigth = 1520;


    CarsCarriage carsCarriage(carsCarriageEntity);
    carsCarriage
        .SetAmountOfCars(101)
        .SetEachCarWeigth(12100)
        ;

    carsCarriageEntity.ownWeigth = 12400;

    carsCarriage.Print();
    cout << "\n\tYears of usage CarsCarriage:\t" << carsCarriage.GetYearsOfUsage();

    
    
    RailwayTank::Entity railwayEntity;
    railwayEntity
        .SetManufacturer("ZAO_RZD_VOSTOK")
        .SetYearOfConstruction(1869)
        .SetOwnWeigth(26665);

    
    railwayEntity.cargoClass = "Castor oil";
    railwayEntity.cargoWeigth = 30001;


    RailwayTank railwayTank(railwayEntity);
    railwayTank
        .SetCargoClass("Diesel")
        .SetCargoWeigth(30001)
        ;

    railwayEntity.ownWeigth = 12400;

    railwayTank.Print();
    cout << "\n\tYears of usage Tank :\t" << railwayTank.GetYearsOfUsage();

    
    
    
    
    return 0;
}
