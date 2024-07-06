#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    currentPath = QDir::currentPath();
    QWidget* mainWindowWidget = new QWidget(this);

    createNavigation();
    createStatistic();
    createStrategyBox();

    QVBoxLayout* vLayout = new QVBoxLayout(this);

    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(navigationView);
    hLayout->addWidget(statisticView);

    vLayout->addWidget(strategyBox);
    vLayout->addLayout(hLayout);

    mainWindowWidget->setLayout(vLayout);

    this->setCentralWidget(mainWindowWidget);

    createStatusBar();
    this->setGeometry(100,100,1500,800);
}

MainWindow::~MainWindow()
{
    if(strategy!= nullptr){
        delete strategy;
        strategy = nullptr;
    }
}

void MainWindow::createNavigation()
{
    navigationView = new QTreeView(this);
    navigationModel = new QFileSystemModel(this);

    navigationModel->setRootPath(currentPath);
    navigationModel->setFilter(QDir::AllDirs|QDir::NoDotAndDotDot);

    navigationView->setModel(navigationModel);

    navigationView->expandAll();

    navigationView->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    QItemSelectionModel* selectionModel = navigationView->selectionModel();
    QItemSelection selection;
    QModelIndex currentPathIndex = navigationModel->index(currentPath);
    selection.select(currentPathIndex, currentPathIndex);
    selectionModel->select(currentPathIndex, QItemSelectionModel::Toggle);

    connect(
        selectionModel,
        &QItemSelectionModel::selectionChanged,
        this,
        &MainWindow::onSelectionChange
        );
}

QMap<QString, double> MainWindow::calculateStatistic()
{
    QMap<QString, long long> rawData = context.executeStrategy(currentPath);
    QMap<QString, double> data = countPrecent(rawData, 1.0f);

    return data;
}

void MainWindow::createStatistic()
{
    statisticView = new QTableView(this);
    strategy = new FolderEntrance();

    context.setStrategy(strategy);

    QMap<QString, double> data = calculateStatistic();

    statisticModel = new StatisticModel(data, this);

    statisticView->setModel(statisticModel);

    connect(
        this,
        &MainWindow::pathChanges,
        statisticModel,
        &StatisticModel::onPathChange
        );
}

void MainWindow::createStatusBar()
{
    this->setStatusBar(new QStatusBar(this));
    this->statusBar()->showMessage("Выбранный путь " + currentPath);
}

void MainWindow::createStrategyBox()
{
    strategyBox = new QComboBox(this);
    strategyBox->addItems(
        {"Folder", "Type"}
        );

    connect(
        strategyBox,
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        &MainWindow::onStrategyChange
        );
}

void MainWindow::onSelectionChange(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QModelIndex selectedItem = selected.indexes().constFirst();

    currentPath = navigationModel->filePath(selectedItem);

    QMap<QString, double> data = calculateStatistic();

    emit pathChanges(data);
}

void MainWindow::onStrategyChange(int index)
{
    if(strategy!=nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }

    switch(index)
    {
    case 0:
        strategy = new FolderEntrance();
        break;
    case 1:
        strategy = new TypeEntrance();
        break;
    }

    context.setStrategy(strategy);
    QMap<QString, double> data = calculateStatistic();

    emit pathChanges(data);
}
