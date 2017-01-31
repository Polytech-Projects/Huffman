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

void compression(const char *fal, const char *nf);
int fichier_existe(const char * const nom);
void init_tampon();
void ajouter_bit_tampon(int bit, FILE *nf);
void ajouter_char_au_tampon(char carac, FILE *nf);
void ajouter_au_tampon(tpn arbre, FILE *nf);
void clear_tampon(FILE *nf);

//void debug(tpn arbre);

#endif //HUFFMAN_TOOLS_H
