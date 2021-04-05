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

class controller;
class model;

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
    Ui::MainWindow *ui;

    void initWindows(controller *control, model *mod);
    void updateTestMsg(model *mod);

    int getTestSceneHeight();
    int getTestSceneWidth();

    void drawCircle(QPoint center,int size);

private slots:
    void on_actionQuitter_triggered();


private:


};
#endif // MAINWINDOW_H
