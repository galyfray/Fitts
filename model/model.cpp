#include "model.h"
#include <math.h>

#include <QPoint>

model::model(QObject *parent) : QObject(parent){}

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

    if(this->circlesLeft == 0){
        this->endTest();
        return;
    }

    int size = qrand() % ((this->maxSize + 1) - this->minSize) + this->minSize;

    int sceneW = 0;
    int sceneH = 0;

    qreal x = qrand() % ((sceneW - size) - size) + size;
    qreal y = qrand() % ((sceneH - size) - size) + size;

    QPointF center = QPointF(x,y);

    this->circleSizes.append(size);
    this->circleCenters.append(center);

    //TODO maj x,y pour prendre taille cercle
    //ajouter appelle a drawCircle.

    this->circlesLeft--;
    /*
     if(!this->fittsModel->cercleCenter.isEmpty())
        this->fittsModel->cibleLeft--;
    this->fittsView->updateTestMsg();

    QGraphicsScene *scene = this->fittsView->scene;
    scene->clear();

    // On stop si c'est finis
    if(this->fittsModel->cibleLeft == 0) {
        this->finish();
        return;
    }

    // On génère la taille du cercle rouge
    // qrand() % ((high + 1) - low) + low;
    int size = qrand() % ((this->fittsModel->maxSize + 1) - this->fittsModel->minSize) + this->fittsModel->minSize;
    // Car on veut le rayon
    // On place le cercle dans la scene (Attention faut pas qu'il soit en dehors du cadre)
    int sceneW = int(this->fittsView->scene->width());
    int sceneH = int(this->fittsView->scene->height());

    qreal posX = qrand() % ((sceneW - size) - size) + size;
    qreal posY = qrand() % ((sceneH - size) - size) + size;

    // On stock les infos sur le cercle
    this->fittsModel->cercleCenter.append(QPoint(int(posX),int(posY)));
    this->fittsModel->cercleSize.append(size);

    // On place le cercle
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
     */
}

void model::endTest(){}

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
}

bool model::isTestStarted(){
    return !this->circleCenters.isEmpty();
}

bool model::isInLastCircle(QPointF point){
    return sqrt(pow(point.x() - this->circleCenters.last().x(),2) + pow(point.y() - this->circleCenters.last().y(),2)) <= (this->circleSizes.last() / 2);
}
