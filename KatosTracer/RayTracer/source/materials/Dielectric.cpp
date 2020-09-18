#include "materials/Dielectric.h"

bool Dielectric::scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const
{
	attenuation = Color(1.0, 1.0, 1.0);

	double refractionCoefficient = hitRecord.isNormalFrontFace ? (1.0 / refractionIndex) : refractionIndex;
	
	Vector3 normalizedIncidentDirection = incidentRay.getDirection().getNormalizedVector();
	double cosTheta = fmin((-normalizedIncidentDirection).dotProduct(hitRecord.normalToSurfaceHit), 1.0);
	double sinTheta = sqrt(1.0 - cosTheta*cosTheta);

	Vector3 scatterDirection;
	if (refractionCoefficient * sinTheta > 1.0)
	{
		scatterDirection = Vector3::reflect(normalizedIncidentDirection, hitRecord.normalToSurfaceHit);
	}
	else
	{
		double reflectionProbability = schlickAproximation(cosTheta, refractionCoefficient);
		if (getRandomDouble() < reflectionProbability)
		{
			scatterDirection = Vector3::reflect(normalizedIncidentDirection, hitRecord.normalToSurfaceHit);
		}
		else
		{
			scatterDirection = Vector3::refract(incidentRay.getDirection().getNormalizedVector(), hitRecord.normalToSurfaceHit, refractionCoefficient);
		}
	}

	scatteredRay = Ray(hitRecord.hitPoint, scatterDirection);
	return true;
}

double Dielectric::schlickAproximation(double cosine, double refractionCoefficient) const
{
	double r0 = (1 - refractionCoefficient) / (1 + refractionCoefficient);
	r0 = r0 * r0;
	return r0 + (1 - r0) * pow((1-cosine), 5);
}
