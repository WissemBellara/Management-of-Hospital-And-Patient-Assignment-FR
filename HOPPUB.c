#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HOPPUB.h"
#include "LSTBESPRIM.h"
HOPPUB publCreer()
{
    HOPPUB e ;
    BESOI n=lsbesCreer() ;
    e=(HOPPUB)malloc(sizeof(hopipubl)) ;
    e->b=n ;
    if (!e)
        printf ("Pas assez de memoire\n");
    return e ;
}

void publDetruire (HOPPUB e)
{
  free(e) ;
}

void publLire(HOPPUB *e)
{
}

void publAfficher(HOPPUB e)
{

printf("\nL'Hopital a pour Nom : %s  \nDans le gouvernorat de %s \nIl presente ces besoins :  \n",e->Nom,e->gov) ;
lsbesAfficher (e->b) ;
}

void publAffecter(HOPPUB *e,HOPPUB e2)
{
*e = e2 ;
}

int publComparer(HOPPUB e, HOPPUB e2)
{
return (strcmp(e->Nom,e2->Nom)) ;
 }
void publCopier(HOPPUB* e1, HOPPUB e2)
{strcpy((*e1)->Nom, e2->Nom);
strcpy((*e1)->gov, e2->gov);


}
