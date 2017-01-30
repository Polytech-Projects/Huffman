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
 * @file main.h
 *
 */

#ifndef MAIN_H
#define MAIN_H

/* Les différents choix pour le menu.
 * Attention, les nombres associé aux choix doivent être positif et
 * doivent se suivre (on peut changer leur ordre mais pas mettre
 * d'écart entre eux.) */
typedef enum e_choice
{
	COMPRESS = 1, DECOMPRESS = 2, COMPRESS_MSG = 3, TEST_DEBUG = 4, CHOICE_NBR
} e_choice;

void print_menu();

#endif //MAIN_H