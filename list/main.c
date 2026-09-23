#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *elemek; // Mutató a dinamukus tömbre
    int meret; // Hány elem van benne.
    int kapacitas; // Hány elemnek van jelenleg lefoglalva hely
}Lista;


// Kezdőértékek megadása.
void lista_init(Lista *l)
{
    l->meret = 0;
    l->kapacitas = 2; // Kezdésnek 2 helyet foglal le.
    l->elemek = realloc(l->elemek, l->kapacitas * sizeof(int));
}

void lista_hozzaad(Lista *l, int ertek)
{
    // Ha megtelt megduplázzuk
    if (l->meret == l->kapacitas)
    {
        l->kapacitas *=2;
        l->elemek = realloc(l->elemek, l->kapacitas * sizeof(int));
    }

    l->elemek[l->meret] = ertek;
    l->meret++;
}

void lista_felszabadit(Lista *l)
{
    free(l->elemek);
    l->elemek = NULL;
    l->meret = 0;
    l->kapacitas = 0;
}

int main()
{
    Lista szamok;
    lista_init(&szamok); // Átadjuk a címét.

    // Bármennyi elemet hozzáadhatunk, automatikusan bővül a memória!
    lista_hozzaad(&szamok, 10);
    lista_hozzaad(&szamok, 25);
    lista_hozzaad(&szamok, 50);

    // Kiíratás
    printf("A lista elemei (%d db):\n", szamok.meret);
    for (int i = 0; i < szamok.meret; i++) {
        printf("%d. elem: %d\n", i + 1, szamok.elemek[i]);
    }
    
    // Használat után mindig fel kell szabadítani!
    lista_felszabadit(&szamok);
    
    


    return 0;
}