#include "global.h"
#include "Shader.h"

class GameObject {
public:
  GameObject();
  ~GameObject();

  void init(glm::vec3 position = GAMEOBJECT_POSITION, glm::vec3 size = GAMEOBJECT_SIZE);
  void update(float deltaTime);

private:
  glm::vec3 position;
  glm::vec3 size;

};