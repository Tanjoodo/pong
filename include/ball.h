#ifndef BALL_H
#define BALL_H

#include "framework.h"
#include "aabb.h"
#include "game_object.h"
#include "paddle.h"
class Ball : public GameObject
{
    public:
        Ball();
        virtual ~Ball();
        int Update(AABB, AABB);
        void Draw(SDL_Renderer *ren);
    protected:
    private:
        int direction = -10;
        int v_direction = 1;
        AABB bottom;
        AABB top;
        AABB right;
        AABB left;
        bool collided = false;
        Mix_Chunk *impact_sound; //sound for hitting paddles
        Mix_Chunk *edge_sound; //sound for hitting edges
        Mix_Chunk *score_sound; //sound for scoring
};
#endif // BALL_H
