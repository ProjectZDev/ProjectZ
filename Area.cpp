#include "Area.h"


Area::Area(std::vector<Vec3*> cornersIn, bool collidableIn)
{
	corners = cornersIn;
	collidable = collidableIn;
}


Area::~Area(void)
{
	/* Beh�vs ej d� ~Position sk�ter destrueringen?
	for each (Position* corner in corners)
	{
		delete corner;
	}
	*/
}

std::vector<Vec3*> Area::getCorners()
{
	return corners;
}

void Area::setCorners(std::vector<Vec3*> cornersIn)
{
	corners = cornersIn;
}

unsigned long Area::getCornerCount()
{
	return corners.size();
}

std::string Area::getAreaType()
{
	if(getCornerCount() == 3)
		return "Triangle";
	else if(getCornerCount() == 4)
		return "Square";
	else
		return "Unidentified";
}