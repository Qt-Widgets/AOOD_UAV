#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "src/uavData/uavObject.h"

class MapController : public QGraphicsView
{
public:
    MapController();
    void mousePressEvent(QMouseEvent *event);

    void addUavToScene( uavObject* uav );
    void setPrimaryUav( uavObject* uav );

    QGraphicsScene * scene;

  private:

    uavObject* uav;
};

#endif // MAPCONTROLLER_H
