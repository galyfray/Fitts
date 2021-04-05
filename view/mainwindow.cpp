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

#include <QStackedLayout>
#include <QGraphicsView>

//QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    int sceneW = int(this->ui->graphicsView->width());
    return sceneW;
}


int MainWindow::getTestSceneHeight()
{
    int sceneH = int(this->ui->graphicsView->height());
    return sceneH;
}

void MainWindow::initWindows(controller *control) {

    ui->groupBox_3->NbCible->setValue(10);
    ui->groupBox_3->NbCible->setMaximum(100);

    ui->groupBox_3->TailleMini->setMaximum(1000);
    ui->groupBox_3->TailleMini->setValue(10);

    ui->groupBox_3->TailleMaxi->setMaximum(1000);
    ui->groupBox_3->TailleMaxi->setValue(10);

    ui->spinBoxA->setValue(10);
    ui->spinBoxB->setValue(10);

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
    connect(ui->groupBox_3->NbCible,SIGNAL(valueChanged(int)),control,SLOT(onNbCibleChange(int)));
    connect(ui->groupBox_3->TailleMini,SIGNAL(valueChanged(int)),control,SLOT(onMinSizeChange(int)));
    connect(ui->groupBox_3->TailleMaxi,SIGNAL(valueChanged(int)),control,SLOT(onMaxSizeChange(int)));


    ui->graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene;
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),300);

}

void MainWindow::updateTestMsg(model *mod) {
    ui->nbciblesr->setText("" + QString::number(mod->getCirclesLeft()));
}

/*
FittsView::FittsView(FittsModel *fittsModel) : QMainWindow() {
    this->fittsModel = fittsModel;

    this->initWindows();
    this->fittsController = new FittsController(this, this->fittsModel);
}



void drawCircle (center, size, sceneW, sceneH)
{
    qreal posX = qrand() % ((sceneW - size) - size) + size;
    qreal posY = qrand() % ((sceneH - size) - size) + size;
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}



*/


