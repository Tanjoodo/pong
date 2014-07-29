#include "../include/framework.h"
#include "../include/menu_option.h"

MenuOption::MenuOption(SDL_Texture *texture, int x, int y)
{
    this->texture = texture;
    this->x = x;
    this->y = y;
    SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
}

void MenuOption::Draw(SDL_Renderer *renderer)
{
    renderTexture(texture, renderer, x + 128 - w /2, y);
}


