#include <stdio.h>
#include <stdlib.h>
#include "Humain.h"
#include "Sudoku.h"
#include "Tests.h"

void saisieGrille(uneCase grille[9][9])
{

    int lig,col;
    for (lig=0;lig<9;lig++)
    {
        for (col=0;col<9;col++)
        {
            do
            {
                scanf("%d",&(grille[lig][col]).valCase);
                if((grille[lig][col]).valCase==0)
                    (grille[lig][col]).typeCase=VIDE;
                else
                    (grille[lig][col]).typeCase=ORIGINAL;
            }while(((((grille[lig][col]).valCase > 9) || (grille[lig][col]).valCase < 0)));
        }

    }
}
void saisieChemin(char chemin[])
{
    printf("Tapez le chemin :\n");
    scanf("%s",chemin);
    system("cls");
}

void insertionValeurPositionAssist(uneCase grille[9][9],leCoup *coup)
{
    if(((coup->numLigne)<0) || ((coup->numLigne)>8) || ((coup->numColonne)<0) || ((coup->numColonne)>8) || ((coup->valeurCoup)<0) || (coup->valeurCoup)>9)
       printf("Erreur de Coup\n");
    else
    {
        if((grille[coup->numLigne][coup->numColonne]).typeCase==NOUVELLE || (grille[coup->numLigne][coup->numColonne]).typeCase==VIDE)
        {
            if(nombrePossible(coup->valeurCoup,grille,coup->numLigne,coup->numColonne))
            {
                (grille[coup->numLigne][coup->numColonne]).valCase=coup->valeurCoup;
                (grille[coup->numLigne][coup->numColonne]).typeCase=NOUVELLE;
            }
            else
                printf("Nombre non possible pour cette case.\n");

        }
        else
            printf("Case originale.\n");
    }
}
void insertionValeurPositionSeul(uneCase grille[9][9],leCoup *coup)
{
    if(((coup->numLigne)<0) || ((coup->numLigne)>8) || ((coup->numColonne)<0) || ((coup->numColonne)>8) || ((coup->valeurCoup)<0) || (coup->valeurCoup)>9)
       printf("Erreur de Coup\n");
    else
    {
        if((grille[coup->numLigne][coup->numColonne]).typeCase==NOUVELLE || (grille[coup->numLigne][coup->numColonne]).typeCase==VIDE)
        {
            (grille[coup->numLigne][coup->numColonne]).valCase=coup->valeurCoup;
            (grille[coup->numLigne][coup->numColonne]).typeCase=NOUVELLE;
        }
        else
            printf("Case originale.\n");
    }
}


void sauvegarder(char chemin[],uneCase grille[9][9])
{
    int lig,col;
    FILE *fichier;
    fichier=fopen(chemin,"w");
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
            fprintf(fichier,"%d,%d,%d,%d\n",lig,col,(grille[lig][col]).valCase,(grille[lig][col]).typeCase);
    }
    fclose(fichier);
}
