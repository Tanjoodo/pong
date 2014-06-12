#ifndef KB_INPUT_H
#define KB_INPUT_H

#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>

class KB_Input
{
    public:
        KB_Input();
        ~KB_Input();
        std::vector<SDL_Keysym> keybuffer;
        void Update(SDL_Event&);
    protected:
    private:

};

#endif // KB_INPUT_H


