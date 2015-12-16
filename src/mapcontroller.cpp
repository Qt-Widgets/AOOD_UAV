#include "mapcontroller.h"

#include <QGraphicsScene>
#include "uavController/uavBaseController.h"

MapController::MapController()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // set the scene
    setScene(scene);

    // create a UAV
    uavBaseController * uav = new uavBaseController();
    uav->setPos(250,250);

    // add the tower to scene
    scene->addItem(uav);

    // alter window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


void MapController::mousePressEvent(QMouseEvent *event){


}
