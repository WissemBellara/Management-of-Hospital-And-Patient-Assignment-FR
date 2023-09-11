#ifndef _LSTHOPPUBPRIM_H
#define  _LSTHOPPUBPRIM_H

#include "HOPPUBPRIM.h"
#include "LSTHOPPUBSDD.h"
#include "LSTHOPUB.H"



LISTEHOPPUB LISTEHOPPUBCreer(void);
void LISTEHOPPUBDetruire(LISTEHOPPUB );
void LISTEHOPPUBAfficher(LISTEHOPPUB );
int estVidehoppub(LISTEHOPPUB );
int estSatureehoppub(LISTEHOPPUB );
int LISTEHOPPUBTaille(LISTEHOPPUB );
int insererhoppub (LISTEHOPPUB , HOPPUB , int );
int supprimerhoppub (LISTEHOPPUB , int );
HOPPUB recupererhoppub(LISTEHOPPUB , int );
LISTEHOPPUB LISTEHOPPUBCopier(LISTEHOPPUB );
int  LISTEHOPPUBComparer (LISTEHOPPUB ,LISTEHOPPUB );

#endif
