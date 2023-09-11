#include <stdlib.h>
#include <stdio.h>
#include "LSTHOTPRIM.h"

/* Implantation des primitives du TAD LISTE */


NOEUDHOT noeudhotCreer(HOTEL e){
NOEUDHOT n;

n=(NOEUDHOT)malloc (sizeof(structNoeudhot));
if(!n)
    printf("\nplus d'espace");
else
{
    HOTELAffecter(&n->info,e);
    n->suivant=NULL;
    n->precedent=NULL ;
}
return n ;}

void noeudhotDetruire(NOEUDHOT n){
HOTELDetruire(n->info);
free(n);
}
LISTEHOT LISTEHOTCreer()
{
    LISTEHOT L ;
    L=(LISTEHOT)malloc(sizeof(lastructhot)) ;
    if(!L)
    printf("Memoire insuffisante") ;
    return L ;
}
void LISTEHOTDetruire(LISTEHOT L)
{NOEUDHOT q;
    q=L->tete ;
    while (q!=NULL)
        {HOTELDetruire(q->info) ;
        q=q->suivant ;}
        free(L) ;
}
int insererhot (LISTEHOT L, HOTEL e, int pos){
int i;NOEUDHOT n,q,p;
   int succee=1;

  if (estSatureehot(L)){
		printf ("\nListe saturée");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
                        n=noeudhotCreer(e);
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

int supprimerhot (LISTEHOT L, int pos ){
	int i;
	int succee=1;
NOEUDHOT p,q;
if (estVidehot(L)){
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
                            noeudhotDetruire(q);
                            (L->lg)--;
                        }
						}
						return succee;
			}

int estVidehot(LISTEHOT L) {
	return (L->lg == 0);
}
int estSatureehot(LISTEHOT L) {
	NOEUDHOT temp ;
	int saturee =1;
	temp=(NOEUDHOT)malloc(sizeof(structNoeudhot));
	if(temp!=NULL){
        saturee=0;
        free(temp);
	}
	return saturee;
}

int LISTEHOTTaille(LISTEHOT L) {
   return (L->lg);
}

HOTEL recupererhot(LISTEHOT L, int pos) {


	HOTEL elt= HOTELCreer();
int i;
NOEUDHOT p;
	if (estVidehot(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else {
                    p=L->tete;
                    for(i=1;i<pos;i++)
                        p=p->suivant;
                    HOTELAffecter(&elt,p->info);
				}
	}
	return(elt);
}

void LISTEHOTAfficher(LISTEHOT L){
	int i;
	NOEUDHOT p;
	p=L->tete;
   for(i = 1;i <= L->lg; i++){
		HOPITALAfficher(p->info);
p=p->suivant;
}}


LISTEHOT LISTEHOTCopier(LISTEHOT L){

LISTEHOT LR = LISTEHOTCreer();

int i;
HOTEL elt;

   for(i = 1;i <= L->lg; i++) {

	elt=HOTELCreer();
		HOTELCopier(&elt, recupererhot(L,i));

		insererhot(LR,elt, i);
	}
 return LR;
}


int  LISTEHOTComparer (LISTEHOT L1,LISTEHOT L2 )
{
int test= 1;
int i=1;

if (LISTEHOTTaille(L1) != LISTEHOTTaille(L2)) test= 0;

while ((i<=LISTEHOTTaille(L1)) && (test)) {
	   if (HOTELComparer(recupererhot(L1,i),recupererhot(L2,i))!=0)
		test=0;
	i++;
}

return test;
}

