/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author PORET Tanguy <tanguy.poret@etu.univ-amu.fr>
 * @author DI-GIOVANI Hugo <hugo.DI-GIOVANNI@etu.univ-amu.fr>
 *
 * @version 0.0.1 / 27-11-2016
 */


/**
 * @file tools.c
 * @brief
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

#define NOMBRE_DE_CHOIX 3


int main()
{
    int choix;
    char fget;

    do
    {
        system(CLEAR);
        printf("\n");
        printf("\t\t--------------------\n");
        printf("\t\t|Hoffman  Compressor|\n");  
        printf("\t\t--------------------\n");
        printf("\n");
        printf("\n");
        printf("\tQue voulez vous faire ?\n");
        printf("\t\n");
        printf("\t1 - Compresser un fichier\n");
        printf("\t2 - Decompresser un fichier\n");
        printf("\t3 - Compresser un message (dans un fichier)\n");
        printf("\t0 - Quitter\n");
        printf("\t\n");
        printf("\tChoix :");
        scanf("%d", &choix);
        if (!(choix >= 0 && choix < NOMBRE_DE_CHOIX)){
            system(CLEAR);
            printf("\n\n\t choix inconnu ...\n\n");
            printf("appuyez sur entree pour continuer...");
            system(SYSREAD);
        } 
    }while (choix !=0);
    system(CLEAR);
    printf("\t\n");
    printf("\t\taurevoir !\n");
    printf("\n");
    printf("appuyez sur entree pour continuer...");
    system(SYSREAD);
    system(CLEAR);

    /*
    // On ouvre le fichier en mode lecture
    FILE *file = fopen("../test.txt", "r");
    if (file != NULL)
    {
        // longueur maximale d'une chaîne
        char line[10];

        // lire une chaîne, 1 lecture par boucle
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // afficher la chaîne en cours
            printf("Ligne : %s ", line);
        }
        fclose(file);
    } else
    {
        //renvoie l'erreur impechant l'ouverture de fichier
        perror("test.txt");
    }
    return EXIT_SUCCESS;
    */
}

