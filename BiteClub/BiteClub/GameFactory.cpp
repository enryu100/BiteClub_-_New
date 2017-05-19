#include "GameFactory.h"


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
GameObject GameFactory::Create(Vector4f pos, std::string type, float hgt, float wdt, float dpt){
	GameObject tmp = GameObject(pos, type, hgt, wdt, dpt);
	return tmp;
}

/** 
*\fn Create
* Game Object Creator.
* A function for creating GameObjects.
* Receives 4 floats separately as 
* parameters
* @param x x-coordinate position of the object
* @param y y-coordinate position of the object
* @param z z-coordinate position of the object
* @param dir the direction the object is facing
* @param type the type of the object, NPC, enemy, etc.
* @param hgt the height of the object, with the origin in the front bottom left
* @param wdt the width of the object, with the origin in the front bottom left
* @param dpt the depth of the object, with the origin in the front bottom left
* @return the newly created object
**/
GameObject GameFactory::Create(float x, float y, float z, float dir, std::string type, float hgt, float wdt, float dpt){
	GameObject tmp = GameObject(x, y, z, dir, type, hgt, wdt, dpt);
	return tmp;
}