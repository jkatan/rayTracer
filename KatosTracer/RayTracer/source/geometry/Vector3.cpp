#include "geometry/Vector3.h"

double Vector3::x() const
{
	return vector[0];
}

double Vector3::y() const
{
	return vector[1];
}

double Vector3::z() const
{
	return vector[2];
}

double Vector3::length() const
{
	return std::sqrt(lengthSquared());
}

double Vector3::lengthSquared() const
{
	return vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2];
}

Vector3 Vector3::operator-() const
{
	return Vector3(-vector[0], -vector[1], -vector[2]);
}

double Vector3::operator[](int i) const
{
	return vector[i];
}

double& Vector3::operator[](int i)
{
	return vector[i];
}

Vector3& Vector3::operator+=(const Vector3& otherVector)
{
	vector[0] += otherVector[0];
	vector[1] += otherVector[1];
	vector[2] += otherVector[2];

	return *this;
}

Vector3& Vector3::operator*=(const double scalar)
{
	vector[0] *= scalar;
	vector[1] *= scalar;
	vector[2] *= scalar;

	return *this;
}

Vector3& Vector3::operator/=(const double scalar)
{
	return *this *= 1/scalar;
}

Vector3 Vector3::operator+(const Vector3& otherVector) const
{
	return Vector3(vector[0] + otherVector.vector[0], vector[1] + otherVector.vector[1], vector[2] + otherVector.vector[2]);
}

Vector3 Vector3::operator-(const Vector3& otherVector) const
{
	return Vector3(vector[0] - otherVector.vector[0], vector[1] - otherVector.vector[1], vector[2] - otherVector.vector[2]);
}

Vector3 Vector3::operator*(const Vector3& otherVector) const
{
	return Vector3(vector[0] * otherVector.vector[0], vector[1] * otherVector.vector[1], vector[2] * otherVector.vector[2]);
}

Vector3 Vector3::operator*(double scalar) const
{
	return Vector3(vector[0] * scalar, vector[1] * scalar, vector[2] * scalar);
}

Vector3 Vector3::operator/(double scalar) const
{
	return *this * (1/scalar);
}

double Vector3::dotProduct(const Vector3& otherVector) const
{
	return vector[0] * otherVector.vector[0] + vector[1] * otherVector.vector[1] + vector[2] * otherVector[2];
}

Vector3 Vector3::crossProduct(const Vector3& otherVector) const
{
	return Vector3(vector[1] * otherVector.vector[2] - vector[2] * otherVector.vector[1],
		vector[2] * otherVector.vector[0] - vector[0] * otherVector.vector[2],
		vector[0] * otherVector.vector[1] - vector[1] * otherVector.vector[0]);
}

Vector3 Vector3::getNormalizedVector() const
{
	return *this / this->length();
}

Vector3 Vector3::random()
{
	return Vector3(getRandomDouble(), getRandomDouble(), getRandomDouble());
}

Vector3 Vector3::random(double min, double max)
{
	return Vector3(getRandomDouble(min, max), getRandomDouble(min, max), getRandomDouble(min, max));
}

Vector3 Vector3::randomUnitVector()
{
	double radians = getRandomDouble(0, 2*pi);
	double z = getRandomDouble(-1, 1);
	double root = sqrt(1 - z*z);
	return Vector3(root * cos(radians), root * sin(radians), z);
}

Vector3 Vector3::randomInUnitDisk()
{
	while (true)
	{
		Vector3 rand = Vector3(getRandomDouble(-1, 1), getRandomDouble(-1, 1), 0);
		if (rand.lengthSquared() < 1)
		{
			return rand;
		}
	}
}

Vector3 Vector3::reflect(const Vector3& vectorInNormalized, const Vector3& normal)
{
	return vectorInNormalized - 2 * vectorInNormalized.dotProduct(normal) * normal;
}

Vector3 Vector3::refract(const Vector3& vectorInNormalized, const Vector3& normal, double refractionCoeficient)
{
	double cosTheta = (-vectorInNormalized).dotProduct(normal);
	Vector3 refractedPerpendicularComponent = refractionCoeficient * (vectorInNormalized + cosTheta*normal);
	Vector3 refractedParallelComponent = -sqrt(fabs(1.0 - refractedPerpendicularComponent.lengthSquared())) * normal;
	return refractedParallelComponent + refractedPerpendicularComponent;
}

std::ostream& operator<<(std::ostream& outStream, const Vector3& vector)
{
	return outStream << '(' << vector[0] << ', ' << vector[1] << ', ' << vector[2] << ')';
}

Vector3 operator*(double scalar, const Vector3& vector)
{
	return vector * scalar;
}
