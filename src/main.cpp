#include "../include/framework.h"
#include "../include/paddle.h"
#include "../include/ball.h"
#include "../include/kb_state.h"
#include "../include/menu_option.h"
#include "../include/globals.h"
#include <sstream>

bool menu();

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

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
        std::cout << "audio init error" << std::endl;
        return 1;
	}

	TTF_Init();
	TTF_Font *font = TTF_OpenFont("assets/alterebro-pixel-font.ttf", 150);

    Paddle paddle1,                      paddle2;
    paddle1.SetTexture("assets/paddle.png", ren);
    paddle2.SetTexture("assets/paddle.png", ren);
    int w1, h1, w2, h2;
    SDL_QueryTexture(paddle1.GetTexture(), NULL, NULL, &w1, &h1);
    SDL_QueryTexture(paddle2.GetTexture(), NULL, NULL, &w2, &h2);
    paddle1.Setx(0 + 5);                      paddle2.Setx(SCREEN_WIDTH - w2  - 5);
    paddle1.Sety(SCREEN_HEIGHT / 2 - h1/2);   paddle2.Sety(SCREEN_HEIGHT / 2 - h2/2);


    Ball ball;
    ball.SetTexture("assets/ball.png", ren);
    ball.Setx(SCREEN_WIDTH / 2 - 16);
    ball.Sety(SCREEN_HEIGHT / 2 - h1/2);


    SDL_Texture *scoretext = renderText("0      0", "assets/alterebro-pixel-font.ttf", white, 150, ren);
    std::ostringstream ss;
    int score_w, score_h;
    SDL_QueryTexture(scoretext, NULL, NULL, &score_w, &score_h);

    bool quit = menu();

    bool pause = false;
    while (!quit)
    {
        //Update
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) quit = true;
            if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
                kbstate.Update(e);
        }

        if (!pause)
        {
            if (kbstate.GetKey(SDL_SCANCODE_W))
                paddle1.MoveY(-5);
            if (kbstate.GetKey(SDL_SCANCODE_S))
                paddle1.MoveY(5);
            if (kbstate.GetKey(SDL_SCANCODE_UP))
                paddle2.MoveY(-5);
            if (kbstate.GetKey(SDL_SCANCODE_DOWN))
                paddle2.MoveY(5);
            if (kbstate.GetKey(SDL_SCANCODE_ESCAPE))
                quit = menu();


            int ball_status = ball.Update(paddle1.GetAABB(), paddle2.GetAABB());
            if (ball_status == 1)
            {
                paddle2.UpScore();
            }
            else if (ball_status == 2)
            {
                paddle1.UpScore();
            }

            if (ball_status)
            {
                SDL_DestroyTexture(scoretext); //We don't need the old texture anymore.
                ss.str(std::string());
                ss << paddle1.GetScore() << "      " << paddle2.GetScore();
                scoretext = renderText(ss.str(), font,white,150,ren);
                //SDL_QueryTexture(scoretext, NULL, NULL, &score_w, &score_h);
            }
        }


        //Draw
        SDL_RenderClear(ren);
        if (pause)
        {

        }
        renderTexture(scoretext, ren, SCREEN_WIDTH / 2 - score_w / 2, 0);
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

bool menu()
{
    bool play = false;
    bool quit = false;
    SDL_Texture *selection = loadTexture("assets/selection.png", ren);
    int selec_location = 0; //I know it's missing a t, I'll leave it this way.
    int max_select = 1;

    bool prev_down_key = false;
    bool prev_up_key = false;

    SDL_Texture *play_text = renderText("Play","assets/alterebro-pixel-font.ttf", white, 64, ren);
    SDL_Texture *exit_text = renderText("Exit","assets/alterebro-pixel-font.ttf", white, 64, ren);
    MenuOption play_option(play_text, SCREEN_WIDTH / 2 - 128, 128);
    MenuOption exit_option(exit_text, SCREEN_WIDTH / 2 - 128, 128 + 64);


    while (!play)
    {
       while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
                kbstate.Update(e);
        }

        if (kbstate.GetKey(SDL_SCANCODE_RETURN))
           {
               switch(selec_location)
               {
                   case 0:
                    play = true;
                    break;
                   case 1:
                    play = true;
                    quit = true; //Skip game loop
                    break;
               }
           }

        if (kbstate.GetKey(SDL_SCANCODE_DOWN))
        {
            if (!prev_down_key)
            {
                if (selec_location < max_select)
                    ++selec_location;
                else
                    selec_location = 0;

                prev_down_key = true;
            }
        }
        else
            prev_down_key = false;

        if (kbstate.GetKey(SDL_SCANCODE_UP))
        {
            if (!prev_up_key)
            {
                if (selec_location > 0)
                    --selec_location;
                else
                    selec_location = max_select;

                prev_up_key = true;
            }
        }
        else
            prev_up_key = false;

        SDL_RenderClear(ren);
        exit_option.Draw(ren);
        play_option.Draw(ren);
        renderTexture(selection, ren, 0 + SCREEN_WIDTH / 2 - 128, 128 + 64 * selec_location);
        SDL_RenderPresent(ren);
    }

    return quit;
}
