#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mod.h"

int menu()
{



    int choix;


    puts("1: afficher l enigme \n ");
    puts("2: generer l enigme \n ");
    
    puts("0: quitter \n");

    do
    {
        printf("donner votre choix: \n");
        scanf("%d",&choix);
    }
    while(choix>2 || choix <0);

    return choix;

}

void afficherEnigme(enigme e, SDL_Surface * screen)
{













}

void genererEnigme(enigme * e, char *nomfichier)
{






}
