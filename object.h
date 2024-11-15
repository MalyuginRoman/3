#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include <QString>

class action
{
public:
    action(int actionID, int timeStep);
    ~action();

    int actionID() const;
    int timeStep() const;

private:
    class actionP* imp;
};

class object
{
public:
    object(int id, int velocity, double angular, double angularVelocity, int placeX, int placeY);
    ~object();
    void reset();

    int id() const;
    int velocity() const;
    double angular() const;
    double angularVelocity() const;
    int placeX() const;
    int placeY() const;

    void setVelocity(int value);
    void setAngular(double value);
    void setAngularVelocity(double value);
    void setPlaceX(int value);
    void setPlaceY(int value);

    action* add(int actionId, int timeStep);
    void remove(int index);
    bool isEmpty() const;
    int count() const;
    const QList<action *>& list() const;

    void addAction(int actionID, int timeStep);
    void removeAction(int actionID, int timeStep);

private:
    class objectP* imp;
};

class objectList
{
public:
    objectList();
    ~objectList();
    void reset();

    int defaultVelocity() const;
    double defaultAngular() const;
    double defaultAngularVelocity() const;
    int defaultPlaceX() const;
    int defaultPlaceY() const;

    void setDefaultVelocity(int value);
    void setDefaultAngular(double value);
    void setDefaultAngularVelocity(double value);
    void setDefaultPlaceX(int value);
    void setDefaultPlaceY(int value);

    object* add(int id, int velocity, double angular, double angularVelocity, int placeX, int placeY);
    bool isEmpty() const;
    int count() const;
    const QList<object *>& list() const;
private:
    class objectListP* imp;
};

#endif // OBJECT_H
