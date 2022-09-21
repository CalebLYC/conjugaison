#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conjugaison.h"

//Prototype des fonctions
char *saisie_verbe(void);
int groupe_verbe(char *verbe);
char *get_radical_verbe(char *verbe);
void conjug(char* verbe, int choice);
void conjug_present_indicatif(char *verbe);
void conjug_imparfait_indicatif(char *verbe);
void conjug_passeSimple(char *verbe);
void conjug_futurSimple(char *verbe);

int main()
{
    printf("\t\tPROGRAMME DE CONJUGAISON\n\n");//Nom du programme

    char *verbe, reponse, *temps;
    int choice;
   // int len_verbe;

    do//boucle g�n�rale d'ex�cution
    {
        verbe = saisie_verbe();//saisie du verbe
        //Choix du temps
        printf("\n\nChoizir le temps\n1 présent de l'indicatif\n"
               "2 Imparfait de l,indicatif\n"
               "3 Pass� simple de l'indicatif\n"
               "4 Futur simple de l'indicatif\n");
        printf("\nVotre choix:  ");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
                temps = "présent de l'indicatif";
                break;
            case 2:
                temps = "imparfait de l'indicatif";
                break;
            case 3:
                temps = "passé simple de l'indicatif";
                break;
            case 4:
                temps = "futur simple de l'indicatif";
                break;
        default:
                printf("Choix invalide\n");
                return (EXIT_FAILURE);
        }

        printf("\n\tConjugaison du verbe %s au %s\n",verbe, temps);
        conjug(verbe, choice);//Conjugaison du verbe

        //Libération de la mémoire
        free(verbe);
        free(temps);

        //Possibilité de reprise
        printf("Voulez-vous recommencer?(O/N)  ");
        fflush(stdin);
        scanf("%c",&reponse);
    }while(reponse == 'O' || reponse == 'o');

    return 0;
}
