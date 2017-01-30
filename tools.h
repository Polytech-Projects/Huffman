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

#ifndef HUFFMAN_TOOLS_H
#define HUFFMAN_TOOLS_H

#include <stdio.h>
#include "arbre.h"

char tampon;
int compteur_tampon;

void compression(const char *fal, const char *nf);
void init_tampon();
void verif_tampon(char *nf);
void ajouter_char_au_tampon(char carac, char *nf);
void ajouter_au_tampon(tpn arbre, char *nf);
void clear_tampon(char *nf);

//void debug(tpn arbre);

#endif //HUFFMAN_TOOLS_H
