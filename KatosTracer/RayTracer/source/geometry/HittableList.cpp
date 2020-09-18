#include "geometry/HittableList.h"

HittableList::HittableList(shared_ptr<Hittable> hittableObject)
{
	add(hittableObject);
}

void HittableList::clear()
{
	this->hittableObjects.clear();
}

void HittableList::add(shared_ptr<Hittable> hittableObject)
{
	this->hittableObjects.push_back(hittableObject);
}

bool HittableList::hit(const Ray& ray, double minDistance, double maxDistance, HitRecord& hitRecord) const
{
	HitRecord currentHitRecord;
	bool isAHit = false;
	double closestHitDistance = maxDistance;

	for (const shared_ptr<Hittable>& hittableObject : hittableObjects)
	{
		if (hittableObject->hit(ray, minDistance, closestHitDistance, currentHitRecord))
		{
			isAHit = true;
			closestHitDistance = currentHitRecord.hitRayDistance;
			hitRecord = currentHitRecord;
		}
	}

	return isAHit;
}
