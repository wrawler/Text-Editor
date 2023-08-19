#pragma once

#include <iostream>
#include <fstream>
#include "lib/imgui/imgui.h"
#include "lib/imgui/imgui_impl_glfw.h"
#include "lib/imgui/imgui_impl_opengl2.h"
#include "Menu_bar.hpp"
#include "lib/glfw/include/glfw3.h"
#include "lib/glfw/include/glfw3native.h"

namespace Mynamespace{
    // Param: void
    // return: void
    // brief: It creates a new ImGui window which can be used to take notes
    void renderNotesWindow();

    // Param: void
    // return: void
    // brief: It changes the theme of the app when 'change theme' option is selected in the menu bar
    void HandleThemes();

    // param: void
    // return: void
    // brief: It creates new windows as per options selected in the menu bar
    void renderRequiredWindows();

    // param: void
    void handleFonts();
};