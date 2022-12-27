#if !defined(_PRODUIT)
#define _PRODUIT
#include "include/produit.h"
#endif // _PRODUIT

/// @brief Afficher un produit
/// @param produit Le produit en question
void afficher_produit(Produit *produit)
{
    // printf("-> PRODUIT N°%d\n", produit->id);
    // printf("\tDésignation: %s\n", produit->designation);
    // printf("\tPrix: %d FCFA\n", produit->prix);
    // printf("\tQuantité: %d\n", produit->quantite);

    printf("-> %d: %s (%d FCFA) : %d restants \n",
           produit->id, produit->designation, produit->prix, produit->quantite);
}