#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "SDL.h"
#include "Sprite.h"
//rwc tutoring position
typedef struct Entity_S
{
   int inuse;
   Sprite_t *sprite;
   int frame;
   Vect2D position;
   int nextThink;
   int thinkRate;
   int health, maxhealth;
   int inventory[10];
   int stamina, staminaMax;
   int state;
   Vect2D velocity;

   void (*think)(struct Entity_S*self);
   void (*draw)(struct Entity_S *self, SDL_Renderer *renderer);
   void (*free)(struct Entity_S *self);
   void(*update)(struct Entity_S *self);
   void (*touch)(struct Entity_S *self, struct Entity_S *other);
 
}Entity_t;

void entity_inizilization(Uint32 maxEntities);

Entity_t *entity_new();
void closeEntitySystem();

void entity_free(Entity_t **entity);


void entity_think_all();
void entity_free_all();
void entity_draw_all();

#endif