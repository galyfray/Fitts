#include "mainwindow.h"
#include "ui_mainwindow.h"

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

int getTestSceneWidth ()
{
    int sceneW = int(this->fittsView->scene->width());
    return sceneW;
}


int getTestSceneHeight ()
{
    int sceneH = int(this->fittsView->scene->height());
    return sceneH;
}
