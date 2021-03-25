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
    QList<QPoint> clickPoints;
    QList<QPoint> circleCenters;
    QList<int> circleSizes;
    QList<qint64> times;

    QElapsedTimer *timer;

public slots:
    void onCircleClick(int x,int y);
};

#endif // MODEL_H
