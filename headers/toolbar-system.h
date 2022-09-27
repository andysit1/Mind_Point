#pragma once
#include "../include/raylib.h"
#include <iostream>
#include <string>


struct Tool{
  Tool(std::string name, Vector2 size);
  std::string Name;
  Vector2 Size;
};

struct ToolBar{
  std::string selected_tool;
  void Draw();
  void Update();
};