#include "GameObject.h"



GameObject::GameObject(std::string Type){
	for(int i = 0; i<4; i++){
		Position[i] = 0;
	}
	type = Type;
}

void GameObject::setPosition(Vector4f pos){
	for(int i = 0; i < 4; i++){
		Position[i] = pos[i];
	}
}

void GameObject::setPosition(float x, float y, float z, float dir){
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	Position[3] = dir;
}

void GameObject::setType(std::string Type){
	type = Type;
}

void GameObject::setDimensionsY(float hgt){
	height = hgt;
}

void GameObject::setDimensionsX(float wdt){
	width = wdt;
}

void GameObject::setDimensionsZ(float dpt){
	depth = dpt;
}

void GameObject::setModID(int tex){
	modelID = tex;
}

void GameObject::setDimensions(float x, float y, float z){
	setDimensionsX(x);
	setDimensionsY(y);
	setDimensionsZ(z);
}