#ifndef _VECT_H
#define _VECT_H
#include<math.h>
#include<stdlib.h>

typedef struct vector{
double x;
double y;
double z;
}vector;

vector *p;

double magnitude(vector *v1){
return (sqrt((v1->x*v1->x)+(v1->y*v1->y)+(v1->z*v1->z)));
}
	
vector * normalize(vector *v1){
double m = sqrt((v1->x*v1->x)+(v1->y*v1->y)+(v1->z*v1->z));
p=(vector *)malloc(sizeof(vector));
p->x=v1->x/m;
p->y=v1->y/m;
p->z=v1->z/m;
return p;
}
	
vector * negative(vector *v1){
p=(vector *)malloc(sizeof(vector));
p->x=-v1->x;
p->y=-v1->y;
p->z=-v1->z;
return p;
}
	
double dotproduct(vector *v1,vector *v2){
return (v1->x*v2->x+v1->y*v2->y+v1->z*v2->z);
}
	
vector * crossproduct(vector *v1,vector *v2){
p=(vector *)malloc(sizeof(vector));
p->x=v1->y*v2->z-v1->z*v2->y;
p->y= v1->z*v2->x-v1->x*v2->z;
p->z=v1->x*v2->y-v1->y*v2->x;
return p;
}
	
vector * vectadd(vector *v1,vector *v2){
p=(vector *)malloc(sizeof(vector));
p->x=v1->x+v2->x;
p->y=v1->y+v2->y;
p->z=v1->z+v2->z;
return p;
}

vector * vectsub(vector *v1,vector *v2){
p=(vector *)malloc(sizeof(vector));
p->x=v1->x-v2->x;
p->y=v1->y-v2->y;
p->z=v1->z-v2->z;
return p;
}

vector * vectmult(double scalar, vector *temp){
p=(vector *)malloc(sizeof(vector));
p->x=scalar*temp->x;
p->y=scalar*temp->y;
p->z=scalar*temp->z;
return p;
}

void vec(vector *a,double x,double y,double z){
a->x=x;
a->y=y;
a->z=z;
}

                

#endif
