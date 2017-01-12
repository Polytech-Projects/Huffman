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


#include "tools.h"
#include "arbre.h"

/** @brief Compresse le fichier vers un autre
 *
 * Le fichier va être compression via l'algorithme de Huffman adaptatif.
 *
 * @param fal  chaine de caractère étant le nom du fichier à lire
 * @param nf  chaine de caractère étant le nom du fichier à sauvegarder
 * TODO: faire en sorte que la fonction soit portable (lecture taille fichier)
 */
void compression(const char *fal, const char *nf)
{
	/* Contient l'arbre de Huffman, celui-ci doit respecter l'ordre
	 * de Gallager. */
	tpn arbre_huffman;
	/* Déclaration des tableaux d'ordre de gallager et celui contenant les
	 * pointeurs sur les caractères en local pour meilleur performance. */
	/* Contient l'ordre de gallager ordonné par ordre décroissant.
	 * Dans l'arbre, la feuille à gauche aura son ordre > à celle de droite.
	 * Si un ordre n'est pas associé à un feuille, vaut TPN_NULL */
	tpn ordre_gallager[256] = {TPN_NULL};
	/* Chaque indice correspond a un caractère de la table ASCII et
	 * contient le pointeur vers la feuille de l'arbre s'il a déjà été
	 * rencontré, sinon TPN_NULL. */
	tpn position_caracteres[256] = {TPN_NULL};
	/* Longueur du fichier.
	 * Attention: un fichier excédant la longueur que peut contenir cette
	 * variable entrainera un résultat inconnu. */
	long int tailleFichier = 0;
	// Utilisé pour parcourir le fichier
	long int i;
	// caractère actuel
	char c;
	// Pointeur sur le fichier à lire.
	FILE *pfl = fopen (fal, "r");
	FILE *pfe = fopen(nf, "w");

	// Test de l'ouverture du fichier
	if (pfl == NULL)
	{
		perror ("Erreur d'ouverture du fichier.");
	}
	else if (pfe == NULL)
	{
		/* Si impossible de créer un fichier pour écrire,
		 * on ferme celui qui a été ouvert pour la lecture. */
		fclose(pfl);
		perror ("Erreur d'ouverture du fichier.");
	}
	else
	{
		fseek (pfl, 0, SEEK_END);   // non-portable
		tailleFichier = ftell(pfl);
		rewind(pfl); // Important, remettre le curseur en début de fichier
		printf ("Le fichier contient: %ld caractères.\n", tailleFichier);

		for (i = 0; i < tailleFichier; i++)
		{
			// Lecture du complète du fichier.

			/* getc à la place de fgetc car est parfois implémenté en tant que
			 * macro, ce qui peut induire un gain de performance. */
			c = getc(pfl);
			printf("%c", c);

			// Opérations sur l'arbre d'Huffman
		}
		fclose(pfl);
		fclose(pfe);
	}
}