#include <QCoreApplication>
#include <iostream>
#include "EventManager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    objectList* list = new objectList;
    EventManager* manager = new EventManager;

    int count = 5;
    for(int i = 0; i < count; i++)
    {
        int id = i;
        int velocity = 10 * i;
        int angular = 45 * i;
        int angularVelocity = 0;
        int placeX = list->defaultPlaceX();
        int placeY = list->defaultPlaceY();
        list->add(id, velocity, angular, angularVelocity, placeX, placeY);
        qDebug() << "addObject:" << list->count();
        qDebug() << id << "," << velocity << "," << angular << "," << angularVelocity<< "," << placeX<< "," << placeY;
    }

    bool isOk = manager->init(list);
    if(!isOk) return false;

    int timeStep = 1;

    // start timestep
    isOk = manager->appendCommand(list, timeStep);
    if(!isOk) return false;

    // release timestep
    isOk = manager->execute(list, timeStep);
    if(!isOk) return false;

    // end timestep
    isOk = manager->removeCommand(list, timeStep);
    if(!isOk) return false;

    return a.exec();
}
