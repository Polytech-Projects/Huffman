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

int main()
{
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
}

