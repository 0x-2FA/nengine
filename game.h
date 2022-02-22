#ifndef GAME_H
#define GAME_H

#include <window.h>

namespace nengine
{
  class Game
  {
    public:
     Game();
     virtual ~Game();

     void Run();

     void CloseGame();

     virtual void OnInit() = 0;
     virtual void OnExit() = 0;

     void OnEvent(SDL_Event &event);

     /* 
     * Return current FPS.
     */
     const float GetFPS();

    private:

  };

}

#endif // GAME_H