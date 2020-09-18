#pragma once

#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <iostream>
#include "geometry/Vector3.h"
#include "MathUtils.h"

void writeColor(std::ostream& outputStream, const Color& color, int samplesPerPixel)
{
	double red = color.x();
	double green = color.y();
	double blue = color.z();

	double scale = 1.0 / samplesPerPixel;
	// Gamma correction for gamma = 2.0
	red = sqrt(scale * red);
	green = sqrt(scale * green);
	blue = sqrt(scale * blue);
	
	outputStream << static_cast<int>(255 * clamp(red, 0, 1)) << ' '
		<< static_cast<int>(255 * clamp(green, 0, 1)) << ' '
		<< static_cast<int>(255 * clamp(blue, 0, 1)) << '\n';
}

#endif