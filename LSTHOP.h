#ifndef _LSTHOP_H
#define  _LSTHOP_H

#include "HOPPRIM.h"



typedef struct structNoeudhop{
HOPITAL info ;
struct structNoeudhop *precedent;
struct structNoeudhop *suivant;}
structNoeudhop,*NOEUDHOP;

typedef struct {
NOEUDHOP tete ;
NOEUDHOP queue ;
int lg;
}lastructhop,*LISTEHOP;

#endif
