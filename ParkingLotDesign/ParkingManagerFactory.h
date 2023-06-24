#pragma once
#include <iostream>
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "ParkingSpotManager.h"


class ParkingManagerFactory{
    private:
        static ParkingSpotManager* pmInstanceForTwoWheel;

        static ParkingSpotManager* pmInstanceForFourWheel;
        static ParkingManagerFactory* pmfInstance;

        ParkingManagerFactory(){}
    
    public:
        static ParkingManagerFactory* getParkingManagerFactory();
        static ParkingSpotManager* getPrakingSpotManager(Vehicle* v);
};