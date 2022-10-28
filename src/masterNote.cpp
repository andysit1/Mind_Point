#include "../headers/masterNote.h"
#include <iostream>


MasterNote::~MasterNote(){
  std::cout << "Deleted NoteMaster" << std::endl;
}

void MasterNote::generateNote(){
  BasicNote newObject(GetMousePosition(), {200, 100}, YELLOW);
  noteContainer.push_back(newObject);
}

