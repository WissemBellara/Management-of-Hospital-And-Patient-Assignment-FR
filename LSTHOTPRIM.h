#ifndef _LSTHOTPRIM_H
#define  _LSTHOTPRIM_H

#include "HOTPRIM.h"
#include "LSTHOTSDD.h"


NOEUDHOT noeudhotCreer (HOTEL );
void noeudhotDetruire(NOEUDHOT );
LISTEHOT LISTEHOTCreer(void);
void LISTEHOTDetruire(LISTEHOT );
void LISTEHOTAfficher(LISTEHOT );
int estVidehot(LISTEHOT );
int estSatureehot(LISTEHOT );
int LISTEHOTTaille(LISTEHOT );
int insererhot (LISTEHOT , HOTEL , int );
int supprimerhot (LISTEHOT , int );
HOTEL recupererhot(LISTEHOT , int );
LISTEHOT LISTEHOTCopier(LISTEHOT );
int  LISTEHOTComparer (LISTEHOT ,LISTEHOT );

#endif
