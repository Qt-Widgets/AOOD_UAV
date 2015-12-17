/*
 * uavAutomaticOperator.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: dgwalthney
 */

#include "uavAutomaticOperator.h"
#include "src/uavController/automaticDutiesProvider.h"
#include "src/uavLogger/uavLogger.h"
#include "src/uavData/uavDataStruct.h"

uavAutomaticOperator::uavAutomaticOperator(
                   automaticDutiesProvider* duties_provider )
{
  this->duties_provider = duties_provider;
}

uavAutomaticOperator::~uavAutomaticOperator()
{

}

void uavAutomaticOperator::update( uavData* uav_data )
{
  //uavLogger::getInstance()->log( "Performing Automatic Operator Update" );

  duties_provider->performMissionDuty( uav_data );
}
