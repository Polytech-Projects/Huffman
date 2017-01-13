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

/** @brief Représente un noeud ou feuille de l'arbre
 *
 * Un noeud a au moins un fils qui n'est pas NULL (s'il en qu'un seul,
 * c'est obligatoirement le fils gauche qui est alloué en premier).
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
	 * 'caractère indéfini' -> SHRT_MAX. */
	short val;
	int ord_gal; // Ordre de gallager
	int poids; // Poids de 'val'
} t_noeud, *tpn;

tpn cree_feuille(char val, tpn parent);
int est_feuille(tpn feuille);
int est_fg(tpn feuille);
tpn cree_noeud(tpn parent, char val, tpn fg, tpn fd);
tpn noeud_fg(tpn noeud);
tpn noeud_fd(tpn noeud);
char elem_valeur(tpn elem);
int elem_ordre(tpn elem);
int elem_poids(tpn elem);

#endif //HUFFMAN_ARBRE_H
