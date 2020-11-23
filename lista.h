#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "heroe.h"
#include "nodo.h"

struct lista {
    int tam;
    Nodo *inicio;
    Nodo *fin;
};

typedef struct lista Lista;

void iniciarLista(Lista *pLista,int tam);
int vacia(Lista *pLista);
void agregarNodoFinal(Lista *pLista,void *pInfo);
void agregarNodoInicio(Lista *pLista,void *pInfo);
void recorre(Lista *pLista, void (operacion) (Heroe *h) );
void recorreInverso(Lista *pLista, void (operacion) (Heroe *h) );
void *retiraNodoInicio(Lista *pLista);
void *retiraNodoFinal(Lista *pLista);
void *retirarElPrimerValor(Lista *pLista, char *eliminar, int (igualdad) (Heroe *h, char *eliminar));

void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) );
void *retirarNodoFinal(Lista *pLista,void *clave, int (igualdad) (void *d1,void *d2) );

int agregarNodoAntesDe(Lista *pLista,void *clave, void *antes, int (igualdad) (Heroe *h1,Heroe *h2));
int nombresIguales(Heroe *h1, Heroe* h2);
int igualdadHeroe(Heroe *h, char* s);
#endif // LISTA_H_INCLUDED
