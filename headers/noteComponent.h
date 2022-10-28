#pragma once
#include "../include/raylib.h"
#include "../headers/settings.h"
#include "../headers/noteComponent.h"

//purpose: sets the properties of each type of notes

class BasicNote{
  public:
  BasicNote(Vector2 position, Vector2 size, Color color);
 ~BasicNote();

  //changeable variables
  Vector2 position;
  Vector2 size;
  Color color;

  //Constants
  Vector2 DEFAULT_SIZE{200, 100};
  Color DEFAULT_COLOR{YELLOW};
};
