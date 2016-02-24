#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SDL.h>
#include <SDL_image.h>
#include "vector.h"

typedef struct {
	int refCount;
	char fileName[128];
	SDL_Texture *image; //texture;
	Vect2D imageSize;
	int framePerLine;
	Vect2D frameSize;

}Sprite_t;

void initSpriteSystem(int maxSprites);
void closeSpriteSystem();

Sprite_t* loadSprite(char *filename, int frameW, int frameH);

void drawSprite(Sprite_t *sprite, int frame, SDL_Renderer *renderer, Vect2D position);

void freeSprite(Sprite_t **sprite);

#endif