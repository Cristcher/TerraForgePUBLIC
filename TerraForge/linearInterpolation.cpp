#include "linearInterpolation.hpp"

// �������� ������������ � �������������� �������� �������
float linearInterpolate(float a0, float a1, float w) {
    return a0 + w * (a1 - a0);
}

// ���������� ������������ � �������������� �������� �������
float smoothInterpolate(float a0, float a1, float w) {
    float smoothW = w * w * (3.0f - 2.0f * w);
    return a0 + smoothW * (a1 - a0);
}
