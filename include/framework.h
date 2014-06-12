#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"


void logSDLError(std::ostream, std::string&);

SDL_Texture* loadTexture(const std::string&, SDL_Renderer*);

SDL_Texture* renderText(const std::string&, const std::string&, SDL_Color, int, SDL_Renderer);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst,  SDL_Rect *clip = nullptr);

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip = nullptr);


#endif // FRAMEWORK_H
