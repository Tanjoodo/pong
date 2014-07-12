#include "framework.h"
#ifndef MENU_OPTION_H
#define MENU_OPTION_H

class MenuOption
{
    private:
    SDL_Texture *texture;
    int x, y, h, w;
    protected:

    public:
    MenuOption(SDL_Texture *texture, int x, int y);
    virtual ~MenuOption() {}
    void Draw(SDL_Renderer *renderer);
};

#endif // MENU_OPTION_H
