/*
 * uavDataStruct.h
 *
 *  Created on: Dec 13, 2015
 *      Author: David
 */

#ifndef UAVDATASTRUCT_H_
#define UAVDATASTRUCT_H_

#include "../uavController/MissionModes.h"
#include "string.h"

struct uavData
{
  int refreshRate;
  bool rotateL;
  bool rotateR;
  bool thrustUav;
  bool brakeUav;
  int shipAngle;
  int rotateSlow;
  int rotateRate;
  int uavPower;
  int mBrakeCount;
  double shipDx;
  double shipDy;
  int  textDy;
  int  mFrameNum;
  bool mPaused;
  int  mTimerId;
  bool return_to_base;
  bool night_vision_enabled;
  int uav_id;
  int missile_inventory;
  bool initialized;
  uavMissionModes::uavMissionTypesEnum mission_type;


  uavData()
  {
    initialize();
  }

  ~uavData() {}

  void initialize()
  {
    memset( this, 0,sizeof(*this) );
    missile_inventory = 5;
    mission_type = uavMissionModes::NO_MISSION;
  }

};


#endif /* UAVDATASTRUCT_H_ */
