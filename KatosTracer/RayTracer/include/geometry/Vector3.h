#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>
#include "utilities/MathUtils.h"

class Vector3
{
	public:
		Vector3() : vector{0, 0, 0} {}
		Vector3(double x, double y, double z) : vector{x, y, z} {}

		double x() const;
		double y() const;
		double z() const;

		double length() const;
		double lengthSquared() const;

		Vector3 operator-() const;
		double operator[](int i) const;
		double& operator[](int i);

		Vector3& operator+=(const Vector3& otherVector);
		Vector3& operator*=(const double scalar);
		Vector3& operator/=(const double scalar);

		Vector3 operator+(const Vector3& otherVector) const;
		Vector3 operator-(const Vector3& otherVector) const;
		Vector3 operator*(const Vector3& otherVector) const;
		Vector3 operator*(double scalar) const;
		Vector3 operator/(double scalar) const;

		double dotProduct(const Vector3& otherVector) const;
		Vector3 crossProduct(const Vector3& otherVector) const;
		Vector3 getNormalizedVector() const;

		static Vector3 random();
		static Vector3 random(double min, double max);
		static Vector3 randomUnitVector();
		static Vector3 randomInUnitDisk();

		static Vector3 reflect(const Vector3& vectorInNormalized, const Vector3& normal);
		static Vector3 refract(const Vector3& vectorInNormalized, const Vector3& normal, double refractionCoeficient);

	private:
		double vector[3];
};

std::ostream& operator<<(std::ostream& outStream, const Vector3& vector);
Vector3 operator*(double scalar, const Vector3& vector);

using Point3 = Vector3;
using Color = Vector3;

#endif