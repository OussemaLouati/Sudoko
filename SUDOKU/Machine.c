#include <stdio.h>
#include <stdlib.h>
#include "Tests.h"
#include "Machine.h"
#include "Sudoku.h"


int resolutionAutomatique(uneCase grille[9][9])
{
    int lig=0,col=0,nbp;
    if(!encoreCasesVides(grille,&lig,&col))
        return 1;
    for (nbp=1;nbp<=9;nbp++)
    {
        if(nombrePossible(nbp,grille,lig,col))
        {
            (grille[lig][col]).valCase = nbp;
            if (resolutionAutomatique(grille))
                return 1;
        }
        (grille[lig][col]).valCase=0;
    }
    return 0;
}

void generer(uneCase grille[9][9])
{
    int lig,col,nbp;
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
        {
            (grille[lig][col]).valCase=0;
        }

    }
    (grille[0][0]).valCase=(rand()%9)+1;
    (grille[3][3]).valCase=(rand()%9)+1;
    (grille[6][6]).valCase=(rand()%9)+1;
    while (1)
    {
        do
        {
            lig=(rand()%9)+1;
            col=(rand()%9)+1;
            nbp=(rand()%9)+1;
            if(nombrePossible(nbp,grille,lig,col))
            {
                (grille[lig][col]).valCase=nbp;
            }
        }while (nombrePossible(nbp,grille,lig,col));
        if (resolutionAutomatique(grille))
            break;

    }
}

void remplissageTotalMachine(uneCase grille[9][9])
{
    int lig,col;
    if (resolutionAutomatique(grille))
    {
        affichageGrille(grille);
        printf("Les cases remplisses:\n");
        for(lig=0;lig<9;lig++)
        {
            for(col=0;col<9;col++)
            {
                if((grille[lig][col]).typeCase==VIDE)
                {
                    printf("La case (%d,%d):%d\n",lig,col,(grille[lig][col]).valCase);
                }
            }
        }

	}
	else
    {
        printf("Pas de solution.\n");
	}
}
