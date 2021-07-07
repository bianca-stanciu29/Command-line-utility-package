#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//citire date
void read_sir(char ***lista_siruri, int *n)
{
    int i;
    char ch;
    //citire numar siruri si caracter \n
    scanf("%d", n);
    scanf("%c", &ch);
    //alocare spatiu temporar pentru sirurile citite
    char* sir_temp = calloc(201,sizeof(char));
    //alocare memorie corespunzatoare pentru vector de pointeri catre siruri
    *lista_siruri = calloc(*n, sizeof(char*));
    for(i=0; i<*n; i++)
    {
        fgets(sir_temp, 200, stdin);
        //elimiare spatiu suplimentar
        if(sir_temp[strlen(sir_temp)-2]==' ')
            {
                sir_temp[strlen(sir_temp)-2]=sir_temp[strlen(sir_temp)-1];
                sir_temp[strlen(sir_temp)-1]=sir_temp[strlen(sir_temp)];
            }
        // alocare spatiu pentru sirul curent si copiere din sirul temporar
        (*lista_siruri)[i]=calloc(strlen(sir_temp)+1, sizeof(char));
        strcpy((*lista_siruri)[i],sir_temp);
    }
    //eliberare memorie sir temporar
    free(sir_temp);
}

//codificare siruri
void encrypt(char **lista_siruri, int n)
{
    int i,j, k, ok;
    char ch;
    //parcurgere siruri
    for(k=0; k<n; k++)
    {

        i=0;
        while(i<strlen(lista_siruri[k]))
        {
            //se plaseaza i la inceput de cuvant si j la sfarsit
            //se depasesc spatiile
            while(lista_siruri[k][i]==' ')
            {
                i++;
            }
            //j identifica sfarsitul cuvantului
            j=i;
            //ok verifica daca cuvantul e numar
            ok=1;
            while(lista_siruri[k][j] && lista_siruri[k][j]!='\n' &&
                  lista_siruri[k][j]!=' ')
            {
                if(lista_siruri[k][j]<'0' || lista_siruri[k][j]>'9')
                {
                    ok=0;
                }
                j++;
            }
            //daca e numar trece mai departe
            if(ok)
            {
                i=j;
            }
            // daca nu e numar se codifica
            else
            {
                //ch este primul caracter al cuvantului curent
                ch=lista_siruri[k][i];
                i++;
                while(i<j)
                {
                    //codificare
                    lista_siruri[k][i]=(lista_siruri[k][i]+ch)%256;
                    i++;
                }
            }
            //depasire sfarsit de linie
            if(lista_siruri[k][i]=='\n')
            {
                i++;
            }
        }
    }
}

int main()
{
    int n, i;
    char  **lista_siruri=NULL;
    //citire date
    read_sir(&lista_siruri, &n);
    //criptare date
    encrypt(lista_siruri,n);
    // afisare date
    for(i=0; i<n; i++)
    {
        printf("%s", lista_siruri[i]);
    }

    //eliberare memorie
    for(i=0;i<n;i++)
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
    return 0;
}
