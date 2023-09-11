#ifndef _HOPPUBPRIM_H
#define _HOPPUBPRIM_H
#include "HOPPUBSDD.h"

HOPPUB publCreer(void);
void publLire(HOPPUB*);
void publDetruire (HOPPUB);
void publAfficher(HOPPUB);
void publAffecter(HOPPUB*, HOPPUB);
int publComparer(HOPPUB, HOPPUB);
void publCopier(HOPPUB* , HOPPUB);

#endif
