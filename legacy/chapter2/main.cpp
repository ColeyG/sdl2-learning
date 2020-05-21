#include <iostream>
#include <SDL.h>

bool gameRunning = false;
SDL_Window *gameWindow = 0;
SDL_Renderer *gameRenderer = 0;

bool init(const char *title, int xpos, int ypos, int height, int width, int flags)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    gameWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if (gameWindow != 0)
    {
      gameRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
    }
  }
  else
  {
    std::cout << "SDL did not initialize\n";
    return false;
  }

  return true;
}

void render()
{
  SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);

  SDL_RenderClear(gameRenderer);

  SDL_RenderPresent(gameRenderer);
}

int main(int argc, char *argv[])
{
  if (init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
  {
    gameRunning = true;
  }
  else
  {
    std::cout << "Something went wrong initializing this game\n";
    return 1;
  }

  while (gameRunning)
  {
    render();
  }
}
