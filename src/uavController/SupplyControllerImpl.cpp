//
//  SupplyController.cpp
//  Group2_Final_Project2
//
//  Created by Group 2
//  09DEC15
//

#include "SupplyControllerImpl.h"
#include "src/uavLogger/uavLogger.h"
#include "src/uavData/uavDataStruct.h"

SupplyControllerImpl::SupplyControllerImpl()
{
}

SupplyControllerImpl::~SupplyControllerImpl()
{
}
void SupplyControllerImpl::performMission( uavData* uav_data )
{
  if( uav_data->perform_mission )
  {
    dropSupply();
    uav_data->perform_mission = false;
  }
}

void SupplyControllerImpl::dropSupply()
{
  uavLogger::getInstance()->log( "Supplies are being dropped!" );
}

void SupplyControllerImpl::performMissionDuty( uavData* uav_data )
{
  if( uav_data->mission_type == uavMissionModes::SUPPLY_MISSION )
    performMission( uav_data );
  else
    uavLogger::getInstance()->log( "Unhandled Mission Type." );
}
