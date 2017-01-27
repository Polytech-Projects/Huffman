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
#include "tools.h"

/* Les différents choix pour le menu.
 * Attention, les nombres associé aux choix doivent être positif et
 * doivent se suivre (on peut changer leur ordre mais pas mettre
 * d'écart entre eux.) */
typedef enum e_choice
{
	COMPRESS = 1, DECOMPRESS = 2, COMPRESS_MSG = 3, TEST_DEBUG = 4, CHOICE_NBR
} e_choice;
#define NOMBRE_DE_CHOIX CHOICE_NBR


int main()
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
	while (!(choix >= 0 && choix < NOMBRE_DE_CHOIX));
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
	}

	printf("\n");
	return EXIT_SUCCESS;
}

