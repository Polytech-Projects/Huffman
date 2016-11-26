//
// Created by Hugo on 26/11/2016.
//

#include <stdio.h>

int lecture_fichier(char filename[])
{
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        // longueur maximale d'une ligne
        char line [ 128 ];

        // lire une ligne, 1 ligne par boucle
        while ( fgets ( line, sizeof line, file ) != NULL )
        {
            // afficher la ligne en cours
            printf("Ligne : %s", line);
        }
        fclose ( file );
    }
    else
    {
        //renvoie l'erreur impechant l'ouverture de fichier
        perror ( filename );
    }
    return 0;

}