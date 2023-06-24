#pragma once
#include <iostream>
#include <chrono>
#include "ParkingSpot.h"
#include "Vehicle.h"

class Ticket{
    std::chrono::system_clock::time_point entryTime;
    Vehicle* vehicle;
    int parkedSpot;

    public:
        Ticket(Vehicle* v,int spot){
            entryTime = std::chrono::system_clock::now();
            std::time_t entryTimeT = std::chrono::system_clock::to_time_t(entryTime);
            vehicle = v;
            parkedSpot = spot;
            std::cout<<"Ticket generated for vehicle "<<v->getVehicleNo()<<" at time "<< std::ctime(&entryTimeT)<<std::endl;
        }

        Vehicle* getVehicle(){
            return vehicle;
        }
        std::chrono::system_clock::time_point getEntryTime(){
            return entryTime;
        }


};