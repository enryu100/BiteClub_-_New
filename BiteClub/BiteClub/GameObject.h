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
		std::string texture; //Declares filepath of texture to be loaded on to the object.
		float height, width, depth; //Dimensions of the object, with the Origin in the BOTTOM LEFT

	public:
		//CONSTRUCTOR & DESTRUCTOR
		GameObject(Vector4f pos, std::string typ, float hgt, float wdt, float dpt);
		GameObject(float x, float y, float z, float dir, std::string typ, float hgt, float wdt, float dpt);

		//GET METHODS
		float getX(){ return Position[0]; }
		float getY(){ return Position[1]; }
		float getZ(){ return Position[2]; }
		float getDir(){ return Position[3]; }
		float getHeight(){ return height; }
		float getWidth(){ return width; }
		float getDepth(){ return depth; }
		std::string getType(){ return type; }
		std::string getTex(){ return texture; }

		//SET METHODS
		void setPosition(Vector4f pos);
		void setPosition(float x, float y, float z, float dir);
		void setHeight(float hgt);
		void setWidth(float wdt);
		void setDepth(float dpt);
		void setType(std::string Type);
		void setTexture(std::string tex);
};

#endif