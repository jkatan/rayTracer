#pragma once

#ifndef HITTABLE_LIST
#define HITTABLE_LIST

#include "Hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable
{
	public:
		HittableList() {};
		HittableList(shared_ptr<Hittable> hittableObject);

		void clear();
		void add(shared_ptr<Hittable> hittableObject);

		virtual bool hit(const Ray& ray, double minDistance, double maxDistance, HitRecord& hitRecord) const override;


	private:
		std::vector<shared_ptr<Hittable>> hittableObjects;
};

#endif
