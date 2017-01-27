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
 * @file arbre.c
 * @brief
 *
 */

#ifndef HUFFMAN_ARBRE_H
#define HUFFMAN_ARBRE_H

#include <limits.h>

#define TPN_NULL (tpn)NULL
#define FAKE_EOF (SHRT_MAX-1)
#define UNKNOWN_CHAR (SHRT_MAX-2)

/** @brief Représente un noeud ou feuille de l'arbre
 *
 * Un noeud a obligatoirement deux fils
 * Une feuille est un noeud qui n'a pas de fils (son fils droit et fils
 * gauche sont tous les deux à NULL).
 *
 */
typedef struct t_noeud
{
	struct t_noeud *parent;
	// Fils d'un noeud
	struct t_noeud *fg;
	struct t_noeud *fd;
	/* Prend une valeur de la table ASCII ou bien celle de
	 * 'caractère indéfini' -> UNKNOWN_CHAR. */
	short val;
	int ord_gal; // Ordre de gallager
	int poids; // Poids de 'val'
} t_noeud, *tpn;

typedef struct t_arbre {
	/* Contient l'arbre de Huffman, celui-ci doit respecter l'ordre
	 * de Gallager. */
	tpn racine;
	/* Contient l'ordre de gallager ordonné par ordre décroissant.
	 * Dans l'arbre, la feuille à gauche aura son ordre > à celle de droite.
	 * Si un ordre n'est pas associé à un feuille, vaut TPN_NULL */
	tpn ordres[515];
	/* Chaque indice correspond a un caractère de la table ASCII et
	 * contient le pointeur vers la feuille de l'arbre s'il a déjà été
	 * rencontré, sinon TPN_NULL. */
	tpn caracteres[256];
} t_arbre;

void init_arbre(t_arbre *arbre);
tpn cree_feuille(short val, int ordre, int poids);
tpn cree_noeud(tpn parent, tpn fg, tpn fd, int ordre);
void ajout_feuille(t_arbre *arbre, unsigned char c);
void incrementer_feuille(t_arbre *arbre, tpn feuille);
void maintenir_gallager(t_arbre *arbre);
void maj_poids_noeud(tpn noeud);
int est_feuille(tpn feuille);
int est_fg(tpn feuille);
tpn noeud_fg(tpn noeud);
tpn noeud_fd(tpn noeud);
char elem_valeur(tpn elem);
int elem_ordre(tpn elem);
int elem_poids(tpn elem);
void permuter(tpn elem1, tpn elem2);

#endif //HUFFMAN_ARBRE_H
