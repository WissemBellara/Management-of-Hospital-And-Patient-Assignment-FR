#ifndef _LSTPAT_H
#define  _LSTPAT_H
#include "ELTPRIM.h"


typedef struct structNoeud{
ELEMENT info ;
struct structNoeud *precedent;
struct structNoeud *suivant;}
structNoeud,*NOEUD;

typedef struct {
NOEUD tete ;
NOEUD queue ;
int lg;
}lastruct,*LISTE;

#endif
