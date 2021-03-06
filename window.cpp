#include "window.h"
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include <stdio.h>

#include <string>

namespace nengine
{
  Window::Window(){}
  Window::~Window(){}

  int Window::CreateWindow(const char *name, int width, int height, unsigned int flags)
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


    sdl_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fl);

    if(sdl_window == nullptr)
    {
      printf("Could not create sdl window.\n");
      return -1;
    }

    SDL_GLContext ogl_context = SDL_GL_CreateContext(sdl_window);

    if(ogl_context == nullptr)
    {
      printf("Could not create OpenGL context.\n");
      return -1;
    }

    if(glewInit() != GLEW_OK)
    {
      printf("Could not init GLEW.\n");
    }

    // setting background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return 0;
  }

  int Window::GetWindowWidth()
  {
    return window_width;
  }

  int Window::GetWindowHeight()
  {
    return window_height;
  }

  void Window::SwapBuffer()
  {
    SDL_GL_SwapWindow(sdl_window);
  }
}