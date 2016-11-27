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
 * @brief Regroupe les fonctions utilitaires
 *
 */

#include <stdio.h>
#include "tools.h"

/** @brief Lit et affiche le contenu d'un fichier dans la console
 *
 * @param filename chemin du fichier à lire
 */
int lecture_fichier(char filename[])
{
    // On ouvre le fichier en mode lecture
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        // longueur maximale d'une ligne
        char line[128];

        // lire une ligne, 1 ligne par boucle
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // afficher la ligne en cours
            printf("Ligne : %s", line);
        }
        fclose(file);
    } else
    {
        //renvoie l'erreur impechant l'ouverture de fichier
        perror(filename);
    }
    return 0;
}