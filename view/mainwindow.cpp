#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "../model/model.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QList>
#include <QStackedLayout>
#include <QGraphicsView>

//QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),300);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication :: quit();
}

int MainWindow::getTestSceneWidth()
{
    int sceneW = int(this->scene->width());
    return sceneW;
}


int MainWindow::getTestSceneHeight()
{
    int sceneH = int(this->scene->height());
    return sceneH;
}

void MainWindow::initWindows(controller *control, model *mod) {

    ui->groupBox_3->findChild<QSpinBox *>("NbCible")->setValue(mod->nbCircles);
    ui->groupBox_3->findChild<QSpinBox *>("NbCible")->setMaximum(100);

    ui->groupBox_3->findChild<QSpinBox *>("TailleMini")->setMaximum(mod->maxSize);
    ui->groupBox_3->findChild<QSpinBox *>("TailleMini")->setValue(mod->minSize);
    ui->groupBox_3->findChild<QSpinBox *>("TailleMini")->setMinimum(10);

    ui->groupBox_3->findChild<QSpinBox *>("TailleMaxi")->setMaximum(1000);
    ui->groupBox_3->findChild<QSpinBox *>("TailleMaxi")->setValue(mod->maxSize);
    ui->groupBox_3->findChild<QSpinBox *>("TailleMini")->setMinimum(mod->minSize);

    ui->spinBoxA->setValue(mod->a);
    ui->spinBoxB->setValue(mod->b);

    //connect(leaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    //connect(startBtn,SIGNAL(clicked()),fittsController,SLOT(startSimulation()));

    //connect(backBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));
    //connect(resultBtn,SIGNAL(clicked()),control,SLOT(resultClicked()));

    //connect(resultLeaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    //connect(restartBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));

    connect(ui->graphicsView, SIGNAL(mouseClicked(int,int)), control, SLOT(onClick(int,int)));

    // SpinBox values update
    connect(ui->spinBoxA,SIGNAL(valueChanged(double)),control,SLOT(onAChange(double)));
    connect(ui->spinBoxB,SIGNAL(valueChanged(double)),control,SLOT(onBChange(double)));
    connect(ui->groupBox_3->findChild<QSpinBox *>("NbCible"),SIGNAL(valueChanged(int)),control,SLOT(onNbCibleChange(int)));
    connect(ui->groupBox_3->findChild<QSpinBox *>("TailleMini"),SIGNAL(valueChanged(int)),control,SLOT(onMinSizeChange(int)));
    connect(ui->groupBox_3->findChild<QSpinBox *>("TailleMaxi"),SIGNAL(valueChanged(int)),control,SLOT(onMaxSizeChange(int)));

    ui->graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void MainWindow::PrintResults(QList<QPointF> theorique, QList<QPointF> exp)
{

   plot = new QChartView;
   scene->addWidget(plot);

   QChart *chart = new QChart;
   this->plot->setChart(chart);
   chart->setTitle("Temps d'éxecution en fonction de la distance");
   chart->createDefaultAxes();
   chart->legend()->setVisible(true);
   chart->legend()->setAlignment(Qt::AlignBottom);

    QLineSeries *expSeries = new QLineSeries;
    expSeries->setName("Courbe expérimentale");
    QLineSeries *fittsSeries = new QLineSeries;
    fittsSeries->setName("Courbe théorique");
    QCategoryAxis *axis=new QCategoryAxis;

    expSeries->append(exp);
    fittsSeries->append(theorique);

    axis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    chart->addSeries(expSeries);
    chart->addSeries(fittsSeries);
}

void MainWindow::updateTestMsg(model *mod) {
    ui->nbciblesr->setText("" + QString::number(mod->getCirclesLeft()));
}

void MainWindow::drawCircle(QPoint center,int size){
    scene->clear();
    scene->addEllipse(center.x() - (size / 2), center.y() - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

QSpinBox * MainWindow::getNbCibleSpin(){
    return ui->groupBox_3->findChild<QSpinBox *>("NbCible");
}

QSpinBox * MainWindow::getTailleMinSpin(){
    return ui->groupBox_3->findChild<QSpinBox *>("TailleMini");
}

QSpinBox * MainWindow::getTailleMaxSpin(){
    return ui->groupBox_3->findChild<QSpinBox *>("TailleMaxi");
}

QSpinBox * MainWindow::getASpin(){
    return ui->groupBox_3->findChild<QSpinBox *>("a");
}

QSpinBox * MainWindow::getBSpin(){
    return ui->groupBox_3->findChild<QSpinBox *>("b");
}
