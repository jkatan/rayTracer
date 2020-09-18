#include "geometry/Ray.h"

Point3 Ray::getOrigin() const
{
	return origin;
}

Vector3 Ray::getDirection() const
{
	return direction;
}

Point3 Ray::getPosition(double distance) const
{
	return origin + distance * direction;
}
