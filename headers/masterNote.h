#pragma once
#include "../include/raylib.h"
#include "../headers/settings.h"
#include "../headers/noteComponent.h"
#include <vector>
//purpose: controls all notes via draw and updating -> also stores

class MasterNote{
 ~MasterNote();
  void generateNote();
  std::vector<BasicNote> noteContainer{};

  void Draw();
  void Update();
};
