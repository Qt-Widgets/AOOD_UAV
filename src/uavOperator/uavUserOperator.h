/*
 * uavUserOperator.h
 *
 *  Created on: Dec 10, 2015
 *      Author: dgwalthney
 */

#ifndef UAVUSEROPERATOR_H_
#define UAVUSEROPERATOR_H_

#include "uavOperator.h"
#include "src/uavGui/uavButtonActions.h"

class uavFactory;
class SupplyController;
class ReconController;
class CombatController;
struct uavData;

///-----------------------------------------
///  This class handles the user operations
///  of the UAV. It implements the uavButtonActions
///  interface. Implementing that interface allows
///  for this class to be part of the proxy pattern.
///-----------------------------------------
class uavUserOperator : public uavOperator,
                        public uavButtonActions
{
  public:

    uavUserOperator( uavFactory* uav_factory );
    virtual ~uavUserOperator();

    virtual void update( uavData* uav_data );

    virtual void startMission() {}
    virtual void switchPrimaryUav( int uav_id ) {}
    virtual void switchOperator( int operatorMode ) {}

    virtual void fireMissile();
    virtual void fireGun();
    virtual void dropBomb();
    virtual void lockTarget();
    virtual void breakEngage();

    virtual void takePicture();
    virtual void transmitPictures();

    virtual void dropSupplies();

  private:

    SupplyController* supply_controller;
    ReconController*  recon_controller;
    CombatController* combat_controller;
};

#endif /* UAVUSEROPERATOR_H_ */
