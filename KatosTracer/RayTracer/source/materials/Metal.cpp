#include "materials/Metal.h"

bool Metal::scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const
{
	Vector3 reflectedDirection = Vector3::reflect(incidentRay.getDirection().getNormalizedVector(), hitRecord.normalToSurfaceHit);
	scatteredRay = Ray(hitRecord.hitPoint, reflectedDirection + fuzziness * Vector3::randomUnitVector());
	attenuation = albedo;
	return scatteredRay.getDirection().dotProduct(hitRecord.normalToSurfaceHit) > 0;
}
