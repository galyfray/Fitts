#include "fittsmodel.h"
#include "../View/fittsview.h"

FittsModel::FittsModel() {
    this->fittsView = new FittsView(this);
}
