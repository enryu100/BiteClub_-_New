#ifndef __MOVEMENT_H
#define __MOVEMENT_H

#include "Types.h"
using namespace types;
/*********************************************************************************************
* Moves an object located at curpos and travelling at curVelocity towards targetPos. This    *
* function changes the curPos and curVelocity to steer it towards targetPos over time. The   *
* time factor is specified by timeElasped which should be the current time in the game loop  *
* timer. 20ms is a reasonable update time.                                                   *
* Pre: all vars are assigned values.                                                         *
* Post: curPos and curVelocity are updated to incrementally move towards targetPos. curPos   *
*       will be equal to targetPos if the object has reached the target.                     *
* Returns: true if target has reached targetPos, otherwise false.                            *
*********************************************************************************************/
bool Patrol(Vector3D &curPos, const Vector3D& targetPos,Vector3D& curVelocity, double timeElapsed,double offset=0);
bool pursue(const Vector3D &evaderPos, Vector3D& pursuerPos,const Vector3D& evaderVelocity, Vector3D& pursuerVelocity, double timeElapsed,double offset);
bool seeTarget(const Vector3D &patroller,const Vector3D& target, const Vector3D &patrollerVel,float coneDistance, float coneRadius);

#endif