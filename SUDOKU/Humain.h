#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED
#include "Sudoku.h"

void saisieGrille(uneCase grille[9][9]);
void insertionValeurPositionAssist(uneCase grille[9][9],leCoup *coup);
void insertionValeurPositionSeul(uneCase grille[9][9],leCoup *coup);
void saisieChemin(char chemin[]);
void sauvegarder(char chemin[],uneCase grille[9][9]);



#endif // HUMAIN_H_INCLUDED
