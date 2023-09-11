#include <stdlib.h>
#include <stdio.h>
#include "LSTBESPRIM.H"

BESOI lsbesCreer(void) {

BESOI L;
BESOIN n ;
n=besCreer() ;
L = (BESOI) malloc(sizeof(be));
L->bes[1]=n ;
if(!L) {

printf(" \nProblème de mémoire") ;
exit(0) ;

}
L->lg = 0;
return(L);

}
void lsbesDetruire(BESOI L){
int i;
for(i = 1;i <= L->lg; i++)

besDetruire(L->bes[i]);

free(L);
}

int lsbesinserer (BESOI L, BESOIN e, int pos) {
int i;
int succee=1;
if (lsbesestSaturee(L)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {

for(i = L->lg; i>= pos; i--)

besAffecter(&L->bes[i+1],

L->bes[i]);
besAffecter(&L->bes[pos], e);
(L->lg)++;
}

}
return(succee);
}

int lsbessupprimer (BESOI L, int pos ) {
int i;
int succee=1;
if (lsbesestVide(L)) {

printf ("\nListe vide");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg)) {

printf ("\nPosition invalide");
succee=0;}

else {

besDetruire(L->bes[pos]);
for(i=pos;i<=L->lg;i++)
besAffecter(&L->bes[i],
L->bes[i+1]);

(L->lg)--;
}

}
return(succee);
}

BESOIN lsbesrecuperer(BESOI L, int pos) {
BESOIN elt= besCreer();
if (lsbesestVide(L))

printf ("\nListe vide");

else {

if ((pos < 1) || (pos > L->lg))

printf ("\nPosition invalide");

else

elt=(L->bes[pos]);

}

return(elt);
}

BESOI lsbesCopier(BESOI L){
BESOI LR = lsbesCreer();
int i;
BESOIN elt;
for(i = 1;i <= L->lg; i++) {
elt=besCreer();
besCopier(&elt , lsbesrecuperer(L,i));
lsbesinserer(LR, elt, i);
}
return LR;
}

int lsbesComparer (BESOI L1,BESOI L2 )
{
int test= 1;
int i=1;
if (lsbesTaille(L1) != lsbesTaille(L2)) test= 0;
while ((i<=lsbesTaille(L1)) && (test)) {
if (besComparer(lsbesrecuperer(L1,i),lsbesrecuperer(L2,i))!=0)
test=0;
i++;
}
return test;
}

void lsbesAfficher(BESOI L) {
int i;
for(i = 1; i <= L->lg; i++)

besAfficher(L->bes[i]);

}

int lsbesestVide(BESOI L) {
return (L->lg == 0);
}

int lsbesestSaturee(BESOI L) {
return (L->lg == LongMax);
}

int lsbesTaille(BESOI L) {
return (L->lg);
}
