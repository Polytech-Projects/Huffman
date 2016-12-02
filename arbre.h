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

#ifndef HUFFMAN_ARBRE_H
#define HUFFMAN_ARBRE_H

#define TPA_NULL (tpa)NULL

typedef enum type_noeud {
    ARBRE, NOEUD, FEUILLE
} type_noeud;

typedef struct t_arbre {
    struct t_arbre * parent;
    // Fils d'un noeud
    struct t_arbre * fg;
    struct t_arbre * fd;
    type_noeud type; // Vaut 0 pour une feuille, 1 pour un noeud
    char val; // Contient le code ASCII
    int ord_gal; // Ordre de gallager
    int poids; // Poids de 'val'
} t_arbre, * tpa;

tpa cree_feuille(char val);
void supprimer_arbre(tpa arbre);
void supprimer_noeud(tpa noeud);
void supprimer_feuille(tpa feuille);
int est_feuille(tpa feuille);
tpa cree_noeud(tpa parent, char val, tpa fg, tpa fd);
tpa arbre_fg(tpa noeud);
tpa arbre_fd(tpa noeud);
char arbre_valeur(tpa elem);
int arbre_ordre(tpa elem);
int arbre_poids(tpa elem);

#endif //HUFFMAN_ARBRE_H
