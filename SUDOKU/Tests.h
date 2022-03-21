#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "Sudoku.h"

BOOL seulSurLigne(int nbr, uneCase grille[9][9], int lig);
BOOL seulSurColonne(int nbr, uneCase grille[9][9], int col);
BOOL seulSurBloc(int nbr, uneCase grille[9][9], int lig, int col);
BOOL nombrePossible(int nbr,uneCase grille[9][9],int lig,int col);
int encoreCasesVides(uneCase grille[9][9],int *lig,int *col);
int remplissageIncorrecte(uneCase grille[9][9],uneCase grilleAux[9][9]);
int grilleRemplie(uneCase grille[9][9]);


#endif // TESTS_H_INCLUDED
