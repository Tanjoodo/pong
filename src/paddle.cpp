#include "../include/paddle.h"

void Paddle::Draw(SDL_Renderer *ren)
{
    renderTexture(texture, ren, x, y);
    //renderTexture(debug_ver, ren, 320, 0);
    Update_AABB();
}

void Paddle::MoveX(int direction)
{
    Setx(Getx() + direction);
    Update_AABB();
}

void Paddle::MoveY(int direction)
{
    if (Gety() + direction > 480) return;
    if (Gety() + direction < 0 - 128) return;
    Sety(Gety() + direction);
    Update_AABB();
}


void Paddle::SetTexture(const std::string &path, SDL_Renderer *ren)
{
    texture   = loadTexture(path, ren);
    //debug_ver = loadTexture("assets/debug_ver.png", ren);
}
