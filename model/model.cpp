#include "model.h"
#include <math.h>

#include <QPoint>

model::model(QObject *parent) : QObject(parent){}

void model::onCircleClick(int x, int y){
    QPoint point = QPoint(x,y);

    if(this->circleCenters.isEmpty()) {
        // Si vide alors premier click, on demarre le timer
        this->timer = new QElapsedTimer;
        timer->start();
        this->clickPoints.append(point);
    }else if (sqrt(pow(point.x() - this->circleCenters.last().x(),2) + pow(point.y() - this->circleCenters.last().y(),2)) <= this->circleSizes.last() / 2){

    }
    /*
     * if(this->fittsModel->cercleCenter.isEmpty()) {


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
