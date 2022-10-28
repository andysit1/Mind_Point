#include "../headers/noteComponent.h"
#include <iostream>

BasicNote::BasicNote(Vector2 position, Vector2 size, Color color){
  this->position = position;
  this->size = size;
  this->color = color;
}

BasicNote::~BasicNote(){
  std::cout << "Deleted Note" << std::endl;
}

