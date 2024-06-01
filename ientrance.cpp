#include "ientrance.h"

void FolderTraversal::entrance(QDir & directory, QMap<QString, long long> *statistic)
{
    QString path = directory.absolutePath();

    (*statistic)[path] = 0;

    foreach(QFileInfo file, directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)){
        if(file.isDir()){
            QDir folder(file.absoluteFilePath());
            entrance(folder, statistic);
            continue;
        }
        (*statistic)[path] += ((long long) file.size());
    }
}

QMap<QString, long long>* FolderTraversal::execute(QString &path)
{
    QDir dir(path);
    QMap<QString, long long> *map = new QMap<QString, long long>();

    entrance(dir, map);

    return map;
}
