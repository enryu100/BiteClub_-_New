/**
* \
* @class Intersection.h
* @brief  stores data about collision, created for use with BoundBox 
* @author Ben Porter 
*/
class Intersection
{
public:
	/**
	* @brief default constructor for Intersection
	* @param intersect-bool, dist-float
	*/
	Intersection(bool intersect, float dist);
	/**
	* @brief default deconstructor for Intersection
	*/
	~Intersection(void);
	/**
	* @brief Getter for Does_interact
	* @return bool - Does-Interact
	*/
	bool GetDoesInteract();
	/**
	* @brief Getter for distance
	* @return float - Does-distance
	*/
	float GetDistance();
private:
	///bool meant to be used with BoundBoxes for collision
	bool doesIntersect;
	/// float distance
	float distance;
};