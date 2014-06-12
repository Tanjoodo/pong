#ifndef KB_STATE_H
#define KB_STATE_H

#include "framework.h"

class KB_State
{
    public:
        KB_State();
        virtual ~KB_State() {}
        void Update(SDL_Event &event);
        void SetKey(int index, bool value) {keys[index] = value;}
        int GetKey(int index) {return keys[index];}
    protected:
    private:
        bool keys[1024] = {}; //The assignment is important, it initializes the array with zeroes.
};
#endif // KB_STATE_H
