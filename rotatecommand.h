#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "IRotable.h"

class object;

class RotateCommand
{
public:
    RotateCommand(int x, int y, double a1, double a2, int v, int dt);
    virtual bool getAngular(object *obj, int dt);
    virtual bool setAngular(object *obj);
    virtual bool getAngularVelocity(object *obj, int dv);
    virtual bool setAngularVelocity(object *obj);
private:
    class RotateCommandP *imp;
};

#endif // ROTATECOMMAND_H
