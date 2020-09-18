#pragma once

#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"
#include "Vector3.h"

class Sphere : public Hittable
{
	public:
		Sphere() : center(Point3(0, 0, 0)), radius(0.0) {};
		Sphere(const Point3& sphereCenter, double sphereRadius, shared_ptr<Material> sphereMaterial) : center(sphereCenter), radius(sphereRadius), material(sphereMaterial) {};

		virtual bool hit(const Ray& ray, double minDistance, double maxDistance, HitRecord& hitRecord) const override;

	private:
		bool processHitInformation(const Ray& ray, HitRecord& hitRecord, double hitRayDistance, double minDistance, double maxDistance) const;

		Point3 center;
		double radius;
		shared_ptr<Material> material;
};

#endif