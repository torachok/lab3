#ifndef IENTRANCE_H
#define IENTRANCE_H

#include <QMap>
#include <QDir>

class IEntrance
{
public:
    virtual QMap<QString, long long>* execute (QString & psth) = 0;
    virtual ~IEntrance(){}
};

class FolderTraversal : public IEntrance{
    void entrance(QDir& directory, QMap<QString, long long> *statistic);
public:
    QMap<QString, long long>* execute(QString &path) override;
};

#endif // IENTRANCE_H
