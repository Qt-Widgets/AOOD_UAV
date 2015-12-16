/*
 * uavOperator.h
 *
 *  Created on: Dec 15, 2015
 *      Author: David
 */

#ifndef UAVOPERATOR_H_
#define UAVOPERATOR_H_


class uavOperator
{
  public:

    virtual ~uavOperator() {}

    virtual void update() = 0;
};

#endif /* UAVOPERATOR_H_ */
