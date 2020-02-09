#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <iostream>
// #include "Results.h"
#include "BMR.h"

// About Desktop OpenGL function loaders:
//  Modern desktop OpenGL doesn't have a standard portable header file to load OpenGL function pointers.
//  Helper libraries are often used for this purpose! Here we are supporting a few common ones (gl3w, glew, glad).
//  You may use another loader/header of your choice (glext, glLoadGen, etc.), or chose to manually implement your own.

#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include "GL/gl3w.h" // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING)
#define GLFW_INCLUDE_NONE        // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/glbinding.h> // Initialize with glbinding::initialize()
#include <glbinding/gl/gl.h>
using namespace gl;
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

class Diet
{
    bool loss;
    bool keep;
    bool gain;
    void selectGoal(bool g)
    {
        bool goal = g;
    }
};
class Calories
{
public:
    double calr = 2000;
    double setCalories(double BMIndex)
    {
        if (BMIndex < 18.5)
            calr += 1000;
        else if (BMIndex > 18.5)
        {
            calr -= 1000;
        }
        return calr;
    }
};

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Health Planner", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
    bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING)
    bool err = false;
    glbinding::initialize([](const char *name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });
#else
    bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_demo_window = true;
    bool showBmiResultWindow = false;
    bool errorWindowHeight = false;
    bool show_second_window = false;
    bool show_third_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Calculating BMI"); // Create a window and append into it.
            BMI bmi;

            ImGui::Text("Enter your height:"); // Display some text (you can use a format strings too)
            static char heightEnteredChar[64] = "";
            ImGui::InputText("cm", heightEnteredChar, 64);

            ImGui::Text("Enter your weight:"); // Display some text (you can use a format strings too)
            static char weightEnteredChar[64] = "";
            ImGui::InputText("kg", weightEnteredChar, 64);

            static double bmiResultDouble;

            if (ImGui::Button("Calculate BMI"))
            {
                double height = atoi(heightEnteredChar);
                double weight = atoi(weightEnteredChar);

                try
                {
                    if (height <= 0 || weight <= 0)
                    {
                        throw "error";
                    }
                    bmiResultDouble = bmi.calcBMI(weight, height);
                    showBmiResultWindow = true;
                }
                catch (const char *e)
                {
                    std::cout << e << std::endl;
                    errorWindowHeight = true;
                }
            }
            if (errorWindowHeight)
            {
                ImGui::Begin("Error");
                ImGui::Text("Value of height and weight cannot be 0 or less.");
                ImGui::Text("Please enter positive number");
                if (ImGui::Button("Close Me"))
                    errorWindowHeight = false;
                ImGui::End();
            }

            if (showBmiResultWindow)
            {
                ImGui::Begin("BMI Result", &showBmiResultWindow); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
                ImGui::Text("Your BMI is: ");
                int bmiResultInt = (double)bmiResultDouble;
                ImGui::Text("%i", bmiResultInt);
                if (ImGui::Button("Close Me"))
                    showBmiResultWindow = false;
                ImGui::End();
            }
            ImGui::End();
        }

        {
            ImGui::Begin("Calculating BMR"); // Create a window and append into it.
            BMR bmr;

            ImGui::Text("Enter your height:"); // Display some text (you can use a format strings too)
            static char heightEnteredChar[64] = "";
            ImGui::InputText("cm", heightEnteredChar, 64);

            ImGui::Text("Enter your weight:"); // Display some text (you can use a format strings too)
            static char weightEnteredChar[64] = "";
            ImGui::InputText("kg", weightEnteredChar, 64);

            ImGui::Text("Enter your age:"); // Display some text (you can use a format strings too)
            static char ageEnteredChar[64] = "";
            ImGui::InputText("years", ageEnteredChar, 64);

            static double bmrResultDouble;

            if (ImGui::Button("Calculate BMR"))
            {
                double height = atoi(heightEnteredChar);
                double weight = atoi(weightEnteredChar);
                double age = atoi(ageEnteredChar);

                bmrResultDouble = bmr.calcBMR(weight, height, age);
                show_second_window = true;
            }

            if (show_second_window)
            {
                ImGui::Begin("BMR Result", &show_second_window); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
                ImGui::Text("Your BMR is: ");
                int bmrResultInt = (double)bmrResultDouble;
                ImGui::Text("%i", bmrResultInt);
                if (ImGui::Button("Close Me"))
                    show_second_window = false;
                ImGui::End();
            }
            ImGui::End();
        }

        // {
        //     static bool checkBox1 = false;
        //     static bool checkBox2 = false;
        //     static bool checkBox3 = false;
        //     static bool checkBox4 = false;
        //     static bool checkBox5 = false;
        //     static bool checkBox6 = false;
        //     static bool checkBox7 = false;

        //     ImGui::Begin("Tracking training"); // Create a window and append into it.
        //     ImGui::Checkbox("Day 1", &checkBox1);
        //     ImGui::Checkbox("Day 2", &checkBox2);
        //     ImGui::Checkbox("Day 3", &checkBox3);
        //     ImGui::Checkbox("Day 4", &checkBox4);
        //     ImGui::Checkbox("Day 5", &checkBox5);
        //     ImGui::Checkbox("Day 6", &checkBox6);
        //     ImGui::Checkbox("Day 7", &checkBox7);

        //     ImGui::End();
        // }

        // {
        //     Calories ckal;
        //     ImGui::Begin("Diet"); // Create a window and append into it.
        //     ImGui::Text("Set your diet goal: ");
        //     if (ImGui::TreeNode("Weight loss"))
        //     {
        //         static bool checkBoxx = false;
        //         ImGui::Checkbox("1000 kcal", &checkBoxx);
        //     }
        //     if (ImGui::TreeNode("Keeping weight"))
        //     {
        //         static bool checkBoxy = false;
        //         ImGui::Checkbox("2000 kcal", &checkBoxy);
        //     }

        //     if (ImGui::TreeNode("Weight gain"))
        //     {
        //         static bool checkBoxz = false;
        //         ImGui::Checkbox("3000 kacl", &checkBoxz);
        //     }

        //     ImGui::End();
        // }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
