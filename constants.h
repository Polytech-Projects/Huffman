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
 * @file constants.h
 *
 */

#ifndef HUFFMAN_CONSTANTS_H
#define HUFFMAN_CONSTANTS_H
	#ifdef OS_WINDOWS
	    //define pour windows
	    #define CLEAR "cls"
	    #define SYSREAD "pause"
	#else
	    //define pour linux
	    #define CLEAR "clear"
	    #define SYSREAD "read a"
	#endif
#endif //HUFFMAN_TOOLS_H
