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
				/* On regarde si le fichier est à compresser ou
				 * décompresser. */
				if (strstr(argv[i], ".huff") != NULL)
				{
					// Contient notre extension, c'est à décompresser
					strcpy(nom_compresse, argv[i]);
					nom_compresse[strlen(nom_compresse)-5] = '\0';
					decompression(argv[i], nom_compresse);
				}
				else
				{
					// C'est à compresser
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
					compression(argv[i], nom_compresse);
				}
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

void display_titre()
{
	printf("\n");
	printf("\t\t--------------------\n");
	printf("\t\t|Hoffman  Compressor|\n");
	printf("\t\t--------------------\n");
	printf("\n");
	printf("\n");
}

void fichier_destination(char* fichierDestination)
{
	//ATTENTION, il faut rajouter la vérification du nom de fichier. un fichier ne doit pas contenir
	//certains caractaires comme par exemple: / \ : * ? > < " |

		system(CLEAR);
		display_titre();
		printf("\tQuel est nom de fichier de destination ? (max chemin de 512 caracteres)\n");
		printf("\n\t Nom: ");
		scanf("%s",fichierDestination);
}

void print_menu()
{
	int choix;
	char destination[512] = {0};
	char fichier_a_compresser[512] = {0};
	char message[1024];
	FILE* fichier = NULL;

	do
	{
		system(CLEAR);
		display_titre();
		printf("\t\tQue voulez vous faire ?\n");
		printf("\t\n");
		printf("\t%d - Compresser un fichier\n", COMPRESS);
		printf("\t%d - Decompresser un fichier\n", DECOMPRESS);
		printf("\t%d - Compresser un message (dans un fichier)\n", COMPRESS_MSG);
		printf("\t%d - Tester la fonction debug\n", TEST_DEBUG);
		printf("\t0 - Quitter\n");
		printf("\n");
		printf("\tChoix :");
		scanf("%d", &choix);
	}
	while (!(choix >= 0 && choix < CHOICE_NBR));
	
	switch (choix)
	{
		case COMPRESS:
			system(CLEAR);
			printf("\tEntrez le chemin du fichier à compresser\n");
			scanf("%s", fichier_a_compresser);
			if (fichier_existe(fichier_a_compresser))
			{
				if (strlen(fichier_a_compresser)+1 < 256-6)
				{
					strcpy(destination, fichier_a_compresser);
					strcat(destination, ".huff");
				}
				// Sinon on coupe le nom
				else
				{
					strncpy(destination, fichier_a_compresser, 256-6);
					strcat(destination, ".huff");
				}
				compression(fichier_a_compresser, destination);
				printf("\nVotre fichier se trouve à l'emplacement suivant:\n\t\
						%s\n", destination);
			}
		break;
		case COMPRESS_MSG:
			choix=0;
			do
			{
				system(CLEAR);

				display_titre();
				printf("\tQuel est votre message ?\n");
				printf("\n\tmessage (max 512 caracteres): ");
				scanf("%s", message);
				fichier = fopen("input.txt", "w");
				//ecrit dans un fichier temporaire le message rentre par l'utisateur
				if (fichier != NULL)
				{
					fprintf(fichier, "%s", message);
        			fclose(fichier);
				}

        		system(CLEAR);

				display_titre();
				printf("\tou voulez vous compresser ?\n");
				printf("1- Dans un fichier\n");
				printf("2- Dans la console\n");
				printf("\n\tchoix :");
				scanf("%d",&choix);

			}while(choix!=1 && choix!=2);

			if(choix == 1)
			{
				fichier_destination(destination);
				compression("input.txt", destination);
			} else {
				strcpy(destination, "tmp.huff");
				compression("input.txt", destination);
			}
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
			system(CLEAR);
			printf("\tEntrez le chemin du fichier à decompresser\n");
			scanf("%s", fichier_a_compresser);
			if (fichier_existe(fichier_a_compresser))
			{
				strcpy(destination, fichier_a_compresser);
				destination[strlen(destination)-5] = '\0';
				decompression(fichier_a_compresser, destination);
				printf("\nVotre fichier se trouve à l'emplacement suivant:\n\t\
						%s\n", destination);
			}
		break;
		case TEST_DEBUG:
			choix=0;
			do
			{
				system(CLEAR);

				display_titre();
				printf("\tQuel est votre message ?\n");
				printf("\n\tmessage (max 512 caracteres): ");
				scanf("%s", message);
				fichier = fopen("input.txt", "w");
				//ecrit dans un fichier temporaire le message rentre par l'utisateur
				if (fichier != NULL)
				{
					fprintf(fichier, "%s", message);
        			fclose(fichier);
				}

        		system(CLEAR);

				display_titre();
				printf("\tou voulez vous compresser ?\n");
				printf("1- Dans un fichier\n");
				printf("2- Dans la console\n");
				printf("\n\tchoix :");
				scanf("%d",&choix);

			}while(choix!=1 && choix!=2);

			if(choix == 1)
			{
				fichier_destination(destination);
				debug_compression("input.txt", destination);
			} else {
				strcpy(destination, "tmp.huff");
				debug_compression("input.txt", destination);
			}
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
		default:
		break;
	}
}
