#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Choix.h"
#include "Humain.h"
#include "Machine.h"
#include "Tests.h"
#include "Sudoku.h"

void main()
{
    int selection,selection_1,selection_2;
    char chemin[500]="";
    uneCase grille[9][9];
    do
    {
        printf("\t\t\t ==========\n");
        printf("\t\t\t||        ||\n");
        printf("\t\t\t|| SUDOKU ||\n");
        printf("\t\t\t||        ||\n");
        printf("\t\t\t ==========\n");
        printf("\n\n");
        printf("\t===========================================\n");
        printf("\t||\t(1) Creer une nouvelle partie\t ||\n");
        printf("\t||\t(2) Reprendre une partie\t ||\n");
        printf("\t||\t(3) Quitter le jeu           \t ||\n");
        printf("\t===========================================\n");
        scanf("%d",&selection);
        system("cls");
        switch(selection)
        {
            case 1:
                    do
                    {
                        printf("\t=================================================\n");
                        printf("\t||\t(1) Generer une grille                 ||\n");
                        printf("\t||\t(2) Saisir une grille manuellement     ||\n");
                        printf("\t||\t(3) Retourner au menu principale       ||\n");
                        printf("\t=================================================\n");
                        scanf("%d",&selection_1);
                        system("cls");
                        switch(selection_1)
                        {
                            case 1:
                                nouvellePartieGeneree(grille);
                                modeJoueur(grille);
                                break;
                            case 2:
                                printf("Saisir les nombres ligne par ligne:\n");
                                nouvellePartieSaisie(grille);
                                modeJoueur(grille);
                                break;
                            case 3:
                                break;
                            default:
                                printf("Choix invalide, veuillez choisir correctement.\n");
                                getch();
                                system("cls");
                                break;
                        }
                    }while(selection_1!=3);
                    break;

            case 2:
                    do
                    {
                        printf("\t===================================================\n");
                        printf("\t||\t(1) Ouvrir le fichier de la partie      ||\n");
                        printf("\t||\t(2) Retourner au menu principale        ||\n");
                        printf("\t===================================================\n");
                        scanf("%d",&selection_2);
                        system("cls");
                        switch(selection_2)
                        {
                            case 1:
                                saisieChemin(chemin);
                                reprendreGrille(chemin,grille);
                                modeJoueur(grille);
                                break;
                            case 2:
                                break;
                            default:
                                printf("Choix invalide, veuillez choisir correctement.\n");
                                getch();
                                system("cls");
                                break;
                        }
                    }while(selection_2!=2);
                    break;
            case 3:
                    printf("Quitter le jeu.");
                    exit(0);
            default:
                    printf("Choix invalide, veuillez choisir correctement.\n");
                    getch();
                    system("cls");
                    break;
        }
    }while(selection!=3);
}
