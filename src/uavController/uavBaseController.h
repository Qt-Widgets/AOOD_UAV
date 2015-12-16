#ifndef UAVBASECONTROLLER_H
#define UAVBASECONTROLLER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "../uavData/uavDataStruct.h"

class uavBaseController : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    uavBaseController( QGraphicsItem *parent = 0);
    ~uavBaseController();

public slots:
    void go_to_target();

private:

    QGraphicsPolygonItem * collision_area;
    QPointF travel_dest;
};

#endif // UAVBASECONTROLLER_H
