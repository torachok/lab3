#include <QCoreApplication>
#include <QMap>
#include <QDir>
#include <QTextStream>

#include "ientrance.h"
#include "context.h"

void getStatistic(Context& context){
    QTextStream cout(stdout);

    //QString path = QDir::currentPath();
    QString path = "C:/Users/User/Documents/qtcreator_projects/lab3/TestFolder1";

    IEntrance* strat = new FolderEntrance();
    //Entrance* strat = new TypeEntrance();

    context.setStrategy(strat);

    QMap<QString, long long> stat = *(context.executeStrategy(path));

    QMap<QString, double> map = *(countPrecent(stat, 1.0));

    cout << "Key - size:" << Qt::endl;
    foreach(QString x, stat.keys()) cout << x << " - " << stat[x] << Qt::endl;

    delete strat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Context context;
    getStatistic(context);

    return a.exec();
}
