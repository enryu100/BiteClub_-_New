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

		GameObject Create(Vector4f pos, std::string type, float hgt, float wdt, float dpt);
		GameObject Create(float x, float y, float z, float dir, std::string type, float hgt, float wdt, float dpt);
};

#endif