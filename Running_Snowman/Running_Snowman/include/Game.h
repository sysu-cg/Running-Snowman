#ifndef GAME_H_
#define GAME_H_

#include "global.h"
#include "window.h"
#include "Menu.h"
#include "Camera.h"
#include "Shader.h"
#include "ResourceManager.h"
#include "Plane.h"
#include "GameObject.h"

class Game {
public:
  Game();
  ~Game();

  void init();
  void clear();
  void update();
  void render();
  bool isClose();
  void processInput();

private:
  // time
  float currTime;
  float lastTime;

  Window window;
  Menu menu;
  Camera camera;
  Shader shaderGameObject;
  Plane plane;

};

#endif