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
tpa cree_feuille(char val)
{
    tpa feuille = (tpa)malloc(sizeof(t_arbre));
    feuille->type = FEUILLE;
    feuille->val = val;
    return feuille;
}

/** @brief Supprime un arbre complet
 * @todo implémenter la fonction
 *
 * @param arbre  l'arbre que l'on veut supprimer
 */
void supprimer_arbre(tpa arbre)
{

}

/** @brief Supprime un noeud et ses fils
 *
 * @param noeud  le noeud que l'on veut supprimer
 */
void supprimer_noeud(tpa noeud)
{
    assert(noeud != TPA_NULL);

}

/** @brief Supprime une feuille
 *
 * @param feuille  la feuille qu'on veut supprimer
 */
void supprimer_feuille(tpa feuille)
{
    assert(feuille != TPA_NULL);
    // On averti le parent de la perte d'un de ses fils
    if (feuille->parent != TPA_NULL)
    {
        // On cherche la bonne branche à reset
        if (arbre_fd(feuille->parent) == feuille)
            feuille->parent->fd = TPA_NULL;
        else
            feuille->parent->fg = TPA_NULL;
    }
    free(feuille);
}

/** @brief Retourne vrai si le paramètre est une feuille
 *
 * @param element  l'élément à tester
 */
int est_feuille(tpa element)
{
    assert(element != TPA_NULL);
    return (element->type == FEUILLE);
}

/** @brief Créée un noeud et le renvoi
 *
 * @param etiq  l'étiquette du noeud
 * @param fg  le fils gauche du noeud
 * @param fd  le fils droit du noeud
 */
tpa cree_noeud(tpa parent, char val, tpa fg, tpa fd)
{
    assert((fg != TPA_NULL) && (fd != TPA_NULL));
    tpa noeud = (tpa)malloc(sizeof(t_arbre));
    if (parent != TPA_NULL)
        noeud->type = ARBRE;
    else
    {
        noeud->type = NOEUD;
        noeud->parent = parent;
    }
    noeud->val = val;
    noeud->fg = fg;
    noeud->fd = fd;
    return noeud;
}

/** @brief Retourne le fils gauche du noeud
 *
 * @param noeud  le noeud dont on veut le fils
 */
tpa arbre_fg(tpa noeud)
{
    assert((noeud != TPA_NULL) && !est_feuille(noeud));
    return noeud->fg;
}

/** @brief Retourne le fils droit du noeud
 *
 * @param noeud  le noeud dont on veut le fils
 */
tpa arbre_fd(tpa noeud)
{
    assert((noeud != TPA_NULL) && !est_feuille(noeud));
    return noeud->fd;
}

/** @brief Retourne la valeur de l'élément
 *
 * @param elem  l'élément dont on veut la valeur
 */
char arbre_valeur(tpa elem)
{
    assert(elem != TPA_NULL);
    return elem->val;
}

/** @brief Retourne l'ordre de l'élément
 *
 * @param elem  l'élément dont on veut l'ordre
 */
int arbre_ordre(tpa elem)
{
    assert(elem != TPA_NULL);
    return elem->ord_gal;
}

/** @brief Retourne le poids de l'élément
 *
 * @param elem  l'élément dont on veut le poids
 */
int arbre_poids(tpa elem)
{
    assert(elem != TPA_NULL);
    return elem->poids;
}