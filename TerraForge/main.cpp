//ImguiLibs
#include "imgui.h"
#include "imgui-SFML.h"

//SFMLlibs
#include "SFML/Graphics.hpp"

//Modules
#include "WindowHandler.hpp"

//STL
#include <chrono>
#include <thread>
#include <windows.h>

int main()
{
    int windowWidth = GetSystemMetrics(SM_CXSCREEN);
    int windowHeight = GetSystemMetrics(SM_CYSCREEN);
    
    //Отрисовщик окна
    WindowHandler(windowWidth, windowHeight);

    return 0;
}
