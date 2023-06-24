#pragma once
#include <iostream>
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "ParkingSpotManager.h"
#include "ParkingManagerFactory.h"
#include "Ticket.h"

class EntryGate{
    ParkingManagerFactory* pmf;
    ParkingSpotManager* pmTwoWheeler;
    ParkingSpotManager* pmFourWheeler;
    public:
    EntryGate(){
        pmf = ParkingManagerFactory::getParkingManagerFactory();
    }

    private:
        int findSpot(Vehicle* v){
            if(v->getVehicleType()==VEHICLETYPE::TWOWHEELER){
                    pmTwoWheeler = pmf->getPrakingSpotManager(v);
                    return pmTwoWheeler->findParkingSpot();                         
            }
            else if(v->getVehicleType()==VEHICLETYPE::FOURWHEELER){
                    pmFourWheeler = pmf->getPrakingSpotManager(v);
                    return pmFourWheeler->findParkingSpot();               
            }
            return -1;
        }

        void bookSpot(Vehicle* v, int spot){
            if(v->getVehicleType()==VEHICLETYPE::TWOWHEELER){pmTwoWheeler->parkVehicle(v,spot);}
            else if(v->getVehicleType()==VEHICLETYPE::FOURWHEELER){pmFourWheeler->parkVehicle(v,spot);}

        }

        Ticket* generateTicket(Vehicle* v, int spot){
        if(spot==-1) return nullptr;
        return new Ticket(v,spot);          
    }

    public:
        Ticket* parkVehicle(Vehicle* v){
            int spot = findSpot(v);
            if(spot!=-1){
                bookSpot(v,spot);
                return generateTicket(v,spot);
            }
            return nullptr;
        }

        ParkingManagerFactory* getParkingManagerFactoryInstance(){
            return pmf;
        }
};