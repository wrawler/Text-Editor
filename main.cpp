//===============================================================================================================================
//                                                INCLUDES AND OTHER STUFF
//===============================================================================================================================
#include "MyApp.hpp"

#ifndef FILE_DIALOG_INCLUDED
#include "FileDialog.hpp"
#define FILE_DIALOG_INCLUDED
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// Default Error handling
static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
//===============================================================================================================================
//                                               SOME FUNCTIONS DEFINED BY ME
//===============================================================================================================================

// Creating Required Menu-Bar windows 
void Mynamespace::renderRequiredWindows()
{
    // The New Window
    if (requiredWindows["newWindow"] == true)
    {
        ImGui::Begin("Ping !!", &requiredWindows["newWindow"]);
        ImGui::Text("This is the new window");
        ImGui::End();
    }
};


//void renderNotesWindow(const char* notesContent) {
//    if (requiredWindows["notesWindow"] == true) {
//        ImGui::Begin("Notess");
//        std::string Text = "text";
//        ImGui::Text("lol");
//        std::cout << notesContent;
//        ImGui::InputTextMultiline();
//        ImGui::End();
//    }
//}

// void renderNotesWindow(std::string path) {
//    if (requiredWindows["notesWindow"] == true) {
//        std::string fileContent;
//        std::ifstream inputfile(path);
//        char buffer[4096];
//        inputfile.read(buffer, sizeof(buffer));
//        buffer[inputfile.gcount()] = '\0';
//        std::cout << buffer;
//
//        //char imGuiBuffer[4096];
//        //std::strcpy(imGuiBuffer, buffer);
//        //std::cout << imGuiBuffer;
//        fileContent = buffer;
//
//        ImGui::Begin("Notess");
//        ImGui::Text("lol");
//        //ImGui::InputTextMultiline("##inputText", buffer, sizeof(buffer), ImGui::GetWindowSize() /*text box size*/);
//        //ImGui::InputTextMultiline("##inputText", imGuiBuffer, sizeof(imGuiBuffer), ImGui::GetWindowSize() /*text box size*/);
//        ImGui::InputTextMultiline("##inputText", &fileContent[0], fileContent.size(), ImGui::GetWindowSize());
//        ImGui::End();
//    }
//}

void Mynamespace::renderNotesWindow() {
    if (requiredWindows["notesWindow"] == true) {
        ImGui::Begin("Notess");
        ImGui::Text("lol");
        ImGui::End();
    }
};

// The background color of base window
ImVec4 base_color_light = ImVec4(145.0f / 255.0f, 152.0f / 255.0f, 204.0f / 255.0f, 1.0f);
ImVec4 base_color_dark = ImVec4(40.0f / 225.0f, 48.0f / 255.0f, 65.0f / 225.0f, 0.8f);

// Default background color of base window
ImVec4 base_color = base_color_dark;

// Theme Management
int theme = 1;
void Mynamespace::HandleThemes()
{
    if (theme == 0){
        ImGui::StyleColorsLight();
        base_color = base_color_light;
    }
    else {
        ImGui::StyleColorsDark();
        base_color = base_color_dark;
    }
};

//===============================================================================================================================
//                                                     ENTRY POINT
//===============================================================================================================================
int main(int, char**)
{
    // Throws error if GLFW is not intialised properly
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Create window with graphics context (The Base Window)
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Dear ImGui GLFW+OpenGL2 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    //glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

    // Setting Up Fonts
    io.Fonts->AddFontDefault();
    ImFontAtlas* atlas = io.Fonts;
    ImFont* font1 = atlas->AddFontFromFileTTF("../lib/fonts/Cousine-Regular.ttf", 24.0f);
    ImFont* font2 = atlas->AddFontFromFileTTF("../lib/fonts/DroidSans.ttf", 24.0f);
    ImFont* font3 = atlas->AddFontFromFileTTF("../lib/fonts/Karla-Regular.ttf", 24.0f);
    ImFont* font4 = atlas->AddFontFromFileTTF("../lib/fonts/ProggyClean.ttf", 24.0f);
    ImFont* font5 = atlas->AddFontFromFileTTF("../lib/fonts/ProggyTiny.ttf", 24.0f);
    ImFont* font6 = atlas->AddFontFromFileTTF("../lib/fonts/Roboto-Medium.ttf", 24.0f);

    io.FontDefault = font1;

    // Setup Dear ImGui Default style
    ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 10.0f;
        style.Colors[ImGuiCol_WindowBg].w = 0.2f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

//===============================================================================================================================
//                                                  MAIN LOOP
//===============================================================================================================================
    // Default state
    bool showWelcomeScreen = true;
    bool ischecked = false;

    // input size of text box in Notes
    char inputText[4096] = "";

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // The main menu bar
        if (ImGui::BeginMainMenuBar())
        {
            // File Menu
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("New")) { requiredWindows["newWindow"] = true; }
                if (ImGui::MenuItem("Open")) { requiredWindows["openDialog"] = true; }
                if (ImGui::MenuItem("Save")) { requiredWindows["saveDialog"] = true; }
                ImGui::EndMenu();
            }

            // View menu
            if (ImGui::BeginMenu("View")) {
                if (ImGui::MenuItem("Change Theme")) {
                    if (theme == 1)theme = 0;
                    else theme = 1;
                }
                if (ImGui::BeginMenu("Fonts")){
                    if(ImGui::MenuItem("Cousine-Regular")){
                        io.FontDefault = font1;
                    }
                    if(ImGui::MenuItem("DroidSans")){
                        io.FontDefault = font2;
                    }
                    if(ImGui::MenuItem("Karla-Regular")){
                        io.FontDefault = font3;
                    }
                    if(ImGui::MenuItem("ProggyClean")){
                        io.FontDefault = font4;
                    }
                    if(ImGui::MenuItem("ProggyTiny")){
                        io.FontDefault = font5;
                    }
                    if(ImGui::MenuItem("Roboto-Medium")){
                        io.FontDefault = font6;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        // Custom Window
        if (showWelcomeScreen)
        {
            // A window
            ImGui::Begin("Welcome");
            ImGui::Text("Hye! This is the welcome screen of this beautiful software");
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

            // A window created when checkbox is on
            ImGui::Checkbox("Open Notes", &ischecked);
            if (ischecked) {
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0,0)); // setting padding to zero
                ImGui::Begin("Notes", &ischecked);
                ImGui::InputTextMultiline("##inputText", inputText, sizeof(inputText), ImGui::GetWindowSize() /*text box size*/);
                ImGui::End();
                ImGui::PopStyleVar();
            }

            // closing window button
            if (ImGui::Button("close")) {
                showWelcomeScreen = false;
            }
            ImGui::End();
        }
//=================================================================================================================================

        // Calling The User defined functions
        Mynamespace::renderRequiredWindows();
        Mynamespace::HandleThemes();

        // The Open Dialog
        std::string filePath;
        std::string output;
        if (requiredWindows["openDialog"] == true)
        {
            filePath = openDialog();
            output = getOutput(filePath);
            requiredWindows["notesWindow"] = true;
        }

        // The save Dialog
        if (requiredWindows["saveDialog"] == true)
        {
            saveDialog();
        }

        // initiallising a const char* to the output string because I thought that ImGui::Text function takes const char* as parameter
        const char* outputCharPtr = output.c_str();
        Mynamespace::renderNotesWindow();

        requiredWindows["openDialog"] = false;

//================================================================================================================================
//                                                     RENDERING
//================================================================================================================================

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(base_color.x * base_color.w, base_color.y * base_color.w, base_color.z * base_color.w, base_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    };

//================================================================================================================================
//                                                    CLEAN UP
//================================================================================================================================

    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

