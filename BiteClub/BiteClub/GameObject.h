#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


/**
* \class GameObject
* \author Brandon Lim
* A Game Object Class. A class that stores the different data
* about a game object, whether it be an NPC, an enemy, or
* something else.
*/
#include <string>

/**
*\typedef Vector4f
* A 4-float vector array for storing position.
* An array of 4 floats for the purpose of storing
* object location.
*/
typedef float Vector4f[4];
class GameObject {
	private:
		Vector4f Position; //4 floats. Contains x,y,z coords, and direction angle
		std::string type; //Declares object type. NPC, enemy, boss, obstacle, etc.
		//Rendering information goes here:
		int modelID; //Declares Identifier of modelID to be loaded on to the object.
		float height, width, depth; //Dimensions of the object, with the Origin in the BOTTOM LEFT

	public:
		//CONSTRUCTOR
		/**
		*\fn GameObject
		* A Constructor for the GameObject Class.
		* Constructor for the GameObject Class. Sets enemy to default
		* @param type the type of the object, NPC, enemy, etc.
		*/
		GameObject(std::string Type);

		//GET METHODS
		float getX(){ return Position[0]; }
		float getY(){ return Position[1]; }
		float getZ(){ return Position[2]; }
		float getDir(){ return Position[3]; }
		float getHeight(){ return height; }
		float getWidth(){ return width; }
		float getDepth(){ return depth; }
		std::string getType(){ return type; }
		int getModID(){ return modelID; }

		//SET METHODS
		/**
		* \fn setPosition
		* A function for setting the position of the Object.
		* Sets the position of the object, receiving a 
		* Vector4f as the parameter. See below for counterpart
		* @see GameObject::setPosition(float x, float y, float z, float dir)
		* @param pos the float position and facing direction of the object, stored in an array
		*/
		void setPosition(Vector4f pos);
		/**
		* \fn setPosition
		* A function for setting the position of the Object.
		* Sets the position of the object, receiving a 
		* Vector4f as the parameter. See above for counterpart
		* @see GameObject::setPosition(Vector4f pos)
		* @param x x-coordinate position of the object
		* @param y y-coordinate position of the object
		* @param z z-coordinate position of the object
		* @param dir the direction the object is facing, range is from 0 along the z-axis, to 359.9 clockwise
		*/
		void setPosition(float x, float y, float z, float dir);
		/**
		* \fn setDimensionsY
		* Sets the height of object.
		* A function for setting the
		* height of the object.
		* @param hgt the height of the object.
		*/
		void setDimensionsY(float hgt);
		/**
		* \fn setDimensionsX
		* Sets the width of object.
		* A function for setting the
		* width of the object.
		* @param wdt the width of the object.
		*/
		void setDimensionsX(float wdt);
		/**
		* \fn setDimensionsZ
		* Sets the z-axis length of object.
		* A function for setting the
		* z-axis length of the object.
		* @param dpt the depth of the object.
		*/
		void setDimensionsZ(float dpt);
		/**
		* \fn setDimensions
		* Sets the 3 dimensions of the object.
		* A function for setting the
		* dimensions of the object.
		* @param x the width of the object.
		* @param y the height of the object.
		* @param z the depth of the object.
		*/
		void setDimensions(float x, float y, float z);
		/**
		* \fn setType
		* Sets the type of object.
		* A function for setting the
		* type of the object.
		* @param Type the type of the object. Currently has no validation.
		*/
		void setType(std::string Type);
		/**
		* \fn setModID
		* Sets the modelID of the object.
		* A function for setting the modelID
		* to be applied to the object.
		* @param tex the modelID of the object
		*/
		void setModID(int tex);
};

#endif