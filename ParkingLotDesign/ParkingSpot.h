#pragma once
#include <iostream>
#include "Vehicle.h"


class ParkingSpot{

    int id;
    static int nextId;
    bool isEmpty;
    Vehicle* vehicle;

    protected:
    int price;
    public:
        ParkingSpot(){
            id = nextId++;
            isEmpty = true;
            vehicle = NULL;  
            price = 10;        
        }
        void parkVehicle(Vehicle* v){
            vehicle = v;
            isEmpty = false;
            std::cout<<"Vehilce "<<v->getVehicleNo()<<" is parked at parking spot "<<id<<std::endl;
        }
        void removeVehicle(Vehicle* v){
            std::cout << "Vehicle " << v->getVehicleNo() << " removed from parking spot "<<id<<std::endl;
            vehicle = NULL;
            isEmpty = true;
        }

        bool isSpotEmpty(){
            return isEmpty;
        }
        Vehicle* getVehicle(){
            return vehicle;
        }
        int getPrice(){
            return price;
        }


};

class TwoWheelerParkingSpot : public ParkingSpot{
    public:
        int getPrice(){
            return price;
        }
};

class FourWheelerParkingSpot : public ParkingSpot{
    public:
        int getPrice(){
            return 2*price;
        }
};