#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "ELTPRIM.h"


ELEMENT elementCreer()
{
    ELEMENT e ;

    e=(ELEMENT)malloc(sizeof(patient)) ;
    if (!e)
        printf ("Pas assez de memoire\n");
    return e ;
}

void elementDetruire (ELEMENT e)
{
  free(e) ;
}

void elementLire(ELEMENT *e)
{int x=1,i=0,r;



    printf("\nEntrez le Nom du Patient : ") ;
    scanf("%i",&r) ;
    gets((*e)->Nom) ;
    printf("\nEntrez le Prenom du Patient : ") ;
    gets ((*e)->Prenom) ;
    printf("\nEntrez l'Adresse du Patient : ") ;
    gets ((*e)->Adr) ;
    printf("\nEntrez l'Age du Patient : ") ;
    scanf("%i",&(*e)->age) ;
    printf("\nEntrez le Nombre des Maladies Chroniques du Patient : ") ;
    scanf("%i",&x) ;
for(i=0;i<x;i++)
{
    printf("\nEntrez La Maladie : ") ;
    scanf("%i",&r) ;
    gets((*e)->M_chron[i]) ;
}x=1;
int z=0;

while (x==1)
    {do
    {printf("\nEtait %s en contact avec quelqu'un ?(1 si oui sinon 0) : ", (*e)->Prenom) ;
    scanf("%i",&x) ;}
    while ((x!=0) && (x!=1)) ;
        z++;
    if (x==0)
        {break;}

   ELEMENT e1=elementCreer() ;
   elementLire(&e1) ;
   elementAffecter(&(*e)->contact,e1) ;
        }

do {
printf("\nEst-ce que la contamination de %s est  : \n1.Introduite \n2.Locale \n3.Provenance \n Entrez votre choix ici : ",(*e)->Prenom) ;
scanf("%i",&r) ;
} while ((r<1)|| (r>3)) ;
  if (r==1)
    strcpy((*e)->Cont_int,"Contamination Introduite") ;
  else if (r==2)
    strcpy((*e)->Cont_int,"Contamination Locale") ;
  else
    strcpy((*e)->Cont_int,"Contamination de Provenance") ;
  do {
    printf("\nEst ce que l'etat de %s est : \n1.NORMAL \n2.CRITIQUE \nEntrez votre choix :  ",(*e)->Prenom) ;
    scanf("%i",&r) ;
  } while ((r<1) || (r>2)) ;
    if (r==1)
    strcpy((*e)->etat,"NORMAL") ;
  else
    strcpy((*e)->etat,"CRITIQUE") ;
  printf("\nQuelle est le gouvernorat de %s : ",(*e)->Prenom ) ;
  scanf("%i",&r) ;
  gets((*e)->region) ;
}

void elementAfficher(ELEMENT e)
{ int i=0,tst=0;
    printf("\nNom : %s \nPrenom : %s \nAdresse : %s \nAge : %i \n",e->Nom,e->Prenom,e->Adr,e->age) ;
      while ((i<50) && (tst==0))
      {if (strcmp(e->M_chron[i],"")==0)
      {tst=1;
      if (i==0)
      printf("\nLe patient %s n'a aucune maladie chronique \n",e->Prenom) ;
      }
      else
      {printf("\nLe Patient %s a cette Maladie :\n",e->Prenom) ;
          printf("%s",e->M_chron[i]) ;
      i++;
      }
      }
i=0 ;
tst=0 ;

      printf("\nLa contamination de ce patient %s est-elle Introduite ? : %s",e->Prenom,e->Cont_int) ;
      printf("\nL'Etat de ce patient %s est : %s",e->Prenom,e->etat) ;
      Sleep(1) ;
      printf("\nle patient %s est issue de : Gouvernorat :%s Rue : %s",e->Prenom,e->region,e->Adr) ;
       if ((e->contact)==NULL)
      {printf("\nLe patient %s n'a etait pas en contact avec personne \n",e->Prenom) ;
      }
      else
      {printf("\n%s etait en contact avec :\n",e->Prenom) ;
          elementAfficher(e->contact) ;

      }


}
void elementAffecter(ELEMENT *e,ELEMENT e2)
{*e = e2 ;
}

int elementComparer(ELEMENT e, ELEMENT e2)
{

return 0 ;}
void elementCopier(ELEMENT* e1, ELEMENT e2)
{ int i ;
strcpy((*e1)->Nom, e2->Nom);
strcpy((*e1)->Prenom, e2->Prenom);
strcpy((*e1)->Adr, e2->Adr);
(*e1)->age = e2->age;
for (i=0;i<50;i++)
   strcpy((*e1)->M_chron[i], e2->M_chron[i]);
strcpy((*e1)->Cont_int, e2->Cont_int);
strcpy((*e1)->etat, e2->etat);
strcpy((*e1)->region, e2->region);
(*e1)->contact=e2->contact ;
}
