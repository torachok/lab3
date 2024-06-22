#include <QCoreApplication>
#include <QMap>
#include <QDir>
#include <QTextStream>

#include "ientrance.h"
#include "context.h"

void getStatistic(Context& context){
    IEntrance* strat = new FolderEntrance();

    context.setStrategy(strat);

    //QString path = QDir::currentPath();
    QString path = "C:\\Users\\Viktoriia\\QtCreatorProjects\\lab3\\TestFolder2";

    QMap<QString, long long> statistic = context.executeStrategy(path);

    QMap<QString, double> map = countPrecent(statistic, 1.0);
    QTextStream cout(stdout);

    foreach(const QString& key, map.keys())
        cout << key << " " << map[key] << Qt::endl;

    cout.flush();

    delete strat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Context context;
    getStatistic(context);

    return a.exec();
}
