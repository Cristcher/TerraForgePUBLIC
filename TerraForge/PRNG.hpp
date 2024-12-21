#ifndef PRNG_Gradient_HPP
#define PRNG_Gradient_HPP

#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>

//Структурная составляющая 2д-вектора
typedef struct {
    float x, y;
} vector2;

vector2 randomGradient(int ix, int iy, unsigned seed);

#endif