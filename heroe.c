#include <stdio.h>
#include "heroe.h"

void leer(Heroe *h) {
    printf("Nombre? ");
    scanf("%s",h->nombre);
    printf("Vida? ");
    scanf("%d",&(h->vida));
    printf("Ataque? ");
    scanf("%d",&(h->ataque));
}

void imprime(Heroe *h) {
    printf("------------------\n");
    printf("Nombre: %s\n",h->nombre);
    printf("Vida: %d\n",h->vida);
    printf("Ataque: %d\n",h->ataque);
}

