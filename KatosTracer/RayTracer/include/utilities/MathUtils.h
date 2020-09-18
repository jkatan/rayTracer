#pragma once

#ifndef MAIN_H
#define MAIN_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degreesToRadians(double degrees) 
{
    return degrees * pi / 180.0;
}

inline double getRandomDouble()
{
    return rand() / (RAND_MAX + 1.0);
}

inline double getRandomDouble(double min, double max)
{
    return min + (max - min) * getRandomDouble();
}

inline double clamp(double value, double min, double max)
{
    if (value < min)
    {
        return min;
    }

    if (value > max)
    {
        return max;
    }

    return value;
}

#endif