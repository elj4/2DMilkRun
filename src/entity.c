#include "entity.h"
#include "simple_logger.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "stdio.h"
#include "vector.h"

static Entity_t *EntityList=NULL;
static Uint32 MaxEntities =0;


void initEntitySystem(int maxEntities){
	if(maxEntities==0){
		slog("cannot allocate 0 Entities");
		return;
	}
	EntityList= (Entity_t *)malloc(sizeof(Entity_t)*maxEntities);
	if(!EntityList){
		slog("failed to allocate Entity system");
		return;
	}
	memset(EntityList,0,sizeof(Entity_t)*maxEntities);
	MaxEntities=maxEntities;
	atexit(closeEntitySystem);

}

void closeEntitySystem(){
	int i;
	Entity_t *ent;
	for(i=0; i<MaxEntities;i++){
		ent= &EntityList[i];
		entity_free(&ent);
	}
	free(EntityList);
};

Entity_t *entity_new(){
	int i;
	for(i=0;i < MaxEntities; i++){
		if(EntityList[i].inuse){
			continue;
		}
		memset(&EntityList[i],0,sizeof(Entity_t));
		/*some default values should go here*/
		EntityList[i].inuse=1;
		return &EntityList[i];
	}
	return NULL;
}

void entity_free(Entity_t **entity){
	Entity_t *self;
	if(!entity) return;
	if(!*entity) return;
	self = *entity;
	freeSprite(&self->sprite);
	*entity =NULL;
}

void entity_think_all(){
	int i;
	for(i=0; i < MaxEntities;i++){
		if(!EntityList[i].inuse){
			continue;
		}
		if(!EntityList[i].think){
			continue;
		}

		EntityList[i].think(&EntityList[i]);
	}
}

void entity_update_all(){
	int i;
	for(i=0; i< MaxEntities; i++){
		if(!EntityList[i].inuse){
			continue;
		}

		vec2d_add(EntityList[i].position,EntityList[i].velocity, EntityList[i].position);

		if(!EntityList[i].update){
			continue;
		}

		EntityList[i].update(&EntityList[i]);
	}
}
void entity_free_all(){};
void entity_draw_all(){};