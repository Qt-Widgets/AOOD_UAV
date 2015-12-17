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
#include <qglobal.h>

struct uavData
{
  int refreshRate;
  int shipAngle;
  int mBrakeCount;
  double Dx;
  double Dy;
  double Ax;
  double Ay;
  double width;
  double height;
  bool return_to_base;
  bool night_vision_enabled;
  int uav_id;
  int missile_inventory;
  int current_pic_count;
  int direction;
  int randX;
  int randY;
  //Auto = 1 Man = 2
  int operator_mode;
  bool initialized;
  bool perform_mission;
  uavMissionModes::uavMissionTypesEnum mission_type;


  uavData()
  {
    initialize();
  }

  ~uavData() {}

  void initialize()
  {
    //srand(time(0));
    memset( this, 0,sizeof(*this) );
    missile_inventory = 5;
    mission_type = uavMissionModes::NO_MISSION;
    operator_mode = 2;
    qsrand(qrand());
    randX = qrand()%((3+1)+3)-3;
    randY = qrand()%((3+1)+3)-3;
  }

};


#endif /* UAVDATASTRUCT_H_ */
