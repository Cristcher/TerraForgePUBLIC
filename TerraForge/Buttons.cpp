#include "Buttons.hpp"

// Функция для сохранения настроек в файл
void saveSettings(const char* filename, unsigned seed, int grid_size, float amplitudeModifier, float frequencyModifier, int octaves, int precision, int ColoringScheme) {
    FILE* file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%u\n", seed);
        fprintf(file, "%d\n", grid_size);
        fprintf(file, "%f\n", amplitudeModifier);
        fprintf(file, "%f\n", frequencyModifier);
        fprintf(file, "%d\n", octaves);
        fprintf(file, "%d\n", precision);
        fprintf(file, "%d\n", ColoringScheme);
        fclose(file);
    }
}

// Функция для загрузки настроек из файла
void loadSettings(const char* filename, unsigned& seed, int& grid_size, float& amplitudeModifier, float& frequencyModifier, int& octaves, int& precision, int& ColoringScheme, char* seedInput) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fscanf(file, "%u", &seed);
        fscanf(file, "%d", &grid_size);
        fscanf(file, "%f", &amplitudeModifier);
        fscanf(file, "%f", &frequencyModifier);
        fscanf(file, "%d", &octaves);
        fscanf(file, "%d", &precision);
        fscanf(file, "%d", &ColoringScheme);
        fclose(file);
        snprintf(seedInput, sizeof(seedInput), "%u", seed); 
    }
}

void Buttons(bool& updatePressed, std::chrono::steady_clock::time_point& lastUpdateTime, unsigned& seed, char* seedInput, sf::Uint8*& pixels, int windowHeight, int windowWidth, int& grid_size, float& amplitudeModifier, float& frequencyModifier, int& octaves, sf::Texture& texture, sf::RenderWindow& window, int& precision, int& ColoringScheme)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 20));
    ImGui::Begin("Settings");
    ImVec2 buttonSize = ImVec2(windowWidth * 0.2f, windowHeight * 0.05f);
    static const char* SCHEMES[] = { "Atlas", "Black & White", "Classic", "Heatmap", "Ocean blue", "Old palette", "Royal purple", "Soft green" };

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::Combo("Coloring Scheme", &ColoringScheme, SCHEMES, IM_ARRAYSIZE(SCHEMES));
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Changes the color scheme of the noise.");

    ImGui::SetNextItemWidth(buttonSize.x);
    if (ImGui::InputText("Seed Input", seedInput, sizeof(seedInput), ImGuiInputTextFlags_CharsDecimal)) {
        if (strlen(seedInput) == 0 || *seedInput == '-' || *seedInput == '.' || *seedInput == ',' || *seedInput == '+' || *seedInput == '*' || *seedInput == '/') {
            seed = 0;
        }
        else {
            seed = std::stoi(seedInput);
        }
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Seed value for the Perlin noise generator.");

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::SliderFloat("Amplitude Modifier", &amplitudeModifier, 0.1f, 6.0f);
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Controls the amplitude of the Perlin noise. Higher values result in more pronounced variations.");

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::SliderFloat("Frequency Modifier", &frequencyModifier, 0.1f, 6.0f);
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Controls the frequency of the Perlin noise. Higher values result in more frequent variations.");

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::SliderInt("Octaves", &octaves, 1, 6);
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Number of octaves in the Perlin noise. More octaves add more detail.");

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::SliderInt("Grid-size", &grid_size, 1, 1000);
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Size of the grid for the Perlin noise. Larger grids result in larger patterns.");

    ImGui::SetNextItemWidth(buttonSize.x);
    ImGui::SliderInt("Calculation Precision", &precision, 1, 12);
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Precision of calculations, the more precise - the slower it generates");

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(29 / 255.0f, 162 / 255.0f, 38 / 255.0f, 1.0f));
    if (ImGui::Button("Refresh", buttonSize) && !updatePressed)
    {
        updatePressed = true;
        lastUpdateTime = std::chrono::steady_clock::now();
        delete[] pixels;
        pixels = coloring(windowHeight, windowWidth, grid_size, seed, amplitudeModifier, frequencyModifier, octaves, precision, ColoringScheme);
        texture.update(pixels);
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Refresh the Perlin noise with the current settings.");
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(162 / 255.0f, 29 / 255.0f, 29 / 255.0f, 1.0f));
    if (ImGui::Button("Exit", buttonSize))
    {
        window.close();
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Close the application.");
    ImGui::PopStyleColor();

    ImGui::Separator();
    ImGui::Text("USER CONFIGURATION SETTINGS");

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(42 / 255.0f, 47 / 255.0f, 76 / 255.0f, 1.0f));
    if (ImGui::Button("Save Settings", buttonSize))
    {
        saveSettings("settings.txt", seed, grid_size, amplitudeModifier, frequencyModifier, octaves, precision, ColoringScheme);
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Save the current settings to a file.");
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(42 / 255.0f, 47 / 255.0f, 76 / 255.0f, 1.0f));
    if (ImGui::Button("Load Settings", buttonSize))
    {
        loadSettings("settings.txt", seed, grid_size, amplitudeModifier, frequencyModifier, octaves, precision, ColoringScheme, seedInput);
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Load settings from a file.");
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(162 / 255.0f, 29 / 255.0f, 29 / 255.0f, 1.0f));
    if (ImGui::Button("Reset to Standard Settings", buttonSize))
    {
        grid_size = 600;
        seed = 1323;
        sprintf(seedInput, "%u", seed);
        amplitudeModifier = 0.5;
        frequencyModifier = 1.5;
        octaves = 2;
        precision = 1;
        ColoringScheme = 2;
    }
    if (ImGui::IsItemHovered())
        ImGui::SetTooltip("Set the settings to their standard values.");
    ImGui::PopStyleColor();

    ImGui::End();
    ImGui::PopStyleVar();

    ImGui::SetNextWindowPos(ImVec2(windowWidth - 700, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(700, 0), ImGuiCond_Always);
    ImGui::Begin("FAQ", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::Text("TerraForge - Procedural Terrain Generation");
    ImGui::Separator();
    ImGui::Text("This program generates realistic terrain using Perlin noise.");
    ImGui::Text("Features:");
    ImGui::BulletText("Seed Input: Enter a seed value to generate unique terrain.");
    ImGui::BulletText("Amplitude Modifier: Adjusts the height variations.");
    ImGui::BulletText("Frequency Modifier: Controls the frequency of terrain features.");
    ImGui::BulletText("Octaves: Number of layers of noise for added detail.");
    ImGui::BulletText("Grid-size: Size of the grid for noise generation.");
    ImGui::BulletText("Calculation Precision: Higher precision results in slower generation.");
    ImGui::BulletText("Coloring Scheme: Choose different color schemes for the terrain.");
    ImGui::Separator();
    ImGui::Text("Mouse Wheel: Use the mouse wheel to zoom in and out.");
    ImGui::Separator();
    ImGui::Text("Extras:");
    ImGui::BulletText("Save settings: Use to save current settings");
    ImGui::BulletText("Load settings: Use to load last saved settings");
    ImGui::BulletText("Reset settings: Use to set the settings back to their standard values");
    ImGui::End();

    if (updatePressed)
    {
        auto currentTime = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastUpdateTime).count() >= 3)
        {
            updatePressed = false;
        }
    }
}
