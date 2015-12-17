/*
 * uavMain.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#include "uavMain.h"
#include <QTimer>
#include "src/uavData/uavDatabase.h"
#include "mapController.h"
#include "src/uavFactory/uavFactoryImpl.h"
#include "src/uavOperator/uavOperator.h"
#include "src/uavOperator/uavAutomaticOperator.h"
#include "src/uavOperator/uavUserOperator.h"

uavMain::uavMain() : QObject()
{
  uav_database   = new uavDatabase();
  map_controller = new mapController();

  current_uav = uav_database->createUav( uavMissionModes::COMBAT_MISSION );
  map_controller->addUavToScene( current_uav );
  current_uav = uav_database->createUav( uavMissionModes::COMBAT_MISSION );
  map_controller->addUavToScene( current_uav );
  current_uav = uav_database->createUav( uavMissionModes::SUPPLY_MISSION );
  map_controller->addUavToScene( current_uav );
  current_uav = uav_database->createUav( uavMissionModes::RECON_MISSION );
  map_controller->addUavToScene( current_uav );

  uav_factory = new uavFactoryImpl();

  auto_operator = new uavAutomaticOperator( uav_factory->getDutiesProvider() );
  user_operator = new uavUserOperator( uav_factory );

  current_operator = auto_operator;
  current_uav      = uav_database->getUavData( 1 );
  map_controller->setPrimaryUav( current_uav );
  map_controller->show();
}

uavMain::~uavMain()
{
  delete uav_database;
  delete uav_factory;
  delete auto_operator;
  delete user_operator;
  current_operator = 0;
}

void uavMain::updateUavs()
{
  //We need a main loop that gets call every x seconds.
  current_uav->updatePosition();
  current_operator->update();
}

void uavMain::switchPrimaryUav( int uav_id )
{
  current_uav = uav_database->getUavData( uav_id );
  //set some classes with this.
  map_controller->setPrimaryUav( current_uav );
}

void uavMain::switchOperator()
{
  //switch current_operator pointer here.
}

void uavMain::fireMissile()
{
    // connect a timer to attack_target
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateUavs()));
    timer->start(1000);

  //user_operator->fireMissile();
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
