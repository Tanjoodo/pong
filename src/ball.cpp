#include "../include/framework.h"
#include "../include/ball.h"
#include <iostream>
#include <math.h>

Ball::Ball()
{
    top.x = 0;
    top.y = 0;
    top.h = 0;
    top.w = SCREEN_WIDTH;

    bottom.x = 0;
    bottom.y = SCREEN_HEIGHT;
    bottom.h = 0;
    bottom.w = SCREEN_WIDTH;

    right.x = 0 - 32;
    right.y = 0;
    right.h = SCREEN_HEIGHT;
    right.w = 32;

    left.x = SCREEN_WIDTH;
    left.y = 0;
    left.h = SCREEN_HEIGHT;
    left.w = 32;

    impact_sound = Mix_LoadWAV("assets/ball.wav");
    edge_sound   = Mix_LoadWAV("assets/ball_edge.wav");
    score_sound  = Mix_LoadWAV("assets/ball_score.wav");
    if (impact_sound == nullptr || edge_sound == nullptr || score_sound == nullptr) std::cout << "error loading wav" << std::endl;

}

Ball::~Ball()
{
    SDL_DestroyTexture(texture);
}


int Ball::Update(AABB aabb1, AABB aabb2)
{
    y += v_direction;
    x += direction;
    Update_AABB();
    if (aabb.Intersects(aabb1))
    {
        if (!collided)
        {
            if (direction == 1) direction = 5;
            direction *= -1;
            if (64 - y - aabb1.y == 0)
            {
                v_direction = 0;
            }
            else
            {
                v_direction = ((abs(y - aabb1.y)/(y - aabb1.y)) / 2) * 5 ; //magic maths
            }

            Update_AABB();
            collided = true;
        }

        Mix_PlayChannel(-1, impact_sound, 0);

    }
    else if (aabb.Intersects(aabb2))
    {
        if (!collided)
        {
            if (direction == 1) direction = 5;
            direction *= -1;
            v_direction = (abs(y - aabb2.y)/(y - aabb2.y)) * 5;
            collided = true;
        }

        Mix_PlayChannel(-1, impact_sound, 0);
    }

    else if (aabb.Intersects(top) || aabb.Intersects(bottom))
    {
        v_direction *= -1;
        Mix_PlayChannel(-1, edge_sound, 0);
    }

    else if (aabb.Intersects(right))
    {
        direction = -10;
        v_direction = 1;
        x = SCREEN_WIDTH / 2 - 16;
        y = SCREEN_HEIGHT / 2- 64;

        collided = true;
        Mix_PlayChannel(-1, score_sound, 0);
        return 1;
    }
    else if (aabb.Intersects(left))
    {
        direction = 10;
        v_direction = 1;
        x = SCREEN_WIDTH / 2 - 16;
        y = SCREEN_HEIGHT / 2 - 64;
        collided = true;
        Mix_PlayChannel(-1, score_sound, 0);
        return 2;

    }

    else //no collision
    {
        collided = false;

    }
    return 0;



}

void Ball::Draw(SDL_Renderer *ren)
{
    renderTexture(texture, ren, x, y);
}
