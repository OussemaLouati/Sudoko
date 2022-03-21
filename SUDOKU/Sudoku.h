#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

enum _TYPEVALEUR{ORIGINAL,NOUVELLE,VIDE};
typedef enum _TYPEVALEUR TYPEVALEUR;

enum _VERACITE{VRAI,FAUX};
typedef enum _VERACITE BOOL;

typedef struct {int valCase; TYPEVALEUR typeCase;}uneCase;
typedef struct {int numLigne;int numColonne;int valeurCoup;}leCoup;

void affichageGrille(uneCase grille[9][9]);
void copierGrille(uneCase grilleOriginale[9][9],uneCase grilleCopie[9][9]);
void demanderCoupHumain(char chaine[]);
void verifChaineHumain(char chaine[],leCoup *coup,uneCase grille[9][9]);


#endif // SUDOKU_H_INCLUDED
