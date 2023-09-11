#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "LSTPRIM.h"
/* Implantation des primitives du TAD LISTE */


NOEUD noeudcreer(ELEMENT e){
NOEUD n;

n=(NOEUD)malloc (sizeof(structNoeud));
if(!n)
    printf("\nplus d'espace");
else
{
    elementAffecter(&n->info,e);
    n->suivant=NULL;
    n->precedent=NULL ;
}
return n ;}

void noeudDetruire(NOEUD n){
elementDetruire(n->info);
free(n);
}
LISTE listeCreer()
{
    LISTE L ;
    L=(LISTE)malloc(sizeof(lastruct)) ;
    if(!L)
    printf("Memoire insuffisante") ;
    else {
        L->lg=0;
        L->tete=NULL;
        L->queue=NULL;
    }
    return L ;
}
void listeDetruire(LISTE L)
{NOEUD q;
    q=L->tete ;
    while (q!=NULL)
        {elementDetruire(q->info) ;
        q=q->suivant ;}
        free(L) ;
}
int inserer (LISTE L, ELEMENT e, int pos){
int i;NOEUD n,q,p;
   int succee=1;

  if (estSaturee(L)){
		printf ("\nListe saturée");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
                        n=noeudcreer(e);
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

int supprimer (LISTE L, int pos ){
	int i;
	int succee=1;
NOEUD p,q;
if (estVide(L)){
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
                            noeudDetruire(q);
                            (L->lg)--;
                        }
						}
						return succee;
			}

int estVide(LISTE L) {
	return (L->lg == 0);
}
int estSaturee(LISTE L) {
	NOEUD temp ;
	int saturee =1;
	temp=(NOEUD)malloc(sizeof(structNoeud));
	if(temp!=NULL){
        saturee=0;
        free(temp);
	}
	return saturee;
}

int listeTaille(LISTE L) {
   return (L->lg);
}

ELEMENT recuperer(LISTE L, int pos) {

	ELEMENT elt= elementCreer();
int i;
NOEUD p;
	if (estVide(L))
	//	printf ("\nListe vide");
Sleep(1) ;
	else		{
		if   ((pos < 1) || (pos > L->lg))
			//printf ("\nPosition invalide");
Sleep(1) ;
				else {
                    p=L->tete;
                    for(i=1;i<pos;i++)
                        {p=p->suivant;}
                    elementAffecter(&elt,p->info);
				}
	}
	return(elt);
}

void listeAfficher(LISTE L){
	int i;
	NOEUD p;
	p=L->tete;
   for(i = 1;i <= L->lg; i++){
		elementAfficher(p->info);
p=p->suivant;
}}


LISTE listeCopier(LISTE L){

LISTE LR = listeCreer();

int i;
ELEMENT elt;

   for(i = 1;i <= L->lg; i++) {

	elt=elementCreer();
		elementCopier(&elt, recuperer(L,i));

		inserer(LR,elt, i);
	}
 return LR;
}


int  listeComparer (LISTE L1,LISTE L2 )
{
int test= 1;
int i=1;

if (listeTaille(L1) != listeTaille(L2)) test= 0;

while ((i<=listeTaille(L1)) && (test)) {
	   if (elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
		test=0;
	i++;
}

return test;
}
