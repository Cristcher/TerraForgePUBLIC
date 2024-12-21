#pragma warning(disable : 4244)

#ifndef WINDOW_HANDLER_HPP
#define WINDOW_HANDLER_HPP

#include <chrono>
#include <thread>
#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include "coloring.hpp"
#include "Buttons.hpp"
#include "Zoom.hpp"

void WindowHandler(int windowWidth, int windowHeight);

#endif