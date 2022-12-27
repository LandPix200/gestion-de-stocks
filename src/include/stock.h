/*
Tout ce qui concerne le stock
    - Il s'agit d'un singleton dans le programme (Une structure a instatiation unique)
*/
#if !defined(_PRODUIT_)
#define _PRODUIT_
#include "produit.h"
#endif // _PRODUIT_

#if !defined(STDLIB)
#define STDLIB

#include "stdlib.h"

#endif // STDLIB

#if !defined(_STR__)
#define _STR__

#include <string.h>

#endif // _STR__


typedef struct Stock Stock;
/// @brief Structure representant le stock
struct Stock
{
    Produit *premier_produit;
    Produit *dernier_produit;
};

// Liste des fonctions à realiser sur le stock
void afficher_stock(Stock *stock);
int ajouter_produit(Stock *stock, const char *designation, float prix, int quantite);
Stock *creer_stock();
int nombre_produit(Stock *Stock);
void enregistrer_stock(Stock *stock);
Stock *charger_stock();
void vendre_produit(Stock *stock, int id, int quantite);
void cls();
void fermer_stock(Stock *stock);

