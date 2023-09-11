#ifndef _HOPPRIM_h
#define _HOPPRIM_h
#include "HOPSDD.h"

HOPITAL HOPITALCreer(void);
void HOPITALLire(HOPITAL*);
void HOPITALDetruire (HOPITAL);
void HOPITALAfficher(HOPITAL);
void HOPITALAffecter(HOPITAL*, HOPITAL);
int HOPITALComparer (HOPITAL, HOPITAL);
void HOPITALCopier (HOPITAL* , HOPITAL);

#endif
