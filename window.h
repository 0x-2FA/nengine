#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include <stdio.h>

namespace nengine
{
  enum WinFlags
  {
    FULLSCREEN = 0X1,
    BORDERLESS = 0X2
  };

  class Window
  {
    public:
      Window();
      ~Window();

      /* 
      * Create a window.
      */
      int CreateWindow(char *name,  int width, int height, unsigned int flags);
      
      /*
      * Return the width of the current window. 
      */
      int GetWindowWidth();

      /*
      * Return the height of the current window. 
      */
      int GetWindowHeight();

      void SwapBuffer();

    private:
      SDL_Window *sdl_window;
      int window_width;
      int window_height;
  };
}

#endif