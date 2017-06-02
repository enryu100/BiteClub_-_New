#include "BoundBox.h"

BoundBox::BoundBox(){

}

BoundBox::BoundBox(types::Vector3D min, types::Vector3D max){
	min_extents = min;
	max_extents = max;
}



BoundBox::~BoundBox(void){
	
}
//could return an intersect, don't need to however
Intersection BoundBox::IntersectAABB( BoundBox other) const{
	types::Vector3D distances;// = other.GetMin_Extents() - max_extents;
	distances.x = other.GetMin_Extents().x - max_extents.x;
	distances.y = other.GetMin_Extents().y - max_extents.y;
	distances.z = other.GetMin_Extents().z - max_extents.z;

	types::Vector3D distances2;


	distances2.x = min_extents.x - other.GetMax_Extents().x;
	distances2.y = min_extents.y - other.GetMax_Extents().y;
	distances2.z = min_extents.z - other.GetMax_Extents().z;
	types::Vector3D distance = distances.max(distances2);

	float maxDistance = distance.max();
	/*
	if(maxDistance<0){
		return true;
	}else{
		return false;
	}
	*/
	return Intersection(maxDistance >0, maxDistance);
}

types::Vector3D& BoundBox::GetMin_Extents(){
	return min_extents;
}

types::Vector3D& BoundBox::GetMax_Extents(){
	return max_extents;
}

void BoundBox::setMax_Extents(types::Vector3D max){
	max_extents = max;
}

void BoundBox::setMin_Extents(types::Vector3D min){
	min_extents = min;
}