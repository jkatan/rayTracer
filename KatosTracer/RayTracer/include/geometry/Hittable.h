#pragma once

#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"
#include "materials/Material.h"

class Material;

struct HitRecord
{
	Point3 hitPoint;
	Vector3 normalToSurfaceHit;
	shared_ptr<Material> material;
	double hitRayDistance;
	bool isNormalFrontFace;

	inline void setFaceNormal(const Ray& ray, const Vector3& outwardNormal)
	{
		isNormalFrontFace = ray.getDirection().dotProduct(outwardNormal) < 0;
		normalToSurfaceHit = isNormalFrontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
	public:
		virtual bool hit(const Ray& ray, double minDistance, double maxDistance, HitRecord& hitRecord) const = 0;
};

#endif