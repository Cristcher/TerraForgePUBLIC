#include "dotGridGradient.hpp"

float dotGridGradient(int ix, int iy, float x, float y, unsigned seed) {
    vector2 gradient = randomGradient(ix, iy, seed);
    //���������� ���������� �� ������� �� ���� ������ �����
    float dx = x - (float)ix;
    float dy = y - (float)iy;
    //��������� ������������ �������� ��� ��������� ����������� ��������
    return (dx * gradient.x + dy * gradient.y);
}