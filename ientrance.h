#ifndef IENTRANCE_H
#define IENTRANCE_H

#include <QMap>
#include <QDir>

QMap<QString, double> *countPrecent(QMap<QString, long long>& stat, double border);

class IEntrance
{
public:
    virtual QMap<QString, long long>* execute (QString & psth) = 0;
    virtual ~IEntrance(){}
};

class FolderEntrance : public IEntrance{
    void entrance(QDir& directory, QMap<QString, long long>* statistic);
public:
    QMap<QString, long long>* execute(QString &path) override;
};

class TypeEntrance : public IEntrance{
    void entrance(QDir& directory, QMap<QString, long long> *statistic);
public:
    QMap<QString, long long>* execute(QString &path) override;
};

#endif // IENTRANCE_H
