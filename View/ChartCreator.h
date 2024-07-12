#ifndef CHARTCREATOR_H
#define CHARTCREATOR_H

#include <QChartView>
#include <QPieSeries>
#include <QBarSeries>
#include "Model\StatisticModel.h"

using namespace QtCharts;

class ChartCreator
{
public:
    ChartCreator();

    QChartView* createPieChart(QString& title, StatisticModel* model);
    QChartView* createBarChart(QString& title, StatisticModel* mode);

private:
    QChartView* chartView;
};

#endif // CHARTCREATOR_H
