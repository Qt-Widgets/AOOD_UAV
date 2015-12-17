/*
 * automaticDutiesProvider.h
 *
 *  Created on: Dec 9, 2015
 *      Author: dgwalthney
 */

#ifndef AUTOMATICDUTIESPROVIDER_H_
#define AUTOMATICDUTIESPROVIDER_H_

struct uavData;


///------------------------------------------
///  This class provides the interface for
///  classes to become part of the chain of
///  responsibility pattern. Each member of
///  the chain inherits this interface and
///  takes the next provider in at constructor.
///------------------------------------------
class automaticDutiesProvider
{
  public:

    virtual ~automaticDutiesProvider() {}

    ///-------------------------------------
    ///  Each member of the chain implements
    ///  this function. The mission type gets
    ///  passed in so that the right member
    ///  of the chain acts on it.
    ///-------------------------------------
    virtual void performMissionDuty( uavData* uav_data ) = 0;
};

#endif /* AUTOMATICDUTIESPROVIDER_H_ */
