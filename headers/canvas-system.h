#pragma once
#include "../include/raylib.h"
#include "grid.h"

struct Canvas{
std::vector<Note> selected_notes{};
void events_manager_input();
void events_manager_collision();
void draw_notes_and_update();
void init();
void Draw();
void Update();

bool create_mode{false};
void creation_mode_logic();
};