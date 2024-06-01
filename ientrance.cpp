#include "ientrance.h"

void FolderTraversal::entrance(QDir & directory, QMap<QString, long long> *statistic)
{
    foreach(QFileInfo file, directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)){
        if(file.isDir()){
            QDir folder(file.absoluteFilePath());
            entrance(folder, statistic);
            continue;
        }

        QString extension = file.suffix();
        if((*statistic).count(extension) != 0) (*statistic)[extension] += ((long long) file.size());
        else (*statistic)[extension] = ((long long) file.size());
    }
}

QMap<QString, long long>* TypeEntrance::execute(QString &path)
{
    QDir dir(path);
    QMap<QString, long long> *map = new QMap<QString, long long>();

    entrance(dir, map);

    return map;
}

