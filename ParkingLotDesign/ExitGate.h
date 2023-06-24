#pragma once
#include <iostream>
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "ParkingSpotManager.h"
#include "ParkingManagerFactory.h"
#include "Ticket.h"
#include "EntryGate.h"

class ExitGate{
    Ticket* ticket;
    ParkingManagerFactory* pmf;
    ParkingSpotManager* pmTwoWheeler;
    ParkingSpotManager* pmFourWheeler;
    std::chrono::system_clock::time_point exitTime;

    public:
        ExitGate(ParkingManagerFactory* pmfPassed):pmf(pmfPassed){}

        void  removeVehicle(Ticket* ticket){
            Vehicle* v = ticket->getVehicle();
            if(v->getVehicleType()==VEHICLETYPE::TWOWHEELER){
                pmTwoWheeler = pmf->getPrakingSpotManager(v);
                
                pmTwoWheeler->removeVehicle(v);
                }
            else if(v->getVehicleType()==VEHICLETYPE::FOURWHEELER){
                pmFourWheeler = pmf->getPrakingSpotManager(v);
                pmFourWheeler->removeVehicle(v);
                }

            exitTime = std::chrono::system_clock::now();
            std::time_t exitTimeT = std::chrono::system_clock::to_time_t(exitTime);
            std::cout<<"Vehicle "<<v->getVehicleNo()<<" removed at "<<std::ctime(&exitTimeT)<<std::endl;

        }

        void calculatePrice(Ticket* ticket){
            Vehicle* v = ticket->getVehicle();
            exitTime = std::chrono::system_clock::now();
            std::chrono::duration<long> duration = std::chrono::duration_cast<std::chrono::seconds>(exitTime - ticket->getEntryTime());           
            int price = 0;
            if(v->getVehicleType()==VEHICLETYPE::TWOWHEELER){
                pmTwoWheeler = pmf->getPrakingSpotManager(v);
                ParkingSpot* ps = pmTwoWheeler->getParkingSpotFromVehicle(v);
                if(ps==nullptr){
                    std::cout<<"Spot is empty\n";
                    return;
                }
                 price = ps->getPrice();             
                
            }
            else if(v->getVehicleType()==VEHICLETYPE::FOURWHEELER){
                pmFourWheeler = pmf->getPrakingSpotManager(v);
                ParkingSpot* ps = pmFourWheeler->getParkingSpotFromVehicle(v);
                if(ps==nullptr){
                    std::cout<<"Spot is empty\n";
                    return ;
                }                
                 price = ps->getPrice();               
            }  

            std::cout<<"Vehicle "<<v->getVehicleNo()<<" parking cost is  "<< price*duration.count()<<std::endl;        

        }

    
};