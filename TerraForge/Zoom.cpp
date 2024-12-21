#include "Zoom.hpp"

void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow& window, float zoom, float& currentZoom, float maxZoom, float minZoom, const sf::FloatRect& textureBounds)
{
    if (currentZoom * zoom > maxZoom || currentZoom * zoom < minZoom)
        return;

    const sf::Vector2f beforeCoord = window.mapPixelToCoords(pixel);
    sf::View view = window.getView();
    view.zoom(zoom);
    window.setView(view);
    const sf::Vector2f afterCoord = window.mapPixelToCoords(pixel);
    const sf::Vector2f offsetCoords = beforeCoord - afterCoord;
    view.move(offsetCoords);

    // Проверка границ
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.0f, view.getSize());
    if (viewBounds.left < textureBounds.left)
        view.setCenter(textureBounds.left + view.getSize().x / 2.0f, view.getCenter().y);
    if (viewBounds.top < textureBounds.top)
        view.setCenter(view.getCenter().x, textureBounds.top + view.getSize().y / 2.0f);
    if (viewBounds.left + viewBounds.width > textureBounds.left + textureBounds.width)
        view.setCenter(textureBounds.left + textureBounds.width - view.getSize().x / 2.0f, view.getCenter().y);
    if (viewBounds.top + viewBounds.height > textureBounds.top + textureBounds.height)
        view.setCenter(view.getCenter().x, textureBounds.top + textureBounds.height - view.getSize().y / 2.0f);

    window.setView(view);

    currentZoom *= zoom;
}

void ZoomEvent(float& currentZoom, float maxZoom, float minZoom, sf::RenderWindow& window, const sf::FloatRect& textureBounds, sf::Event event) {
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        if (event.mouseWheelScroll.delta > 0)
        {
            zoomViewAt(sf::Mouse::getPosition(window), window, 0.95f, currentZoom, maxZoom, minZoom, textureBounds); // Уменьшение масштаба
        }
        else if (event.mouseWheelScroll.delta < 0)
        {
            zoomViewAt(sf::Mouse::getPosition(window), window, 1.05f, currentZoom, maxZoom, minZoom, textureBounds); // Увеличение масштаба
        }
    }
}