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

void display_titre(){
	printf("\n");
	printf("\t\t--------------------\n");
	printf("\t\t|Hoffman  Compressor|\n");
	printf("\t\t--------------------\n");
	printf("\n");
	printf("\n");
}

char* fichier_destination(){
	//ATTENTION, il faut rajouter la vérification du nom de fichier. un fichier ne doit pas contenir
	//certains caractaires comme par exemple: / \ : * ? > < " |
		char* nom;

		system(CLEAR);
		display_titre();
		printf("\tQuel est nom de fichier de destination ?\n");
		printf("\n\t Nom: ");
		scanf("%s",nom);

		return nom;
	
}

void print_menu()
{
	int choix;
	char* destination;

	do
	{
		system(CLEAR);
		display_titre();
		printf("\tQue voulez vous faire ?\n");
		printf("\t\n");
		printf("%d - Compresser un fichier\n", COMPRESS);
		printf("%d - Decompresser un fichier\n", DECOMPRESS);
		printf("%d - Compresser un message (dans un fichier)\n", COMPRESS_MSG);
		printf("%d - Tester la fonction debug\n", TEST_DEBUG);
		printf("0 - Quitter\n");
		printf("\n");
		printf("\tChoix :");
		scanf("%d", &choix);
	}
	while (!(choix >= 0 && choix < CHOICE_NBR));
	

	switch (choix)
	{
		case COMPRESS:
			system(CLEAR);
			destination = "compression.huff";
			compression("test.txt", destination);
		break;
		case COMPRESS_MSG:
			choix=0;
			char* message;
			FILE* fichier;

			do
			{
				
				system(CLEAR);

				display_titre();
				printf("\tQuel est votre message ?\n");
				printf("\n\tmessage: ");
				scanf("%s", message);
				fichier = fopen("input.txt", "w");
				//ecrit dans un fichier temporaire le message rentre par l'utisateur
				fprintf(fichier, "%s", message); //erreur de segmentation a cause de la variable message
        		fclose(fichier);

        		system(CLEAR);

				display_titre();
				printf("\tou voulez vous compresser ?\n");
				printf("1- Dans un fichier\n");
				printf("2- Dans la console\n");
				printf("\n\tchoix :");
				scanf("%d",&choix);

			}while(choix!=1 || choix!=2);

			if(choix == 1)
			{
				destination = fichier_destination();
			} else {
				destination = "tmp.huff";
			}
			compression("input.txt", destination);
			remove("input.txt");
			if(choix == 2)
			{
				fichier = fopen(destination, "r");
 				int caractereActuel = 0;
			    if (fichier != NULL)
			    {
			        // Boucle de lecture des caractères un à un
			        do
			        {
			            caractereActuel = fgetc(fichier); // On lit le caractère
			            printf("%c", caractereActuel); // On l'affiche
			        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
			 
			        fclose(fichier);
			    }
			    remove(destination);
			}

		break;
		case DECOMPRESS:
			decompression("compresse.txt", "clair.txt");
		break;
		case TEST_DEBUG:
		break;
		default:
		break;
	}
}