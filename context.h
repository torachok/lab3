#ifndef CONTEXT
#define CONTEXT

#include "ientrance.h"
#include <QDebug>

class Context
{
    IEntrance * strategy;
public:
    Context();
    void setStrategy(IEntrance* newStrategy);
    QMap<QString, long long>* executeStrategy(QString& path);
};

#endif // CONTEXT
