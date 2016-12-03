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
 * @todo Implémenter la suppression d'un noeud
 *
 */

#include <malloc.h>
#include <assert.h>
#include "arbre.h"

/** @brief Créée une feuille et la renvoie
 *
 * @param val  valeur de l'élément
 */
tpn cree_feuille(char val, tpn parent)
{
    tpn feuille = (tpn)malloc(sizeof(t_noeud));
    feuille->val = val;
    feuille->fg = TPN_NULL;
    feuille->fd = TPN_NULL;
    feuille->parent = parent;
    return feuille;
}

/** @brief Retourne vrai si le paramètre est une feuille
 *
 * Une feuille est un noeud qui a ses deux fils à NULL
 * @param element  l'élément à tester
 */
int est_feuille(tpn element)
{
    assert(element != TPN_NULL);
    /* Normalement seul la feuille gauche est à tester car par définition
     * un noeud qui n'a qu'un fils a obligatoirement comme fils celui de
     * gauche et non celui de droite.
     */
    return ((element->fg == TPN_NULL) && (element->fd == TPN_NULL));
}

/** @brief Créée un noeud et le renvoi
 *
 * @param etiq  l'étiquette du noeud
 * @param fg  le fils gauche du noeud
 * @param fd  le fils droit du noeud
 */
tpn cree_noeud(tpn parent, char val, tpn fg, tpn fd)
{
    tpn noeud = (tpn)malloc(sizeof(t_noeud));
    noeud->parent = parent;
    noeud->val = val;
    noeud->fg = fg;
    noeud->fd = fd;
    return noeud;
}

/** @brief Retourne le fils gauche du noeud
 *
 * @param noeud  le noeud dont on veut le fils
 */
tpn noeud_fg(tpn noeud)
{
    assert((noeud != TPN_NULL) && !est_feuille(noeud));
    return noeud->fg;
}

/** @brief Retourne le fils droit du noeud
 *
 * @param noeud  le noeud dont on veut le fils
 */
tpn noeud_fd(tpn noeud)
{
    assert((noeud != TPN_NULL) && !est_feuille(noeud));
    return noeud->fd;
}

/** @brief Retourne la valeur de l'élément
 *
 * @param elem  l'élément dont on veut la valeur
 */
char elem_valeur(tpn elem)
{
    assert(elem != TPN_NULL);
    return elem->val;
}

/** @brief Retourne l'ordre de l'élément
 *
 * @param elem  l'élément dont on veut l'ordre
 */
int elem_ordre(tpn elem)
{
    assert(elem != TPN_NULL);
    return elem->ord_gal;
}

/** @brief Retourne le poids de l'élément
 *
 * @param elem  l'élément dont on veut le poids
 */
int elem_poids(tpn elem)
{
    assert(elem != TPN_NULL);
    return elem->poids;
}