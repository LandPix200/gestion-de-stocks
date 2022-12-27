/*
Fichier qui contient tout ce qui concerne un produit
*/
#if !defined(_STDIO_)
#define _STDIO_
#include "stdio.h"
#endif // _STDIO_


typedef struct Produit Produit;

struct Produit
{
    int id;
    char designation[256];
    int prix;
    int quantite;
    Produit *suivant;
    
};

// 

void afficher_produit(Produit *produit);