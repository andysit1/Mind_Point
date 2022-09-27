#include <iostream>
#include <cmath>
#include "../headers/settings.h"
#include "../headers/note.h"

int framesCounter = 0;


Note::~Note(){
  std::cout << "Note destroyed" << std::endl;
}

void Note::draw_attachments(){
  for(int i = 0; i < attachments.size(); i++){
    DrawCircleV(attachments[i], 5.0f, RED);
  }
}

void Note::check_collisions(){
    //body text collisions
  if(CheckCollisionPointRec(GetMousePosition(), text_box_title)){
    this->on_text_title = true;
  }else{
    this->on_text_title = false;
  }

  //body title collsisions
  if(CheckCollisionPointRec(GetMousePosition(), text_box_body)){
    this->on_text_body = true;
  }else{
    this->on_text_body = false;
  }
}


//need to change which text place
void Note::text_logic_updater(char* text_storage, bool on_text){
  if (on_text)
  {
    // Set the window's cursor to the I-Beam
    SetMouseCursor(MOUSE_CURSOR_IBEAM);
    // Get char pressed (unicode character) on the queue
    int key = GetCharPressed();
    // Check if more characters have been pressed on the same frame
    while (key > 0)
    {
      // NOTE: Only allow keys in range [32..125]
      if ((key >= 32) && (key <= 125) && (letter_count < MAX_INPUT_CHARS))
      {
        if(std::floor(MeasureText(text_storage, font_size) / 170) > this->previous_indent){
          text_storage[letter_count] = '\n';
          text_storage[letter_count+1] = '\0';
          letter_count++;
          this->previous_indent++;
        }
        std::cout << "3: " << letter_count << std::endl;
        //condition: if previous index is '\n' and the key != space then we=
        if(!(text_storage[letter_count - 1] == '\n' && key == 32)){
          std::cout << "1: " << letter_count << std::endl;
          text_storage[letter_count] = (char)key;
          text_storage[letter_count+1] = '\0'; // Add null terminator at the end of the string.
          letter_count++;
          std::cout << "2: " << letter_count << std::endl;
        }
      }
      key = GetCharPressed();  // Check next character in the queue
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
      std::cout << MeasureText(text_storage, font_size) << std::endl;

      if(std::floor(MeasureText(text_storage, font_size) / 170) < this->previous_indent){
        this->previous_indent--;
      }
      letter_count--;
      if (letter_count < 0) letter_count = 0;
      text_storage[letter_count] = '\0';
    }
    //std::cout << this->previous_indent << std::endl;
  }else{
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
  }
}


void Note::render_note_text(Rectangle text_box_size, char* text_storage, bool on_text){
  if (on_text) {
    DrawRectangleLines((int)text_box_size.x, (int)text_box_size.y, (int)text_box_size.width, (int)text_box_size.height, RED);
  }else{
    DrawRectangleLines((int)text_box_size.x, (int)text_box_size.y, (int)text_box_size.width, (int)text_box_size.height, DARKGRAY);
  }

  DrawText(text_storage, (int)text_box_size.x + 5 , (int)text_box_size.y + 8, font_size, MAROON); //draws the words
  DrawText(TextFormat("INPUT CHARS: %i/%i", letter_count, MAX_INPUT_CHARS), position.x, position.y + note_box.height, header_size, DARKGRAY);

  if (on_text)
  {
    if (letter_count < MAX_INPUT_CHARS)
    {
        // Draw blinking underscore char
        if (((framesCounter/20)%2) == 0) DrawText("_", (int)text_box_size.x + 8 + MeasureText(text_storage, font_size) + position.x, (int)text_box_size.y + 12 + position.y, font_size, MAROON);
    }else DrawText("Press BACKSPACE to delete chars...", position.x, position.y, font_size, GRAY);
  }
}


void Note::get_attachment_docks(){
  Rectangle left_rect{position.x - 10, position.y, 10, size.y};
  Rectangle right_rect{position.x + size.x, position.y, 10, size.y};
  Rectangle top_rect{position.x, position.y - 10, size.x, 10};
  Rectangle bottom_rect{position.x, position.y + size.y, size.x, 10};

  if (attachment_docks.size() > 0){
    attachment_docks.clear();
  }

  attachment_docks.push_back(left_rect);
  attachment_docks.push_back(right_rect);
  attachment_docks.push_back(top_rect);
  attachment_docks.push_back(bottom_rect);
}

//Progress Log -> got attachment calculated and drawn -> should be in class
//classes will provide easy change of color

void Note::draw_attachment_docks(){
  for (int i = 0 ; i < attachment_docks.size(); i++){
    DrawRectangleRec(attachment_docks[i], GREEN);
  }
}

void Note::render_note_box(){
  Rectangle inbox{position.x, position.y, size.x, size.y};

  Color left_rect_color{GREEN};
  draw_attachment_docks();
  DrawRectangleRec(inbox, LIGHTGRAY);
}

void Note::update(){
  this->text_box_title = {position.x, position.y, size.x, size.y / 2};
  this->text_box_body = {position.x, position.y + (size.y / 2), size.x, size.y / 2};
  this->note_box = {position.x, position.y, size.x, size.y};

  text_logic_updater(title_text, on_text_title);
  text_logic_updater(body_text, on_text_body);
}

void Note::draw(){
  render_note_box();

  render_note_text(text_box_title, title_text, on_text_title);
  render_note_text(text_box_body, body_text, on_text_body);
}

