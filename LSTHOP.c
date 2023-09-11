#include <stdlib.h>
#include <stdio.h>
#include "LSTHOPPRIM.h"

/* Implantation des primitives du TAD LISTE */


NOEUDHOP noeudhopCreer(HOPITAL e){
NOEUDHOP n;

n=(NOEUDHOP)malloc (sizeof(structNoeudhop));
if(!n)
    printf("\nplus d'espace");
else
{
    HOPITALAffecter(&n->info,e);
    n->suivant=NULL;
    n->precedent=NULL ;
}
return n ;}

void noeudhopDetruire(NOEUDHOP n){
HOPITALDetruire(n->info);
free(n);
}
LISTEHOP LISTEHOPCreer()
{
    LISTEHOP L ;
    L=(LISTEHOP)malloc(sizeof(lastructhop)) ;
    if(!L)
    printf("Memoire insuffisante") ;
    return L ;
}
void LISTEHOPDetruire(LISTEHOP L)
{NOEUDHOP q;
    q=L->tete ;
    while (q!=NULL)
        {HOPITALDetruire(q->info) ;
        q=q->suivant ;}
        free(L) ;
}
int insererhop (LISTEHOP L, HOPITAL e, int pos){
int i;NOEUDHOP n,q,p;
   int succee=1;

  if (estSatureehop(L)){
		printf ("\nListe saturée");
		succee=0;}
   else		{
			if   (
				(pos < 1) || (pos > L->lg + 1)) {
			printf ("\nPosition invalide");
			succee=0;}
				else	{
                        n=noeudhopCreer(e);
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

int supprimerhop (LISTEHOP L, int pos ){
	int i;
	int succee=1;
NOEUDHOP p,q;
if (estVidehop(L)){
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
                            noeudhopDetruire(q);
                            (L->lg)--;
                        }
						}
						return succee;
			}

int estVidehop(LISTEHOP L) {
	return (L->lg == 0);
}
int estSatureehop(LISTEHOP L) {
	NOEUDHOP temp ;
	int saturee =1;
	temp=(NOEUDHOP)malloc(sizeof(structNoeudhop));
	if(temp!=NULL){
        saturee=0;
        free(temp);
	}
	return saturee;
}

int LISTEHOPTaille(LISTEHOP L) {
   return (L->lg);
}

HOPITAL recupererhop(LISTEHOP L, int pos) {


	HOPITAL elt= HOPITALCreer();
int i;
NOEUDHOP p;
	if (estVidehop(L))
		printf ("\nListe vide");

	else		{
		if   ((pos < 1) || (pos > L->lg))
			printf ("\nPosition invalide");

				else {
                    p=L->tete;
                    for(i=1;i<pos;i++)
                        p=p->suivant;
                    HOPITALAffecter(&elt,p->info);
				}
	}
	return(elt);
}

void LISTEHOPAfficher(LISTEHOP L){
	int i;
	NOEUDHOP p;
	p=L->tete;
   for(i = 1;i <= L->lg; i++){
		HOPITALAfficher(p->info);
p=p->suivant;
}}


LISTEHOP LISTEHOPCopier(LISTEHOP L){

LISTEHOP LR = LISTEHOPCreer();

int i;
HOPITAL elt;

   for(i = 1;i <= L->lg; i++) {

	elt=HOPITALCreer();
		HOPITALCopier(&elt, recupererhop(L,i));

		insererhop(LR,elt, i);
	}
 return LR;
}


int  LISTEHOPComparer (LISTEHOP L1,LISTEHOP L2 )
{
int test= 1;
int i=1;

if (LISTEHOPTaille(L1) != LISTEHOPTaille(L2)) test= 0;

while ((i<=LISTEHOPTaille(L1)) && (test)) {
	   if (HOPITALComparer(recupererhop(L1,i),recupererhop(L2,i))!=0)
		test=0;
	i++;
}

return test;
}
