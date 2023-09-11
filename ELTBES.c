#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ELTBES.h"
BESOIN besCreer()
{
    BESOIN e ;
    e=(BESOIN)malloc(sizeof(Beso)) ;
    if (!e)
        printf ("Pas assez de memoire\n");
    return e ;
}

void besDetruire (BESOIN e)
{
  free(e) ;
}

void besLire(BESOIN *e)
{int n=0;
do {
    printf("\nS'agit il d'argent (Entrez 0 ) ou non (Entrez 1) : ") ;
    scanf("%i",&n) ;
} while ((n!=0) && (n!=1)) ;
(*e)->Nat=n ;
if (n==0){
    strcpy((*e)->Nom , "Argent") ;
    printf("\nEntrez le montant de l'argent : ") ;
    scanf("%i",&(*e)->disp) ;}
else
    {printf("\nEntrez le Nom du produit : ") ;
    scanf ("%s",((*e)->Nom)) ;
    printf("\nEntrez la quantite du Produit  : ") ;
    scanf("%i",&(*e)->disp) ;}
}

void besAfficher(BESOIN e)
{
if (e->Nat==0)
    {printf("\nIl s'agit de : Argent  \nMontant : %i \n",e->disp) ;
    }
else
{
printf("\nIl s'agit de : %s  \nQuantite : %i \n",e->Nom ,e->disp) ;
}
}
void besAffecter(BESOIN *e,BESOIN e2)
{
*e = e2 ;
}

int besComparer(BESOIN e, BESOIN e2)
{
return !(((e->Nat) == (e2->Nat)) && (!strcmp(e->Nom,e2->Nom)) && (e->disp==e2->disp)) ;
 }
void besCopier(BESOIN* e1, BESOIN e2)
{strcpy((*e1)->Nom, e2->Nom);
(*e1)->Nat = e2->Nat;
(*e1)->disp = e2->disp;
}
