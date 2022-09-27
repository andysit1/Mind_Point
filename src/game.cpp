#include <assert.h>
#include "../headers/canvas-system.h"
#include "../headers/game.h"

Canvas canvas;

Game::Game(int width, int height, int fps, const char* title)
{
  assert(!GetWindowHandle());
  SetTargetFPS(fps);
  InitWindow(width, height,title);
}

Game::~Game() noexcept
{
  assert(GetWindowHandle());
  CloseWindow();
}

bool Game::isGameRunning() const
{
  return WindowShouldClose();
}

void Game::InitGame()
{
  canvas.init();
}

void Game::Update()
{
  ClearBackground(RAYWHITE);
  canvas.Update();
}

void Game::Draw()
{
  canvas.Draw();
}

void Game::tick()
{
  BeginDrawing();
  Update();
  Draw();
  EndDrawing();
}
