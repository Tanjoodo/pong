#include "../include/kb_state.h"

void KB_State::Update(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {
        keys[event.key.keysym.scancode] = true;
    }
    else if (event.type == SDL_KEYUP)
    {
        keys[event.key.keysym.scancode] = false;
    }
}

KB_State::KB_State()
{

}
