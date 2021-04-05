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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication :: quit();
}

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


int getTestSceneWidth()
{
    int sceneW = int(this->fittsView->scene->width());
    return sceneW;
}


int getTestSceneHeight()
{
    int sceneH = int(this->fittsView->scene->height());
    return sceneH;
}


void drawCircle (center, size, sceneW, sceneH)
{
    qreal posX = qrand() % ((sceneW - size) - size) + size;
    qreal posY = qrand() % ((sceneH - size) - size) + size;
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

void FittsView::initWindows() {

    graphicsView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene;
    graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    graphicsView->setScene(scene);
    scene->setSceneRect(0,0,graphicView->width(),300);

    nbCible->setValue(this->fittsModel->nbCible);
    nbCible->setMaximum(100);

    minSize->setMaximum(1000);
    minSize->setValue(this->fittsModel->minSize);

    maxSize->setMaximum(1000);
    maxSize->setValue(this->fittsModel->maxSize);

    aValue->setValue(this->fittsModel->a);
    bValue->setValue(this->fittsModel->b);

}

void FittsView::updateTestMsg() {
    this->nbciblesr->setText("<strong>Le test commencera après avoir appuyé sur la cible bleu.</strong> Nombre de cibles restantes : " + QString::number(this->fittsModel->cibleLeft));
}

*/


