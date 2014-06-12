#include "../include/aabb.h"

AABB::AABB()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

AABB::AABB(float X, float Y, int H, int W)
{
    x = X;
    y = Y;
    w = W;
    h = H;
}

AABB::~AABB()
{

}

bool AABB::Intersects(AABB aabb)
{
    if ((x >= aabb.x) && (x <= aabb.x + aabb.w))
    {
        if ((y >= aabb.y) && (y <= aabb.y + aabb.h))
            return true;
    }

    if ((x + w >= aabb.x) && ((x + w) <= (aabb.x + aabb.w + w)))
    {
        if ((y + h >= aabb.y) && (y + h <= aabb.y + aabb.h + h))
            return true;
    }
    return false;
}
