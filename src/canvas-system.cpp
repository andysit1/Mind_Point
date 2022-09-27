#include <iostream>
#include "../headers/canvas-system.h"
#include "../headers/toolbar-system.h"
#include "../headers/settings.h"

Grid grid(40, 40);

void Canvas::draw_notes_and_update(){
  for (int i = 0; i < grid.note_objects.size(); i++){
    grid.note_objects[i].update();
    grid.note_objects[i].draw();
  }
}

void Canvas::events_manager_collision(){
  //checks for collision of note
  for (int i = 0; i < grid.note_objects.size(); i++){
    grid.note_objects[i].check_collisions();
  }

  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !grid.creation_mode){
    grid.get_potential_collisons();
  }
}

void Canvas::events_manager_input(){
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
  }

  if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
    if(create_mode){
      std::cout << "width/height" << grid.grid_width << " " << grid.grid_height << std::endl;
      grid.generate_note({5 * float(grid.grid_width), 3 * float(grid.grid_height)});
    }
  }
}


Color logic_box{GREEN};
void Canvas::creation_mode_logic(){
  if(CheckCollisionPointRec(GetMousePosition(), Rectangle{1330, 0, 100, 100})){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      create_mode = !create_mode;
    }
  }
}

void Canvas::init(){
  grid.init();
}

void Canvas::Update(){
  grid.update();
  events_manager_input();
  events_manager_collision();
  creation_mode_logic();

  if(!create_mode){
    ShowCursor();
  }
}

void Canvas::Draw(){
  if (create_mode == true){
    logic_box = {RED};
  }else{
    logic_box = {GREEN};
  }

  DrawRectangle(1340, 0, 100, 100, logic_box);
  grid.draw();
  grid.show_creation_rect(create_mode, {5 * float(grid.grid_width), 3 * float(grid.grid_height)});
  draw_notes_and_update();
}
