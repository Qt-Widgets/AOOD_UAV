/*
 * uavDatabase.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: David
 */

#include "uavDatabase.h"

uavDatabase::uavDatabase()
{
  current_uav_id = 0;
}

uavDatabase::~uavDatabase()
{
  for( int i = 0; i < current_uav_id; i++ )
    delete uavs[current_uav_id];
}

uavObject* uavDatabase::createUav( uavMissionModes::uavMissionTypesEnum mission )
{
  current_uav_id++;

  uavs[current_uav_id] = new uavObject();
  uavs[current_uav_id]->uav_data.mission_type = mission;

  return uavs[current_uav_id];
}

uavObject* uavDatabase::getUavData( int uav_id )
{
  return uavs[uav_id];
}
