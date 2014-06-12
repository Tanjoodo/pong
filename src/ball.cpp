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

    right.x = 0;
    right.y = 0;
    right.h = SCREEN_HEIGHT;
    right.w = 0;

    left.x = SCREEN_WIDTH;
    left.y = 0;
    left.h = SCREEN_HEIGHT;
    left.w = 0;
}

Ball::~Ball()
{

}

void Ball::Update(AABB aabb1, AABB aabb2)
{
    float old_x = x;
    float old_y = y;
    y += v_direction;
    x += direction;
    Update_AABB();
    if (aabb.Intersects(aabb1))
    {
        if (direction == 1) direction = 5;
        direction *= -1;
        if (64 - y - aabb1.y == 0)
        {
            v_direction = 0;
        }
        else
        {
            v_direction = ((abs(y - aabb1.y)/(y - aabb1.y)) / 2) * 5 ;

        }

        x = old_x;
        y = old_y;
        Update_AABB();

    }
    else if (aabb.Intersects(aabb2))
    {
        if (direction == 1) direction = 5;
        direction *= -1;
        v_direction = (abs(y - aabb2.y)/(y - aabb2.y)) * 5;
    }

    if (aabb.Intersects(top) || aabb.Intersects(bottom))
        v_direction *= -1;

    if (aabb.Intersects(right))
    {
        direction = -5;
        v_direction = 1;
        x = SCREEN_WIDTH / 2 - 16;
        y = SCREEN_HEIGHT / 2- 64;

    }
    if (aabb.Intersects(left))
    {
        direction = 5;
        v_direction = 1;
        x = SCREEN_WIDTH / 2 - 16;
        y = SCREEN_HEIGHT / 2 - 64;
    }



}

void Ball::Draw(SDL_Renderer *ren)
{
    renderTexture(texture, ren, x, y);
}
