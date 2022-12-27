#include "include/menu.h"

void input_enregistrer_produit(Stock *stock)
{
    cls();
    char *d = malloc(sizeof(char));
    int p, q;
    printf("### ENREGISTREMENT DU PRODUIT ###\n\n");
    printf("Quel est le nom du produit ? (Ex: stylo_rouge) > ");
    scanf("%s", d);
    printf("Combien coûte 1 %s ? > ", d);
    scanf("%d", &p);
    printf("Donner la quantité > ");
    scanf("%d", &q);
    printf("Le produit a été enregistré avec succes !");
    ajouter_produit(stock, d, p, q);
    int choix;
    printf("\nVoulez-vous enregistrer un autre produit ? (1: OUI)\n>");
    scanf("%d", &choix);
    if (choix == 1)
        input_enregistrer_produit(stock);

    return;
}

void input_vendre_produit(Stock *stock)
{
    cls();
    printf("Veuillez entrer l'id du produit à vendre (Entre 1 et %d)\n>", nombre_produit(stock));
    int id;
    scanf("%d", &id);
    printf("Combien voulez-vous en vendre ?\n>");
    int qtte;
    scanf("%d", &qtte);
    vendre_produit(stock, id, qtte);
}