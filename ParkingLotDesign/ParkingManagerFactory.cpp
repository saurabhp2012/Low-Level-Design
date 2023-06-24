#include <iostream>
#include "ParkingManagerFactory.h"
#include "Vehicle.h"

ParkingManagerFactory* ParkingManagerFactory::pmfInstance = nullptr;
ParkingSpotManager* ParkingManagerFactory::pmInstanceForTwoWheel= nullptr;
ParkingSpotManager* ParkingManagerFactory::pmInstanceForFourWheel= nullptr;


ParkingManagerFactory* ParkingManagerFactory::getParkingManagerFactory(){

    if(pmfInstance==nullptr){
        return new ParkingManagerFactory();
    }
    return pmfInstance;
}

ParkingSpotManager* ParkingManagerFactory::getPrakingSpotManager(Vehicle* v){

        if(v->getVehicleType()==VEHICLETYPE::TWOWHEELER){
            if(pmInstanceForTwoWheel==nullptr){
                TwoWheelerParkingSpotManager* twoWheelerManager = new TwoWheelerParkingSpotManager();
                twoWheelerManager->initialize();
                std::cout << "\nTotal parking spots in TwoWheelerParkingSpotManager: " << twoWheelerManager->getTotalParkingSpots() << std::endl;
                std::cout<<std::endl;
                pmInstanceForTwoWheel= twoWheelerManager;               
            }
            return pmInstanceForTwoWheel;

        }
        else if(v->getVehicleType()==VEHICLETYPE::FOURWHEELER){
            if(pmInstanceForFourWheel==nullptr){
                FourWheelerParkingSpotManager* fourWheelerManager = new FourWheelerParkingSpotManager();
                fourWheelerManager->initialize();
                std::cout << "\nTotal parking spots in FourWheelerParkingSpotManager: " << fourWheelerManager->getTotalParkingSpots() << std::endl;
                std::cout<<std::endl;
                pmInstanceForFourWheel =  fourWheelerManager;
            }
            return pmInstanceForFourWheel;
        }  
        return nullptr; 
}