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
	arbre->pfi = noeud_fd(arbre->racine);
    arbre->pffe = noeud_fg(arbre->racine);
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
    assert(fg != TPN_NULL && fd != TPN_NULL);

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

/** @brief Ajout une nouvelle feuille
 *
 * Maintient l'ordre de Gallager
 * @param arbre  l'arbre en question
 * @param c  le caractère à ajouter
 */
void ajout_feuille(t_arbre *arbre, unsigned char c)
{
	/* Et on ajoute la nouvelle feuille en créant un
	 * nouveau noeud.
	 * Car on sait que la feuille UNKNOWN_CHAR sera toujours
	 * le fils droit d'un noeud et qu'il faut donc créer un
	 * nouveau noeud. */
	tpn noeud = cree_noeud(arbre->pfi->parent, cree_feuille((short)c, arbre->pfi->ord_gal+1, 1), arbre->pfi, arbre->pfi->ord_gal);
	noeud->parent->fd = noeud; // Ne pas oublier de mettre à jour le parent.
	arbre->caracteres[(int)c] = noeud_fg(noeud); // Ajout du caractère dans la liste
	// Ne pas oublier de mettre à jour l'ordre de Gallager
	noeud_fd(noeud)->ord_gal += 2;
	arbre->ordres[noeud->ord_gal] = noeud;
	arbre->ordres[noeud_fd(noeud)->ord_gal] = noeud_fd(noeud);
	arbre->ordres[noeud_fg(noeud)->ord_gal] = noeud_fg(noeud);
	// Maintenir l'ordre de Galager
	maintenir_gallager(arbre, noeud);
}

/** @brief Incrémente le poids d'une feuille
 *
 * Maintient l'ordre de Gallager
 * @param arbre  l'arbre en question
 * @param feuille  la feuille à incrémenter
 */
void incrementer_feuille(t_arbre *arbre, tpn feuille)
{
	feuille->poids++;
	maintenir_gallager(arbre, feuille);
}

/** @brief Met à jour le poids du noeud
 *
 * Fonction récursive qui maintient l'ordre de Gallager et
 * met à jour les noeud
 * @param arbre  l'arbre sur lequel l'ordre doit être maintenu
 * @param noeud  noeud dont on viens de mettre à jour le poids
 */
void maintenir_gallager(t_arbre *arbre, tpn noeud)
{
	int i = noeud->ord_gal-1;
	int valid = 1;
	// Test validité de l'ordre
	while (valid && i > 0)
	{
		if (noeud->poids >= arbre->ordres[i]->poids)
			valid = 0;
		i--;
	}
	if (!valid)
	{
		tpn echange = arbre->ordres[i+1]; // Reviens sur celui d'avant
		permuter(noeud, echange, arbre); // Echange sans maj des poids
		// Mettre à jour poids du parents du fautif (inutile pour l'autre, changera pas)
		maj_poids_noeud(noeud->parent);
		// Revérifier ordre
		maintenir_gallager(arbre, noeud->parent);
	}
}

/** @brief Met à jour le poids du noeud
 *
 * @param noeud  l'élément à mettre à jour
 */
void maj_poids_noeud(tpn noeud)
{
	noeud->poids = elem_poids(noeud_fd(noeud)) + elem_poids(noeud_fg(noeud));
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
 * Echange leur parents, mets à jour leur ordres et le tableau d'ordres.
 * @param elem1  le 1er élément à permuter
 * @param elem2  le 2ème élément à permuter
 */
void permuter(tpn elem1, tpn elem2, t_arbre *arbre)
{
    assert(elem1 != TPN_NULL && elem2 != TPN_NULL);

    tpn tmp_parent = elem1->parent;
	int tmp_ordre = elem1->ord_gal;

	arbre->ordres[elem1->ord_gal] = elem2;
	arbre->ordres[elem2->ord_gal] = elem1;

    elem1->parent = elem2->parent;
	elem1->ord_gal = elem2->ord_gal;

    elem2->parent = tmp_parent;
	elem2->ord_gal = tmp_ordre;
}

/** @brief Libère toute la mémoire réservé pour l'arbre
 *
 * @param racine  pointeur sur la racine de l'arbre à libérer
 */
void liberer_arbre(tpn racine)
{
	if (est_feuille(racine))
	{
		free(racine);
	}
	else
	{
		liberer_arbre(racine->fg);
		liberer_arbre(racine->fd);
		free(racine);
	}
}

/** @brief calcule le nombre de feuille d'un arbre
 *
 * fonction récursive qui renvoie le nombre de feuilles d'un arbre 
 * @param arbre arbre
 */

int nb_feuilles(tpn a){
	if(est_feuille(a)){
		return 1;
	} else{
		return (nb_feuilles(a->fg)+nb_feuilles(a->fd));
	}
}


/** @brief Calcul et renvoie la profondeur d'un arbre
 *
 * fonction récursive qui renvoie la profondeur d'un arbre 
 * @param arbre arbre sur lequel on veux calculer la profondeur de l'arbre
 */
int profondeur(tpn arbre)
{
	int b,c;
	if(est_feuille(arbre)){
		return 0;	
	} else {
		b=nb_feuilles(arbre->fg);
		c=nb_feuilles(arbre->fd);
		return (1 + (b<c)?b:c);
		/* if (b<c){
			return b;
		}else{
			return c;
		}
		*/
	}
}