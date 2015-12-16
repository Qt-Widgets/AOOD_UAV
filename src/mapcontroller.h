#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QGraphicsView>
#include <QMouseEvent>

class MapController : public QGraphicsView
{
public:
    MapController();
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene * scene;
};

#endif // MAPCONTROLLER_H
