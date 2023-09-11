#ifndef _ELTPERSONNEQ_H
#define _ELTPERSONNEQ_H
typedef struct{
char nom[30];
char prenom[30];
char adresse[30];
int age;
char maladie_chro [50][50];
char personne_contact[50][50];
char contamination_intro[5];
char dateentr [10] ;
}personneq ,*PERSONNE;
#endif // _ELTPERSONNEQ_H
