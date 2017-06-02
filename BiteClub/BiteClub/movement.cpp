#include "movement.h"
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
* Variables: curPos is the position vector of the current agent.                             *
*            targetPos is the vector of the target position.                                 *
*            curVelocity is the current velocity of the agent.                               *
*            timeElaspsed is the time elaspsed since last logic update.                      *
*            offset is the distance to stop prior to reaching the target.                    *
*********************************************************************************************/
bool Patrol(Vector3D &curPos, const Vector3D& targetPos, double timeElapsed)
{ 
	return true;
}


bool pursue(const types::Vector3D &evaderPos, types::Vector3D& pursuerPos, double timeElapsed)
{
	if(pursuerPos.x==evaderPos.x && pursuerPos.z==evaderPos.z){
		return true;
	}else if(evaderPos.x >pursuerPos.x){
		pursuerPos.x +=(float)(1*timeElapsed);
		return false;
	}else if(evaderPos.z >pursuerPos.z){
		pursuerPos.z +=(float)(1*timeElapsed);
		return false;
	}else if(evaderPos.x <pursuerPos.x){
		pursuerPos.x -=(float)(1*timeElapsed);
		return false;
	}else if(evaderPos.z <pursuerPos.z){
		pursuerPos.z -=(float)(1*timeElapsed);
		return false;
	}else {
		return false;
	}

}
//fov in degrees not radians
bool seeTarget(const types::Vector3D &patroller,const types::Vector3D& target, const types::Vector3D &patrollerVel,float coneDistance, float fov)
{

	return true;
}
