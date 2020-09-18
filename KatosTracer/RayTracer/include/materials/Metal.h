#pragma once
#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal : public Material
{
	public:
		Metal(const Color& metalAlbedo, double metalFuzziness) : albedo(metalAlbedo), fuzziness(metalFuzziness < 1 ? metalFuzziness : 1) {}

		virtual bool scatterRay(const Ray& incidentRay, const HitRecord& hitRecord, Color& attenuation, Ray& scatteredRay) const override;

	private:
		Color albedo;
		double fuzziness;
};

#endif
