#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "global.h"

class ResourceManager {
public:
  static void loadTexture(unsigned int &texture, const char* image);

private:
  ResourceManager();  // can not be used & need not be defined

};

#endif