#include "geometry/Sphere.h"

bool Sphere::hit(const Ray& ray, double minDistance, double maxDistance, HitRecord& hitRecord) const
{
	Vector3 sphereCenterToRayOrigin = ray.getOrigin() - this->center;
	double a = ray.getDirection().lengthSquared();
	double simplifiedB = ray.getDirection().dotProduct(sphereCenterToRayOrigin);
	double c = sphereCenterToRayOrigin.lengthSquared() - this->radius * this->radius;
	double discriminant = simplifiedB * simplifiedB - a * c;

	if (discriminant > 0)
	{
		double discriminantRoot = std::sqrt(discriminant);

		double root = (-simplifiedB - discriminantRoot) / a;
		if (processHitInformation(ray, hitRecord, root, minDistance, maxDistance))
		{
			return true;
		}
		else
		{
			root = (-simplifiedB + discriminantRoot) / a;
			return processHitInformation(ray, hitRecord, root, minDistance, maxDistance);
		}
	}

	return false;
}

bool Sphere::processHitInformation(const Ray& ray, HitRecord& hitRecord, double hitRayDistance, double minDistance, double maxDistance) const
{
	if (hitRayDistance > minDistance && hitRayDistance < maxDistance)
	{
		hitRecord.hitRayDistance = hitRayDistance;
		hitRecord.hitPoint = ray.getPosition(hitRecord.hitRayDistance);
		Vector3 outwardNormal = (hitRecord.hitPoint - this->center) / this->radius;
		hitRecord.setFaceNormal(ray, outwardNormal);
		hitRecord.material = material;
		return true;
	}

	return false;
}
