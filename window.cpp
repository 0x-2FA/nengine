#include "window.h"
#include "SDL2/SDL.h"

namespace nengine
{
  Window::Window(){}
  Window::~Window(){}

  int Window::CreateWindow(char *name, int width, int height, unsigned int flags)
  {
    Uint32 fl = SDL_WINDOW_OPENGL;

    if(flags & FULLSCREEN)
    {
      fl |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    if(flags & BORDERLESS)
    {
      fl |= SDL_WINDOW_BORDERLESS;
    }
  }
}