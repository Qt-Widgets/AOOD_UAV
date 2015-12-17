/*
 * uavAutomaticOperator.h
 *
 *  Created on: Dec 10, 2015
 *      Author: dgwalthney
 */

#ifndef UAVAUTOMATICOPERATOR_H_
#define UAVAUTOMATICOPERATOR_H_

#include "uavOperator.h"

class automaticDutiesProvider;
struct uavData;

///-----------------------------------------
///  This class handles the automatic operations
///  of the UAV.
///-----------------------------------------
class uavAutomaticOperator : public uavOperator
{
  public:

    uavAutomaticOperator( automaticDutiesProvider* duties_provider );
    virtual ~uavAutomaticOperator();

    virtual void update( uavData* uav_data );

  private:

    automaticDutiesProvider* duties_provider;
};

#endif /* UAVAUTOMATICOPERATOR_H_ */
