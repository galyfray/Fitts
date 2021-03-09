#include "Model/fittsmodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    FittsModel *fittsModel = new FittsModel;

    return a.exec();
}
