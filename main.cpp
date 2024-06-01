#include <QCoreApplication>
#include <QMap>
#include <QDir>
#include <QTextStream>

#include "ientrance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IEntrance * strat = new TypeEntrance();
    QString path = QDir::currentPath();
    QMap<QString, long long> map = *(strat->execute(path));

    QTextStream cout(stdout);

    foreach(auto x, map.keys()){
        cout << x << " " << map[x] << Qt::endl;
        cout.flush();
    }

    return a.exec();
}
