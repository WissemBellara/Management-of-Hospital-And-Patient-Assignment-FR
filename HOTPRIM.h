#ifndef _HOTPRIM_h
#define _HOTPRIM_h
#include "HOTSDD.h"

HOTEL HOTELCreer(void);
void HOTELLire(HOTEL*);
void HOTELDetruire (HOTEL);
void HOTELAfficher(HOTEL);
void HOTELAffecter(HOTEL*,HOTEL);
int HOTELComparer (HOTEL,HOTEL);
void HOTELCopier (HOTEL*,HOTEL);

#endif
