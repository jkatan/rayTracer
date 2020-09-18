#pragma once
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{
	public:
		Lambertian(const Color& lambertianAlbedo) : albedo(lambertianAlbedo) {}

		virtual bool scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const override;

	private:
		Color albedo;
};

#endif
