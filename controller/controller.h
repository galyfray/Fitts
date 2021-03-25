#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model/model.h"

class controller : public QObject
{
    Q_OBJECT
private:
    model* model;
public:
    explicit controller(class model* model);

public slots:
    void onClick(int x, int y);

};

#endif // CONTROLLER_H
