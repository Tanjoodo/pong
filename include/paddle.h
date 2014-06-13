#ifndef PADDLE_H
#define PADDLE_H

#include "framework.h"
#include "aabb.h"
#include "game_object.h"

class Paddle : public GameObject
{
    public:
        void Update();
        void Draw(SDL_Renderer*);
        void MoveX(int direction);
        void MoveY(int direction);
        void SetTexture(const std::string &path, SDL_Renderer *ren);
        void UpScore() {++score;}
        void ResetScore() { score = 0;}
        int GetScore() {return score;}
    protected:
    private:
       // SDL_Texture *debug_ver;
       int score = 0;

};

#endif // PADDLE_H
