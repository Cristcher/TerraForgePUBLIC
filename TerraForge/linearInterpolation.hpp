#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

// ќпределение типа функции обратного вызова
using ValueProvider = float(*)();

// Ћинейна€ интерпол€ци€ между значени€ми, полученными через обратные вызовы
float linearInterpolate(float a0, float a1, float w);

// —глаженна€ интерпол€ци€ между значени€ми, полученными через обратные вызовы
float smoothInterpolate(float a0, float a1, float w);

#endif

