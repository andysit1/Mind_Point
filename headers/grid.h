#pragma once
#include <iostream>
#include "../include/raylib.h"
#include "../headers/note.h"
// #include "../headers/objects.h"
#include <vector>

struct Tile{
  Tile(int width, int height);
  Color color{BLUE};
  int index{0};
  Vector2 tile_size;
  Vector2 tile_position;
  void setIndex(int value);

  void update();
  void tile_update();

  float tile_timer{};
  bool interactable{false};
};

class Grid
{
public:
  Grid(int width, int height);
  void init();
  void update();
  void draw();
  void generate_grid(Tile& tile);

  //player -> grid interaction;
  void get_gridPosition();
  Vector2 mouse_grid_positon;
  Vector2 player_grid_position;

  //checks keys events
  void check_conditions();

  bool show_grid_lines{false};
  void show_grid();
  void show_creation_rect(bool mode, Vector2 bounds);

  //grid features
  void setColor(Color color);
  void getCollisionBox();
  void draw_tiles();
  void draw_hitbox_tiles();
  // //grid->objects
  // void set_objects(Objects& object);
  // void draw_objects();

  Vector2 mousePos;
  Vector2 current_pos;
  std::vector<Tile> gridArray{};
  std::vector<Tile> effectedArray{};
  std::vector<Vector2> hitboxArray{};
  // std::vector<Objects> objectArray{};

  //grid game features
  void ray_init();
  std::vector<Vector2> horizontal_rays{};
  std::vector<Vector2> vertical_rays{};
    //vertical ray
  void vertical_ray_draw();
    //hortizontal ray
  void horizontal_ray_draw();

  void tile_updater(); //runs on a diff timing
  void update_grid_game();
  int preivous_timer{};

  bool creation_mode{false};

  std::vector<Note> note_objects{};
  void generate_note(Vector2 note_size);
  void note_print();


  void currentNote(Note& note);
  Note current_note;

  void get_master_point();
  Vector2 masterPoint{};

  void get_potential_collisons();
  Vector2 gridify(Vector2 point);

  int width;
  int height;
  int grid_width;
  int grid_height;

};

