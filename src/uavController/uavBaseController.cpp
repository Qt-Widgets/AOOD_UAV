#include "uavbasecontroller.h"


#define REFRESH_DELAY           33
#define SHIP_SPEED              0.3
#define SHIP_STEPS              64
#define ROTATE_RATE             2
#define BRAKE_ON_COST           4
#define MAX_SHIP_SPEED          12
#define MAX_BRAKES              5

#define PI_X_2                  6.283185307
#ifndef M_PI
#define M_PI 3.141592654
#endif

uavBaseController::uavBaseController(QWidget *parent)
    : QWidget( parent),
      field(0, 0, 640, 440),
      view(&field, this)
{
    _uavData->initialize();
}

uavBaseController::~uavBaseController()
{

}

void uavBaseController::Update( uavData* data)
{
     _uavData = data;
}

void uavBaseController::rotateLeft(bool r)
{
     _uavData->rotateL = r;
     _uavData->rotateSlow = 5;
}

void uavBaseController::rotateRight(bool r)
{
    _uavData->rotateR = r;
    _uavData->rotateSlow = 5;
}

void uavBaseController::thrust(bool t)
{
    _uavData->thrustUav = t && _uavData->uavPower > 0;
}

void uavBaseController::brake(bool b)
{
    if( !_uavData->initialized )
        return;
    if( _uavData->mBrakeCount )
    {
        if(_uavData->brakeUav && !b)
        {
            _uavData->rotateL = false;
            _uavData->rotateR = false;
            _uavData->thrustUav = false;
            _uavData->rotateRate = ROTATE_RATE;
        }

        _uavData->brakeUav = b;
    }
}

void uavBaseController::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    field.setSceneRect(0, 0, width()-4, height()-4);
    view.resize(width(),height());
}

void uavBaseController::timerEvent(QTimerEvent *)
{
    field.advance();
    //wrapSprite( ship );
}

void uavBaseController::showEvent(QShowEvent *e)
{
#if defined( QT_LICENSE_PROFESSIONAL )
    static bool wasThere = false;

    if ( !wasThere ) {
        wasThere = true;
#endif

    QWidget::showEvent( e );
}
