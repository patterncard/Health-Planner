#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "BMR.h"
#include "Water.h"
#include "Food.h"
#include "Workout.h"
#include "ToFile.h"
#include "FromFile.h"

#include "GL/gl3w.h" // Initialize with gl3wInit()
#include <GLFW/glfw3.h>

using json = nlohmann::json;

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

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

#if __APPLE__
    // Setup GLFW context for MacOS
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    // Setup GLFW context for other OS's
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1500, 1000, "Health Planner", NULL, NULL);
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
    bool err = false;
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

    bool showBmiResultWindow = false;
    bool errorWindowBmi = false;
    bool showBmrResultWindow = false;
    bool errorWindowBmr = false;
    bool testWindow = false;

    Water water;
    BMI bmi;
    BMR bmr;
    Food food;
    Workout workout;
    ToFile file;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Week");
            ImGui::Columns(8, "days");

            ImVec2 buttonSize(150, 50);
            ImGui::NextColumn();
            ImGui::Button("Monday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Tuesday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Wednesday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Thursday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Friday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Saturday", buttonSize);
            ImGui::NextColumn();
            ImGui::Button("Sunday", buttonSize);
            ImGui::NextColumn();

            ImGui::Separator();

            ImGui::Text("BMI");
            if (ImGui::Button("Clean"))
            {
                //Deleting from file
            }
            ImGui::NextColumn();
            ImGui::Text("1");
            ImGui::NextColumn();
            ImGui::Text("2");
            ImGui::NextColumn();
            ImGui::Text("3");
            ImGui::NextColumn();
            ImGui::Text("4");
            ImGui::NextColumn();
            ImGui::Text("5");
            ImGui::NextColumn();
            ImGui::Text("6");
            ImGui::NextColumn();
            ImGui::Text("7");
            ImGui::NextColumn();

            ImGui::Separator();

            ImGui::Text("BMR");
            if (ImGui::Button("Clean"))
            {
                //Deleting from file
            }
            ImGui::NextColumn();
            ImGui::Text("11");
            ImGui::NextColumn();
            ImGui::Text("22");
            ImGui::NextColumn();
            ImGui::Text("33");
            ImGui::NextColumn();
            ImGui::Text("44");
            ImGui::NextColumn();
            ImGui::Text("55");
            ImGui::NextColumn();
            ImGui::Text("66");
            ImGui::NextColumn();
            ImGui::Text("77");
            ImGui::NextColumn();

            ImGui::Separator();

            ImGui::Text("Calories");
            if (ImGui::Button("Clean"))
            {
                //Deleting from file
            }
            ImGui::NextColumn();
            ImGui::Text("111");
            ImGui::NextColumn();
            ImGui::Text("222");
            ImGui::NextColumn();
            ImGui::Text("333");
            ImGui::NextColumn();
            ImGui::Text("444");
            ImGui::NextColumn();
            ImGui::Text("555");
            ImGui::NextColumn();
            ImGui::Text("666");
            ImGui::NextColumn();
            ImGui::Text("777");
            ImGui::NextColumn();

            ImGui::Separator();

            ImGui::Text("Water");
            if (ImGui::Button("Clean"))
            {
                //Deleting from file
            }
            ImGui::NextColumn();
            ImGui::Text("1111");
            ImGui::NextColumn();
            ImGui::Text("2222");
            ImGui::NextColumn();
            ImGui::Text("3333");
            ImGui::NextColumn();
            ImGui::Text("4444");
            ImGui::NextColumn();
            ImGui::Text("5555");
            ImGui::NextColumn();
            ImGui::Text("6666");
            ImGui::NextColumn();
            ImGui::Text("7777");
            ImGui::NextColumn();

            ImGui::Separator();

            ImGui::Text("Workout");
            if (ImGui::Button("Clean"))
            {
                //Deleting from file
            }
            ImGui::NextColumn();
            ImGui::Text("11111");
            ImGui::NextColumn();
            ImGui::Text("22222");
            ImGui::NextColumn();
            ImGui::Text("33333");
            ImGui::NextColumn();
            ImGui::Text("44444");
            ImGui::NextColumn();
            ImGui::Text("55555");
            ImGui::NextColumn();
            ImGui::Text("66666");
            ImGui::NextColumn();
            ImGui::Text("77777");
            ImGui::NextColumn();

            ImGui::Columns(1);

            ImGui::End();
        }

        {
            ImGui::Begin("Calculating BMI");

            ImGui::Text("Enter your height:");
            static char heightEnteredChar[64] = "";
            ImGui::InputText("cm", heightEnteredChar, 64);

            ImGui::Text("Enter your weight:");
            static char weightEnteredChar[64] = "";
            ImGui::InputText("kg", weightEnteredChar, 64);

            static double bmiResultDouble;

            if (ImGui::Button("Calculate BMI"))
            {
                double height = atoi(heightEnteredChar);
                double weight = atoi(weightEnteredChar);

                // std::cout << height << std::endl;
                // std::cout << "bmi pressed" << std::endl;

                try
                {
                    if (height <= 0 || weight <= 0)
                    {
                        throw "error1";
                    }
                    bmiResultDouble = bmi.calcBMI(weight, height);
                    showBmiResultWindow = true;
                }
                catch (const char *e1)
                {
                    std::cout << e1 << std::endl;
                    errorWindowBmi = true;
                }
            }
            if (errorWindowBmi)
            {
                ImGui::Begin("Error 101", &errorWindowBmi);
                ImGui::Text("Value of height and weight cannot be 0 or less.");
                ImGui::Text("Please enter positive number");
                if (ImGui::Button("Close Me"))
                    errorWindowBmi = false;
                ImGui::End();
            }

            if (showBmiResultWindow)
            {
                ImGui::Begin("BMI Result", &showBmiResultWindow); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
                ImGui::Text("Your BMI is: ");
                int bmiResultInt = (double)bmiResultDouble;
                ImGui::Text("%i", bmiResultInt);

                if (ImGui::Button("Save"))
                {
                    //writing to file
                }

                if (ImGui::Button("Close Me"))
                    showBmiResultWindow = false;
                ImGui::End();
            }
            ImGui::End();
        }

        {
            ImGui::Begin("Calculating BMR");

            ImGui::Text("Enter your height:");
            static char heightEnteredChar[64] = "";
            ImGui::InputText("cm", heightEnteredChar, 64);

            ImGui::Text("Enter your weight:");
            static char weightEnteredChar[64] = "";
            ImGui::InputText("kg", weightEnteredChar, 64);

            ImGui::Text("Enter your age:");
            static char ageEnteredChar[64] = "";
            ImGui::InputText("years", ageEnteredChar, 64);

            static double bmrResultDouble;

            if (ImGui::Button("Calculate BMR"))
            {
                double height = atoi(heightEnteredChar);
                double weight = atoi(weightEnteredChar);
                double age = atoi(ageEnteredChar);

                try
                {
                    if (height <= 0 || weight <= 0 || age <= 0)
                    {
                        throw "error2";
                    }
                    bmrResultDouble = bmr.calcBMR(weight, height, age);
                    showBmrResultWindow = true;
                }
                catch (const char *e2)
                {
                    std::cout << e2 << std::endl;
                    errorWindowBmr = true;
                }
            }
            if (errorWindowBmr)
            {
                ImGui::Begin("Error 202", &errorWindowBmr);
                ImGui::Text("Value of height, weight and age cannot be 0 or less.");
                ImGui::Text("Please enter positive number");
                if (ImGui::Button("Close Me"))
                    errorWindowBmr = false;
                ImGui::End();
            }

            if (showBmrResultWindow)
            {
                ImGui::Begin("BMR Result", &showBmrResultWindow);
                ImGui::Text("Your BMR is: ");
                int bmrResultInt = (double)bmrResultDouble;
                ImGui::Text("%i", bmrResultInt);

                if (ImGui::Button("Save"))
                {
                    //writing to file
                }

                if (ImGui::Button("Close Me"))
                    showBmrResultWindow = false;
                ImGui::End();
            }
            ImGui::End();
        }

        {
            ImGui::Begin("Workout Tracking");

            ImGui::Text("Add time spend on training:");
            static char timeInput[64] = "";
            ImGui::InputText("h", timeInput, 64);

            double sumOfTimeTrained;

            if (ImGui::Button("Add"))
            {
                double volume = atof(timeInput);
                workout.addRecord(volume);
                sumOfTimeTrained = workout.sumAllTimeSpent();
            }

            ImGui::Text("Time spent on training: %f", sumOfTimeTrained);

            if (ImGui::Button("Save"))
            {
                //writing to file
            }

            ImGui::End();
        }

        {
            ImGui::Begin("Water Hydration");

            ImGui::Text("Add glass of water:");
            static char volumeInput[64] = "";
            ImGui::InputText("ml", volumeInput, 64);

            int sumOfWaterVolume;

            if (ImGui::Button("Add"))
            {
                int volume = atoi(volumeInput);
                water.addGlasses(volume);
                sumOfWaterVolume = water.sumAllGlassesVolume();
            }

            std::cout << sumOfWaterVolume << std::endl;

            ImGui::Text("Water drank: %i", sumOfWaterVolume);

            std::string day;
            ImGui::Text("Choose day");
            if (ImGui::SmallButton("mon"))
            {
                day = "mon";
            }
            if (ImGui::SmallButton("tue"))
            {
                day = "tue";
                std::cout << "in small button: " << day << std::endl;
                file.saveToFileInt(day, "calories", 123);
                std::cout << "in small button saved: " << day << std::endl;
            }
            if (ImGui::SmallButton("wed"))
            {
                day = "wed";
            }
            if (ImGui::SmallButton("thu"))
            {
                day = "thu";
            }
            if (ImGui::SmallButton("fri"))
            {
                day = "fri";
            }
            if (ImGui::SmallButton("sat"))
            {
                day = "sat";
            }
            if (ImGui::SmallButton("sun"))
            {
                day = "sun";
            }

            std::cout << "outside small button: " << day << std::endl;
            ImGui::Text("%s", day);

            if (ImGui::Button("Save"))
            {
                std::cout << "in button save: " << day << std::endl;
                file.saveToFileInt(day, "calories", 123);
            }

            ImGui::End();
        }

        {
            ImGui::Begin("Calorie Tracking");

            ImGui::Text("Dish proteins:");
            static char dishProteinsInput[64] = "";
            ImGui::InputText("proteins", dishProteinsInput, 64);

            ImGui::Text("Dish carbohydrates:");
            static char dishCarbsInput[64] = "";
            ImGui::InputText("carbs", dishCarbsInput, 64);

            ImGui::Text("Dish fats:");
            static char dishFatInput[64] = "";
            ImGui::InputText("fat", dishFatInput, 64);

            if (ImGui::Button("Add"))
            {
                int dishProtein = atoi(dishProteinsInput);
                int dishCarbs = atoi(dishCarbsInput);
                int dishFat = atoi(dishFatInput);

                food.addDish(dishProtein, dishCarbs, dishFat);
            }

            ImGui::Text("calories:");

            for (int i = 0; i < food.getAllDishes().size(); i++)
            {
                ImGui::Text("%i", food.getAllDishes()[i].getDishCalories());
            }

            if (ImGui::Button("Save"))
            {
                //writing to file
            }

            ImGui::End();
        }

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
