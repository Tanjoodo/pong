#include "../include/framework.h"
#include "../include/paddle.h"
#include "../include/ball.h"
#include "kb_state.h"


int main(int argc, char** argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("Hello World!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);

    if (win == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

	SDL_Renderer *ren = nullptr;
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

    Paddle paddle1,                      paddle2;
    paddle1.SetTexture("assets/paddle.png", ren);
    paddle2.SetTexture("assets/paddle.png", ren);
    int w1, h1, w2, h2;
    SDL_QueryTexture(paddle1.GetTexture(), NULL, NULL, &w1, &h1);
    SDL_QueryTexture(paddle2.GetTexture(), NULL, NULL, &w2, &h2);
    paddle1.Setx(0 + 5);                      paddle2.Setx(SCREEN_WIDTH - w2  - 5);
    paddle1.Sety(SCREEN_HEIGHT / 2 - h1/2);   paddle2.Sety(SCREEN_HEIGHT / 2 - h2/2);

    KB_State kbstate;

    Ball ball;
    ball.SetTexture("assets/ball.png", ren);
    ball.Setx(SCREEN_WIDTH / 2 - 16);
    ball.Sety(SCREEN_HEIGHT / 2 - h1/2);



    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) quit = true;
            if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
                kbstate.Update(e);
        }

        if (kbstate.GetKey(SDL_SCANCODE_W))
            paddle1.MoveY(-5);
        if (kbstate.GetKey(SDL_SCANCODE_S))
            paddle1.MoveY(5);
        if (kbstate.GetKey(SDL_SCANCODE_UP))
            paddle2.MoveY(-5);
        if (kbstate.GetKey(SDL_SCANCODE_DOWN))
            paddle2.MoveY(5);
        if (kbstate.GetKey(SDL_SCANCODE_ESCAPE))
            quit = true;



        ball.Update(paddle1.GetAABB(), paddle2.GetAABB());

        SDL_RenderClear(ren);
        paddle1.Draw(ren);
        paddle2.Draw(ren);
        ball.Draw(ren);
        SDL_RenderPresent(ren);

    }

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}

