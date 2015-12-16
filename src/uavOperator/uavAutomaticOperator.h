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

///-----------------------------------------
///  This class handles the automatic operations
///  of the UAV.
///-----------------------------------------
class uavAutomaticOperator : public uavOperator
{
  public:

    uavAutomaticOperator( automaticDutiesProvider* duties_provider );
    virtual ~uavAutomaticOperator();

    void update();

  private:

    automaticDutiesProvider* duties_provider;
};

#endif /* UAVAUTOMATICOPERATOR_H_ */
