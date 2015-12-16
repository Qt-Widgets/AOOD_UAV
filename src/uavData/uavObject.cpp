#include "uavObject.h"

#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsRectItem>


uavObject::uavObject(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set the graphics
    setPixmap(QPixmap(":/Pictures/pictures/uav.jpg"));


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

    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(go_to_target()));
    timer->start(1000);

    // set attack_dest
    travel_dest = QPointF(0,800);
}

uavObject::~uavObject() {}

void uavObject::go_to_target()
{
    this->setPos(x()-16,y()-16);


    QLineF ln(QPointF(x()-16,y()+16),travel_dest);
    int angle = -1 * ln.angle();

    this->setRotation(angle);
}
