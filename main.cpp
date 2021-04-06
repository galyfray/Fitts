#include "view/mainwindow.h"
#include "model/model.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow win;

    model mod(&win);
    mod.init();

    controller ctrl(&mod,&win);

    win.initWindows(&ctrl,&mod);
    win.show();

    return a.exec();
}
