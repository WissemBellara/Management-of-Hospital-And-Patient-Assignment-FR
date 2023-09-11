#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HOTPRIM.h"

HOTEL HOTELCreer()
{
    HOTEL e ;
    e=(HOTEL)malloc(sizeof(hotel)) ;
if (!e)
        printf ("Pas assez de memoire\n");
return e ;
}

void HOTELDetruire (HOTEL e)
{
  free(e) ;
}

void HOTELLire(HOTEL *e)
{ int d ;

    printf("\nEntrez le Nom de l'hotel : ") ;
    scanf("%i",&d) ;
    gets((*e)->Nom) ;

    printf("\nEntrez l'Adresse de l'hotel : ") ;
    gets ((*e)->Adr) ;

    printf("\nQuel est la capacite de l'hotel : ");
    scanf("%i",&((*e)->cap)) ;
}




void HOTELAfficher(HOTEL e)
{
printf("\nNom : %s \nAdresse : %s \ncap : %i  ",e->Nom,e->Adr,e->cap) ;
      }

void HOTELAffecter(HOTEL *e,HOTEL e2)
{
*e=e2;
}

int HOTELComparer(HOTEL e, HOTEL e2)
{
if (strcmp(e->Nom,e2->Nom)==0)
return 0 ;
else
    return 1;
}
void HOTELCopier(HOTEL* e1, HOTEL e2)
{
(*e1)->cap=e2->cap;
strcpy((*e1)->Nom,e2->Nom);
strcpy((*e1)->Adr,e2->Adr);

}

