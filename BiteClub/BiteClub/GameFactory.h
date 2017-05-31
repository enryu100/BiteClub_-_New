#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H
 
/**
* \class GameFactory
* \author Brandon Lim
* A Game Factory Class. A class for the purpose of creating
* instances of other classes. Is somewhat simple currently,
* only supporting intances of GameObject, but can easily have
* other types added.
*/

#include <string>
#include <vector>
#include "GameObject.h"

/**
*\typedef Vector4f
* A 4-float vector array for storing position.
* An array of 4 floats for the purpose of
* storing object location.
*/
typedef float Vector4f[4];

//v1.0 - Relatively simple at this point
class GameFactory{
	public:
		//std::vector<GameObject> gameObjects; //don't know if this is needed... probably isn't
		/** 
		*\fn Create
		* Game Object Creator.
		* A function for creating GameObjects.
		* Receives unique defined type of 4 floats
		* as a parameter
		* @param pos the float position and facing direction of the object, stored in an array
		* @param type the type of the object, NPC, enemy, etc.
		* @param hgt the height of the object, with the origin in the front bottom left
		* @param wdt the width of the object, with the origin in the front bottom left
		* @param dpt the depth of the object, with the origin in the front bottom left
		* @return the newly created object
		**/
		GameObject Create(std::string type);
};

#endif