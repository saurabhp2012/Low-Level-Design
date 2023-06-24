#pragma once
#include <iostream>
#include "ParkingSpot.h"
#include "Vehicle.h"

class ParkingSpotManager {
protected:
    std::vector<ParkingSpot*> parkingSpots;
    int parkedVehicleCount = 0;

public:
    virtual void initialize() = 0;
    //virtual int findParkingSpot() = 0;
    virtual void parkVehicle(Vehicle* v,int spot) = 0;

    void addParkingSpot(ParkingSpot* spot) {
        parkingSpots.push_back(spot);
    }

    int getTotalParkingSpots() const {
        return parkingSpots.size();
    }

    int findParkingSpot(){
        int i = 0;
        while(i<getTotalParkingSpots()){
            if(parkingSpots[i]->isSpotEmpty()){
                return i;
            }
            i++;
        }
        std::cout<<" Sorry, all parking spots are full\n\n";
        return -1;
    }

    void removeVehicle(Vehicle* v){

       ParkingSpot* ps = getParkingSpotFromVehicle(v);
        if (ps != nullptr) {
            ps->removeVehicle(v);
            parkedVehicleCount--;

        } else {
            std::cout << "Given Vehicle not found\n";
        }
    }

    int getParkedVehicleCount(){
        return parkedVehicleCount;
    }
    ParkingSpot* getParkingSpotFromVehicle(Vehicle* v) {
        for (auto spot : parkingSpots) {
            if (!spot->isSpotEmpty() && spot->getVehicle() == v) {
                return spot;
            }
        }
        return nullptr;
    }

};

class TwoWheelerParkingSpotManager : public ParkingSpotManager {
public:

    void initialize() override {
        for (int i = 0; i < 6; ++i) {
            ParkingSpot* spot = new TwoWheelerParkingSpot();
            addParkingSpot(spot);
        }
    }

    void parkVehicle (Vehicle* v, int spot) override{
        if(v->getVehicleType()!=VEHICLETYPE::TWOWHEELER){
            std::cout<<"Vehicle type doen't match with parking spot\n";
            return;
        }
        ParkingSpot* ps = getParkingSpotFromVehicle(v);
        if(ps!=nullptr){
            std::cout<<"Vehicle "<<v->getVehicleNo()<<" already parked\n";
            return;         
        }
        if(spot==-1) return;
        
        parkingSpots[spot]->parkVehicle(v);
        parkedVehicleCount++;

        //std::cout << "Total two wheeler parked vehicle: " << getParkedVehicleCount() << std::endl;

    }

};

class FourWheelerParkingSpotManager : public ParkingSpotManager {
public:
    void initialize() override {     
        for (int i = 0; i < 2; ++i) {
            ParkingSpot* spot = new FourWheelerParkingSpot();
            addParkingSpot(spot);
        }
    }

    void parkVehicle(Vehicle* v, int spot) override{
        if(v->getVehicleType()!=VEHICLETYPE::FOURWHEELER){
            std::cout<<"Vehicle type doen't match with parking spot\n";
            return;
        }
        ParkingSpot* ps = getParkingSpotFromVehicle(v);
        if(ps!=nullptr){
            std::cout<<"Vehicle "<<v->getVehicleNo()<<" already parked\n";
            return;
        }
        if(spot==-1) return;

        parkingSpots[spot]->parkVehicle(v);
        parkedVehicleCount++;

        //std::cout << "Total four wheeler parked vehicle: " << getParkedVehicleCount() << std::endl;

    }

};
