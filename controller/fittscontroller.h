#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include <QObject>
#include <QElapsedTimer>

class FittsView;
class FittsModel;

class FittsController : public QObject
{
    Q_OBJECT
public:
    FittsController(FittsView *fittsView, FittsModel *fittsModel);
    virtual ~FittsController() {}
    void start();

private:
    void initGame();
    void finish();
    void nextCible();

    void calculateResult();

    FittsModel *fittsModel;
    FittsView *fittsView;

    QElapsedTimer *timer;

private slots:
    void quit();
    void startSimulation();
    void backToSettings();
    void resultClicked();

    void aValueChanged(double value);
    void bValueChanged(double value);
    void nbCibleChanged(int value);
    void minSizeChanged(int value);
    void maxSizeChanged(int value);

    void cibleClicked(int x, int y);
};

#endif // FITTSCONTROLLER_H
