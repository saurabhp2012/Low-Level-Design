#pragma once
#include <iostream>

enum class VEHICLETYPE{
    TWOWHEELER,
    FOURWHEELER,
};

class Vehicle{
    int vehicleNo;
    VEHICLETYPE vehicleType;

    public:
        Vehicle(int vn,VEHICLETYPE vt):vehicleNo(vn),vehicleType(vt){}

        int getVehicleNo(){
            return vehicleNo;
        }
        void setVehicleNo(int vn){
            vehicleNo = vn;
        }
        VEHICLETYPE getVehicleType(){
            return vehicleType;
        }
        void setVehicleType(VEHICLETYPE vt){
            vehicleType = vt;
        }

};

