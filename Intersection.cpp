#include "Intersection.h"

Intersection::Intersection(bool intersect, float dist){
	doesIntersect = intersect;
	distance = dist;
}

Intersection::~Intersection(void){
	
}

bool Intersection::GetDoesInteract(){
	return doesIntersect;
}

float Intersection::GetDistance(){
	return distance;
}
