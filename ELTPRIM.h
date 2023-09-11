#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.h"

ELEMENT elementCreer(void);
void elementLire(ELEMENT*);
void elementDetruire (ELEMENT);
void elementAfficher(ELEMENT);
void elementAffecter(ELEMENT*, ELEMENT);
int elementComparer(ELEMENT, ELEMENT);
void elementCopier(ELEMENT* , ELEMENT);

#endif
