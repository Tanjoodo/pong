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
        void Update(AABB, AABB);
        void Draw(SDL_Renderer *ren);
    protected:
    private:
        int direction = -5;
        int v_direction = 5;
        AABB bottom;
        AABB top;
        AABB right;
        AABB left;
        bool collided = false;
};
#endif // BALL_H
