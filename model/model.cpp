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

void model::computeGraph(){

    QList<QPointF> experimental = QList<QPointF>() ,theoric = QList<QPointF>();

    for(int i = 0; i < this->circleCenters.size(); ++i) {
        qreal D = sqrt(pow(this->clickPoints[i].x() - this->circleCenters[i].x(),2) + pow(this->clickPoints[i].y() - this->circleCenters[i].y(),2));
        qreal ID = log2( D/this->circleSizes[i] +1 );

        QPointF e = QPointF(ID,this->times[i]),t = QPointF(ID,this->b*ID + this->a);

        experimental.append(e);
        theoric.append(t);

    }

    /*
    QLineSeries *expSeries = new QLineSeries;
    expSeries->setName("Courbe expérimentale");
    QLineSeries *fittsSeries = new QLineSeries;
    fittsSeries->setName("Courbe théorique");
    QCategoryAxis *axis = new QCategoryAxis;

    QList<double> fittsValues;

    for(int i = 0; i < this->fittsModel->nbCible; ++i) {
        double T = this->fittsModel->times[i];
        expSeries->append(i,T);
        double D = sqrt(pow(this->fittsModel->clickPoints[i].x() - this->fittsModel->cercleCenter[i].x(),2) + pow(this->fittsModel->clickPoints[i].y() - this->fittsModel->cercleCenter[i].y(),2));

        // On multiplie par 100 pour être en ms
        double value = (this->fittsModel->a * 1000) + ((this->fittsModel->b * 1000) * log2((D / this->fittsModel->cercleSize[i]) + 1));
        fittsValues.append(value);
        fittsSeries->append(i,value);

        axis->append(QString::number(i + 1) + "<br />T: "+QString::number(T)+"<br />D: " + QString::number(D),i);
    }
    */
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
