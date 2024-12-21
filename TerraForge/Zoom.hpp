#ifndef ZOOM_HPP
#define ZOOM_HPP

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom, float& currentZoom, float maxZoom, float minZoom, const sf::FloatRect& textureBounds);

void ZoomEvent(float& currentZoom, float maxZoom, float minZoom, sf::RenderWindow& window, const sf::FloatRect& textureBounds, sf::Event event);

#endif