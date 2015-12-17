#include "mapcontroller.h"

#include <QGraphicsScene>
#include <QTransform>
#include "uavLogger/uavLogger.h"
#include <sstream>

using namespace std;

mapController::mapController()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    // set the scene
    setScene(scene);

    setBackgroundBrush(QBrush(QImage(":/Pictures/pictures/Ny_satview.jpg")));
    // alter window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void mapController::mousePressEvent(QMouseEvent *event)
{
  //if left arrow
  //  uav->rotate
}

void mapController::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_Up:

        if(uav->uav_data.direction == 0)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(0);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 90)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(90);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 180)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(180);
            uav->transform().translate(-16, -16);
        }
        else if(uav->uav_data.direction == 270)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(270);
            uav->transform().translate(-16, -16);
        }

        uav->uav_data.Dy = -3;
        uav->uav_data.Dx = 0;

        uav->uav_data.direction = 0;
        break;

    case Qt::Key_Down:

        if(uav->uav_data.direction == 0)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(180);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 90)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(270);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 180)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(0);
            uav->transform().translate(-16, -16);
        }
        else if(uav->uav_data.direction == 270)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(90);
            uav->transform().translate(-16, -16);
        }

        uav->uav_data.Dy = 3;
        uav->uav_data.Dx = 0;

        uav->uav_data.direction = 180;
        break;

    case Qt::Key_Left:

        if(uav->uav_data.direction == 0)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(270);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 90)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(180);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 180)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(90);
            uav->transform().translate(-16, -16);
        }
        else if(uav->uav_data.direction == 270)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(0);
            uav->transform().translate(-16, -16);
        }

        uav->uav_data.Dy = 0;
        uav->uav_data.Dx = -3;


        uav->uav_data.direction = 270;
        break;

    case Qt::Key_Right:

        if(uav->uav_data.direction == 0)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(270);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 90)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(0);
            uav->transform().translate(-16, -16);
        }
        else if (uav->uav_data.direction == 180)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(90);
            uav->transform().translate(-16, -16);
        }
        else if(uav->uav_data.direction == 270)
        {
            uav->transform().translate(16, 16);
            uav->transform().rotate(180);
            uav->transform().translate(-16, -16);
        }

        uav->uav_data.Dy = 0;
        uav->uav_data.Dx = 3;

        uav->uav_data.direction = 90;
        break;

    default:
        uavLogger::getInstance()->log("INVALID KEY");
        break;
    }
}

void mapController::addUavToScene( uavObject* uav )
{
  uav->setPos(400,300);

  // add the tower to scene
  scene->addItem(uav);
}

void mapController::setPrimaryUav( uavObject* uav )
{
  this->uav = uav;
}
