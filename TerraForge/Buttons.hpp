#pragma warning(disable : 6031)

#ifndef BUTTONS_HPP
#define BUTTONS_HPP
#define _CRT_SECURE_NO_WARNINGS

#include "coloring.hpp"

#include "imgui.h"
#include "SFML/Graphics.hpp"

#include <chrono>
#include <cstdio>
#include <cstring>

// Функция для обработки кнопок и взаимодействия с интерфейсом ImGui
void Buttons(bool& updatePressed, std::chrono::steady_clock::time_point& lastUpdateTime, unsigned& seed, char* seedInput, sf::Uint8*& pixels, int windowHeight, int windowWidth, int& grid_size, float& amplitudeModifier, float& frequencyModifier, int& octaves, sf::Texture& texture, sf::RenderWindow& window, int& precision, int& ColoringScheme);

void loadSettings(const char* filename, unsigned& seed, int& grid_size, float& amplitudeModifier, float& frequencyModifier, int& octaves, int& precision, int& ColoringScheme, char* seedInput);

void saveSettings(const char* filename, unsigned seed, int grid_size, float amplitudeModifier, float frequencyModifier, int octaves, int precision, int ColoringScheme);

#endif // BUTTONS_HPP

