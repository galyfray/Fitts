#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model/model.h"

class controller : public QObject
{
    Q_OBJECT
private:
    model* pmodel;
public:
    explicit controller(class model* model);

public slots:
    void onClick(int x, int y);
    void onAChange(double value);
    void onBChange(double value);
    void onNbCibleChange(int value);
    void onMinSizeChange(int value);
    void onMaxSizeChange(int value);

};

#endif // CONTROLLER_H
