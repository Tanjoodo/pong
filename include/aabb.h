#ifndef AABB_H
#define AABB_H

#include "framework.h"

class AABB
{
    public:
        AABB();
        AABB(float X, float Y, int H, int W);
        virtual ~AABB();
        float x, y;
        int   w, h;
        bool Intersects(AABB aabb);
        bool Intersects(SDL_Rect rectangle);
    protected:
    private:
};

#endif // AABB_H
