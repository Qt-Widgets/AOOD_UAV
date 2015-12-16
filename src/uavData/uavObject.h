#ifndef UAVBASECONTROLLER_H
#define UAVBASECONTROLLER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "uavDataStruct.h"

class uavObject : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    uavObject( QGraphicsItem *parent = 0);
    ~uavObject();

    uavData uav_data;

public slots:

    void go_to_target();

private:

    QGraphicsPolygonItem * collision_area;
    QPointF travel_dest;
};

#endif // UAVBASECONTROLLER_H
