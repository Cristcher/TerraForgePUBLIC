#include "coloring.hpp"

sf::Uint8* coloring(int windowHeight, int windowWidth, int GRID_SIZE, unsigned seed, float amplitudeModifier, float frequencyModifier, int octaves, int precision, int ColoringScheme) {
    sf::Uint8* pixels = new sf::Uint8[windowWidth * windowHeight * 4];
    for (int x = 0; x < windowWidth; x++)
    {
        for (int y = 0; y < windowHeight; y++)
        {
            int index = (y * windowWidth + x) * 4;

            float calculationMax = 0;
            float calculationPersistence = 1;
            float amp = 1;

            for (int i = 0; i < precision; i++)
            {
                calculationMax += perlin(x * calculationPersistence / GRID_SIZE, y * calculationPersistence / GRID_SIZE, seed, amplitudeModifier, frequencyModifier, octaves) * amp;
                calculationPersistence *= 2;
                amp /= 2;
            }

            // Contrast
            calculationMax *= 1.2;

            // Clipping
            if (calculationMax > 1.0f)
                calculationMax = 1.0f;
            else if (calculationMax < -1.0f)
                calculationMax = -1.0f;

            switch (ColoringScheme) {
            case 0:
                colorScheme5(calculationMax, pixels, index); // Atlas
                break;
            case 1:
                colorScheme8(calculationMax, pixels, index); // Black & White
                break;
            case 2:
                colorScheme6(calculationMax, pixels, index); // Classic
                break;
            case 3:
                colorScheme7(calculationMax, pixels, index); // Heatmap
                break;
            case 4:
                colorScheme4(calculationMax, pixels, index); // Ocean blue
                break;
            case 5:
                colorScheme2(calculationMax, pixels, index); // Old palette
                break;
            case 6:
                colorScheme3(calculationMax, pixels, index); // Royal purple
                break;
            case 7:
                colorScheme1(calculationMax, pixels, index); // Soft green
                break;
            default:
                colorScheme1(calculationMax, pixels, index); // Default to Soft green
            }
        }
    }
    return pixels;
}