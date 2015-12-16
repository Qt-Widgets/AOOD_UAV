#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "mainwindow.h"
#include "src/uavMain.h"
#include "src/uavMath/myrect.h"
#include "src/mapController.h"


MapController *mapCtrl;

int main(int argc, char *argv[])
{
    uavMain* uav_main = new uavMain();

    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create an item to put into scene
    //MyRect * rect = new MyRect();
    //rect->setRect(0,0,100,100);

    // add the item to the scene
    //scene->addItem(rect);

    //make rect focusable
    //rect->setFlag(QGraphicsItem::ItemIsFocusable);
    //rect->setFocus();

    mapCtrl = new MapController();
    mapCtrl->show();

    // add a view
   // QGraphicsView * view = new QGraphicsView();
   // view->setScene(scene);
    //view->show();


    MainWindow w;
    w.initialize(uav_main);
    w.show();
    return a.exec();
}
