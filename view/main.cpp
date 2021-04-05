#include "mainwindow.h"
#include "model/model.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow win;
    model mod(&win);
    controller ctrl(&mod,&win);
    win.initWindows(&ctrl);
    win.show();
    return a.exec();
}
