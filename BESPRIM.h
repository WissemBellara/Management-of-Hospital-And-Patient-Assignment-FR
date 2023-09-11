#ifndef _BESPRIM_H
#define _BESPRIM_H
#include "BESSDD.h"

BESOIN besCreer(void);
void besLire(BESOIN*);
void besDetruire (BESOIN);
void besAfficher(BESOIN);
void besAffecter(BESOIN*, BESOIN);
int besComparer(BESOIN, BESOIN);
void besCopier(BESOIN* , BESOIN);

#endif
