#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphicwidget.h"

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QLineSeries>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class FittsModel;
class FittsController;

class FittsView : public QMainWindow
{
    Q_OBJECT
public:
    FittsView(FittsModel *fittsModel);
    ~FittsView();

    void initWindows();
private:
    void updateTestMsg();
    void displayResults();

    FittsModel *fittsModel;
    FittsController *fittsController;

    QPushButton *leaveBtn;
    QPushButton *startBtn;
    QPushButton *backBtn;
    QPushButton *resultBtn;
    QPushButton *resultLeaveBtn;
    QPushButton *restartBtn;

    QDoubleSpinBox *aValue;
    QDoubleSpinBox *bValue;
    QSpinBox *nbCible;
    QSpinBox *minSize;
    QSpinBox *maxSize;

    QStackedLayout *mainStack;

    GraphicWidget *graphicView;
    QGraphicsScene *scene;

    QLabel *testLabel;
    QLabel *ecartType;
    QLabel *erreurType;
    QLabel *diffMoy;
    QLabel *itc95;

    QChartView *plot;

    friend FittsController;
};

#endif // MAINWINDOW_H
