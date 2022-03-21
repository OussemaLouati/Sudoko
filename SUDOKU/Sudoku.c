#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Sudoku.h"
#include "Tests.h"
#include "Humain.h"

void affichageGrille(uneCase grille[9][9])
{
    int lig,col;
    printf("\t-------------------------\n");
    for (lig=0;lig<9;lig++)
    {
        printf("\t");
        for (col=0;col<9;col++)
        {
            if(col==0)
                printf("| ");
            if ((grille[lig][col]).valCase==0)
                printf("  ");
            else
                printf("%d ",(grille[lig][col]).valCase);
            if ((col+1)%3 == 0)
                printf("| ");
        }
        if ((lig+1)%3 == 0)
            printf("\n\t-------------------------");
        printf("\n");
    }
}

void copierGrille(uneCase grilleOriginale[9][9],uneCase grilleCopie[9][9])
{
    int lig,col;
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
        {
            (grilleCopie[lig][col]).valCase=(grilleOriginale[lig][col]).valCase;
            (grilleCopie[lig][col]).typeCase=(grilleOriginale[lig][col]).typeCase;
        }
    }
}

void verifChaineHumain(char chaine[],leCoup *coup,uneCase grille[9][9])
{
    char chemin[500]="",sauv[500]="";
    if(strcmp("quit",chaine)==0)
    {
        printf("Vous allez quitter,voulez vous sauvegarder:\n");
        scanf("%s",sauv);
        if(strcmp("oui",sauv)==0)
        {
            saisieChemin(chemin);
            sauvegarder(chemin,grille);
            coup = NULL;
            system("cls");
        }
        system("cls");
    }
    else
        sscanf(chaine,"%d/%d/%d",&coup->numLigne,&coup->numColonne,&coup->valeurCoup);
}


void demanderCoupHumain(char chaine[])
{
    printf("Tapez le coup sous cette forme: lig/col/val , ou bien tapez quit pour quitter :\n");
    scanf("%s",chaine);
}
