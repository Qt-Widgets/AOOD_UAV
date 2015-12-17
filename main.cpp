#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "mainwindow.h"
#include "src/uavMain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    uavMain* uav_main = new uavMain();

    MainWindow w;
    w.initialize(uav_main);
    w.show();
    return a.exec();
}
