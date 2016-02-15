#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "SDL.h"
#include "SDL_image.h"

typedef struct {
	int refCount;
	char fileName[128];
	SDL_Surface image;
	int imageW, imageH;
	int frameW, frameH;
	int framePerLine;

}Sprite_t;

void initSpriteSystem();
void closeSpriteSystem();

Sprite_t* loadSprite();
void freeSprite(Sprite_t* sprite);
void drawSprite(Sprite_t *sprite, int frame, SDL_Renderer * renderer, int drawX, int drawY);

#endif