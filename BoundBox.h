#include "Types.h"
#include "Intersection.h"
class BoundBox
{
public:
	BoundBox();
	BoundBox(types::Vector3D min, types::Vector3D max);
	~BoundBox(void);
	Intersection IntersectAABB(const BoundBox other) const;
	
	types::Vector3D& GetMin_Extents();
	types::Vector3D& GetMax_Extents();
	void setMax_Extents(types::Vector3D);
	void setMin_Extents(types::Vector3D);
private:
	//these represent the 2 extreme corners
	types::Vector3D min_extents;
	types::Vector3D max_extents;

};