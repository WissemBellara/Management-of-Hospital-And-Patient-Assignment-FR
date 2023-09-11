#ifndef _LSTHOT_H
#define  _LSTHOT_H

#include "HOTPRIM.h"



typedef struct structNoeudhot{
HOTEL info ;
struct structNoeudhot *precedent;
struct structNoeudhot *suivant;}
structNoeudhot,*NOEUDHOT;

typedef struct {
NOEUDHOT tete ;
NOEUDHOT queue ;
int lg;
}lastructhot,*LISTEHOT;

#endif
