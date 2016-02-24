#include "Sprite.h"
#include "stdio.h"
#include "simple_logger.h"
#include <stdio.h>
#include <stdlib.h>

Sprite_t *spriteList=NULL;
Uint32 MaxSprites =0;

void initSpriteSystem(int maxSprites){
	if(maxSprites==0){
		slog("cannot allocate 0 sprites");
		return;
	}
	spriteList= (Sprite_t *)malloc(sizeof(Sprite_t)*maxSprites);
	if(!spriteList){
		slog("failed to allocate sprite system");
		return;
	}
	memset(spriteList,0,sizeof(Sprite_t)*maxSprites);
	MaxSprites=maxSprites;
	atexit(closeSpriteSystem);

}

void closeSpriteSystem(){
	int i;
	if(!spriteList){
		return;
	}

	for(i=0; i< MaxSprites;i++){
		if(spriteList[i].image != NULL){
			SDL_DestroyTexture(spriteList[i].image);
		}
	}
	free(spriteList);
	spriteList=NULL;
	MaxSprites=0;

}


Sprite_t* loadSprite(char *filename, int frameW, int frameH){
	int i;
	SDL_Surface *surface;
	Sprite_t *sprite =NULL;
	if(!spriteList){
		slog("error: using sprite system uninitialized");
		return NULL;
	}
	for(i=0;i<MaxSprites;i++)
	{
		if(spriteList[i].refCount==0)
			continue;
		if(strcmp(spriteList[i].fileName,filename)==0)
		{
			spriteList[i].refCount++;
			return &spriteList[i];
		}

	}

	surface= IMG_Load(filename);
	if (!surface)
    {
        slog("failed to load file %s, re: %s",filename,SDL_GetError());
        return NULL;
    }
    
    
    return sprite;
}

void freeSprite(Sprite_t **sprite)
{
    Sprite_t *target;
    if (!sprite)return;
    if (!*sprite)return;
    target = *sprite;
    target->refCount--;
    if (target->refCount <= 0)
    {
        SDL_DestroyTexture(target->image);
        memset(target,0,sizeof(Sprite_t));
    }
    *sprite = NULL;


}

