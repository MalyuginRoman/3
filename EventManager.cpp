#include <iostream>
#include <QList>
#include "EventManager.h"
#include "MoveCommand.h"
#include "RotateCommand.h"
#include "LogCommand.h"
#include "exception.h"
#include <QDebug>

const int Xmax = 100;
const int Ymax = 100;
const int Tmax = 100;
const int dt = 1;

class MoveCommand;
class RotateCommand;
class LogeCommand;

class EventManagerP
{
public:
    objectList* list;
    int countX, countY;

    EventManagerP():
        countX(0),
        countY(0)
    {
    }
    ~EventManagerP()
    {
    }
    bool init(objectList* starship)
    {
        int count = starship->count();
        for(int i = 0; i < count; i ++)
        {
            /*const*/ object *obj = starship->list().at(i);

//if(i==1) obj->setPlaceX(-3);
            if(!checkPlaceObject(obj))
            {
                std::cerr << "Coordinates of the object with id: " << obj->id() << " are unknown" << std::endl;
                //throw new Exception::UnknownCoord();
                //return false;
            }

//if(i==2) obj->setVelocity(-3);
            if(!checkVelocityObject(obj))
            {
                std::cerr << "Velocity of the object with id: " << obj->id() << " are unknown" << std::endl;
                //throw new Exception::UnknownVelocity();
                //return false;
            }
            list = starship;
        }
        return true;
    }
    bool checkPlaceObject(const object *obj)
    {
        if(obj->placeX() < 0 || obj->placeY() < 0)
            return false;
        return true;
    }
    bool checkVelocityObject(const object *obj)
    {
        if(obj->velocity() < 0 || obj->angular() < 0)
            return false;
        return true;
    }
    bool appendCommand(objectList* starship, int timeStep)
    {
        std::cout << "Start append command for objects" << std::endl;
        int count = starship->count();
        for(int i = 0; i < count; i ++)
        {
            object *obj = starship->list().at(i);
            int countAction = 5;
            for(int j = 0; j < countAction; j++)
            {
                int actionId = (j % 2);
                obj->add(actionId, timeStep);
            }
        }
        return true;
    }
    bool execute(objectList* starship, int timeStep)
    {
        std::cout << "Start moving objects" << std::endl;
        int count = starship->count();
        for(int i = 0; i < count; i ++)
        {
            object *obj = starship->list().at(i);
            int countAction = obj->count();
            for(int j = 0; j < countAction; j ++)
            {
                int currentStep = obj->list().at(j)->timeStep();
                int currentAction = obj->list().at(j)->actionID();
                bool result;
                if(currentStep == timeStep)
                {
                    try
                    {
                        if(currentAction == 0)
                        {
                            MoveCommand *mov = new MoveCommand(obj->placeX(), obj->placeY(), obj->velocity(),
                                                               obj->angular(), obj->angularVelocity(), dt);
                            result = mov->getPosition(obj, dt);
                        }
                        else
                        {
                            RotateCommand *rot = new RotateCommand(obj->placeX(), obj->placeY(), obj->velocity(),
                                                                   obj->angular(), obj->angularVelocity(), dt);
                            result = rot->getAngular(obj, dt);
                        }
                    }
                    catch(Exception::UnknownTimeStep)
                    {
                        qDebug() << QObject::tr("Ошибка");
                        QString text;
                        if(currentAction == 0)
                            text = QString("It is impossible to move the object with id: %1").arg(obj->id());
                        else
                            text = QString("It is impossible to rotate the object with id: %1").arg(obj->id());
                        new LogeCommand(currentAction, text);

                    }
                }
            }
        }
        return true;
    }
    bool removeCommand(objectList* starship, int timeStep)
    {
        std::cout << "Start remove command for objects" << std::endl;
        int count = starship->count();
        for(int i = 0; i < count; i ++)
        {
            object *obj = starship->list().at(i);
            int countAction = obj->list().count();
            for(int j = 0; j < countAction; j++)
            {
                int currentStep = obj->list().at(j)->timeStep();
                if(currentStep == timeStep)
                    obj->remove(j);
            }
        }
        return true;
    }
};

EventManager::EventManager() : imp(new EventManagerP)
{
}

EventManager::~EventManager()
{
    delete imp;
}

bool EventManager::init(objectList* list)
{
    bool result = imp->init(list);
    return result;
}

bool EventManager::appendCommand(objectList* list, int timeStep)
{
    bool result = imp->appendCommand(list, timeStep);
    return result;
}

bool EventManager::execute(objectList* list, int timeStep)
{
    bool result = imp->execute(list, timeStep);
    return result;
}

bool EventManager::removeCommand(objectList* list, int timeStep)
{
    bool result = imp->removeCommand(list, timeStep);
    return result;
}
