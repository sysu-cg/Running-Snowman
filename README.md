# Running-Snowman
## 项目配置

从菜单栏打开【项目】，选择【属性】，配置如下

+ 选择【VC++目录】，在【包含目录】中添加`./OpenGL/Includes;./include`
+ 选择【VC++目录】，在【库目录】中添加`./OpenGL/Libs`
+ 选择【链接器】，选择【输入】，在【附加依赖项】中添加`opengl32.lib;glfw3.lib;assimp-vc141-mtd.lib`



## 文件结构

`OpenGL.h`：引用OpenGL相关的头文件，声明OpenGL类

`global.h`：引用`OpenGL.h`，声明全局参数
