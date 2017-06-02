class Intersection
{
public:
	Intersection(bool intersect, float dist);
	~Intersection(void);
	bool GetDoesInteract();
	float GetDistance();
private:
	bool doesIntersect;
	float distance;
};