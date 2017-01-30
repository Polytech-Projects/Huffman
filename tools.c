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
#include <assert.h>

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
	FILE *pfl = fopen(fal, "r");
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

/** @brief Retourne 1 si le fichier existe
 *
 * @param nom  le chemin complet vers le fichier
 */
int fichier_existe(const char * const nom)
{
	FILE* file = fopen(nom, "r");
	int existe = file != NULL ? 1 : 0;
	if (file != NULL) fclose(file);
	return existe;
}
//initialise le tampon à zéro
void init_tampon()
{
	tampon = 0;
	compteur_tampon = 0;
}

//vérifie si le tampon n'est pas plein, l'ajoute au fichier si c'est le cas
void verif_tampon(char *nf)
{
	if(compteur_tampon == 8){
		printf("DEBUG: le tampon est plein ! vidage du tampon dans le fichier de sortie ...\n");
		FILE fp;
		fp = fopen(nf, "w");
		putc(tampon, fp);
		init_tampon();
	}
}

void ajouter_char_au_tampon(char carac, char *nf)
{
	int i;
	char tmp;

	i=0;
	carac = tmp;

	for(i; i<8; i++)
	{
		tmp = tmp >> 1;
		tmp = tmp << 1;
		if (tmp|carac == 1)
		{
			tampon = tampon << 1;
			tampon = tampon|1;
			compteur_tampon++;
		}
		if (tmp|carac == 0)
		{
			tampon = tampon << 1;
			compteur_tampon++;
		}
		verif_tampon();

	}

}

//ajoute au tampon le code d'un caractère
void ajouter_au_tampon(tpn arbre, char *nf)
{
	tpn tmp;
	int chemin[512];
	int taille_tab = 0;

	//on récupère le chemin binaire en partant de la feuille
	//et en remontant jusqu'a la racine.
	while (arbre->parent!=NULL)
	{
		tmp = arbre;
		arbre = arbre->parent;
		if (arbre->fg = tmp)
		{
			chemin[taille_tab]=0;
			taille_tab++;
		} 
		else if(arbre->fd = tmp)
		{
			chemin[taille_tab]=1;
			taille_tab++;
		}
	}
	taille_tab++;

	//boucle qui écrit dans le tampon le chemin dans l'ordre
	//car on écrit le chemin de la racine vers la feuille.
	//cependant il a été récupéré de la feuille à la racine.
	while(taille_tab!=0)
	{
		taille_tab--;
		assert(chemin[taille_tab]==0 || chemin[taille_tab]==1);
		if(chemin[taille_tab]=0)
		{
			tampon = tampon << 1;
			compteur_tampon++;
			verif_tampon();
		}else if(chemin[taille_tab]=1)
		{
			tampon = tampon << 1;
			compteur = compteur | 1;
			compteur_tampon++;
			verif_tampon();
		}
	}


}


//fonction qui vide le tampon actuel dans le fichier en paramètre.
//si le tampon n'est pas plein, elle rajoute des bits de bourrage
void clear_tampon(char *nf)
{
	printf("DEBUG: ajout de bits de bourrage au tampon et vidage du tampon dans le fichier de sortie\n");
	tampon = tampon << (8 - compteur_tampon);
	compteur_tampon = 8;
	verif_tampon();
}


/** @brief Affiche l'arbre
 *
 * Cette fonction affiche l'arbre ainsi que des informations sur celui-ci
 * à condition qu'il n'a pas de poids > 999.
 *
 * @param arbre prend un pointeur d'arbre en paramètre
 * TODO: 
 */

/* FONCTION MISE DE COTE
void debug(tpn arbre)
{
	int profondeur;

	system(CLEAR); //netoie le terminal (compatible windows / linux)
	printf("\t-------------------------\n");
	printf("\t|     DEBUG    ARBRE    |\n");
	printf("\t-------------------------\n\n");

	//test pour savoir si un des 2 fils à un ordre > 999.
	if (arbre->fg->poids > 999 || arbre->fd->poids > 999){
		printf("Arbre non compatible avec la fonction de debug.\n raison: poids d'un des noeuds superieur a 999");
	}else{
		if (arbre!=NULL){
			//test de profondeur
			profondeur = profondeur(arbre);

			printf("Profondeur de l'arbre: %d \n\n", profondeur);

			int i=1;
			for (i=1; i<=profondeur; i++)
			{
				printf("\n");
			}	
		} else {
			printf("Arbre vide\n");
		}
		

		
	}
}
/*
