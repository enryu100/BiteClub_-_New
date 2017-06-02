#ifndef __WAYPOINT_H
#define __WAYPOINT_H

#include <vector>
using namespace std;

template <class vectorType>
class waypoint
{
private:
	vector<vectorType> waypoints;
public:
	void addWaypoint(const vectorType& wayPt);
	vectorType getWaypoint(unsigned short waypointNo) const;
	int getNumWaypoints(){return waypoints.size();}
};


template <class vectorType>
void waypoint<vectorType>::addWaypoint(const vectorType& wayPt)
{
	waypoints.push_back(wayPt);
}

template <class vectorType>
vectorType waypoint<vectorType>::getWaypoint(unsigned short waypointNo) const
{
 vectorType v;

	if(waypointNo >=0 && waypointNo < waypoints.size())
	{
		v=waypoints[waypointNo];
	}
 return v;
}

#endif