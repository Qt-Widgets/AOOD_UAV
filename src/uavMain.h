/*
 * uavMain.h
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#ifndef UAVMAIN_H_
#define UAVMAIN_H_

#include "src/uavGui/uavButtonActions.h"

class uavDatabase;
class uavFactoryImpl;
class uavOperator;
class uavAutomaticOperator;
class uavUserOperator;
struct uavData;

class uavMain : public uavButtonActions
{
  public:

    uavMain();
    virtual ~uavMain();

    void update();

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

  private:

    uavDatabase* uav_database;

    uavFactoryImpl* uav_factory;
    uavAutomaticOperator* auto_operator;
    uavUserOperator*      user_operator;

    uavOperator* current_operator;
    uavData*     current_uav_data;
};

#endif /* UAVMAIN_H_ */
