#include "GameObject.h"


/**
*\fn GameObject
* A Constructor for the GameObject Class.
* Constructor for the GameObject Class, receives
* position data as a Vector4f (as defined in GameObject.h)
* See below for the other Constructor.
* @see Vector4f
* @see GameObject::GameObject(float x, float y, float z, float dir, std::string typ, float hgt, float wdt, float dpt)
* @param pos the float position and facing direction of the object, stored in an array
* @param type the type of the object, NPC, enemy, etc.
* @param hgt the height of the object, with the origin in the front bottom left
* @param wdt the width of the object, with the origin in the front bottom left
* @param dpt the depth of the object, with the origin in the front bottom left
*/
GameObject::GameObject(Vector4f pos, std::string typ, float hgt, float wdt, float dpt){
	for(int i = 0; i < 4; i++){
		Position[i] = pos[i];
	}
	type = typ;
	height = hgt;
	width = wdt;
	depth = dpt;
}

/**
*\fn GameObject
* A Constructor for the GameObject Class.
* Constructor for the GameObject Class, receives
* position data as four separate float values
* See above for the other Constructor.
* @see Vector4f
* @see GameObject::GameObject(Vector4f pos, std::string typ, float hgt, float wdt, float dpt)
* @param x x-coordinate position of the object
* @param y y-coordinate position of the object
* @param z z-coordinate position of the object
* @param dir the direction the object is facing
* @param type the type of the object, NPC, enemy, etc.
* @param hgt the height of the object, with the origin in the front bottom left
* @param wdt the width of the object, with the origin in the front bottom left
* @param dpt the depth of the object, with the origin in the front bottom left
*/
GameObject::GameObject(float x, float y, float z, float dir, std::string typ, float hgt, float wdt, float dpt){
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	Position[3] = dir;
	type = typ;
	height = hgt;
	width = wdt;
	depth = dpt;
}

/**
* \fn setPosition
* A function for setting the position of the Object.
* Sets the position of the object, receiving a 
* Vector4f as the parameter. See below for counterpart
* @see GameObject::setPosition(float x, float y, float z, float dir)
* @param pos the float position and facing direction of the object, stored in an array
*/

void GameObject::setPosition(Vector4f pos){
	for(int i = 0; i < 4; i++){
		Position[i] = pos[i];
	}
}

/**
* \fn setPosition
* A function for setting the position of the Object.
* Sets the position of the object, receiving a 
* Vector4f as the parameter. See above for counterpart
* @see GameObject::setPosition(Vector4f pos)
* @param x x-coordinate position of the object
* @param y y-coordinate position of the object
* @param z z-coordinate position of the object
* @param dir the direction the object is facing
*/
void GameObject::setPosition(float x, float y, float z, float dir){
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	Position[3] = dir;
}

/**
* \fn setType
* Sets the type of object.
* A function for setting the
* type of the object.
* @param Type the type of the object. Currently has no validation.
*/
void GameObject::setType(std::string Type){
	type = Type;
}

/**
* \fn setHeight
* Sets the height of object.
* A function for setting the
* height of the object.
* @param hgt the height of the object.
*/
void GameObject::setHeight(float hgt){
	height = hgt;
}

/**
* \fn setWidth
* Sets the width of object.
* A function for setting the
* width of the object.
* @param wdt the width of the object.
*/
void GameObject::setWidth(float wdt){
	width = wdt;
}

/**
* \fn setDepth
* Sets the z-axis length of object.
* A function for setting the
* z-axis length of the object.
* @param dpt the depth of the object.
*/
void GameObject::setDepth(float dpt){
	depth = dpt;
}

/**
* \fn setTexture
* Sets the texture of the object.
* A function for setting the texture
* to be applied to the object.
* @param tex the filepath of the texture to be applied, relative to the executable
*/
void GameObject::setTexture(std::string tex){
	texture = tex;
}