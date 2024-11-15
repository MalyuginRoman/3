#ifndef IMOVABLE_H
#define IMOVABLE_H

#include "object.h"

class IMovable
{
public:
    virtual bool getPosition(object *obj, int dt) = 0;
    virtual bool setPosition(object *obj) = 0;
    virtual bool getVelocity(object *obj, int du) = 0;
    virtual bool setVelocity(object *obj) = 0;
};

#endif // IMOVABLE_H
