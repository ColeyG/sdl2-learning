#include <iostream>
#include <SDL.h>

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;

int main(int argc, char *args[])
{
  // std::cout << "Hello, world!\n";
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow("Asdf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 500, SDL_WINDOW_SHOWN);

    if (g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
    else
    {
      std::cout << "SDL Could not initialize\n";
      return 1;
    }

    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(g_pRenderer);

    SDL_Delay(5000);
    SDL_Quit();

    return 0;
  }
}
