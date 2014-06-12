#include <kb_input.h>

KB_Input::KB_Input()
{

}

KB_Input::~KB_Input()
{

}

void KB_Input::Update(SDL_Event &e)
{
    //if ((e.type != SDL_KEYDOWN) || (e.type != SDL_KEYUP)) return;
    //old_keys = current_keys;
    //current_keys = kbsnapshot.GetLatestSnapshot(e);

    //std::cout << "old" << old_keys[SDL_SCANCODE_W] << std::endl;
    //std::cout << "current" << current_keys[SDL_SCANCODE_W] << std::endl;
}
