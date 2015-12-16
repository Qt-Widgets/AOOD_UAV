/*
 * uavUserOperator.h
 *
 *  Created on: Dec 10, 2015
 *      Author: dgwalthney
 */

#ifndef UAVUSEROPERATOR_H_
#define UAVUSEROPERATOR_H_

#include "uavOperator.h"

class uavFactory;
class SupplyController;
class ReconController;
class CombatController;

///-----------------------------------------
///  This class handles the user operations
///  of the UAV. It implements the userButtonActions
///  interface so that the GUI knows what buttons
///  actions can be done.
///-----------------------------------------
class uavUserOperator : public uavOperator
{
  public:

    uavUserOperator( uavFactory* uav_factory );
    virtual ~uavUserOperator();

    virtual void update();

    void fireMissile();
    void fireGun();
    void dropBomb();
    void lockTarget();
    void breakEngage();

    void takePicture();
    void transmitPictures();

    void dropSupplies();

  private:

    SupplyController* supply_controller;
    ReconController*  recon_controller;
    CombatController* combat_controller;
};

#endif /* UAVUSEROPERATOR_H_ */
