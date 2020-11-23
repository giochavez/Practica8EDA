#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "articulos.h"



struct nodo {
    void *informacion;
    struct nodo *siguiente;
    struct nodo  *anterior;
};

typedef struct nodo Nodo;

Nodo *crearNodo(int tam, void *dirInfo);

#endif // NODO_H_INCLUDED
