#include <iostream>
#include "utilities/MathUtils.h"
#include "utilities/ColorUtils.h"
#include "geometry/Vector3.h"
#include "geometry/Ray.h"
#include "geometry/HittableList.h"
#include "geometry/Sphere.h"
#include "Camera.h"
#include "materials/Lambertian.h"
#include "materials/Metal.h"
#include "materials/Dielectric.h"

using std::shared_ptr;
using std::make_shared;

HittableList randomScene()
{
	HittableList world;

	shared_ptr<Lambertian> groundMaterial = make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
	world.add(make_shared<Sphere>(Point3(0, -1000, 0), 1000, groundMaterial));

	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			double randMaterialSelection = getRandomDouble();
			Point3 center(a + 0.9*getRandomDouble(), 0.2, b + 0.9*getRandomDouble());

			if ((center - Point3(4, 0.2, 0)).length() > 0.9)
			{
				shared_ptr<Material> sphereMaterial;

				if (randMaterialSelection < 0.8)
				{
					Color albedo = Color::random() * Color::random();
					sphereMaterial = make_shared<Lambertian>(albedo);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
				else if (randMaterialSelection < 0.95)
				{
					Color albedo = Color::random(0.5, 1);
					double fuzziness = getRandomDouble(0, 0.5);
					sphereMaterial = make_shared<Metal>(albedo, fuzziness);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
				else
				{
					sphereMaterial = make_shared<Dielectric>(1.5);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
			}
		}
	}

	shared_ptr<Material> material1 = make_shared<Dielectric>(1.5);
	world.add(make_shared<Sphere>(Point3(0, 1, 0), 1.0, material1));

	shared_ptr<Material> material2 = make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
	world.add(make_shared<Sphere>(Point3(-4, 1, 0), 1.0, material2));

	shared_ptr<Material> material3 = make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
	world.add(make_shared<Sphere>(Point3(4, 1, 0), 1.0, material3));

	return world;
}

Color computeRayColor(const Ray& ray, const Hittable& world, int depth)
{
	if (depth <= 0)
	{
		return Color(0, 0, 0);
	}

	HitRecord hitRecord;
	if (world.hit(ray, 0.001, infinity, hitRecord))
	{
		Ray scatteredRay;
		Color attenuation;
		if (hitRecord.material->scatterRay(ray, hitRecord, attenuation, scatteredRay))
		{
			return attenuation * computeRayColor(scatteredRay, world, depth-1);
		}

		return Color(0, 0, 0);
	}

	Vector3 normalizedRayDirection = ray.getDirection().getNormalizedVector();
	double blendParameter = 0.5 * (normalizedRayDirection.y() + 1.0);
	return (1.0 - blendParameter) * Color(1.0, 1.0, 1.0) + blendParameter * Color(0.5, 0.7, 1.0);
}

int main() {

	// Image settings

	const double aspectRatio = 3.0 / 2.0;
	const int imageWidth = 1200;
	const int imageHeight = static_cast<int>(imageWidth / aspectRatio);
	const int samplesPerPixel = 500;
	const int maxDepth = 50;

	// World settings

	HittableList world = randomScene();

	// Camera settings
	Point3 lookFrom(13, 2, 3);
	Point3 lookAt(0, 0, 0);
	Vector3 up(0, 1, 0);
	double focusDistance = 10.0;
	double aperture = 0.1;

	Camera camera(lookFrom, lookAt, up, 20.0, aspectRatio, aperture, focusDistance);

	// Render

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int i = imageHeight-1; i >= 0; i--)
	{
		int progressPercentage = ((imageHeight-i) / static_cast<double>(imageHeight))*100;
		std::cerr << "\rProgress: " << progressPercentage << "% - " << "Scanlines remaining: " << i << ' ' << std::flush;

		for (int j = 0; j < imageWidth; j++)
		{
			Color pixelColor(0, 0, 0);
			for (int sample = 0; sample < samplesPerPixel; sample++)
			{
				double normalizedPixelPositionX = (j + getRandomDouble()) / (imageWidth - 1);
				double normalizedPixelPositionY = (i + getRandomDouble()) / (imageHeight - 1);
				Ray ray = camera.getRay(normalizedPixelPositionX, normalizedPixelPositionY);
				pixelColor += computeRayColor(ray, world, maxDepth);
			}

			writeColor(std::cout, pixelColor, samplesPerPixel);
		}
	}

	std::cerr << "\nDone.\n";
}