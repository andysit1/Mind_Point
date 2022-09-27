#pragma once
#include <iostream>
#include "../include/raylib.h"
// #include "../headers/objects.h"
#include <vector>


#define MAX_INPUT_TITLE     20
#define MAX_INPUT_CHARS     100


struct Note{
  ~Note();
  void update();
  void draw();
  void render_note_box();
  void draw_attachments();
  void select();
  void check_collisions();

  Vector2 gui_position{};
  Vector2 position{};
  Vector2 size{};

  bool on_text_title{false};
  bool on_text_body{false};


  void render_note_text(Rectangle text_box_size, char* text_storage, bool on_text);
  void text_logic_updater(char* text_storage, bool on_text);

  Rectangle text_box_title;
  Rectangle text_box_body;

  Rectangle note_box;


  int header_size{16};
  int font_size{15};
  int line_space{0};
  int previous_indent{0};

  char body_text[MAX_INPUT_CHARS + 1] = "\0";
  char title_text[MAX_INPUT_TITLE + 1] = "\0";


  int letter_count{0};
  int body_letter_count{0};

  float delete_cooldown{0};

  std::vector<Note> attached_notes{};
  std::vector<Vector2> attachments{};

  //note attachment methods

  void get_attachment_docks(); //return 4 rectangle locations -> should clear before running
  void draw_attachment_docks();
  std::vector<Rectangle> attachment_docks{};



  bool selected{false};
};