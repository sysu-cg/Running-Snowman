#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <imgui/imconfig.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_internal.h>
#include <imgui/imstb_rectpack.h>
#include <imgui/imstb_textedit.h>
#include <imgui/imstb_truetype.h>

#include <stb_image/stb_image.h>

#include <iostream>
using namespace std;

#include <cmath>
#include <algorithm>

#include <vector>
#include <fstream>
#include <sstream>

// Window
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const char* WINDOW_TITLE;

// GameObject
extern const glm::vec3 GAMEOBJECT_POSITION;
extern const glm::vec3 GAMEOBJECT_SIZE; 

// Camera
extern const glm::vec3 CAMERA_DIRECTION;
extern const glm::vec3 CAMERA_POSITION;
extern const glm::vec3 CAMERA_WORLDUP;
extern const float CAMERA_PITCH;
extern const float CAMERA_YAW;
extern const float CAMERA_SENSITIVITY;
extern const float CAMERA_SPEED;

// mouse
extern bool isFirstMouse;
extern double lastX;
extern double lastY;
extern double currX;
extern double currY;

#endif