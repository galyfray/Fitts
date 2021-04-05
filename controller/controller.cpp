#include "controller.h"

controller::controller(class model* pmodel){
    this->pmodel = pmodel;
}

void controller::onClick(int x, int y){
    //TODO implement
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
