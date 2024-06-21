#include <QCoreApplication>
#include <QMap>
#include <QDir>
#include <QTextStream>

#include "ientrance.h"
#include "context.h"

void getStatistic(Context& context){
    QVector<IEntrance*> vec = {new FolderEntrance(), new TypeEntrance()};
    QString path = QDir::currentPath();
    //QString path = "C:/Users/User/Documents/qtcreator_projects/lab3/TestFolder2";

    for(IEntrance* strat : vec){
        context.setStrategy(strat);

        QMap<QString, long long> statistic = *(context.executeStrategy(path));

        QMap<QString, double> map = *(countPrecent(statistic, 1.0));

        QTextStream cout(stdout);

        foreach(auto x, map.keys()){
            cout << x << " " << map[x] << Qt::endl;
            cout.flush();
        }
        cout << Qt::endl;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Context context;
    getStatistic(context);

    return a.exec();
}
