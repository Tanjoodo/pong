#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "framework.h"
#include "aabb.h"

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        float Getx() {return x;}
        float Gety() {return y;}
        void Setx(float val);
        void Sety(float val);
        void SetTexture(const std::string &path, SDL_Renderer *ren);
        AABB GetAABB() {return aabb;}
        SDL_Texture * GetTexture() {return texture;}

    protected:
        void Update_AABB();
        float x = 0;
        float y = 0;
        SDL_Texture *texture;
        AABB aabb;
    private:
};

#endif // GAME_OBJECT_H
