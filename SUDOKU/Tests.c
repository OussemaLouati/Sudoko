#include <stdio.h>
#include "Tests.h"
#include "Sudoku.h"

BOOL seulSurLigne(int nbr, uneCase grille[9][9], int lig)
{
  int col;
  for (col = 0; col < 9; col++)
  {
    if ((grille[lig][col]).valCase == nbr)
        return FAUX;
  }
  return VRAI;
}

BOOL seulSurColonne(int nbr, uneCase grille[9][9], int col)
{
  int lig;
  for (lig = 0; lig < 9; lig++)
  {
      if ((grille[lig][col]).valCase == nbr)
        return FAUX;
  }
  return VRAI;
}


BOOL seulSurBloc(int nbr, uneCase grille[9][9], int ligDep, int colDep)
{
    int lig,col;
	for (lig = 0; lig < 3; lig++)
    {
        for (col = 0; col < 3; col++)
        {
            if ((grille[lig+ligDep][col+colDep]).valCase == nbr)
				return FAUX;

		}
	}
	return VRAI;
}


BOOL nombrePossible(int nbr,uneCase grille[9][9],int lig,int col)
{
    return (!seulSurLigne(nbr,grille,lig)) && (!seulSurColonne(nbr,grille,col)) && (!seulSurBloc(nbr,grille, lig-(lig%3), col-(col%3) ));
}

int remplissageIncorrecte(uneCase grille[9][9],uneCase grilleAux[9][9])
{
    int lig,col;
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
        {
            if((grille[lig][col]).valCase != (grilleAux[lig][col]).valCase)
            {
                return 1;
            }
        }
    }
    return 0;
}


int encoreCasesVides(uneCase grille[9][9],int *lig,int *col)
{
    for(*lig=0;*lig<9;(*lig)++)
    {
        for(*col=0;*col<9;(*col)++)
        {
            if((grille[*lig][*col]).valCase==0)
                return 1;
        }
    }
    return 0;
}
int grilleRemplie(uneCase grille[9][9])
{
    int lig,col,cases=0;
    for(lig=0;lig<9;lig++)
    {
        for(col=0;col<9;col++)
        {
           if((grille[lig][col]).valCase!=0)
            cases++;
        }
    }
    return cases;
}

