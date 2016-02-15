#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct{
   float x,y;
}Vect2D;

typedef struct{
  union {float x; float r;};
  union {float y; float g;};
  union {float z; float b;};
}Vect3D;

typedef struct{
  union {float x; float r;};
  union {float y; float g;};
  union {float z; float b;};
  union {float w; float a;};
}Vect4D;

void multiply();
void set();
void negate();
void getlength();
void getlengthsq();
void crossproduct();
void scale();
void rotate(); 
void normalize(); 

#define ZERO 0;

#define vec2d_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y)
#define vec3d_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y,c.z=a.z+b.z)
#define vec4d_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y,c.z=a.z+b.z,c.w=a.w+b.w)

#define MAX(a,b) (a>b?a:b)
#define MAX(a,b) (a<b?a:b)


#endif