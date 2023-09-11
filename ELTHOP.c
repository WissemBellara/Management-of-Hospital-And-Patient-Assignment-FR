

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HOPPRIM.h"

HOPITAL HOPITALCreer()
{
    HOPITAL e ;
    e=(HOPITAL)malloc(sizeof(hopital)) ;
if (!e)
        printf ("Pas assez de memoire\n");
return e ;
}

void HOPITALDetruire (HOPITAL e)
{
  free(e) ;
}

void HOPITALLire(HOPITAL *e)
{int d ;
char ch[50];
    printf("\nEntrez le Nom de l'hopital : ") ;
    scanf("%i",&d) ;
    gets((*e)->Nom) ;

    printf("\nEntrez l'Adresse de l'hopital : ") ;
    gets ((*e)->region) ;

    printf("\nEntrez le Nombre de lits disponibles en rea : ") ;
    scanf("%i",&((*e)->lits_rea)) ;

    printf("\nEntrez le nombre de lits disponibles ailleurs : ") ;
scanf("%i",&((*e)->lits_aill)) ;
    do {
printf("\nEst ce qu'il ya des salles disponibles pour les besoins specifiques comme les salles pour des patients qui font la dialyse ? : ");
    printf("veuillez repondre par 'oui' ou 'non' : ");

    scanf("%i",&d) ;
    gets(ch);}
    while ((strcmp(ch,"oui")!=0)&&(strcmp(ch,"non")!=0)) ;
    strcpy((*e)->sal_dis,ch) ;

    printf("\nQuel est le nombre de medecin specialises: ");
    scanf("%i",&((*e)->med_spe)) ;

     printf("\nQuel est le nombre de paramedicaux :");
scanf("%i",&((*e)->para)) ;
}




void HOPITALAfficher(HOPITAL e)
{
printf("\nNom : %s \nAdresse : %s \nNombre de lits disponibles en rea : %i \nNombre de lits disponibles ailleurs : %i \nNombre de medecin specilaises : %i \nNombre de paramedicaux : %i ",e->Nom,e->region,e->lits_rea,e->lits_aill,e->med_spe,e->para) ;

      if (strcmp(e->sal_dis,"oui")==0)
    printf("il y a des salles disponibles");
      else
      printf("il n'y a pas de salles disponibles");


      }

void HOPITALAffecter(HOPITAL *e,HOPITAL e2)
{
*e=e2;
}

int HOPITALComparer(HOPITAL e, HOPITAL e2)
{
if (strcmp(e->Nom,e2->Nom)==0)
return 0 ;
else
    return 1;
}
void HOPITALCopier(HOPITAL* e1, HOPITAL e2)
{
(*e1)->lits_rea=e2->lits_rea;
(*e1)->lits_aill=e2->lits_aill;
(*e1)->med_spe=e2->med_spe;
(*e1)->para=e2->para;

strcpy((*e1)->Nom,e2->Nom);
strcpy((*e1)->region,e2->region);
strcpy((*e1)->sal_dis,e2->sal_dis);
}
