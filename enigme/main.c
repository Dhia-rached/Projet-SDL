#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eaaf.h"

int main()
{

int choix;

 do
    {
        choix=menu();

        switch (choix)
        {
        case 1:
        {
   afficherEnigme(e,&screen);
            break;

        }

        case 2:
        {
      genererEnigme(&e,&nomfichier);
            break;

        }


        }
    }

    while(choix !=0 );

    return 0;
}

