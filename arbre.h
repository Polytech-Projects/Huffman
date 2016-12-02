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

typedef struct t_noeud {
    struct t_noeud * parent;
    struct t_noeud * fg; // Fils gauche
    struct t_noeud * fd; // Fils droit
    char val; // Contient la lettre ASCII
    int ord_gal;
    int poids; // Poids de 'val'
} t_noeud, *ptr_t_noeud;

#endif //HUFFMAN_ARBRE_H
