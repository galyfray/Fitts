#include "controller.h"
#include "view/mainwindow.h"
#include "view/ui_mainwindow.h"

controller::controller(class model* pmodel,class MainWindow * view){
    this->pmodel = pmodel;
    this->view = view;
}

void controller::onClick(int x, int y){
    //TODO implement
    QPointF p = this->view->ui->graphicsView->mapToScene(x,y);
    if(this->pmodel->isTestStarted() || this->pmodel->isInLastCircle(p)){
        this->pmodel->onCircleClick(p);
    }

    /*
    if(this->fittsModel->cercleCenter.isEmpty()) {
        // Si vide alors premier click, on demarre le timer
        this->timer = new QElapsedTimer;
        timer->start();

        // On démarre avec la première cible
        this->fittsModel->clickPoints.append(QPoint(x,y));
        this->nextCible();
    }
    else {
        QPointF coords = this->fittsView->graphicView->mapToScene(x,y);
        if(sqrt(pow(coords.x() - this->fittsModel->cercleCenter.last().x(),2) + pow(coords.y() - this->fittsModel->cercleCenter.last().y(),2)) <= this->fittsModel->cercleSize.last() / 2) {
            // On stock le temps de click
            this->fittsModel->times.append(timer->elapsed());
            // On restart le chrono
            timer->restart();

            // On stock la position du click
            this->fittsModel->clickPoints.append(QPoint(x,y));
            this->nextCible();
        }
    }
     */
}

void controller::onAChange(double value){
    this->pmodel->a = value;
}

void controller::onBChange(double value){
    this->pmodel->b = value;
}

void controller::onNbCibleChange(int value){
    this->pmodel->nbCircles = value;
    this->pmodel->resetTest();
}

void controller::onMinSizeChange(int value){
    this->pmodel->minSize = value;
}

void controller::onMaxSizeChange(int value){
    this->pmodel->maxSize = value;
}
