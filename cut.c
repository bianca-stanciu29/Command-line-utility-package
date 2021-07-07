#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_sir(char **del,int *n,int **v, char **out_del, int *m, char ***lista_siruri)
{
    int i;
    char ch;
    // alocare memorie pentru sir temporar
    char* sir_temp = calloc(201,sizeof(char));
    // citire sir delimitatori, alocare memorie corespunzatare si copiere
    fgets(sir_temp, 200, stdin);
    *del = calloc(strlen(sir_temp)+1, sizeof(char));
    strcpy(*del, sir_temp);
    //citire nr elemente vector
    scanf("%d", n);
    //alocare memorie vector de int
    *v =calloc ((*n) , sizeof(int));
    //citire vector
    for(i=0; i<*n; i++)
    {
        scanf("%d", &((*v)[i]));
        scanf("%c", &ch);
    }
    // citire sir delimitatori out, alocare memorie corespunzatare si copiere
    fgets(sir_temp, 200, stdin);
    if(sir_temp[strlen(sir_temp)-1]=='\n')
        {
            sir_temp[strlen(sir_temp)-1]=0;
        }
    *out_del = calloc(strlen(sir_temp)+1, sizeof(char));
    strcpy(*out_del, sir_temp);
    // citire numar siruri
    scanf("%d", m);
    //citire delimitator de iesire
    scanf("%c",&ch);
    // alocare vector de siruri de caractere
    *lista_siruri = calloc(*m, sizeof(char*));
    // citire siruri
    for(i=0; i<*m; i++)
    {
        // citire sir, eliminare sfarsit linie
        fgets(sir_temp, 200, stdin);
        if(sir_temp[strlen(sir_temp)-1]=='\n')
        {
            sir_temp[strlen(sir_temp)-1]=0;
        }
        //alocare memorie corespunzatoare si copiere in lista
        (*lista_siruri)[i]=calloc(strlen(sir_temp)+1, sizeof(char));
        strcpy((*lista_siruri)[i],sir_temp);
    }
    //eliberare memorie sir temporar
    free(sir_temp);
}

void vsort(int *v, int *n)
{
    int sch, aux, i, j;
    //ordonare vector prin bubble sort
    do
    {  //variabila booleana
        sch=0;
        for(i=0; i<(*n)-1; i++)
        {
            if(v[i]>v[i+1])
            { 
       //interschimbarea cu variabila auxiliara aux
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sch=1;
            }
        }

    }while(sch);

    //eliminare valori identice(dubluri)
    for(i=0; i<(*n)-1; i++)
    {
        if(v[i]==v[i+1])
        {
            for(j=i; j<(*n)-1; j++)
            {
                v[j]=v[j+1];
            }
            (*n)--;
            i--;
        }
    }
}

// eliminare delimitatori initiali si adaugare delimitatori out
void cut(char *del,int n,int *v, char *out_del, int *m, char ***lista_siruri)
{
    char temp[201], *p;
    int i, j, k;
    //parcurgere lista de siruri
    for(j=0; j<*m; j++)
    {
        //initializare sir rezultat
        strcpy(temp,"");
        k=0;
        i=0;
        //descompunere sir curent in cuvinte (dupa delimitatori)
        p=strtok((*lista_siruri)[j], del);
        while(p)
        {
            k++;
            //testare daca cuvantul este in vectorul de cuvinte selectate
            if(i<n && v[i]==k)
            {
                //initial se adauga doar cuvantul
                if(strlen(temp)==0)
                {
                    strcat(temp,p);
                }
                //se adauga delimitator out si apoi cuvantul
                else
                {
                    strcat(temp,out_del);
                    strcat(temp,p);
                }
                i++;
            }
            // cautare in continuare pentru cuvant nou
            p=strtok(NULL, del);
        }
        //realocare spatiu pentru sirul nou si copiere
        (*lista_siruri)[j]= realloc((*lista_siruri)[j], (strlen(temp)+1)*sizeof(char));
        strcpy((*lista_siruri)[j], temp);
    }
}

int main()
{
    //n=numarul de cuvinte din sirul de iesire
    //v= vectorul de pozitii ale cuvintelor pentru sirul de iesire
    int n, m, i, *v;
    // del=delimitatori
    // out_del = delitatori pentru iesire
    // lista_siruri - lista cu sirurile primite respectiv sirurile prelucrate
    char *del=NULL, *out_del=NULL, **lista_siruri=NULL;
    // citire date
    read_sir(&del, &n, &v, &out_del, &m, &lista_siruri);
    //sortare vector
    vsort(v,&n);
    // prelucrare siruri
    cut(del, n, v, out_del, &m, &lista_siruri);
    // afisare siruri prelucrate
    for(i=0; i<m; i++)
    {
        printf("%s\n", lista_siruri[i]);
    }
    // eliberare memorie
    free(del);
    free(out_del);
    for(i=0;i<m;i++)
    {
        if(lista_siruri[i])
        {
            free(lista_siruri[i]);
        }
    }
    if(lista_siruri)
    {
        free(lista_siruri);
    }

    free(v);
    return 0;
}

