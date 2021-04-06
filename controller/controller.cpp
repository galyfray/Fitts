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
    if(!this->pmodel->isTestStarted() || this->pmodel->isInLastCircle(p)){
        this->pmodel->onCircleClick(p);
    }
}

void controller::onAChange(double value){
    this->pmodel->a = value;
    if(this->pmodel->getCirclesLeft() == 0){
        this->pmodel->computeGraph();
    }
}

void controller::onBChange(double value){
    this->pmodel->b = value;
    if(this->pmodel->getCirclesLeft() == 0){
        this->pmodel->computeGraph();
    }
}

void controller::onNbCibleChange(int value){
    this->pmodel->nbCircles = value;
    if(!pmodel->isTestStarted()){
        this->pmodel->resetTest();
    }
}

void controller::onMinSizeChange(int value){
    this->pmodel->minSize = value;
    this->view->getTailleMaxSpin()->setMinimum(value);
}

void controller::onMaxSizeChange(int value){
    this->pmodel->maxSize = value;
    this->view->getTailleMinSpin()->setMaximum(value);
}
