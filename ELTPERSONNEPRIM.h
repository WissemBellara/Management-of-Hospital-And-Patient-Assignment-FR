#ifndef _ELTPERSONNEPRIM_H
#define _ELTPERSONNERIM_H
#include "ELTSDDPERSONNE.H"

void personnelire (PERSONNE *);
void personneAfficher (PERSONNE);
void personneAffecter(PERSONNE *,PERSONNE);
void personneCopier (PERSONNE *,PERSONNE);
int personneComparer(PERSONNE ,PERSONNE );
void personnedetruire(PERSONNE);
PERSONNE personnecreer(void);
#endif // _ELTPRIM_H
