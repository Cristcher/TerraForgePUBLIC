#include "PerlinGenerator.hpp"

// Функция для вычисления значения Перлин-шум в точке (x, y)
float perlin(float x, float y, unsigned seed, float amplitudeModifier, float frequencyModifier, int octaves) {
    float total = 0;        // Итоговое значение шума
    float frequency = 1;    // Начальная частота
    float amplitude = 1;    // Начальная амплитуда
    float maxAmplitude = 0; // Максимальная амплитуда для нормализации
    // Цикл по октавам
    for (int i = 0; i < octaves; i++) {
        // Определение целых координат сетки для текущей частоты
        int x0 = (int)(x * frequency);
        int y0 = (int)(y * frequency);
        int x1 = x0 + 1;
        int y1 = y0 + 1;

        // Определение дробных частей координат
        float sx = x * frequency - (float)x0;
        float sy = y * frequency - (float)y0;

        // Вычисление градиентного шума в углах сетки
        float n0 = dotGridGradient(x0, y0, x * frequency, y * frequency, seed);
        float n1 = dotGridGradient(x1, y0, x * frequency, y * frequency, seed);
        float ix0 = smoothInterpolate(n0, n1, sx);

        n0 = dotGridGradient(x0, y1, x * frequency, y * frequency, seed);
        n1 = dotGridGradient(x1, y1, x * frequency, y * frequency, seed);
        float ix1 = smoothInterpolate(n0, n1, sx);

        // Интерполяция между значениями по оси y
        float value = smoothInterpolate(ix0, ix1, sy);

        // Добавление значения текущей октавы к итоговому значению
        total += value * amplitude;

        // Обновление максимальной амплитуды
        maxAmplitude += amplitude;

        // Уменьшение амплитуды и увеличение частоты для следующей октавы
        amplitude *= amplitudeModifier;
        frequency *= frequencyModifier;
    }

    // Нормализация итогового значения
    return total / maxAmplitude;
}
