#include "PerlinGenerator.hpp"

// ������� ��� ���������� �������� ������-��� � ����� (x, y)
float perlin(float x, float y, unsigned seed, float amplitudeModifier, float frequencyModifier, int octaves) {
    float total = 0;        // �������� �������� ����
    float frequency = 1;    // ��������� �������
    float amplitude = 1;    // ��������� ���������
    float maxAmplitude = 0; // ������������ ��������� ��� ������������
    // ���� �� �������
    for (int i = 0; i < octaves; i++) {
        // ����������� ����� ��������� ����� ��� ������� �������
        int x0 = (int)(x * frequency);
        int y0 = (int)(y * frequency);
        int x1 = x0 + 1;
        int y1 = y0 + 1;

        // ����������� ������� ������ ���������
        float sx = x * frequency - (float)x0;
        float sy = y * frequency - (float)y0;

        // ���������� ������������ ���� � ����� �����
        float n0 = dotGridGradient(x0, y0, x * frequency, y * frequency, seed);
        float n1 = dotGridGradient(x1, y0, x * frequency, y * frequency, seed);
        float ix0 = smoothInterpolate(n0, n1, sx);

        n0 = dotGridGradient(x0, y1, x * frequency, y * frequency, seed);
        n1 = dotGridGradient(x1, y1, x * frequency, y * frequency, seed);
        float ix1 = smoothInterpolate(n0, n1, sx);

        // ������������ ����� ���������� �� ��� y
        float value = smoothInterpolate(ix0, ix1, sy);

        // ���������� �������� ������� ������ � ��������� ��������
        total += value * amplitude;

        // ���������� ������������ ���������
        maxAmplitude += amplitude;

        // ���������� ��������� � ���������� ������� ��� ��������� ������
        amplitude *= amplitudeModifier;
        frequency *= frequencyModifier;
    }

    // ������������ ��������� ��������
    return total / maxAmplitude;
}
