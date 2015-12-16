/*
 * uavMain.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#include "uavMain.h"

uavMain::uavMain()
{
  uav_factory = new uavFactoryImpl();

  auto_operator = new uavAutomaticOperator();
  user_operator = new uavUserOperator(uav_factory);

}

uavMain::~uavMain()
{

}

void uavMain::switchPrimaryUav( int uav_id )
{

}

void uavMain::switchOperator()
{

}

void uavMain::fireMissile()
{
  user_operator->fireMissile();
}

void uavMain::fireGun()
{
  user_operator->fireGun();
}

void uavMain::dropBomb()
{
  user_operator->dropBomb();
}

void uavMain::lockTarget()
{
  user_operator->lockTarget();
}

void uavMain::breakEngage()
{
  user_operator->breakEngage();
}

void uavMain::takePicture()
{
  user_operator->takePicture();
}

void uavMain::transmitPictures()
{
  user_operator->transmitPictures();
}

void uavMain::dropSupplies()
{
  user_operator->dropSupplies();
}
