#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QElapsedTimer>
#include <QPointF>

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);

private:
    QList<QPointF> clickPoints;
    QList<QPointF> circleCenters;
    QList<int> circleSizes;
    QList<qint64> times;

    QElapsedTimer *timer;

    int circlesLeft;

public:

    double a;
    double b;

    int nbCircles;
    int minSize;
    int maxSize;

    void onCircleClick(QPointF point);
    void nextTarget();
    void endTest();
    void resetTest();

    int getCirclesLeft();

};

#endif // MODEL_H
