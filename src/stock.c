#if !defined(_STOCK_)
#define _STOCK_
#include "include/stock.h"
#endif // _STOCK_

/// @brief Obtenir le nombre de produit dans le stock
/// @param Stock le stock en question
/// @return Le nombre de produit
int nombre_produit(Stock *Stock)
{
    int s = 0;
    Produit *p = Stock->premier_produit;
    while (p != NULL)
    {
        s++;
        p = p->suivant;
    }

    return s;
}

/// @brief Creer un nouveau stock
/// @return retourne un pointeur vers le stock créé
Stock *creer_stock()
{

    Stock *stock = malloc(sizeof(Stock));
    stock->premier_produit = NULL;
    stock->dernier_produit = NULL;
    return stock;
}

/// @brief Ajouter un produit au stock
/// @param stock Le stock en question
/// @param designation la désignation du produit
/// @param prix le prix du produit
/// @param quantite la quantité du produit dans le stock
/// @return 1 si tout s'est bien passé et 0 sinon
int ajouter_produit(Stock *stock, const char *designation, float prix, int quantite)
{

    Produit *p = malloc(sizeof(Produit));
    p->id = nombre_produit(stock) + 1;
    strcpy(p->designation, designation);
    p->prix = prix;
    p->quantite = quantite;

    if (stock->premier_produit == NULL)
    {
        if (stock->dernier_produit == NULL)
        {
            stock->premier_produit = p;
            stock->dernier_produit = p;
            p->suivant = NULL;
            return 1;
        }
    }
    else
    {
        stock->dernier_produit->suivant = p;
        stock->dernier_produit = p;
        p->suivant = NULL;
        return 1;
    }

    return 0;
}

/// @brief Afficher le stock
/// @param stock la stock en question
void afficher_stock(Stock *stock)
{
    cls();
    Produit *p = stock->premier_produit;
    printf("######## LISTE DES PRODUITS ########\n\n");
    while (p != NULL)
    {
        afficher_produit(p);
        p = p->suivant;
    }
}

/// @brief Enregistrer le stock dans un fichier
/// @param stock Le stock en question
void enregistrer_stock(Stock *stock)
{
    Produit *p = stock->premier_produit;
    FILE *f = fopen("stock.db", "w");
    while (p != NULL)
    {
        fprintf(f, "%s %d %d\n", p->designation, p->prix, p->quantite);
        p = p->suivant;
    }
    fclose(f);
}

/// @brief Recuperer le stock depuis un fichier
/// @return Le stock récupéré
Stock *charger_stock()
{
    Stock *stock = creer_stock();
    FILE *f = fopen("stock.db", "r");
    while (1)
    {
        char d[256];
        int p = 0, q = 0;
        int a = fscanf(f, "%s %d %d\n", d, &p, &q);
        if (a == -1)
            break;
        ajouter_produit(stock, d, p, q);
    }
    fclose(f);

    return stock;
}

/// @brief Obtenir un produit dans le stock grace a son numero/id
/// @param stock Le stock en question
/// @param id l'id du produit
/// @return Le produit en question ou NULL si le produit n'existe pas
Produit *obtenir_produit(Stock *stock, int id)
{
    Produit *p = stock->premier_produit;
    while (p != NULL)
    {
        if (p->id == id)
            return p;
        p = p->suivant;
    }
    return NULL;
}

/// @brief Vendre un produit
/// @param stock Le stock dans lequel qe trouve le produit
/// @param id l'id du produit en question
/// @param quantite la quantité de produit que l'on veut vendre
void vendre_produit(Stock *stock, int id, int quantite)
{
    Produit *p = obtenir_produit(stock, id);
    if (p == NULL)
    {
        printf("Ce produit n'a pa été trouvé dans le stock !!\nVoulez-vous essayer un autre ID ? (1: OUI)> ");
        int id2, choix;
        scanf("%d", &choix);
        if (choix == 1)
        {
            printf("Entrer le nouvel id (Entre 1 et %d)\n>", nombre_produit(stock));
            scanf("%d", &id2);
            vendre_produit(stock, id2, quantite);
        }
        return;
    }
    printf("Vous avez choisi Le produit nommé: %s\n", p->designation);
    if (quantite > p->quantite)
    {
        printf("Désolé mais il ne reste que %d %s en stock !\nVoulez-vous diminuer la quantité ? (1: OUI)> ",
               p->quantite, p->designation);
        int qtte, choix;
        scanf("%d", &choix);
        if (choix == 1)
        {
            printf("Entrer la nouvelle quantite\n>");
            scanf("%d", &qtte);
            vendre_produit(stock, id, qtte);
        }
    }
    else
    {
        p->quantite -= quantite;
        printf("La vente de %d %s a été réalisé avec succes. Cela fait %d FCFA\n",
               quantite, p->designation, p->prix * quantite);
    }
}

void cls()
{
    system("clear");
}

/// @brief Liberer le stock de la mémoire
/// @param stock Le stock à fermer
void fermer_stock(Stock *stock)
{
    Produit *p = stock->premier_produit;
    while (p != NULL)
    {
        free(p);
        p = p->suivant;
    }
    free(stock);
}