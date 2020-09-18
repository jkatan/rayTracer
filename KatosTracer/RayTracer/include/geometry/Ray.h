#pragma once

#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray
{
	public:
		Ray() {};
		Ray(const Point3& origin, const Vector3& direction) : origin(origin), direction(direction) {}

		Point3 getOrigin() const;
		Vector3 getDirection() const;
		Point3 getPosition(double distance) const;

	private:
		Point3 origin;
		Vector3 direction;
};

#endif