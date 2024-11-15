#ifndef LOGCOMMAND_H
#define LOGCOMMAND_H

#include "QString"

class LogeCommand
{
public:
    LogeCommand(int actionID, QString text);

private:
    class LogeCommandP *imp;
};

#endif // LOGCOMMAND_H
