#ifndef LINEAR_INTERPOLATION_H
#define LINEAR_INTERPOLATION_H

// ����������� ���� ������� ��������� ������
using ValueProvider = float(*)();

// �������� ������������ ����� ����������, ����������� ����� �������� ������
float linearInterpolate(float a0, float a1, float w);

// ���������� ������������ ����� ����������, ����������� ����� �������� ������
float smoothInterpolate(float a0, float a1, float w);

#endif

