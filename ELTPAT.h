#ifndef _ELTPAT_H
#define _ELTPAT_H


typedef struct patient {
char Nom[50] ;
char Prenom [50] ;
char Adr [100] ;
int age  ;
char M_chron [50][50] ;
struct patient *contact ;
char Cont_int [50] ;
char etat[8] ;
char region[20] ;
} patient,*ELEMENT ;
#endif // _ELTPAT_H
