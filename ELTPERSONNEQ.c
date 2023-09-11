#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "ELTPERSONNEPRIM.H"

PERSONNE personnecreer()
{
    PERSONNE e;
    e=(PERSONNE)malloc(sizeof(personneq));
    if(!e)
        printf("Pas de memoire disponnible");
    return e;
}
void personnedetruire (PERSONNE e)
{
    free(e);
}
void personnelire (PERSONNE *e)
{
    int x=1,i=0,valide,vrai,f,jj,mm,aa,j1,m1,a1;
    int j2;
    int m2;
    int a2;

    char jour[4],mois[4],annee[8],jdb[40],ch[50];
printf("\nEntrez le Nom de la Personne en Quarantaine : ") ;
 scanf("%i",&f) ;
 gets((*e)->nom) ;
    printf("\nEntrez le Prenom de la Personne en Quarantaine : ") ;
    gets ((*e)->prenom) ;
    printf("\nEntrez l'Adresse de la Personne en Quarantaine : ") ;
    gets ((*e)->adresse) ;
    printf("\nEntrez l'Age de la Personne en Quarantaine : ") ;
    scanf("%i",&(*e)->age) ;
    printf("\nEntrez le Nombre des Maladies Chroniques de la Personne en Quarantaine : ") ;
    scanf("%i",&x) ;
for(i=0;i<x;i++)
{
    printf("\nEntrez La Maladie : ") ;
    gets((*e)->maladie_chro[i]) ;
}
   printf("\nEntrez le nombre de personnes qui etaient en contact avec le Personne : ") ;
    scanf("%i",&x) ;
    for (i=0;i<x;i++)
   {
       printf("\nEntrez le Prenom et Nom du personne en contact avec le Personne : ") ;
    gets((*e)->maladie_chro[i]) ; }

do {
printf("\nEst-ce que la contamination est introduite ? (Entrez VRAI si oui sinon FAUX (en Majuscule))  : ") ;
  scanf("%i",&f) ;
  gets(ch) ;
} while ((strcmp(ch,"VRAI")!=0)&&(strcmp(ch,"FAUX")!=0)) ;
  strcpy((*e)->contamination_intro,ch) ;

 time_t now;
  time(&now);
   struct tm *local = localtime(&now);

  jj = local->tm_mday;
  mm = local->tm_mon + 1;
  aa = local->tm_year + 1900;

  do
  {
      printf("Donner la date de debut de confinement (jj ensuite mm ensuite yyyy ) :\n");
      scanf("%s",ch);
      for(i=0;i<2;i++)
        jour[i]=ch[i];

      for(i=3;i<5;i++)
        mois [i-3]=ch[i];
      for(i=6;i<10;i++)
        annee[i-6]=ch[i];

      j1=atoi(jour);
      m1=atoi(mois);
      a1=atoi(annee);
printf("j1 = %i \nm1 = %i \na1= %i \n" ,j1,m1,a1) ;
       valide=0;
             switch(m1)
      {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          {if (j1<=31 && j1>=1)
            valide=1;}
          break;
      case 4: case 6: case 9: case 11:
        {if (j1<=30 && j1>=1)
            valide=1;}
        break;
      case 2:
       {if((a1%4==0)&&(a1%100!=0)&&(a1%400==0))
        {
            if (j1<=29 && j1>=1)
                valide=1;
            else if (j1<=28 && j1>=1)
                valide=1;
        }
            break;}
            default:
                valide=0;
      }

      if((mm==m1) && (j1>jj) && (a1==aa))
        {vrai=1;}
      else if ((m1>mm) && (j1>jj || j1<jj) && (j1<jj || j1==jj ) &&(aa==a1))
        {vrai=1;}
      else if ((a1>aa)&& (j1>jj || j1<jj) && (j1<jj || j1==jj ) && (m1>mm || m1<mm || m1==mm ))
         {vrai=1;}
         else if ((m1==mm) && (j1==jj) && (a1==aa))
         {vrai=1;}
      else vrai=0;

} while ((valide==0) || (vrai==0));
 strcpy(jdb,strcat(strcat(jour,mois),annee)) ;
strcpy((*e)->dateentr,jdb) ;

// date mtaa fin de confinement

if ((m1 ==12) && (j1 >17 ))
       m2=1;
    else if ((m1!=12)&&(j1>17))
 m2=m1+1;
else
    m2=m1;


   switch (m2){
   case 1:case 3:case 5:case 7:case 8 : case 10:case 12 :{
       if (j1<=17){
       j2=j1+14;
       printf ("jour de fin %i",j2);}
       else {
        j2=j1+14-31;
       printf("jour de retour %i",j2);}
     } break ;
   case 4: case 6:case 9 : case 11 :{
if (j1<=16){
   j2=j1+14;
       printf ("jour de fin %i",j2);}
else {
    j2=j1+14-30;
    printf("le jour de fin de confinnement est le :%i",j2);
}}break;
   case 2:{
       if (j1<=14){
        j2=j1+14;
       printf("le jour de fin de confinnement est le :%i",j2);}
       else {
        j2=j1+14-28;
        printf("le jour de fin de confinnement est le :%i",j2);}
       break;}

      }


       if ((m1==12)&&(j1>17))
        a2=a1+1;
       else
        a2=a1;

     printf("la date de fin de confinnement est :%i/%i/%i",j2,m2,a2) ;

}

void personneAfficher(PERSONNE e)
{ int i=0,tst=0;
    printf("\nNom : %s \nPrenom : %s \nAdresse : %s \nAge : %i \n",e->nom,e->prenom,e->adresse,e->age) ;
      while ((i<50) && (tst==0))
      {if (strcmp(e->maladie_chro[i],"")==0)
      {tst=1;
      if (i==0)
      printf("Le patient n'a aucune maladie chronique \n") ;
      }
      else
      {printf("Ce Patient a cette Maladie :\n") ;
          printf("%s",e->maladie_chro[i]) ;
      i++;
      }
      }
i=0 ;
tst=0 ;
 while ((i<50) && (tst==0))
      {if (strcmp(e->personne_contact[i],"")==0)
      {tst=1;
      if (i==0)
      printf("Le patient n'a etait pas en contact avec personne \n") ;
      }
      else
      {printf("Ce Patient etait en contact avec :\n") ;
          printf("%s",e->personne_contact[i]) ;
      i++;
      }
      }
      printf("La contamination de ce patient est-elle Introduite ? : %s",e->contamination_intro) ;
      printf("La date de debut de confinement pour cette personne est : %s",e->dateentr) ;
      printf("La date de fin de confinement pour cette personne est : 14 jours apres cette date %s",e->dateentr) ;
}
void personneAffecter(PERSONNE *e1,PERSONNE e2)
{
*e1=e2;
}

int personneComparer(PERSONNE e1, PERSONNE e2)
{
    return (e1->age-e2->age);
 }
void personneCopier(PERSONNE* e1, PERSONNE e2)
{
strcpy((*e1)->nom,e2->nom);
strcpy((*e1)->prenom,e2->prenom);
strcpy((*e1)->adresse,e2->adresse);
(*e1)->age=e2->age; // memcpy(*e1,e2,sizeof(personneq));
}

