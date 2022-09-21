#ifndef CONJUGAISON_H_INCLUDED
#define CONJUGAISON_H_INCLUDED
//Prototype des fonctions
char *saisie_verbe(void);
int groupe_verbe(char *verbe);
char *get_radical_verbe(char *verbe);
void conjug(char* verbe, int choice);
void conjug_present_indicatif(char *verbe);
void conjug_imparfait_indicatif(char *verbe);
void conjug_passeSimple(char *verbe);
void conjug_futurSimple(char *verbe);

//Définition des fonctions
char *saisie_verbe(void)
{
    char *verbe = malloc(sizeof(char)*52);

    do{
        puts("Entrer un verbe:  ");
        verbe = gets(verbe);
        if(groupe_verbe(verbe) != 1 && groupe_verbe(verbe) != 2 && groupe_verbe(verbe) !=30){
            printf("\aLe verbe entré n'est pas pris en charge\n"
                   "Veuilez reprendre\n");
        }
    }while(groupe_verbe(verbe) != 1 && groupe_verbe(verbe) != 2 && groupe_verbe(verbe) !=30);

    return verbe;
}

int groupe_verbe(char *verbe)
{
    int radical_len_verbe = strlen(verbe)-2, g=0;
    if(verbe[radical_len_verbe] == 'e' && verbe[radical_len_verbe+1] =='r'){
        g = 1;
    }
    else if(verbe[radical_len_verbe] == 'i' && verbe[radical_len_verbe+1] =='r' && verbe[radical_len_verbe-1] != 't'){
        g = 2;
    }
    else if(verbe[radical_len_verbe] == 'i' && verbe[radical_len_verbe+1] =='r' && verbe[radical_len_verbe-1] == 't'){
        g = 30;
    }
    return g;
}

char *get_radical_verbe(char *verbe)
{
    int i=0, radical_len_verbe = strlen(verbe)-2;
    char *radical_verbe = malloc(sizeof(char)*50);

    if(groupe_verbe(verbe) == 30){
        while(i < radical_len_verbe-1){
        radical_verbe[i] = verbe[i];
        i++;
        }
    }
    else{
        while(i < radical_len_verbe){
            radical_verbe[i] = verbe[i];
            i++;
        }
    }

    return radical_verbe;
}
void conjug(char* verbe, int choice)
{
    if(choice == 1){
        conjug_present_indicatif(verbe);
    }
   else if(choice == 2){
        conjug_imparfait_indicatif(verbe);
    }
    else if(choice == 3){
        conjug_passeSimple(verbe);
    }
    else if(choice == 4){
        conjug_futurSimple(verbe);
    }
    else{
        printf("Temps non pris en charge\n");
    }
}

void conjug_present_indicatif(char *verbe)
{
    char *radical_verbe = get_radical_verbe(verbe);
    int radical_len_verbe = strlen(verbe)-2;

    if(groupe_verbe(verbe) == 1){
        if(strcmp(verbe, "aller") == 0){
            printf("Le verbe aller est du troisième groupe\n");
            printf("\nJe vais\n"
                    "\nTu vas\n"
                    "\nIl/Elle va\n"
                    "\nNous allons\n"
                    "\nVous allezs\n"
                    "\nIls/Elles vont\n"
            );
        }
        else if(verbe[radical_len_verbe - 1] == 'g'){
            printf("\n\nJe %s\n",strcat(radical_verbe, "e"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "es"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "e"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "eons"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "ez"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "ent"));
            radical_verbe = get_radical_verbe(verbe);
        }
        else{
            printf("\n\nJe %s\n",strcat(radical_verbe, "e"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "es"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "e"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "ons"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "ez"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "ent"));
            radical_verbe = get_radical_verbe(verbe);
        }
    }
    if(groupe_verbe(verbe) == 2){
        printf("\n\nJe %s\n",strcat(radical_verbe, "is"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "is"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "it"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "issons"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "issez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "ssent"));
        radical_verbe = get_radical_verbe(verbe);
    }
    if(groupe_verbe(verbe) == 30){
        printf("\n\nJe %s\n",strcat(radical_verbe, "s"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "s"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "t"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "tons"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "tez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "tent"));
        radical_verbe = get_radical_verbe(verbe);
    }

        return;
}

void conjug_imparfait_indicatif(char *verbe)
{
    char *radical_verbe = get_radical_verbe(verbe);
    int radical_len_verbe = strlen(verbe)-2;

    if(groupe_verbe(verbe) == 1){
        if(strcmp(verbe, "aller") == 0){
            printf("Le verbe aller est du troisième groupe\n");
            printf("\nJ'allais\n"
                    "\nTu allais\n"
                    "\nIl/Elle allait\n"
                    "\nNous allions\n"
                    "\nVous alliezs\n"
                    "\nIls/Elles allaient\n"
            );
        }
        else if(verbe[radical_len_verbe - 1] == 'g'){
            printf("\n\nJe %s\n",strcat(radical_verbe, "eais"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "eais"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "eait"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "eions"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "eiez"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "eaient"));
            radical_verbe = get_radical_verbe(verbe);
        }
        else{
            printf("\n\nJe %s\n",strcat(radical_verbe, "ais"));
            radical_verbe = get_radical_verbe(verbe);
            printf("\nTu %s\n",strcat(radical_verbe, "ais"));
            radical_verbe = get_radical_verbe(verbe);
            printf("\nIl %s\n",strcat(radical_verbe, "ait"));
            radical_verbe = get_radical_verbe(verbe);
            printf("\nNous %s\n",strcat(radical_verbe, "ions"));
            radical_verbe = get_radical_verbe(verbe);
            printf("\nVous %s\n",strcat(radical_verbe, "iez"));
            radical_verbe = get_radical_verbe(verbe);
            printf("\nIls/Elles %s\n",strcat(radical_verbe, "aient"));
            radical_verbe = get_radical_verbe(verbe);
        }
    }
    if(groupe_verbe(verbe) == 2){
        printf("\n\nJe %s\n",strcat(radical_verbe, "issais"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "issais"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "issait"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "issions"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "issiez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "ssaient"));
        radical_verbe = get_radical_verbe(verbe);
    }
    if(groupe_verbe(verbe) == 30){
        printf("\n\nJe %s\n",strcat(radical_verbe, "tais"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "tais"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "tait"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "tions"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "tiez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "taient"));
        radical_verbe = get_radical_verbe(verbe);
    }

    return;
}

void conjug_passeSimple(char *verbe)
{
    char *radical_verbe = get_radical_verbe(verbe);
    int radical_len_verbe = strlen(verbe)-2;

    if(groupe_verbe(verbe) == 1){
        if(strcmp(verbe, "aller") == 0){
            printf("Le verbe aller est du troisième groupe\n");
            printf("\nJ'allai\n"
                    "\nTu allas\n"
                    "\nIl/Elle alla\n"
                    "\nNous allâmes\n"
                    "\nVous allâtes\n"
                    "\nIls/Elles allèrent\n"
            );
        }
        else if(verbe[radical_len_verbe - 1] == 'g'){
            printf("\n\nJe %s\n",strcat(radical_verbe, "eai"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "eas"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "ea"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "eâmes"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "eâtes"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "èrent"));
            radical_verbe = get_radical_verbe(verbe);
        }
        else {
            printf("\n\nJe %s\n",strcat(radical_verbe, "ai"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "as"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "a"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "âmes"));
            radical_verbe = get_radical_verbe(verbe);

            printf("Vous %s\n",strcat(radical_verbe, "âtes"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "èrent"));
            radical_verbe = get_radical_verbe(verbe);
        }
    }
    if(groupe_verbe(verbe) == 2){
        printf("\n\nJe %s\n",strcat(radical_verbe, "is"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "is"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "it"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "îmes"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "îtes"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "irent"));
        radical_verbe = get_radical_verbe(verbe);
    }
    if(groupe_verbe(verbe) == 30){
        printf("\n\nJe %s\n",strcat(radical_verbe, "tis"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "tis"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "tit"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "tîmes"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "tîtes"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "tirent"));
        radical_verbe = get_radical_verbe(verbe);
    }

    return;
}

void conjug_futurSimple(char *verbe)
{
    char *radical_verbe = get_radical_verbe(verbe);
    int radical_len_verbe = strlen(verbe)-2;

    if(groupe_verbe(verbe) == 1){
        if(strcmp(verbe, "aller") == 0){
            printf("Le verbe aller est du troisième groupe\n");
            printf("\nJ'irai\n"
                    "\nTu iras\n"
                    "\nIl/Elle ira\n"
                    "\nNous irons\n"
                    "\nVous irez\n"
                    "\nIls/Elles iront\n"
            );
        }
        else if(verbe[radical_len_verbe - 1] == 'g'){
            printf("\n\nJe %s\n",strcat(radical_verbe, "erai"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "eras"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "era"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nNous %s\n",strcat(radical_verbe, "erons"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "erez"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "eront"));
            radical_verbe = get_radical_verbe(verbe);
        }
        else{
            printf("\n\nJe %s\n",strcat(radical_verbe, "erai"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nTu %s\n",strcat(radical_verbe, "eras"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIl %s\n",strcat(radical_verbe, "era"));
            radical_verbe = get_radical_verbe(verbe);

            printf("Nous %s\n",strcat(radical_verbe, "erons"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nVous %s\n",strcat(radical_verbe, "erez"));
            radical_verbe = get_radical_verbe(verbe);

            printf("\nIls/Elles %s\n",strcat(radical_verbe, "eront"));
            radical_verbe = get_radical_verbe(verbe);
        }
    }
    if(groupe_verbe(verbe) == 2){
        printf("\n\nJe %s\n",strcat(radical_verbe, "irai"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "ras"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "ra"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "irons"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "irez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "iront"));
        radical_verbe = get_radical_verbe(verbe);
    }
    if(groupe_verbe(verbe) == 30){
        printf("\n\nJe %s\n",strcat(radical_verbe, "tirai"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nTu %s\n",strcat(radical_verbe, "tiras"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIl %s\n",strcat(radical_verbe, "tira"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nNous %s\n",strcat(radical_verbe, "tirons"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nVous %s\n",strcat(radical_verbe, "tirez"));
        radical_verbe = get_radical_verbe(verbe);

        printf("\nIls/Elles %s\n",strcat(radical_verbe, "tiront"));
        radical_verbe = get_radical_verbe(verbe);
    }

    return;
}


#endif // CONJUGAISON_H_INCLUDED
