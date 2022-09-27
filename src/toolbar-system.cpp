#include "../headers/toolbar-system.h"
//create different types of tools/shapes with increase tool objects

//draw toolbar which is connected to grid
//when tool is selected on mouse position grid

Tool::Tool(std::string name, Vector2 size){
  this->Name = name;
  this->Size = size;
}
//--------------------------------------------------------
void ToolBar::Update(){
}

void ToolBar::Draw(){
}


//tool.Update();
//tool.Draw();