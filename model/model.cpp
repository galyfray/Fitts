#include "model.h"
#include "view/mainwindow.h"
#include <math.h>

#include <tgmath.h>
#include <QPoint>

model::model(class MainWindow * view){
    this->view = view;
}

void model::onCircleClick(QPointF point){

    if(this->circleCenters.isEmpty()) {
        // Si vide alors premier click, on demarre le timer
        this->timer = new QElapsedTimer;
        timer->start();
    }else{
        this->times.append(this->timer->elapsed());
        this->timer->restart();
    }

    this->clickPoints.append(point);
    this->nextTarget();
}

void model::nextTarget() {

    this->view->updateTestMsg(this);

    if(this->circlesLeft == 0){
        this->computeGraph();
        return;
    }

    int size = qrand() % ((this->maxSize + 1) - this->minSize) + this->minSize;

    int sceneW = this->view->getTestSceneWidth();
    int sceneH = this->view->getTestSceneHeight();

    qreal x = qrand() % ((sceneW - size) - size) + size;
    qreal y = qrand() % ((sceneH - size) - size) + size;

    QPoint center = QPoint((int)x,(int)y);

    this->circleSizes.append(size);
    this->circleCenters.append(center);

    this->view->drawCircle(center,size);

    this->circlesLeft--;
}

void model::computeGraph(){

    QList<QPointF> experimental = QList<QPointF>() ,theoric = QList<QPointF>();

    for(int i = 0; i < this->circleCenters.size(); ++i) {
        qreal D = sqrt(pow(this->clickPoints[i].x() - this->circleCenters[i].x(),2) + pow(this->clickPoints[i].y() - this->circleCenters[i].y(),2));
        qreal ID = log2( D/this->circleSizes[i] +1 );

        QPointF e = QPointF(ID,this->times[i]),t = QPointF(ID,this->b*ID + this->a);

        experimental.append(e);
        theoric.append(t);

    }

    this->view->PrintResults(theoric,experimental);
}

int model::getCirclesLeft(){
    return this->circlesLeft;
}

void model::resetTest(){
    this->circleSizes.clear();
    this->circleCenters.clear();
    this->clickPoints.clear();
    this->times.clear();
    this->timer->invalidate();

    this->circlesLeft = this->nbCircles;

    this->view->drawCircle(QPoint(
                               this->view->getTestSceneWidth()/2,
                               this->view->getTestSceneHeight()/2
                               ),
                           this->maxSize
                           );
}

bool model::isTestStarted(){
    return !this->circleCenters.isEmpty();
}

bool model::isInLastCircle(QPointF point){
    return sqrt(pow(point.x() - this->circleCenters.last().x(),2) + pow(point.y() - this->circleCenters.last().y(),2)) <= (this->circleSizes.last() / 2);
}

void model::init(){
    this->a = 10;
    this->b = 10;

    this->maxSize = 150;
    this->minSize = 20;

    this->nbCircles = 10;
    this->circlesLeft = 10;

    this->view->drawCircle(QPoint(
                               this->view->getTestSceneWidth()/2,
                               this->view->getTestSceneHeight()/2
                               ),
                           this->maxSize
                           );
}
