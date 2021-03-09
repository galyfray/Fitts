#include "fittsmodel.h"
#include "../view/fittsview.h"

FittsModel::FittsModel() {
    this->fittsView = new FittsView(this);
}
