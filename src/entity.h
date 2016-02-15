#ifndef __ENTITY__H
#define __ENTITY__H
#include "SDL.h"
#include "Sprite.h"

typedef struct Entity_S
{
   int inuse;
   Sprite_t *sprite;
   int frame;
   int x,y;
   int health, maxhealth;
   int inventory[10];
   int stamina, staminaMax;
   int state;
   int velocityX, velocityY;

   void (think)(struct Entity_S*self);
   void draw();
   void update();
   void free();
   
   	
}Entity_t;


#endif