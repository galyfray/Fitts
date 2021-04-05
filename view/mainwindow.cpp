#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->NbCible->setValue(10);
    ui->NbCible->setMaximum(100);

    ui->TailleMini->setMaximum(1000);
    ui->TailleMini->setValue(10);

    ui->TailleMaxi->setMaximum(1000);
    ui->TailleMaxi->setValue(10);

    ui->spinBoxA->setValue(10);
    ui->spinBoxB->setValue(10);
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

void MainWindow::initWindows() {

    ui->graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene;
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),300);

}
/*
void MainWindow::updateTestMsg() {
    ui->nbciblesr->setText("<strong>Le test commencera après avoir appuyé sur la cible bleu.</strong> Nombre de cibles restantes : " + QString::number(this->model->cibleLeft));
}*/

/*
FittsView::FittsView(FittsModel *fittsModel) : QMainWindow() {
    this->fittsModel = fittsModel;

    this->initWindows();
    this->fittsController = new FittsController(this, this->fittsModel);

    // Btn clicked
    connect(leaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    connect(startBtn,SIGNAL(clicked()),fittsController,SLOT(startSimulation()));

    connect(backBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));
    connect(resultBtn,SIGNAL(clicked()),fittsController,SLOT(resultClicked()));

    connect(resultLeaveBtn,SIGNAL(clicked()),fittsController,SLOT(quit()));
    connect(restartBtn,SIGNAL(clicked()),fittsController,SLOT(backToSettings()));

    connect(graphicView, SIGNAL(mouseClicked(int,int)), fittsController, SLOT(cibleClicked(int,int)));

    // SpinBox values update
    connect(aValue,SIGNAL(valueChanged(double)),fittsController,SLOT(aValueChanged(double)));
    connect(bValue,SIGNAL(valueChanged(double)),fittsController,SLOT(bValueChanged(double)));
    connect(nbCible,SIGNAL(valueChanged(int)),fittsController,SLOT(nbCibleChanged(int)));
    connect(minSize,SIGNAL(valueChanged(int)),fittsController,SLOT(minSizeChanged(int)));
    connect(maxSize,SIGNAL(valueChanged(int)),fittsController,SLOT(maxSizeChanged(int)));
}




void drawCircle (center, size, sceneW, sceneH)
{
    qreal posX = qrand() % ((sceneW - size) - size) + size;
    qreal posY = qrand() % ((sceneH - size) - size) + size;
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}



*/


