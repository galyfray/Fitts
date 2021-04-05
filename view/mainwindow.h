#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QStackedLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QLineSeries>
#include <QtCharts>
#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;

private slots:
    void on_actionQuitter_triggered();


private:
    Ui::MainWindow *ui;
    int getTestSceneHeight();
    int getTestSceneWidth();
    void initWindows(controller *control);
    void updateTestMsg(model *mod);

};
#endif // MAINWINDOW_H
