#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tip inregistrare pentru materii

struct materie
{
    int nr_note;
    int *note;
    float media;
};
//citire date - situatie  student
void read_situatie(int *nr_materii, struct materie **materii)
{
    int k, i, nota;
    float s;
    //citire numar materii
    scanf("%d", nr_materii);
    //alocare dinamica lista de materii
    (*materii) = (struct materie *)malloc(*nr_materii * sizeof(struct materie));
    // citire note pentru fiecare materie
    for (i = 0; i < *nr_materii; i++)
    {
        k = 3;
        s = 0;
        (*materii)[i].nr_note = 0;
        // alocare spatiu de memorie pentru 3 note
        (*materii)[i].note = (int *)calloc(k, sizeof(int));
        do
        {
            scanf("%d", &nota);
            if (nota > 0)
            {
                //daca numarul de note excede spatiul alocat
                //se suplimenteaza cu 3 locatii
                if ((*materii)[i].nr_note + 1 > k)
                {
                    k += 3;
                    (*materii)[i].note = (int *)realloc((*materii)[i].note, k * sizeof(int));
                }
                //adaugare nota in lista de note
                (*materii)[i].note[(*materii)[i].nr_note] = nota;
                (*materii)[i].nr_note++;
                // calcul suma note
                s += nota;
            }

        } while (nota > 0);
        // calcul media generala pe materie
        (*materii)[i].media = s / (*materii)[i].nr_note;
    }
}

// sortare materii descrescator dupa medie
void sort_mat(struct materie *materii, int nr_materii)
{
    int i, j;
    struct materie aux;
    //algoritmul de sortare: bubble sort
    for (i = 0; i < nr_materii - 1; i++)

        for (j = 0; j < nr_materii - i - 1; j++)

            if (materii[j].media < materii[j + 1].media)
            {
                aux = materii[j];
                materii[j] = materii[j + 1];
                materii[j + 1] = aux;
            }
}

//afisare date
void print_mat(struct materie *materii, int nr_materii)
{
    int i, j;
    for (i = 0; i < nr_materii; i++)
    {
        //afisarea cu 3 zecimale exacte, pe 10 spatii
        printf("%-10.3f%d", materii[i].media, materii[i].note[0]);
        for (j = 1; j < materii[i].nr_note; j++)
        {
            printf(" %d", materii[i].note[j]);
        }
        printf("\n");
    }
}

int main()
{
    //nr_materii numarul de materii
    int i, nr_materii;
    // materii = vector de materii (struct materie)
    struct materie *materii;
    // citire date
    read_situatie(&nr_materii, &materii);

    // sortare descrescator dupa media generala pe materie
    sort_mat(materii, nr_materii);

    //afisare materii ordonate descrescator
    print_mat(materii, nr_materii);

    // eliberare memorie
    for (i = 0; i < nr_materii; i++)
    {
        free(materii[i].note);
    }
    free(materii);
    return 0;
}
