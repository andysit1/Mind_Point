#include <iostream>
#include<string>
#include <cmath>
#include <vector>
#include "../headers/grid.h"
#include "../headers/settings.h"
#include "../include/raylib.h"
//Tile Object
//Goal: make tiles objects changeable ie color or dectable as objects
//have a grid system to clip objects or move freely dependign on the [grid_mode]
//be able to have a grid have a selected note through a pointer address

//Goal: update position of attachment


Tile::Tile(int width, int height){
  this->tile_size.x = width;
  this->tile_size.y = height;
};

//Grid Object
Grid::Grid(int width, int height){
  this->height = height;
  this->width = width;
  this->grid_width = SCREENWIDTH / width;
  this->grid_height = this->grid_width;
}

//creates a grid with tile objects -> tile objects can be altered
void Grid::generate_grid(Tile& tile){
  for (int y = 0; y < this->height; y++){
    for (int x = 0; x < this->width; x++){
      Tile newTile{grid_width, grid_height};
      newTile.tile_position.x = x * grid_width;
      newTile.tile_position.y = y * grid_height;
      this->gridArray.push_back(newTile);
    }
  }
}

void Grid::init(){
  Tile tile{grid_width, grid_height};
  generate_grid(tile);
  std::cout << "generated tile grid" << std::endl;
}

void Grid::get_gridPosition(){
  this->mouse_grid_positon = {std::floor(mousePos.x / grid_width) ,  std::floor(mousePos.y / grid_height)};
}

Vector2 Grid::gridify(Vector2 point){
  return {std::floor(point.x / grid_width) ,  std::floor(point.y / grid_height)};
}

void Grid::show_grid(){
  if(show_grid_lines){
    for (int i = 0; i < height + 1; i++){
      for (int x = 0; x < width + 1; x++){
        // std::cout << "  (" << i * grid_height << ", " << x * grid_width << ")";
        //DrawCircle(x * grid_width, i * grid_height, 5.0f , BLACK);
        DrawLine(x * grid_width, 0, x * grid_width , height * grid_height, BLACK);
      }
      DrawLine(0, i * grid_height,  width * grid_width, i * grid_height, BLACK);
    }
  }
}

void Tile::setIndex(int value){
  this->index = value;
}

//notes stuff
void Grid::generate_note(Vector2 note_size){
  std::cout << "generated" << std::endl;
  Note newobject;

  //setting note size
  newobject.position = this->masterPoint;
  newobject.size = note_size;
  newobject.get_attachment_docks();

  newobject.update();
  note_objects.push_back(newobject);
  std::cout << width << " , " << height << std::endl;
  Vector2 index_position{gridify(newobject.position)};


  for (int y = 0; y < 3; y++){
    for (int x = 0; x < 5; x++){
      this->gridArray[index_position.x + x + (index_position.y * width + (width * y))].setIndex(note_objects.size());
      // std::cout << index_position.x + x + (index_position.y * width + (width * y)) << std::endl;
    }
  }

}

void Grid::get_master_point(){
  this->masterPoint = {std::floor((this->mousePos.x - (current_note.size.x / 2)) / grid_width) * grid_width, std::floor((this->mousePos.y - (current_note.size.y / 2)) / grid_height) * grid_height};
}

void Grid::get_potential_collisons(){
  //std::cout << this->gridArray[mouse_grid_positon.x + (mouse_grid_positon.y * width)].index << ", " << mouse_grid_positon.x + (mouse_grid_positon.y * width) << std::endl;
  //takes the current mouse position and checks if this "tile" has an index
  //index are assigned whne notes are generated of the size of note_objects array

  if(this->gridArray[mouse_grid_positon.x + (mouse_grid_positon.y * width)].index > 0){
      int index_current_mouse_position = this->gridArray[mouse_grid_positon.x + (mouse_grid_positon.y * width)].index;
      std::cout << "Hit Note Objects: " <<  this->gridArray[mouse_grid_positon.x + (mouse_grid_positon.y * width)].index << std::endl;
      //this->note_objects.erase(this->note_objects.begin() + (index_current_mouse_position - 1));
  }
}


void Grid::update(){
  this->mousePos = GetMousePosition();
  this->get_gridPosition();
  get_master_point();
  // std::cout << this->mouse_grid_positon.x << " " << this->mouse_grid_positon.y << std::endl;
  //std::cout << this->player_grid_position.x << " " << this->player_grid_position.y << std::endl;
}

void Grid::show_creation_rect(bool mode, Vector2 bounds){
  if(mode){
    DrawRectangleV(this->masterPoint, bounds, BLUE);
  }
}

void Grid::draw(){
  show_grid();
}
