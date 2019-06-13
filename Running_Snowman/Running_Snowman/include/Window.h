#ifndef WINDOW_H_
#define WINDOW_H_

#include "global.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double x, double y);
void scroll_callback(GLFWwindow* window, double x, double y);

class Window {
public:
  Window(int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT, const char* title = WINDOW_TITLE);
  ~Window();

  GLFWwindow* get() const;
  void show() const;

private:
  GLFWwindow* window;

};

#endif