#ifndef _LSTHOPPRIM_H
#define  _LSTHOPPRIM_H

#include "HOPPRIM.h"
#include "LSTHOPSDD.h"


NOEUDHOP noeudhopCreer (HOPITAL );
void noeudhopDetruire(NOEUDHOP );
LISTEHOP LISTEHOPCreer(void);
void LISTEHOPDetruire(LISTEHOP );
void LISTEHOPAfficher(LISTEHOP );
int estVidehop(LISTEHOP );
int estSatureehop(LISTEHOP );
int LISTEHOPTaille(LISTEHOP );
int insererhop (LISTEHOP , HOPITAL , int );
int supprimerhop (LISTEHOP , int );
HOPITAL recupererhop(LISTEHOP , int );
LISTEHOP LISTEHOPCopier(LISTEHOP );
int  LISTEHOPComparer (LISTEHOP ,LISTEHOP );

#endif
