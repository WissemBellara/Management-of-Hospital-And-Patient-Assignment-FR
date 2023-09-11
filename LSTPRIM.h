#ifndef _LSTPRIM_H
#define  _LSTPRIM_H
#include "ELTPRIM.h"
#include "LSTSDD.h"

NOEUD noeudCreer(ELEMENT );
void noeudDetruire(NOEUD );
LISTE listeCreer(void);
void listeDetruire(LISTE );
void listeAfficher(LISTE );
int estVide(LISTE );
int estSaturee(LISTE );
int listeTaille(LISTE );
int inserer (LISTE , ELEMENT , int );
int supprimer (LISTE , int );
ELEMENT recuperer(LISTE , int );
LISTE listeCopier(LISTE );
int  listeComparer (LISTE ,LISTE );

#endif
