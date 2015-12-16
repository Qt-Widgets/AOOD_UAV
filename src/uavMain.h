/*
 * uavMain.h
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#ifndef UAVMAIN_H_
#define UAVMAIN_H_

#include "src/uavGui/uavButtonActions.h"
#include "src/uavFactory/uavFactoryImpl.h"
#include "src/uavOperator/uavAutomaticOperator.h"
#include "src/uavOperator/uavUserOperator.h"


class uavMain : public uavButtonActions
{
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

  private:

    uavFactoryImpl* uav_factory;
    uavAutomaticOperator* auto_operator;
    uavUserOperator*      user_operator;

};

#endif /* UAVMAIN_H_ */
