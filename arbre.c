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

void init_arbre(t_arbre *arbre)
{
	int i;
	for (i = 0; i < 515; i++)
		arbre->ordres[i] = TPN_NULL;
	for (i = 0; i < 256; i++)
		arbre->caracteres[i] = TPN_NULL;
	/* Initialisation de l'arbre
	 * On crée la racine et on lui ajoute le caractère virtuel de fin
	 * en fils gauche et le caractère inconnu en fils droit. */
	arbre->racine = cree_noeud(TPN_NULL, cree_feuille(FAKE_EOF, 1, 1), cree_feuille(UNKNOWN_CHAR, 2, 0), 0);
	/* On a l'arbre suivant
	 *          O
	 *         / \
	 *        FE UC
	 * FE: FAKE_EOF, ordre(1), poids(1)
	 * UC: UNKNOWN_CHAR, ordre(2), poids(0) */
	arbre->ordres[0] = arbre->racine;
	arbre->ordres[1] = noeud_fg(arbre->racine);
	arbre->ordres[2] = noeud_fd(arbre->racine);
}

/** @brief Créée une feuille et la renvoie
 *
 * Créée une feuille, son parent est mis à jour par
 * ce dernier.
 * @param val  valeur de l'élément
 * @param parent le parent de la feuille
 */
tpn cree_feuille(short val, int ordre, int poids)
{
    tpn feuille = (tpn)malloc(sizeof(t_noeud));
    feuille->val = val;
    feuille->ord_gal = ordre;
    feuille->poids = poids;
    feuille->fg = TPN_NULL;
    feuille->fd = TPN_NULL;
    return feuille;
}

/** @brief Créée un noeud et le renvoi
 *
 * Mets automatiquement les parents des enfants à jour.
 * @param parent  le parent du noeud
 * @param fg  le fils gauche du noeud
 * @param fd  le fils droit du noeud
 * @param ordre  son ordre de gallager
 * @param poids  son poids
 */
tpn cree_noeud(tpn parent, tpn fg, tpn fd, int ordre)
{
    assert(fg == TPN_NULL && fd == TPN_NULL);

    tpn noeud = (tpn)malloc(sizeof(t_noeud));
    noeud->parent = parent;
    noeud->ord_gal = ordre;
    noeud->fg = fg;
    noeud->fd = fd;
    // Mise à jour des parents des feuilles
    fg->parent = noeud;
    fd->parent = noeud;
    // Calcul du poids du noeud
    noeud->poids = elem_poids(fg) + elem_poids(fd);
    return noeud;
}

void ajout_feuille(t_arbre *arbre, char c)
{
	/* On parcours l'ordre de Gallager pour obtenir la
	 * feuille la plus basse dans l'arbre.
	 * TODO: optimiser - stocker l'ordre de gallager le plus
	 * grand dans un variable, évite le parcours. */
	tpn derniere_feuille = TPN_NULL;
	int j = 0;
	while (derniere_feuille == TPN_NULL && j < 515)
	{
		if (arbre->ordres[j] == TPN_NULL)
			derniere_feuille = arbre->ordres[j-1];
		else
			j++;
	}
	/* Et on ajoute la nouvelle feuille en créant un
	 * nouveau noeud.
	 * Car on sait que la feuille UNKNOWN_CHAR sera toujours
	 * le fils droit d'un noeud et qu'il faut donc créer un
	 * nouveau noeud. */
	tpn noeud = cree_noeud(derniere_feuille->parent, cree_feuille(c, j, 1), derniere_feuille, j-1);
	noeud->parent->fd = noeud; // Ne pas oublier de mettre à jour le parent.
	arbre->caracteres[(int)c] = noeud_fg(noeud); // Ajout du caractère dans la liste
	// Ne pas oublier de mettre à jour l'ordre de Gallager
	noeud_fd(noeud)->ord_gal++;
	arbre->ordres[j-1] = noeud;
	arbre->ordres[noeud_fd(noeud)->ord_gal] = noeud_fd(noeud);
	arbre->ordres[noeud_fg(noeud)->ord_gal] = noeud_fg(noeud);
}

void incrementer_feuille(t_arbre *arbre, tpn feuille)
{
	/* On parcours l'ordre de Gallager jusqu'à avoir le dernier
	 * élément de même poids. */
	int ordre = carac->ord_gal;
	while (carac->poids == arbre.ordres[ordre-1]->poids && ordre < 0)
	{
		ordre--;
	}
	// On permute celui trouver avec le caractère actuel
	permuter(carac, arbre.ordres[ordre]);
	// TODO: Vérifier la bonne maj des ordres, répéter jusqu'à ce que ordre conservé
}

/** @brief Retourne vrai si le paramètre est une feuille
 *
 * Une feuille est un noeud qui a ses deux fils à NULL
 * @param element  l'élément à tester
 */
int est_feuille(tpn element)
{
    assert(element != TPN_NULL);
    /* Normalement seul la feuille gauche devrait être à tester car par définition
     * un noeud a obligatoirement 2 fils, sinon c'est une feuille.
     */
    return ((element->fg == TPN_NULL) && (element->fd == TPN_NULL));
}

/** @brief Retourne vrai si la feuille ou noeud est un fils gauche
 *
 * @param elem  l'élément à tester
 */
int est_fg(tpn elem)
{
    if (elem->parent != TPN_NULL && noeud_fg(elem->parent) == elem)
    {
        return 1;
    }
    else
        return 0;
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

/** @brief Permute les 2 éléments
 *
 * On échange simplement leur parents.
 * @param elem1  le 1er élément à permuter
 * @param elem2  le 2ème élément à permuter
 */
void permuter(tpn elem1, tpn elem2)
{
    assert(elem1 != TPN_NULL && elem2 != TPN_NULL);
    tpn tmp_parent = elem1->parent;

    elem1->parent = elem2->parent;
    elem2->parent = tmp_parent;
}