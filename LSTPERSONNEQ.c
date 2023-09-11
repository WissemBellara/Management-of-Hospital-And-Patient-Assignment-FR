#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "LSTPRIMPERSONNE.h"
#include "ELTPERSONNEPRIM.h"
/* Implementation des primitives du TDA LISTE */


 NOEUDPER noeudpercreer(PERSONNE e){
NOEUDPER n;

n=(NOEUDPER)malloc (sizeof(structNoeudper));
if(!n)
    printf("\nplus d'espace");
else
{
    personneAffecter (&n->info,e);
    n->suivant=NULL;
    n->precedent=NULL ;
}
return n ;}

void noeudperDetruire(NOEUDPER n){
personnedetruire(n->info);
free(n);
}
LISTEPER listeperCreer()
{
    LISTEPER L ;
    L=(LISTEPER)malloc(sizeof(lastructper)) ;
    if(!L)
    printf("Memoire insuffisante") ;
    return L ;
}
void listeperDetruire(LISTEPER L)
{NOEUDPER q;
    q=L->tete ;
    while (q!=NULL)
        {personnedetruire(q->info) ;
        q=q->suivant ;}
        free(L) ;
}
int insererper (LISTEPER L, PERSONNE e, int pos){
int i;NOEUDPER n,q,p;
   int succee=1;

  if (estSatureeper(L)){
		printf ("\nListe saturée");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
                        n=noeudpercreer(e);
                if(L->lg==0)
                {
                    L->tete=n;
                    L->queue=n;
                }
else
{
    if(pos==1)
    {
        L->tete->precedent=n;
        n->suivant=L->tete;
        L->tete=n;
    }
    else
    {
        if(pos==(L->lg+1))
{
            L->queue->suivant=n;
            n->precedent=L->queue;
            L->queue=n;
        }
        else
        {
            q=L->tete;
for(i=1;i<pos;i++)
            {
                p=q;
q=q->suivant;
            }
            p->suivant=n;
n->precedent=p;
            n->suivant=q;
            q->precedent=n;

        }
    }
}
	(L->lg)++;
				}
			}
	return(succee);
}

int supprimerper (LISTEPER L, int pos ){
	int i;
	int succee=1;
NOEUDPER p,q;
if (estVideper(L)){
		printf ("\nListe vide");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
						if (L->lg==1)
                        {
                            q=L->tete;
L->tete=NULL;
                            L->queue=NULL;
}
                        else{
                            if(pos==1)
                            {
                                q=L->tete;
L->tete=L->tete->suivant;
L->tete->precedent=NULL;
                            }
                            else
                            {
                                if(pos==L->lg)
                                {
                                    q=L->queue;
L->queue=L->queue->precedent;
                                    L->queue->suivant=NULL;
}
                                else
                                {
                                    q=L->tete;
                                    for(i=1;i<pos;i++)
{
                                        p=q;q=q->suivant;}

                                        q->suivant->precedent=p;
                                        p->suivant=q->suivant;
}
                                }
                            }
                            noeudperDetruire(q);
                            (L->lg)--;
                        }
						}
						return succee;
			}

int estVideper(LISTEPER L) {
	return (L->lg == 0);
}
int estSatureeper(LISTEPER L) {
	NOEUDPER temp ;
	int saturee =1;
	temp=(NOEUDPER)malloc(sizeof(structNoeudper));
	if(temp!=NULL){
        saturee=0;
        free(temp);
	}
	return saturee;
}

int listeTailleper(LISTEPER L) {
   return (L->lg);
}

PERSONNE recupererper(LISTEPER L, int pos) {
PERSONNE elt=personnecreer ();
int i;
NOEUDPER p;
	if (estVideper(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else {
                    p=L->tete;
                    for(i=1;i<pos;i++)
                        p=p->suivant;
                  personneAffecter(&elt,p->info);
				}
	}
	return(elt);
}

void listeAfficherper(LISTEPER L){
	int i;
	NOEUDPER p;
	p=L->tete;
   for(i = 1;i <= L->lg; i++){
		personneAfficher(p->info);
p=p->suivant;
}}


LISTEPER listeCopierper(LISTEPER L){

LISTEPER LR = listeperCreer();

int i;
PERSONNE elt;

   for(i = 1;i <= L->lg; i++) {

	elt=personnecreer();
		personneCopier(&elt, recupererper(L,i));

		insererper(LR,elt, i);
	}
 return LR;
}


int  listeperComparer (LISTEPER L1,LISTEPER L2 )
{
int test= 1;
int i=1;

if (listeTailleper(L1) != listeTailleper(L2)) test= 0;

while ((i<=listeTailleper(L1)) && (test)) {
	   if (personneComparer(recupererper(L1,i),recupererper(L2,i))!=0)
		test=0;
	i++;
}

return test;
}
