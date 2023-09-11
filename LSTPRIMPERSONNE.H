#ifndef _LSTPRIMPERSONNE_H
#define _LSTPRIMPERSONNE_H
#include "ELTPERSONNEPRIM.H"
#include "LSTSDDPERSONNE.H"
NOEUDPER noeudpercreer(PERSONNE );
void noeudperDetruire(NOEUDPER );
LISTEPER listeperCreer(void);
void listeperDetruire(LISTEPER );
void listeAfficherper(LISTEPER );
int estVideper(LISTEPER );
int estSatureeper(LISTEPER );
int listeTailleper(LISTEPER );
int insererper (LISTEPER , PERSONNE , int );
int supprimerper (LISTEPER ,int);
PERSONNE recupererper(LISTEPER , int );
LISTEPER listeCopierper(LISTEPER );
int  listeperComparer(LISTEPER ,LISTEPER );

#endif // _LSTPRIHMPERSONNE_H
