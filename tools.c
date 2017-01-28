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
	/* Longueur du fichier.
	 * Attention: un fichier excédant la longueur que peut contenir cette
	 * variable entrainera un résultat inconnu. */
	long int tailleFichier = 0;
	// Utilisé pour parcourir le fichier
	long int i;
	// caractère actuel
	unsigned char c;
	// Contient l'arbre de Gallager, son ordre, etc.
	t_arbre arbre;
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
		rewind(pfl); // Important, remet le curseur en début de fichier
		printf ("Le fichier contient: %ld caractères.\n", tailleFichier);
		
		// Création de l'arbre de base (racine + feuille EOF et caractère inconnu)
		//init_arbre(&arbre);

		// Lecture du complète du fichier.
		for (i = 0; i < tailleFichier; i++)
		{
			/* getc à la place de fgetc car est parfois implémenté en tant que
			 * macro, ce qui peut induire un gain de performance. */
			c = getc(pfl);
			printf("%u ", c);
			// Opérations sur l'arbre d'Huffman
			tpn code = arbre.caracteres[(int)c];

			// Si le code n'est pas présent dans l'arbre
			if (code == TPN_NULL)
			{
				ajout_feuille(&arbre, c);
			}
			// On doit rééquilibrer l'arbre et incrémenter de 1 succésivement
			else
			{
				incrementer_feuille(&arbre, code);
			}
		}
		fclose(pfl);
		fclose(pfe);
	}
}


/** @brief Affiche l'arbre
 *
 * Cette fonction affiche l'arbre ainsi que des informations sur celui-ci
 * à condition qu'il n'a pas de poids > 999.
 *
 * @param arbre prend un pointeur d'arbre en paramètre
 * TODO: 
 */
void debug(tpn arbre)
{
	int profondeur;

	system(CLEAR); //netoie le terminal (compatible windows / linux)

	//test pour savoir si un des 2 fils à un ordre > 999.
	if (arbre->fg->poids > 999 || arbre->fd->poids > 999){
		printf("arbre non compatible avec la fonction de debug.\n raison: poids d'un des noeuds superieur a 999");
	}else{

		//test de profondeur
		profondeur = profondeur(arbre);
		
	}
}