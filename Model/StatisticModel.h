#ifndef STATISTICMODEL_H
#define STATISTICMODEL_H

#include <QAbstractTableModel>

class StatisticModel:public QAbstractTableModel
{
public:
    StatisticModel(QMap<QString, double>& Data, QObject* parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QVector<QVector<QString>> m_data;
    int columns = 2;
public slots:
    void onPathChange(QMap<QString, double>& newData);
};

#endif // STATISTICMODEL_H
