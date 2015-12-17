//
//  ReconController.cpp
//  Group2_Final_Project2
//
//  Created by Group 2
//  08DEC15
//

#include "ReconControllerImpl.h"
#include "src/uavLogger/uavLogger.h"
#include "src/uavData/uavDataStruct.h"

ReconControllerImpl::ReconControllerImpl( automaticDutiesProvider* next_duty_provider )
{
  this->next_duty_provider = next_duty_provider;
}

ReconControllerImpl::~ReconControllerImpl()
{
}

void ReconControllerImpl::performMission( uavData* uav_data )
{
  if( uav_data->perform_mission )
  {
    if( uav_data->current_pic_count == max_pictures )
    {
      transmitPicture();
      uav_data->current_pic_count = 0;
      uav_data->perform_mission   = false;
    }
    else if( (uav_data->current_pic_count % 5) == 0 )
    {
      transmitPicture();
      takePicture();
      uav_data->current_pic_count++;
    }
    else
    {
      takePicture();
      uav_data->current_pic_count++;
    }
  }
}

void ReconControllerImpl::takePicture()
{
  uavLogger::getInstance()->log( "Taking picture" );
}

void ReconControllerImpl::transmitPicture()
{
  uavLogger::getInstance()->log( "Pictures are being transmitted" );
}

void ReconControllerImpl::performMissionDuty( uavData* uav_data )
{
  if( uav_data->mission_type == uavMissionModes::RECON_MISSION )
    performMission( uav_data );
  else
    next_duty_provider->performMissionDuty( uav_data );
}
