#include "WindowHandler.hpp"

void WindowHandler(int windowWidth, int windowHeight) {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Perlin", sf::Style::Fullscreen);

    sf::View view(sf::FloatRect(0, 0, windowWidth, windowHeight));
    window.setView(view);
    window.setFramerateLimit(120);
    ImGui::SFML::Init(window);
    float currentZoom = 1.0f;
    const float maxZoom = 1.0f;
    const float minZoom = 0.05f;

    //Параметры генерации
    int grid_size = 600;
    unsigned seed = 1323;
    float amplitudeModifier = 0.5;
    float frequencyModifier = 1.5;
    int octaves = 2;
    int precision = 1;

    int ColoringScheme = 2;

    sf::Uint8* pixels = coloring(windowHeight, windowWidth, grid_size, seed, amplitudeModifier, frequencyModifier, octaves, precision, ColoringScheme);

    sf::Texture texture;
    sf::Sprite sprite;

    texture.create(windowWidth, windowHeight);
    texture.update(pixels);
    sprite.setTexture(texture);
    sf::FloatRect textureBounds(0, 0, texture.getSize().x, texture.getSize().y);
    sprite.setScale(
        static_cast<float>(windowWidth) / texture.getSize().x,
        static_cast<float>(windowHeight) / texture.getSize().y
    );

    bool updatePressed = false;
    auto lastUpdateTime = std::chrono::steady_clock::now();

    char seedInput[10];
    snprintf(seedInput, sizeof(seedInput), "%u", seed);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, sf::seconds(1.f / 30.f));

        Buttons(updatePressed, lastUpdateTime, seed, seedInput, pixels, windowHeight, windowWidth, grid_size, amplitudeModifier, frequencyModifier, octaves, texture, window, precision, ColoringScheme);
        ZoomEvent(currentZoom, maxZoom, minZoom, window, textureBounds, event);
        window.clear();
        window.draw(sprite);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

int printSeedtoConsole(unsigned seed) {
    std::cout << seed;
    return seed;
}
int LogSeedInput(char seedInput[10]) {
    int seed = 0;
    std::cout << "Seed changed: " << seedInput;
    return seed;
}
int CreateErrorMessage(unsigned seed) {
    std::cout << "Error! Try generating later with this seed:" << seed;
    return seed;
}