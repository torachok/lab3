#include <QCoreApplication>
#include <QMap>
#include <QDir>
#include <QTextStream>

#include "ientrance.h"
#include "context.h"

void getStatistic(Context& context){
    QVector<ITraversal*> vec = {new FolderTraversal(), new TypeTraversal()};

    QString path = QDir::currentPath();

    for(ITraversal* strat : vec){
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
