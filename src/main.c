/*
Programme en ligne de commande permettant de faire une gestion de stock dans un magazin pour aider
la caisse.
*/

#if !defined(_STDIO_)
#define _STDIO_
#include <stdio.h>
#endif // _STDIO_

#if !defined(_STDLIB)
#define _STDLIB
#include <stdlib.h>
#endif // _STDLIB

#if !defined(_STOCK_)
#define _STOCK_
#include "include/stock.h"
#endif // _STOCK_

#if !defined(_MENU_)
#define _MENU_
#include "include/menu.h"
#endif // _MENU_

int main(int argc, char const *argv[])
{
    Stock *stock = charger_stock();

    int run = 1;
    int choix;
    printf("\n----- BIENVENU SUR STOCKY -----\n\n");

    // MENU //
    do
    {
        enregistrer_stock(stock);
        printf("\n----- MENU PRINCIPAL -----\n");

        printf("1. Vendre un produit\n");
        printf("2. Enregistrer un nouveau produit\n");
        printf("3. Afficher le stock\n");
        printf("4. Quitter");

        printf("\nVeuillez faire un choix\n");
        printf(">");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            input_vendre_produit(stock);
            break;

        case 2:
            input_enregistrer_produit(stock);
            enregistrer_stock(stock);
            break;

        case 3:
            afficher_stock(stock);
            break;

        case 4:
            fermer_stock(stock);
            printf("\n### BYE BYE ###\n");
            run = 0;
            break;

        default:
            
            break;

        cls();
        }

    } while (run);

    return 0;
}
