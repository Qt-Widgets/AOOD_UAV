/*
 * userButtonActions.h
 *
 *  Created on: Dec 10, 2015
 *      Author: dgwalthney
 */

#ifndef UAVBUTTONACTIONS_H_
#define UAVBUTTONACTIONS_H_


class uavButtonActions
{
  public:

    virtual ~uavButtonActions() {}

    virtual void startMission() = 0;
    virtual void switchPrimaryUav( int uav_id ) = 0;
    virtual void switchOperator() = 0;

    virtual void fireMissile() = 0;
    virtual void fireGun() = 0;
    virtual void dropBomb() = 0;
    virtual void lockTarget() = 0;
    virtual void breakEngage() = 0;

    virtual void takePicture() = 0;
    virtual void transmitPictures() = 0;

    virtual void dropSupplies() = 0;
};


#endif /* UAVBUTTONACTIONS_H_ */
