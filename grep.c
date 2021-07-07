#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_sir(char **cuvant, int *n, char ***sir)
{
    int i;
    //alocare memorie pentru vectorul temporar
    char *sir_temp = calloc(201, sizeof(char));
    //se citeste cuvantul si se elimina \n
    fgets(sir_temp, 200, stdin);
    if (sir_temp[strlen(sir_temp) - 1] == '\n')
    {
        sir_temp[strlen(sir_temp) - 1] = 0;
    }
    //se aloca spatiu corespunzator si se copiaza in variabila cuvant
    *cuvant = calloc(strlen(sir_temp) + 1, sizeof(char));
    strcpy(*cuvant, sir_temp);
    //se citeste numarul de linii

    scanf("%d", n);
    // se aloca memorie pentru adresele vectorilor in care se stocheaza liniile
    *sir = calloc((*n), sizeof(char *));
    fgets(sir_temp, 200, stdin);
    for (i = 0; i < *n; i++)
    { //se citeste fiecare linie din sir si se elimina \n
        fgets(sir_temp, 200, stdin);
        if (sir_temp[strlen(sir_temp) - 1] == '\n')
        {
            sir_temp[strlen(sir_temp) - 1] = 0;
        }
        //se aloca memorie pentru fiecare linie si se copiaza

        (*sir)[i] = calloc(strlen(sir_temp) + 1, sizeof(char));
        strcpy((*sir)[i], sir_temp);
    }
    //se elibereaza memoria sirului temporar
    free(sir_temp);
}

int numar_aparitii(char *sir, char *cuvant)
{
    char *p;
    int nr_ap = 0;
    //se cauta prima aparitie a cuvantului in sir
    p = strstr(sir, cuvant);
    while (p)
    {
        nr_ap++;
        //se cauta in continuare alta aparitie a cuvantului
        p = strstr(p + strlen(cuvant), cuvant);
    }
    return nr_ap;
}

void grep(char *sir, char *cuvant)
{
    char *p, temp[200];
    //se cauta prima aparitie a cuvantului in sir
    p = strstr(sir, cuvant);
    while (p)
    { // se salveaza textul care urmeaza dupa cuvant
        strcpy(temp, p + strlen(cuvant));
        //se copiaza la pozitia cuvantului extensia de colorare
        strcpy(p, "\e[0;31m");
        //se concateneaza cuvantul
        strcat(p, cuvant);
        //se adauga dupa cuvant extensia de colorare
        strcat(p, "\e[m");
        // se concateneaza portiunea de text salvata
        strcat(p, temp);
        // se cauta urmatoarea aparitie a cuvantului
        p = strstr(p + 7 + strlen(cuvant), cuvant);
    }
}

int main()
{
    //n numarul de siruri,
    //nr_ap = numar aparitii cuvant in sir
    int n, i, nr_ap;
    //cuvant= cuvantul pentru grep
    // lista_siruri lista de siruri data la intrare
    char *cuvant = NULL, **lista_siruri = NULL;
    // citire date de intrare
    read_sir(&cuvant, &n, &lista_siruri);
    // parcurgere siruri si adaugare cod colorare (grep)
    for (i = 0; i < n; i++)
    {
        nr_ap = numar_aparitii(lista_siruri[i], cuvant);
        if (nr_ap)
        {
            // realocare spatiu pentru inserarea sirurilor pentru colorare
            lista_siruri[i] = realloc(lista_siruri[i], (strlen(lista_siruri[i]) + 10 * nr_ap + 1) * sizeof(char));
            grep(lista_siruri[i], cuvant);
        }
    }

    // afisare date
    for (i = 0; i < n; i++)
    {
        if (numar_aparitii(lista_siruri[i], cuvant) > 0)
        {
            printf("%s\n", lista_siruri[i]);
        }
    }

    //eliberare memoria pentru cuvantul cautat
    free(cuvant);
    //eliberare memoria pentru matricea de vectori
    for (i = 0; i < n; i++)
    {
        free(lista_siruri[i]);
    }
    // eliberare memorie alocata pentru variabila lista_siruri
    free(lista_siruri);
    return 0;
}
