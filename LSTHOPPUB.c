#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LSTHOPUB.H"
#include "LSTBESPRIM.h"
LISTEHOPPUB LISTEHOPPUBCreer(void) {

LISTEHOPPUB L;
L = (LISTEHOPPUB) malloc(sizeof(laStructHOPPUB));
if(!L) {

printf(" \nProblème de mémoire") ;
exit(0) ;

}
L->lg = 0;
return(L);

}
void LISTEHOPPUBDetruire(LISTEHOPPUB L){
int i;
for(i = 1;i <= L->lg; i++)

publDetruire(L->elementshop[i]);

free(L);
}
int insererhoppub (LISTEHOPPUB L, HOPPUB e, int pos) {
int i;
int succee=1;
if ((L->lg==LongMax)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {

for(i = L->lg; i>= pos; i--)

publAffecter(&L->elementshop[i+1],

L->elementshop[i]);
publAffecter(&L->elementshop[pos], e);
(L->lg)++;
}

}
return(succee);
}
int supprimerhoppub (LISTEHOPPUB L, int pos ) {
int i;
int succee=1;
if (L->lg==0) {

printf ("\nListe vide");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg)) {

printf ("\nPosition invalide");
succee=0;}

else {

publDetruire(L->elementshop[pos]);
for(i=pos;i<=L->lg;i++)

publAffecter(&L->elementshop[i],
L->elementshop[i+1]);

(L->lg)--;
}

}
return(succee);
}
HOPPUB recupererhoppub( LISTEHOPPUB L, int pos) {
HOPPUB elt= publCreer();
if ((L->lg==0))

printf (" \n Liste vide");

else {

if ((pos < 1) || (pos > L->lg))

printf ("\nPosition invalide");

else

elt=(L->elementshop[pos]);

}

return(elt);
}
LISTEHOPPUB LISTEHOPPUBCopier(LISTEHOPPUB L){
LISTEHOPPUB LR = LISTEHOPPUBCreer();
int i;
HOPPUB elt;
for(i = 1;i <= L->lg; i++) {
elt=publCreer();
publCopier(&elt, recupererhoppub(L,i));
insererhoppub(LR, elt, i);
}
return LR;
}
int LISTEHOPPUBComparer (LISTEHOPPUB L1,LISTEHOPPUB L2 )
{
int test= 1;
int i=1;
if ((L1->lg) != (L2->lg)) test= 0;
while ((i<=(L1->lg)) && (test)) {
if (publComparer(recupererhoppub(L1,i),recupererhoppub(L2,i))!=0)
test=0;
i++;
}
return test;
}
void LISTEHOPPUBAfficher(LISTEHOPPUB L) {
int i;
for(i = 1; i <= L->lg; i++)

publAfficher(L->elementshop[i]);

}
int estVidehoppub(LISTEHOPPUB L) {
return (L->lg == 0);
}
int estSatureehoppub(LISTEHOPPUB L) {
return (L->lg == LongMax);
}
int LISTEHOPPUBTaille(LISTEHOPPUB L) {
return (L->lg);
}
