#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QElapsedTimer>
#include <QPointF>

class MainWindow;

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(class MainWindow * view);

private:
    QList<QPointF> clickPoints;
    QList<QPointF> circleCenters;
    QList<int> circleSizes;
    QList<qint64> times;

    QElapsedTimer *timer;


    void nextTarget();

    int circlesLeft;

public:

    double a;
    double b;

    int nbCircles;
    int minSize;
    int maxSize;

    MainWindow * view;

    void onCircleClick(QPointF point);
    void resetTest();
    void init();
    void computeGraph();

    int getCirclesLeft();
    bool isTestStarted();
    bool isInLastCircle(QPointF point);

};

#endif // MODEL_H
