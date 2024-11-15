#ifndef IROTABLE_H
#define IROTABLE_H

#include "object.h"

class IRotable
{
public:
    virtual bool getAngular(object *obj, int dt) = 0;
    virtual bool setAngular(object *obj) = 0;
    virtual bool getAngularVelocity(object *obj, int dv) = 0;
    virtual bool setAngularVelocity(object *obj) = 0;
};

#endif // IROTABLE_H
