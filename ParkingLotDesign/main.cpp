#include<iostream>
#include <unistd.h>
#include "ParkingSpot.h"
#include "ParkingSpotManager.h"
#include "ParkingManagerFactory.h"
#include "EntryGate.h"
#include "ExitGate.h"
#include "Ticket.h"

using namespace std;
 
int main()
{
    // ParkingSpot* ps1 = new ParkingSpot();
    // ParkingSpot* ps2 = new ParkingSpot();
    // ParkingSpot* ps3 = new ParkingSpot();
     Vehicle* v1 = new Vehicle(3456,VEHICLETYPE::TWOWHEELER);
    Vehicle* v2 = new Vehicle(6341,VEHICLETYPE::FOURWHEELER);

    Vehicle* v3 = new Vehicle(4444,VEHICLETYPE::FOURWHEELER);
    Vehicle* v4 = new Vehicle(5555,VEHICLETYPE::FOURWHEELER);

    // ps1->parkVehicle(v1);
    // ps3->parkVehicle(v2);

    // TwoWheelerParkingSpotManager* twoWheelerManager = new TwoWheelerParkingSpotManager();
    // twoWheelerManager->initialize();

    

    // FourWheelerParkingSpotManager* fourWheelerManager = new FourWheelerParkingSpotManager();
    // fourWheelerManager->initialize();

    // ParkingManagerFactory* pf = ParkingManagerFactory::getParkingManagerFactory();
    // ParkingSpotManager* pm1 = pf->getPrakingSpotManager(v1);

    // int spot = pm1->findParkingSpot();
    // pm1->parkVehicle(v1,spot);

    // ParkingSpotManager* pm2 = pf->getPrakingSpotManager(v2);
    // int spot2 = pm2->findParkingSpot();
    // pm2->parkVehicle(v2,spot2);

    // ParkingSpotManager* pm3 = pf->getPrakingSpotManager(v3);
    // ParkingSpotManager* pm4 = pf->getPrakingSpotManager(v1);


    // int spot3 = pm3->findParkingSpot();
    // pm3->parkVehicle(v3,spot3);

    // int spot4 = pm2->findParkingSpot();
    // pm2->parkVehicle(v4,spot4);
    
    // pm1->removeVehicle(v1);
    // pm2->removeVehicle(v2);

    EntryGate* eg = new EntryGate();
    // int spot1 = eg->findSpot(v1);
    // eg->bookSpot(v1,spot1);
    // Ticket* t1 = eg->generateTicket(v1,spot1);

    // int spot2= eg->findSpot(v2);
    // eg->bookSpot(v2,spot2);
    // Ticket* t2 = eg->generateTicket(v2,spot2);

    // int spot3= eg->findSpot(v3);
    // eg->bookSpot(v2,spot3);
    // Ticket* t3 = eg->generateTicket(v2,spot3);

    // int spot4= eg->findSpot(v4);
    // eg->bookSpot(v4,spot4);
    // Ticket* t4 = eg->generateTicket(v4,spot4);

    Ticket* t1 = eg->parkVehicle(v1);
    Ticket* t2 = eg->parkVehicle(v2);
    Ticket* t3= eg->parkVehicle(v3);
    Ticket* t4 = eg->parkVehicle(v4);

    ExitGate* ex = new ExitGate(eg->getParkingManagerFactoryInstance());

    sleep(5);
    
    ex->calculatePrice(t1);
    ex->removeVehicle(t1);


    sleep(5);
    
    ex->calculatePrice(t3);
    ex->removeVehicle(t3);

    t4 = eg->parkVehicle(v4);






    return 0;


}