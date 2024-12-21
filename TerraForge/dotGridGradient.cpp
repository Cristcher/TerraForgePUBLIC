#include "dotGridGradient.hpp"

float dotGridGradient(int ix, int iy, float x, float y, unsigned seed) {
    vector2 gradient = randomGradient(ix, iy, seed);
    //¬ычисление рассто€ни€ от пиксел€ до кра€ €чейки грида
    float dx = x - (float)ix;
    float dy = y - (float)iy;
    //—кал€рное произведение векторов дл€ получени€ необходимых значений
    return (dx * gradient.x + dy * gradient.y);
}