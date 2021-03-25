#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QElapsedTimer>

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

    int circlesLeft;
    int minSize;
    int maxSize;


    QElapsedTimer *timer;

public:
    void onCircleClick(QPointF point);
    void nextTarget();
    void endTest();
};

#endif // MODEL_H
