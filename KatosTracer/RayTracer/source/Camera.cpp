#include "Camera.h"

Camera::Camera(Point3 lookFrom, Point3 lookAt, Vector3 vectorUp, double verticalFOV, double aspectRatio, double aperture, double focusDistance)
{
	double theta = degreesToRadians(verticalFOV);
	double halfHeight = tan(theta / 2);

	double viewportHeight = halfHeight * 2.0;
	double viewportWidth = aspectRatio * viewportHeight;

	w = (lookFrom - lookAt).getNormalizedVector();
	u = vectorUp.crossProduct(w).getNormalizedVector();
	v = w.crossProduct(u);

	origin = lookFrom;
	horizontalVector = focusDistance * viewportWidth * u;
	verticalVector = focusDistance * viewportHeight * v;
	lowerLeftCorner = origin - horizontalVector / 2 - verticalVector / 2 - focusDistance * w;

	lensRadius = aperture / 2;
}

Ray Camera::getRay(double normalizedPixelPositionX, double normalizedPixelPositionY) const
{
	Vector3 randomVector = lensRadius * Vector3::randomInUnitDisk();
	Vector3 originOffset = u * randomVector.x() + v * randomVector.y();

	return Ray(origin + originOffset, lowerLeftCorner + normalizedPixelPositionX * horizontalVector + normalizedPixelPositionY * verticalVector - origin - originOffset);
}
