#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "geometry/Ray.h"

class Camera
{
	public:
		Camera(Point3 lookFrom, Point3 lookAt, Vector3 vectorUp, double verticalFOV, double aspectRatio, double aperture, double focusDistance);

		Ray getRay(double normalizedPixelPositionX, double normalizedPixelPositionY) const;

	private:
		Point3 origin;
		Point3 lowerLeftCorner;
		Vector3 horizontalVector;
		Vector3 verticalVector;
		// These vectors define the orthonormal basis that describes the camera's orientation
		Vector3 u, v, w;
		double lensRadius;
};

#endif
