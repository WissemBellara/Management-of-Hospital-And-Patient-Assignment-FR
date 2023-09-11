#ifndef _LSTPERSONNEQ_H
#define _LSTPERSONNEQ_H
#include "ELTPERSONNEPRIM.H"
#include "ELTPERSONNEQ.h"
typedef struct structNoeudper{
PERSONNE info ;
struct structNoeudper *precedent;
struct structNoeudper *suivant;}
structNoeudper,*NOEUDPER;

typedef struct {
NOEUDPER tete ;
NOEUDPER queue ;
int lg;
}lastructper,*LISTEPER;
#endif // _LSTPERSONNEQ_H
