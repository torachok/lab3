#include "context.h"

Context::Context()
{}

void Context::setStrategy(IEntrance *newStrategy)
{
    strategy = newStrategy;
}

QMap<QString, long long>* Context::executeStrategy(QString &path)
{
    if(strategy != nullptr)
        return strategy->execute(path);
    else{
        qWarning() << "Strategy not initilized";
        return new QMap<QString, long long>();
    }
}
