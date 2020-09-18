#pragma once

#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "Material.h"

class Dielectric : public Material
{
	public:
		Dielectric(double refractionIndex) : refractionIndex(refractionIndex) {}

		virtual bool scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const override;

	private:
		double schlickAproximation(double cosine, double refractionCoefficient) const;

		double refractionIndex;
};

#endif
