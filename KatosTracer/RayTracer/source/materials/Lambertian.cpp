#include "materials/Lambertian.h"

bool Lambertian::scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const
{
	const Vector3 scatterDirection = hitRecord.normalToSurfaceHit + Vector3::randomUnitVector();
	scatteredRay = Ray(hitRecord.hitPoint, scatterDirection);
	attenuation = albedo;
	return true;
}
