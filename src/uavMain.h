/*
 * uavMain.h
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#ifndef UAVMAIN_H_
#define UAVMAIN_H_

#include "src/uavGui/uavButtonActions.h"
#include <QObject>

class uavDatabase;
class mapController;
class uavFactoryImpl;
class uavOperator;
class uavAutomaticOperator;
class uavUserOperator;
class uavObject;

class uavMain : public QObject,
                public uavButtonActions
{
  Q_OBJECT

  public:

    uavMain();
    virtual ~uavMain();

    virtual void switchPrimaryUav( int uav_id );
    virtual void switchOperator();

    virtual void fireMissile();
    virtual void fireGun();
    virtual void dropBomb();
    virtual void lockTarget();
    virtual void breakEngage();

    virtual void takePicture();
    virtual void transmitPictures();

    virtual void dropSupplies();

  public slots:

    void updateUavs();

  private:

    uavDatabase* uav_database;

    mapController* map_controller;

    uavFactoryImpl* uav_factory;
    uavAutomaticOperator* auto_operator;
    uavUserOperator*      user_operator;

    uavOperator* current_operator;
    uavObject*   current_uav;
};

#endif /* UAVMAIN_H_ */
