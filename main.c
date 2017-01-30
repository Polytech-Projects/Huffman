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
#include <string.h>
#include "main.h"
#include "constants.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	int i;
	// Si il y a des arguments
	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			// Déclaré aussi comme ca se réset tout seul
			char nom_compresse[256] = {'\0'};
			if (fichier_existe(argv[i]))
			{
				// Si nom assez court
				if (strlen(argv[i])+1 < 256-6)
				{
					strcpy(nom_compresse, argv[i]);
					strcat(nom_compresse, ".huff");
				}
				// Sinon on coupe le nom
				else
				{
					strncpy(nom_compresse, argv[i], 256-6);
					strcat(nom_compresse, ".huff");
				}
				compression(argv[i], "");
			}
		}
	}
	else
	{
		print_menu();
	}

	printf("\n");
	return EXIT_SUCCESS;
}

void print_menu()
{
	int choix;

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
		printf("\t%d - Compresser un fichier\n", COMPRESS);
		printf("\t%d - Decompresser un fichier\n", DECOMPRESS);
		printf("\t%d - Compresser un message (dans un fichier)\n", COMPRESS_MSG);
		printf("\t%d - Tester la fonction debug\n", TEST_DEBUG);
		printf("\t0 - Quitter\n");
		printf("\t\n");
		printf("\tChoix :");
		scanf("%d", &choix);
	}
	while (!(choix >= 0 && choix < CHOICE_NBR));
	system(CLEAR);

	switch (choix)
	{
		case COMPRESS:
			compression("test.txt", "compresse.txt");
		break;
		case COMPRESS_MSG:
		break;
		case DECOMPRESS:
		break;
		case TEST_DEBUG:
		break;
		default:
		break;
	}
}