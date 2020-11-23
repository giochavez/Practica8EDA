#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

typedef struct {
    char nombre[100];
    int vida;
    int ataque;
} Heroe;
void leer(Heroe *h);
void imprime(Heroe *h);


#endif // HEROE_H_INCLUDED
