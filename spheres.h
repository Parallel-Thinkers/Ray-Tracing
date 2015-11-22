#ifndef _SPH_H
#define _SPH_H
#include<math.h>
#include"vectors.h"

typedef struct spheres{
vector centre;
double radius;
double radius1;
vector color;
double reflectivity;
double transparency;
vector emcolor;
}sphere;

int sphere_ray_inter(sphere temp,vector rayorig,vector raydir,double *t0,double *t1)
{

//Source = http://www.lighthouse3d.com/tutorials/maths/ray-sphere-intersection/

vector l; 
//printf("shan=%f",temp.centre.x);
l.x=temp.centre.x-rayorig.x;
l.y=temp.centre.y-rayorig.y;
l.z=temp.centre.z-rayorig.z;
double t=dotproduct(&l,&raydir);
if(t<0)return 0;
double d=dotproduct(&l,&l)-t*t;
if(d>temp.radius1)return 0;
double th=sqrt(temp.radius1-d);
*t0=t-th;
*t1=t+th;
return 1;
}

void sph(vector a,double r,vector c,double re,double tr,vector em,sphere *p)
{
p->centre=a;
p->radius=r;
p->radius1=r*r;
p->color=c;
p->reflectivity=tr;
p->transparency=re;
p->emcolor=em;
}


#endif
