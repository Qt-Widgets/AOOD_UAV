#ifndef UAVBASECONTROLLER_H
#define UAVBASECONTROLLER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include "uavDataStruct.h"

class uavObject : public QGraphicsPixmapItem
{

  public:

    uavObject( QGraphicsItem *parent = 0);
    ~uavObject();

    uavData uav_data;

    void updatePosition();

  private:

    QGraphicsPolygonItem * collision_area;
    QPointF travel_dest;
};

#endif // UAVBASECONTROLLER_H
