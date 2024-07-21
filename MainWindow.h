#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QFileSystemModel>
#include <QTableView>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QComboBox>

#include "ientrance.h"
#include "Context.h"
#include "Model\StatisticModel.h"
#include "View\ChartCreator.h"
#include "View\ViewAdapter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createNavigation();
    QWidget* createStatistic();
    void createStatusBar();
    void createStrategyBox();
    QMap<QString,double> calculateStatistic();
    void createViewBox();

    QString currentPath;

    QTreeView* navigationView;
    QFileSystemModel* navigationModel;

    ViewAdapter* statisticView;
    StatisticModel* statisticModel;
    Context context;
    IEntrance* strategy;

    QComboBox* strategyBox;
    QComboBox* viewBox;

    QHBoxLayout* viewLayout;


private slots:
    void onSelectionChange(const QItemSelection& selected, const QItemSelection& deselected);
    void onStrategyChange(int index);
    void onViewChange(int index);
signals:
    void pathChanges(QMap<QString, double>&);
};
#endif // MAINWINDOW_H
