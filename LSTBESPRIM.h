#ifndef _LSTBESPRIM_H
#define _LSTBESPRIM_H
#include "BESPRIM.H"
#include "LSTBESSDD.H"

BESOI lsbesCreer(void);
void lsbesDetruire(BESOI);
int lsbesestVide(BESOI);
int lsbesestSaturee(BESOI);
int lsbesTaille(BESOI);
BESOIN lsbesrecuperer(BESOI, int);
int lsbesinserer(BESOI, BESOIN,int);
int lsbessupprimer(BESOI, int);
void lsbesAfficher(BESOI);
BESOI lsbesCopier(BESOI);
int lsbesComparer(BESOI, BESOI);

#endif
