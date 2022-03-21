#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "Choix.h"
#include "Sudoku.h"
#include "Humain.h"
#include "Tests.h"
#include "Machine.h"

void nouvellePartieSaisie(uneCase grille[9][9])
{
    saisieGrille(grille);
    affichageGrille(grille);
}
void modeJoueur(uneCase grille[9][9])
{
    int choix;
    uneCase grilleAux[9][9];
    leCoup *coup;
    char chaine[500]="",chemin[500]="",sauv[500]="";
    coup=(leCoup*)malloc(sizeof(leCoup));
    printf("\nVoulez vous remplir cette grille manuellement ou automatiquement?\n\n");
    printf("(1) Manuellement Avec Assistance\n");
    printf("(2) Manuellement Sans Assistance\n");
    printf("(3) Automatiquement\n");
    printf("(4) Quitter la partie\n");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1:
            do
            {
                demanderCoupHumain(chaine);
                verifChaineHumain(chaine,coup,grille);
                if(coup != NULL)
                {
                    insertionValeurPositionAssist(grille,coup);
                    affichageGrille(grille);
                    if(grilleRemplie(grille)==81)
                    {
                        printf("Felicitations, vous avez termine.\n");
                    }
                }
            }while((strcmp("quit",chaine)!=0) && (grilleRemplie(grille)!=81));
            break;
        case 2:
            copierGrille(grille,grilleAux);
            resolutionAutomatique(grilleAux);
            do
            {

                demanderCoupHumain(chaine);
                verifChaineHumain(chaine,coup,grille);
                if(coup!=NULL);
                {
                    insertionValeurPositionSeul(grille,coup);
                    affichageGrille(grille);
                    if(grilleRemplie(grille)==81)
                    {
                        if(remplissageIncorrecte(grille,grilleAux))
                            printf("Remplissage Incorrect.\n");
                        else
                            printf("Felicitations, vous avez termine.\n");
                    }
                }
            }while((strcmp("quit",chaine)!=0) && (remplissageIncorrecte(grille,grilleAux)));
            break;
        case 3:
            remplissageTotalMachine(grille);
            break;
        case 4:
            printf("Vous allez quitter,voulez vous sauvegarder:\n");
            scanf("%s",sauv);
            if(strcmp("oui",sauv)==0)
            {
                saisieChemin(chemin);
                sauvegarder(chemin,grille);
                system("cls");
            }
            system("cls");
            break;
        default:
            printf("Choix invalide, veuillez choisir correctement.\n");
            getch();
            system("cls");
            break;
    }
}
void reprendreGrille(char chemin[],uneCase grille[9][9])
{
    int lig,col,val,leType;
    char str[256];
    FILE *fichier=fopen(chemin,"r");
    if(!fichier){}
    while(fgets(str,sizeof str, fichier))
    {
        char *p=strchr(str,'\n');
        if(p)
            *p=0;
        if(sscanf(str,"%d,%d,%d,%d",&lig,&col,&val,&leType)==4)
        {
            (grille[lig][col]).valCase=val;
            (grille[lig][col]).typeCase=leType;
        }
        else{}
    }
    affichageGrille(grille);
}
void nouvellePartieGeneree(uneCase grille[9][9])
{
    time_t horloge;
    int lig,col,cnt=(rand()%21)+20;
    srand(time(&horloge));
    generer(grille);
    while(cnt!=0)
    {
        lig=(rand()%9)+1;
        col=(rand()%9)+1;
        (grille[lig][col]).valCase=0;
        cnt--;
    }
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
        {
            if((grille[lig][col]).valCase==0)
                (grille[lig][col]).typeCase=VIDE;
            else
                (grille[lig][col]).typeCase=ORIGINAL;
        }
    }
    affichageGrille(grille);
}
