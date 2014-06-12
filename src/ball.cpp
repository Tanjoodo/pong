#include "../include/framework.h"
#include "../include/ball.h"
#include <iostream>
#include <math.h>

Ball::Ball()
{
    top.x = 0;
    top.y = 0;
    top.h = 0;
    top.w = 640;

    bottom.x = 0;
    bottom.y = 480;
    bottom.h = 0;
    bottom.w = 640;

    right.x = 0;
    right.y = 0;
    right.h = 480;
    right.w = 0;

    left.x = 640;
    left.y = 0;
    left.h = 480;
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
            v_direction = (abs(y - aabb1.y)/(y - aabb1.y)) / 2;

        }

        x = old_x;
        y = old_y;
        Update_AABB();

    }
    else if (aabb.Intersects(aabb2))http://lists.gnu.org/archive/html/bug-bash/2001-02/msg00054.html
    {
        if (direction == 1) direction = 5;
        direction *= -1;
        v_direction = abs(y - aabb2.y)/(y - aabb2.y);
    }

    if (aabb.Intersects(top) || aabb.Intersects(bottom))
        v_direction *= -1;

    if (aabb.Intersects(right))
    {
        direction = -5;
        v_direction = 1;
        x = 320 - 16;
        y = 240 - 64;

    }
    if (aabb.Intersects(left))
    {
        direction = 5;
        v_direction = 1;
        x = 320 - 16;
        y = 240 - 64;
    }



}

void Ball::Draw(SDL_Renderer *ren)
{
    renderTexture(texture, ren, x, y);
}
