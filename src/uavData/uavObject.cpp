#include "uavObject.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPointF>
#include <QLineF>
#include <QGraphicsRectItem>


uavObject::uavObject(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    // set the graphics
    setPixmap(QPixmap(":/Pictures/pictures/blue_uav.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 30;
    for (size_t i = 0, n = points.size(); i < n; i++)
    {
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    collision_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF uav_center(x()+16,y()+16);
    QLineF ln(poly_center,uav_center);
    collision_area->setPos(x()+ln.dx(),y()+ln.dy());

    // set attack_dest
    //travel_dest = QPointF(800,0);
}

uavObject::~uavObject() {}

void uavObject::updatePosition()
{
    this->uav_data.width = this->x()+16;
    this->uav_data.height = this->y()+16;

    if(this->uav_data.operator_mode == 1)
    {
        this->setPos(x()+ uav_data.Dx, y() + uav_data.Dy);
    }

    if(this->uav_data.operator_mode == 2)
    {
        this->setPos(x()+ this->uav_data.randX, y() + this->uav_data.randY);
    }
}
