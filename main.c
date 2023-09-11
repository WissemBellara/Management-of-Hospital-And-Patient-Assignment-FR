#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LSTPRIM.h"
#include "LSTHOPPRIM.h"
#include "LSTHOTPRIM.h"
#include "LSTPRIMPERSONNE.h"
#include "ELTPERSONNEPRIM.h"
#include "HOPPUBPRIM.h"
#include "LSTBESPRIM.h"
#include "LSTHOPPUBPRIM.h"
 #include "LSTHOPUB.H"
int rech_hop (LISTEHOP L,char x[])
{
    int i=1,tst=0 ;
    while((i<=L->lg) && (tst==0))
      {if (strcmp(x,(recupererhop(L,i))->Nom)!=0)
        i++;
    else tst=1 ;
      }
      if (tst==0)
        i=0;
    return i ;
}
int rech_hot (LISTEHOT L,char x[])
{
    int i=1,tst=0 ;
    while((i<=L->lg) && (tst==0))
      {if (strcmp(x,(recupererhot(L,i)->Nom))!=0)
        i++;
    else tst=1 ;
      }
      if (tst==0)
        i=0;
    return i ;
}
int rech_hoppub (LISTEHOPPUB L,char x[])
{
    int i=1,tst=0 ;
    while((i<=L->lg) && (tst==0))
      {if (strcmp(x,(recupererhoppub(L,i)->Nom))!=0)
        i++;
    else tst=1 ;
      }
      if (tst==0)
        i=0;
    return i ;
}


int occ_reg (LISTE L, char ch[])
{int nbocc=0,i ;
for (i=0;i<=L->lg;i++)
{if (strcmp((recuperer(L,i))->region,ch)==0)
    nbocc++;
}
return nbocc ;
}
int Numerique (char x[])
{int v=1,i=0 ;
while ((i<strlen(x)) && (v==1))
{if ((x[i]>='0') && (x[i]<='9'))
    i++;
else v=0 ;
    }
    return v ; }
    int rech_nomprenom(LISTE L)
    {int i=1,v=0,tst=0;
    char NM[50],PR[50];
    printf("\nEntrez Nom : ") ;
    gets (NM) ;
    printf("\nEntrez Prenom : ") ;
    gets (PR) ;
    while ((i<=L->lg) && (tst==0))
        {if ((strcmp(NM,(recuperer(L,i)->Nom))==0) && strcmp(PR,recuperer(L,i)->Prenom)==0)
            {tst=1;
            v=i ;}}
    if (tst==0)
        {printf("Le patient n'existe pas");}
        return v;
    }

  int rech_besoin(BESOI L)
    {int i=1,v=0,f,zeta,tst=0;
    char be[50] ;
    do
    {printf("\nS'agit il d'argent (entrez 1 ) ou pas (entrez 0) : ") ;
    scanf("%i",&f);}
    while ((f!=0) && (f!=1)) ;
        if (f==1)
        {while(i<=L->lg)
         {if (strcmp(lsbesrecuperer(L,i)->Nom,"Argent")==0)
         tst=1 ;
         else
            i++;}
if (tst==1)
    v=i;
else
    v=0 ;
        }
else if (f==0)
    {printf("\nEntrez Produit : ") ;
    scanf("%i",&zeta) ;
    gets (be) ;
    for (i=1;i<=L->lg;i++)
        {if (strcmp(be,(lsbesrecuperer(L,i)->Nom))==0)
            v=i;}}
        return v ;}

 int recher_besoin(BESOI L,char x[])
    {int i=1,v=0;
    for (i=1;i<=L->lg;i++)
        {if (strcmp(x,(lsbesrecuperer(L,i))->Nom)==0)
            v=i;}
        return v ;}









int main()
{ char ch[2],eta[50],chax[7],N[50],Hp[40] ;
   int choix0,choix1,choix2,choixx,i,j,ag,s,res,rep,y,d;
   LISTE L=listeCreer(),L2=listeCreer() ;
    LISTEHOPPUB lhp= LISTEHOPPUBCreer();
      LISTEPER LP= listeperCreer();
   HOPITAL H,HA=HOPITALCreer();
   LISTEHOP LH=LISTEHOPCreer() ;
LISTEHOT ListHot=LISTEHOTCreer() ;

   HOPPUB e,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20 ;
  // ************************** MENU PRINCIPAL ********************
   menu :{
do {
printf(" 1.Gestion des Patients/Hopitaux \n 2.Gestion des personnes en Quarantaine \n 3.Gestion des Dons/Besoins des Hopitaux publics \n Entrez Votre Choix : ") ;
gets(ch) ;
if (Numerique(ch)==0)
        printf("ENTREZ UN ENTIER\n") ;
system("cls") ;
choix0=atoi(ch) ;
if ((choix0<1) || (choix0>3))
        printf("CHOIX NON VALIDE \n") ;
}while ((choix0<1) || (choix0>3)||(Numerique(ch)==0)) ;}

//**********INITIALISATION**************************
/*ELEMENT sbe=elementCreer() ;
ELEMENT sbe1=elementCreer() ;
ELEMENT sbe2=elementCreer() ;
ELEMENT sbe3=elementCreer() ;
ELEMENT sbe4=elementCreer() ;
sbe->Adr="Mourouj" ; sbe->age=19 ; sbe ->contact=NULL ; sbe ->Cont_int = "Introduite" ; sbe->etat="NORMAL" ; sbe->M_chron={"Tension"} ; sbe->Nom="Mansouri" ; sbe->Prenom="Amine" ; sbe->region="Ben Arous" ;
sbe1->Adr="Soukra" ; sbe1->age=20 ; sbe1 ->contact=NULL ; sbe1 ->Cont_int = "Locale" ; sbe1->etat="CRITIQUE" ; sbe1->M_chron="" ; sbe1->Nom="Laguem" ; sbe1->Prenom="Makrem" ; sbe1->region="Ariana" ;
sbe4->Adr="Bouchoucha" ; sbe4->age=54; sbe4 ->contact=NULL ; sbe4 ->Cont_int = "Locale" ; sbe4->etat="CRITIQUE" ; sbe4->M_chron="" ; sbe4->Nom="Fitouri" ; sbe4->Prenom="Lassad" ; sbe4->region="Tunis" ;
sbe2->Adr="Med Ali" ; sbe2->age=45 ; sbe2 ->contact=NULL ; sbe2 ->Cont_int = "Provenance" ; sbe2->etat="NORMAL" ; sbe2->M_chron={"Tension"}, {"Obesite"} ; sbe2->Nom="Sellimi" ; sbe2->Prenom="Alya" ; sbe2->region="Nabeul" ;
sbe3->Adr="haffouz" ; sbe3->age=61 ; sbe3 ->contact=sbe4 ; sbe3 ->Cont_int = "Introduite" ; sbe3->etat="NORMAL" ; sbe3->M_chron="" ; sbe3->Nom="Chavarilla" ; sbe3->Prenom="Carlos" ; sbe3->region="Kairouan" ;
*/
//************** MENU GESTION PATIENTS ************************



if (choix0==1)
    {system("cls");
 do { printf(" 1.Gestion des Patients \n 2.Gestion des Hopitaux \n 3.Affectation d'un Patient a un Hopital \n 4.Retour au Menu Principal \n Entrez Votre Choix : ") ;
gets(ch) ;
if (Numerique(ch)==0)
        printf("ENTREZ UN ENTIER\n") ;
system("cls") ;
choix1=atoi(ch) ;
if ((choix1<1) || (choix1>4))
        printf("CHOIX NON VALIDE \n") ;
}while ((choix1<1) || (choix1>4)||(Numerique(ch)==0)) ;


//********** MENU DE GESTION DES PATIENTS PATIENTS *************

if(choix1==1)
{ system("cls");
  do {  printf("1.Ajout d un patient\n");
    printf("2.Modification de l etat du patient\n");
    printf("3.Recherche d un ou plusieurs patients selon un ou plusieurs criteres\n");
    printf("4.Supprimer une personne guerie de la liste\n");
    printf("5.Localisation geographiques de tous les patients\n");
    printf("6.Visualisation des reseaux des patients\n");
    printf("7.Retour au menu principal\n");
    printf("\n");
        printf("Entrez votre choix : ");
        gets(ch) ;
if (Numerique(ch)==0)
        printf("ENTREZ UN ENTIER\n") ;
system("cls") ;
choix2=atoi(ch) ;
if ((choix2<1) || (choix2>7))
        printf("CHOIX NON VALIDE \n") ;
}while ((choix2<1) || (choix2>7)||(Numerique(ch)==0)) ;


    //*********1-1-1******
    if(choix2==1)
    {
     ELEMENT e=elementCreer();
       elementLire(&e);
       inserer(L,e,L->lg+1) ;
       system("cls") ;
       printf("TERMINE\n") ;
       Sleep(1000) ;
       system("cls") ;
       goto menu ;
    }

   // *******1-1-2********
    if (choix2==2)
    { int p=(rech_nomprenom(L)) ;
         if (p!=0)
    do {
        printf("\nEntrez l'etat de patient (soit NORMAL soit CRITIQUE) : ") ;
        gets (eta) ;
    } while ((strcmp("NORMAL",eta)!=0) && (strcmp("CRITIQUE",eta))!=0) ;
    system("cls") ;
   // int p=rech_nomprenom(L) ;
   // ELEMENT elemtemp=elementCreer();
   // elementAffecter(&elemtemp,recuperer(L,p));
    ELEMENT elemtemp2=elementCreer();
    elementCopier(&elemtemp2,recuperer(L,p)) ;
    strcpy(elemtemp2->etat,eta) ;
    supprimer(L,p) ;
    inserer(L,elemtemp2,p) ;
   // elementDetruire(elemtemp) ;
    elementDetruire(elemtemp2) ;
    goto menu ;
    }
   // ******1-1-3 ***********
   if (choix2==3)
   {
   int z=0;
    //do
    choixx=0;
    while(choixx==0)
    { z++;
    printf("\nSelon quel(s) categorie(s) voulez vous effectuer la recherche ? : \n 1.Nom \n 2.Prenom \n 3.Adresse \n 4.Age \n 5.Etat \n 6.Region \n Entrez le ou la succesion des choix :") ;
    gets(chax) ;
  //  while (isdigit chax) ;

    L2=listeCreer() ;
    L2=listeCopier(L) ;
    for (i=0;i<=strlen(chax);i++)
        {
        if (chax[i]=='1')
        {printf("\nEntrez le Nom : ") ;

        gets (N) ;
    for (j=1;j<=L->lg;j++)
    {if (strcmp(recuperer(L2,j)->Nom,N)!=0)
        supprimer(L,j) ;
    }}
    if (chax[i]=='2')
        {printf("\nEntrez le Prenom : ") ;
        gets (N) ;
        for (j=1;j<=L->lg;j++)
    {if (strcmp(recuperer(L2,j)->Prenom,N)!=0)
        supprimer(L,j) ;
    }}
    if (chax[i]=='3')
        {printf("\nEntrez l'Adresse : ") ;
        gets (N) ;
        for (j=1;j<=L->lg;j++)
    {if (strcmp(recuperer(L2,j)->Adr,N)!=0)
        supprimer(L,j) ;
    }}
    if (chax[i]=='4')
        {printf("\nEntrez l'age : ") ;
        scanf("%i",&ag) ;
        for (j=1;j<=L->lg;j++)
    {if ((recuperer(L2,j)->age)!=ag)
        supprimer(L,j) ;
    }}
    if (chax[i]=='5')
        {printf("\nEntrez l'etat : ") ;
        gets (N) ;
        for (j=1;j<=L->lg;j++)
    {if (strcmp(recuperer(L2,j)->etat,N)!=0)
        supprimer(L,j) ;
    }}
    if (chax[i]=='6')
        {printf("\nEntrez la region : ") ;
        gets (N) ;
        for (j=1;j<=L->lg;j++)
    {if (strcmp(recuperer(L2,j)->region,N)!=0)
        supprimer(L,j) ;
    }}
    system("cls") ;
    if (z==2)
    {
    if (i==strlen(chax))
        {listeAfficher(L2) ;
    printf("Voulez vous rentrer au menu principal ? : ");
    scanf("%i",&choixx) ;
    if (choixx==1)
        goto menu ;}
        }}}}

  //  **********1-1-4**********
    if (choix2==4)
{
    s=rech_nomprenom(L) ;
    if (s!=0)

    {supprimer(L,s) ;}
        printf("\nVoulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;
}
//***ro******1-1-5**********
if (choix2==5)
 {
printf("                                            ...........                                             \n") ;
printf("                                          ............/     ........                                   \n");
printf("                                       ....Bizerte %i...... ...Nabeul %i                                    \n",occ_reg(L,"Bizerte"),occ_reg(L,"Nabeul"));
printf("                                      :.............Ariana %i......                                      \n",occ_reg(L,"Ariana")) ;
printf("                                    .Beja %i...Manouba %i..Tunis %i.                                      \n" ,occ_reg(L,"Beja"),occ_reg(L,"Manouba"),occ_reg(L,"Tunis"));
printf("                                     .Jendouba %i....Ben Arous %i                                        \n",occ_reg(L,"Jendouba"),occ_reg(L,"Ben Arous"));
printf("                                     /..........Zaghouan %i.                                           \n",occ_reg(L,"Zaghouan"))  ;
printf("                                     .....................                                          \n");
printf("                                    .El Kef %i..Siliana %i....                                      \n",occ_reg(L,"El Kef"),occ_reg(L,"Siliana"));
printf("                                     ......Kairouan %i..Sousse %i                                   \n",occ_reg(L,"Kairouan"),occ_reg(L,"Sousse"));
printf("                                     /...............Monastir %i.                                   \n",occ_reg(L,"Monastir"));
printf("                                     Kasserine %i..........Mahdia %i.                               \n",occ_reg(L,"Kasserine"),occ_reg(L,"Mahdia"));
printf("                                     :.....Sidi Bouzid %i.........                                  \n",occ_reg(L,"Sidi Bouzid"));
printf("                                     ..................Sfax %i.. ..                                 \n",occ_reg(L,"Sfax"));
printf("                                    .........................../.                                   \n");
printf("                                 .:..Gafsa %i...............  . .                                   \n",occ_reg(L,"Gafsa"));
printf("                                .........................                                           \n");
printf("                              .Tozeur %i.........Gabes %i                                           \n",occ_reg(L,"Tozeur"),occ_reg(L,"Gabes"));
printf("                              ......................./     ...                                      \n");
printf("                              ........................... .....                                     \n");
printf("                              ....Kebili %i................./:..                                     \n",occ_reg(L,"Kebili"));
printf("                               .................................                                    \n") ;
printf("                                .................................:.                                 \n");
printf("                                  -/............................../                                 \n");
printf("                                    ..................Medenine %i.:                                 \n",occ_reg(L,"Medenine"));
printf("                                     /............................/                                 \n");
printf("                                     ..............................                                 \n") ;
printf("                                       ./...Tataouine %i......../.                                  \n",occ_reg(L,"Tataouine"));
printf("                                          .................../.                                     \n");
printf("                                            /................                                       \n");
printf("                                            ...............                                         \n");
printf("                                             ...........                                            \n");
printf("                                             .........:                                             \n");
printf("                                              ..........                                            \n");
printf("                                              -......../                                            \n");
printf("                                               ........:                                            \n");
printf("                                               /......:                                             \n");
printf("                                               `......                                              \n");
printf("                                                /.:.                                                \n");
printf("Voulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;
   }
//***************1-1-6*******
if (choix2==6)
    {for (i=1;i<=L->lg;i++)
    printf("Les personnes en contact avec %s sont : \n",recuperer(L,i)->Prenom) ;
elementAfficher(recuperer(L,i)) ;
printf("Voulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;}
//**************1-1-7********

if (choix2==7)
{goto menu ;}
    }
//***************1-2*********
if(choix1==2)
{ system("cls");
  do {  printf("1.Ajout d un hopital\n");
    printf("2.Modification\n");
    printf("\n");
        printf("enter le choix : ");
         gets(ch) ;
if (Numerique(ch)==0)
        printf("ENTREZ UN ENTIER\n") ;
system("cls") ;
choix2=atoi(ch) ;
if ((choix2<1) || (choix2>2))
        printf("CHOIX NON VALIDE \n") ;
}while ((choix2<1) || (choix2>2)||(Numerique(ch)==0)) ;
if (choix2==1)
   {H=HOPITALCreer() ;
    HOPITALLire(&H) ;
    LH=LISTEHOPCreer() ;
    insererhop(LH,H,LH->lg+1) ;
    printf("Voulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;
     }
  // *********1-2-2*********
if (choix2==2)
{do {
    printf("\nEntrez Le nom d'hopital a modifier : ") ;
    gets(Hp) ;
    res=rech_hop(LH,Hp) ;
} while (res==0) ;
HOPITALLire(&HA) ;
supprimerhop(LH,res) ;
    insererhop(LH,HA,res) ;
    printf("Voulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;
}}
if (choix1==3)
{printf("Quel patient vous voulez affecter ? :") ;
int f=rech_nomprenom(L) ;
if (f!=0)
{ ELEMENT ep;
elementAffecter(&ep,recuperer(L,f)) ;
i=1 ;
int tast=0 ;
while ((i<=LH->lg) && (tast==0))
    {if ((strcmp(ep->region,recupererhop(LH,i)->region)==0) && (recupererhop(LH,i)->sal_dis>0))
    {
        tast=1;
        printf("le patient %s est affecte a l'hopital %s",ep->Prenom,recupererhop(LH,i)->Nom);}
    } if (tast==1)
      printf("le patient %s doit rester chez lui car les hopitals ne sont pas disponibles",ep->Prenom);
}
printf("Voulez vous retourner au menu principal(1 si oui sinon 0) : \n ") ;
    scanf("%i",&d) ;
    if (d==1)
        goto menu ;}
if (choix1==4)
{main() ;}
    }
    /// 2///
if (choix0==2)
{
    system("cls");
printf("1.Ajout d une personne en quarantaine\n");
 //printf("2.Gerer la rotation des confines dans les lieux geres par l etat\n");
 printf("2.Gestion des lieux possibles du confinement\n");
 printf("3.Retour au menu principal\n");
 //printf("5.");
 printf("\n");
do{
printf("entrer un choix : ");
scanf("%i",&choixx);
}while((choixx!=1)&&(choixx!=2)&&(choixx!=3)&&(choixx!=4));
///2-1///
if(choixx==1)
{
     PERSONNE e=personnecreer();
       personnelire(&e);
       insererper(LP,e,LP->lg+1) ;
       listeAfficherper(LP);
       system("cls") ;
       printf("TERMINE\n") ;
       Sleep(1000) ;
       system("cls") ;
       goto menu ;
}
///2-2 ///
int chix ;
char fra[50] ;
if (choixx==2)
{ system("cls") ;
do
    {printf("1.Ajouter un lieu \n2.Supprimer un lieu \n Entrez votre choix ici : ") ;
    scanf("%i",&chix) ;
    } while ((chix<1) || (chix>2) ) ;
    if (chix==1)
        {HOTEL haz=HOTELCreer() ;
        HOTELLire(&haz) ;
    insererhot( ListHot,haz,ListHot->lg+1) ;
    system("cls") ;
    goto menu ; }
    if (chix==2)
    {
        printf("Entrez nom de l'hopital que vous voulez detruire : ") ;
        gets(fra) ;
        int poi=rech_hot(ListHot,fra) ;
        supprimerhot(ListHot,poi) ;
    system("cls") ;
    goto menu ;
    }
}
if (choixx==3)
{
    goto menu ;
}
}
/// 3 ///
if (choix0==3)
{ system("cls");
printf("1.Gestion de la liste de tous les hopitaux publics \n");
printf(" ajout/suppression/modification des besoins pour chaque hopital\n");
printf("2.Gestion des dons (en nature ou en espece)\n");
printf("3.Retour au menu principal\n");
printf("\n");
do{
printf("veillez entrer un choix ici : ");
scanf("%i",&choix1);
}while ((choix1!=1)&&(choix1!=2));
///3-1///
system("cls") ;
if (choix1==1){

        do{
    printf("1.Ajouter un besoin \n");
    printf("2.Supprimer un besoin\n");
    printf("3.Modifier un besoin \n");
    scanf("%i",&rep);
        }while  ((rep!=1)&& (rep!=2) &&(rep!=3));

e1 = publCreer();
        strcpy((e1)->Nom,"Monji slim");
        strcpy((e1)->gov,"TUNIS");
        insererhoppub(lhp,e1,1);

        e = publCreer();
        strcpy(e->Nom,"Aziza Othmana");
        strcpy(e->gov,"TUNIS");
        insererhoppub(lhp,e,2);



        e2 = publCreer();
        strcpy((e2)->Nom,"Habib Thameur");
        strcpy(e2->gov,"TUNIS");
        insererhoppub(lhp,e2,3);

        e3 = publCreer();
        strcpy((e3)->Nom,"Charles Nicolle");
        strcpy(e3->gov,"TUNIS");
        insererhoppub(lhp,e3,4);

        e4 = publCreer();
        strcpy((e4)->Nom,"La Rabta");
        strcpy(e4->gov,"TUNIS");
        insererhoppub(lhp,e4,5);

        e5 = publCreer();
        strcpy((e5)->Nom,"Salah Azaiez");
        strcpy(e5->gov,"TUNIS");
        insererhoppub(lhp,e5,6);

        e6 = publCreer();
        strcpy((e6)->Nom,"Hedi Raies D'ophtalmologie de Tunis");
        strcpy(e6->gov,"TUNIS");
        insererhoppub(lhp,e6,7);
         e7 = publCreer();
        strcpy((e7)->Nom,"Institut National de Neurologie");
        strcpy(e7->gov,"TUNIS");
        insererhoppub(lhp,e7,8);
         e8 = publCreer();
        strcpy((e8)->Nom,"Institut Mohamed Kassab d'Orthopédie");
        strcpy(e8->gov,"TUNIS");
        insererhoppub(lhp,e8,9);

         e9 = publCreer();
        strcpy((e9)->Nom,"Institut pasteur");
        strcpy(e9->gov,"TUNIS");
        insererhoppub(lhp,e9,10);

         e10 = publCreer();
        strcpy((e10)->Nom,"Centre de Maternité et de Neonatologie");
        strcpy(e10->gov,"TUNIS");
        insererhoppub(lhp,e10,11);

        e11 = publCreer();
        strcpy((e11)->Nom,"Hôpital d'Enfants . Tunis");
        strcpy(e11->gov,"TUNIS");
        insererhoppub(lhp,e11,12);

        e12 = publCreer();
        strcpy((e12)->Nom,"Hôpital de Pneumo-Phtisiologie");
        strcpy(e12->gov,"ARIANA");
        insererhoppub(lhp,e12,13);

        e13 = publCreer();
        strcpy((e13)->Nom,"Hôpital Razi");
        strcpy(e13->gov,"MANOUBA");
        insererhoppub(lhp,e13,14);


        e14 = publCreer();
        strcpy((e14)->Nom,"Institut National de Nutrition et de Technologie Alimentaire");
        strcpy(e14->gov,"TUNIS");
        insererhoppub(lhp,e14,15);



        e15 = publCreer();
        strcpy((e15)->Nom,"Hôpital Sahloul");
        strcpy((e15)->gov,"Sousse");
insererhoppub(lhp,e15,16);

        e16 = publCreer();
        strcpy((e16)->Nom,"Hôpital Farhat Hached");
        strcpy(e16->gov,"SOUSSE");

insererhoppub(lhp,e16,17);

        e17 = publCreer();
        strcpy((e17)->Nom,"Hôpital Fattouma Bourguiba");
        strcpy(e17->gov,"MONASTIR");
insererhoppub(lhp,e17,18);
         e18 = publCreer();
        strcpy((e18)->Nom,"Hôpital Hédi Chaker");
        strcpy(e18->gov,"SFAX");
        insererhoppub(lhp,e18,19);

         e19 = publCreer();
        strcpy((e19)->Nom,"Hôpital Habib Bourguiba");
        strcpy(e19->gov,"SFAX");
        insererhoppub(lhp,e19,20);

         e20 = publCreer();
        strcpy((e20)->Nom,"Complexe sanitaire Djebel Ouest");
        strcpy(e20->gov,"ZAGHOUANE");
        insererhoppub(lhp,e20,21);

 //LISTEHOPPUBAfficher(lhp);

///3-1-1///
   if (rep==1)  {
int zeta=0 ;
           char x[300] ;
  // if (rep==1)  {
do { zeta++;
            printf("donner le nom de l'hopital concerne : ");
            scanf("%i",&zeta) ;
            gets(x);
            if ((rech_hoppub(lhp,x)==0) && (zeta!=1))
                printf("\nEntrez un nom valide \n") ;
            }
while (rech_hoppub(lhp,x)==0);
            int lol=rech_hoppub(lhp,x) ;
           BESOIN bas=besCreer() ;
           besLire(&bas) ;
           int nji=(recupererhoppub(lhp,lol)->b->lg)+1;
           lsbesinserer((recupererhoppub(lhp,lol)->b),bas,nji) ;

lsbesAfficher(recupererhoppub(lhp,lol)->b) ;
Sleep(2000) ;
 printf("TERMINE\n") ;
       Sleep(1000) ;
       system("cls") ;
       goto menu ;}
    ///3-1-2///
       if (rep==2) {
int zeta=0 ;
char r[50];
       do { zeta++;
            printf("donner le nom de l'hopital concerne : ");
            scanf("%i",&zeta) ;
            gets(r);
            if ((rech_hoppub(lhp,r)==0) && (zeta!=1))
                printf("\nEntrez un nom valide \n") ;
            }
while (rech_hoppub(lhp,r)==0);

        y=rech_besoin(recupererhoppub(lhp,rech_hoppub(lhp,r))->b) ;
    if (y!=0)
 // HOPPUB bublic=recupererhoppub(lhp,rech_hoppub(lhp,r));
   // lsbesrecuperer( recupererhoppub(lhp,rech_hoppub(lhp,r))->b,y);
    lsbessupprimer( recupererhoppub(lhp,rech_hoppub(lhp,r))->b,y) ;
    int ze;
       do {printf("Voulez vous retournez au menu principal ? (1 si oui et 0 si non ) ") ;
scanf("%i",&ze) ;} while ((ze!=0)&&(ze!=1)) ;
if (ze==1)
    goto menu ;
} ///3-1-3///
 if (rep==3)
        {char z [200] ;
        int zet ;
 gets(z) ;
 int position_hop=rech_hoppub(lhp,z) ;
 scanf("%i",&zet) ;
   y=rech_besoin(recupererhoppub(lhp,position_hop)->b) ;
   printf("y = %i\n",y) ;
 BESOIN bra =lsbesrecuperer(recupererhoppub(lhp,rech_hoppub(lhp,z))->b,y) ;
 lsbessupprimer(lhp->elementshop[rech_hoppub(lhp,z)]->b,y) ;
 printf("Entrez la nouvelle quantite : ") ;
 scanf("%i",&bra->disp) ;
 lsbesinserer(lhp->elementshop[rech_hoppub(lhp,z)]->b,bra,y) ;
 }
}
int v,we ;
char r[40],wi[50] ;
if (choix1==2)
{ do {
            printf("Entrer le nom de l'hopital concerne par ce don : ");
            scanf("%s",r);}
            while (rech_hoppub(lhp,r)==0);
            int ind_hop=rech_hoppub(lhp,r) ;
publAfficher(lhp->elementshop[rech_hoppub(lhp,r)]) ;
do
{printf("Est ce que votre don consiste en argent (entrez 1) ou non ?(entrez 0)") ;
 scanf("%i",&v) ;}
 while ((v!=0) && (v!=1)) ;
 if (v==1)
    {printf("donner le montant a verser   !");
        scanf("%i",&we) ;
     int  ind_besar=recher_besoin(recupererhoppub(lhp,ind_hop)->b,"Argent") ;
     if (ind_besar==0)
        printf("Il n'y a pas de besoin d'argent\n") ;
     else
{int disponi=lsbesrecuperer(recupererhoppub(lhp,ind_hop)->b,ind_besar)->disp ;
int resultats =disponi-we ;
 if (resultats<0)
    lhp->elementshop[ind_hop]->b->bes[ind_besar]->disp=0 ;}}
    if (v==0)
     {printf("donner le produit  !");
       scanf("%s",wi) ;
     printf("donner le nombre de produits a donner ! : ");
        scanf("%i",&we) ;
      int ind_besar=recher_besoin(recupererhoppub(lhp,ind_hop)->b,wi) ;
     if (ind_besar!=0)
{ int disponi=lsbesrecuperer(recupererhoppub(lhp,ind_hop)->b,ind_besar)->disp ;
 int resultats =disponi-we ;
 if (resultats<0)
    lhp->elementshop[ind_hop]->b->bes[ind_besar]->disp=0 ;}
    else
        printf("Il n'y a pas de besoin pour ce produit \n ") ;
    }
}
if (choix1==3)
    goto menu;
}


if(choix0==4)
{
    exit(0);
}

    return 0;
}

