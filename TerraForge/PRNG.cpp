#include "PRNG.hpp"

vector2 randomGradient(int ix, int iy, unsigned seed) {
    // ������ ��������� ��������� �����
    unsigned w = 32;
    unsigned s = w / 2;
    unsigned a = ix + seed, b = iy + seed;
    a *= 3686283654;
    b ^= a << s | a >> w - s;
    b *= 3296336263;
    a ^= b << s | b >> w - s;
    a *= 7387827837;
    float randomTurn = a * (3.14159265 / ~(~0u >> 1)); // [0, 2*Pi]

    // ��������� ������� �� ��������� ���������
    vector2 mainVector;
    mainVector.x = sin(randomTurn);
    mainVector.y = cos(randomTurn);
    return mainVector;
}
