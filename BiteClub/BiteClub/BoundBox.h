/**
* \
* @class BoundBox.h
* @brief  creates AABB and makes a collision check between 2 AABBs 
* @author Ben Porter 
*/

#include "Types.h"
#include "Intersection.h"
class BoundBox
{
public:
	/**
	* @brief default constructor for BoundBoxes
	*/
	BoundBox();
	/**
	* @brief default constructor for BoundBoxes
	* @param min- types::Vector3D, max - types::Vector3D
	*/
	BoundBox(types::Vector3D min, types::Vector3D max);
	/**
	* @brief default deconstructor for BoundBoxes
	*/
	~BoundBox(void);
	/**
	* @brief checks for collisions between 2 BoundBoxes
	* @param other - BoundBox
	* @return Intersection
	*/
	Intersection IntersectAABB(const BoundBox other) const;
	/**
	* @brief getter for min_extents
	* @return Intersection
	*/
	types::Vector3D& GetMin_Extents();
	/**
	* @brief getter for max_extents
	* @return Intersection
	*/
	types::Vector3D& GetMax_Extents();
	/**
	* @brief setter for max_extents
	* @param types::Vector3D
	*/
	void setMax_Extents(types::Vector3D);
	/**
	* @brief setter for min_extents
	* @param types::Vector3D
	*/
	void setMin_Extents(types::Vector3D);
private:
	//these represent the 2 extreme corners
	///Represents the smallest corner on the box
	types::Vector3D min_extents;
	///Represents the maximum corner on the box
	types::Vector3D max_extents;

};