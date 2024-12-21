#ifndef PERLIN_GENERATOR_HPP
#define PERLIN_GENERATOR_HPP

#include "dotGridGradient.hpp"
#include "linearInterpolation.hpp"

float perlin(float x, float y, unsigned seed, float amplitudeModifier, float frequencyModifier, int octaves);

#endif