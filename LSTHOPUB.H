#ifndef _LSTHOPUB_H
#define _LSTHOPUB_H
#include "HOPPUBPRIM.h"
#define LongMax 100 /* longueur maximale d'une liste */
typedef struct {
HOPPUB elementshop[LongMax]; /* tableau automatique */
int lg; /* taille logique de la liste */
} laStructHOPPUB,*LISTEHOPPUB;
#endif
