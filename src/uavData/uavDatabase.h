/*
 * uavDatabase.h
 *
 *  Created on: Dec 13, 2015
 *      Author: David
 */

#ifndef UAVDATABASE_H_
#define UAVDATABASE_H_

#include "uavObject.h"

class uavDatabase
{
  public:

    uavDatabase();
    virtual ~uavDatabase();

    uavObject* createUav( uavMissionModes::uavMissionTypesEnum mission );

    uavObject* getUavData( int uav_id );

  private:

    static const int max_uavs = 10;

    uavObject* uavs[ max_uavs + 1 ];
    int current_uav_id;
};

#endif /* UAVDATABASE_H_ */
