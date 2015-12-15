#ifndef UAVBASECONTROLLER_H
#define UAVBASECONTROLLER_H

#include <QResizeEvent>
#include <QTimerEvent>
#include <QShowEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMap>
#include <QPixmap>
#include <QScrollArea>
#include <QAction>
#include <QList>
#include <QMultiHash>
#include <QShowEvent>
#include <QAnimationGroup>
#include "../uavData/uavDataStruct.h"

#define MAX_POWER_LEVEL        1000

class uavBaseController : public QWidget
{
    Q_OBJECT
public:
    uavBaseController( QWidget *parent = 0);
    ~uavBaseController();

    void Update( uavData* data );
    void rotateLeft(bool r);
    void rotateRight(bool r);
    void thrust(bool t);
    void brake(bool b);
    int brakeCount() const;

    void processUAV();

    double randDouble();
    int randInt(int range);

    virtual void resizeEvent( QResizeEvent* event);
    virtual void timerEvent( QTimerEvent * );

    void showEvent( QShowEvent * );

private:
    QGraphicsScene field;
    QGraphicsView view;
    QMap<int, QList<QPixmap> > animation;
    //AnimatedPixmapItem *uav;
    uavData* _uavData;
};

#endif // UAVBASECONTROLLER_H
