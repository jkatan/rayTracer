#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H

#include "geometry/Ray.h"
#include "geometry/Hittable.h"
#include "geometry/Vector3.h"

struct HitRecord;

class Material
{
	public:
		virtual bool scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const = 0;
};

#endif