#include "game_object.h"

GameObject::GameObject()
{
    texture = nullptr;
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(texture);
}

void GameObject::SetTexture(const std::string &path, SDL_Renderer *ren)
{
    if (texture != nullptr) SDL_DestroyTexture(texture);
    texture = loadTexture(path, ren);
    Update_AABB();
}

void GameObject::Setx(float val)
{
    x = val;
    Update_AABB();
}

void GameObject::Sety(float val)
{
    y = val;
    Update_AABB();
}

void GameObject::Update_AABB()
{
    aabb.x = x;
    aabb.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &aabb.w, &aabb.h);
}
