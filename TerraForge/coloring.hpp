#ifndef COLORING_HPP
#define COLORING_HPP

#include "SFML/Graphics.hpp"
#include "coloringVariants.hpp"
#include "PerlinGenerator.hpp"

sf::Uint8* coloring(int windowHeight, int windowWidth, int GRID_SIZE, unsigned seed, float amplitudeModifier, float frequencyModifier, int octaves, int precision, int ColoringScheme);

#endif