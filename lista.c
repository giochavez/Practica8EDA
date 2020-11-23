#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void iniciarLista(Lista *pLista, int tam) {
    pLista->tam = tam;
    pLista->inicio = NULL;
    pLista->fin = NULL;
}

int vacia(Lista *pLista) {
    if (pLista->inicio == NULL) {
        return 1;
    }
    return 0;
}

void agregarNodoFinal(Lista *pLista,void *pInfo) {
     Nodo *pNodo;

     pNodo = crearNodo(pLista->tam,pInfo);
     if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
     }
     pLista->fin->siguiente = pNodo;
     pNodo->anterior = pLista->fin;
     pLista->fin = pNodo;
}

void agregarNodoInicio(Lista *pLista,void *pInfo) {
    Nodo *pNodo;
    pNodo = crearNodo(pLista->tam,pInfo);
    if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
    }
    pNodo->siguiente = pLista->inicio;
    pLista->inicio->anterior = pNodo;
    pLista->inicio = pNodo;

}

void recorre(Lista *pLista, void (operacion) (Heroe *h) ) {
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vacia!\n");
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }

}

void recorreInverso(Lista *pLista, void (operacion) (Heroe *h) ) {
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vacia!\n");
        return;
    }
    pNodo = pLista->fin;
    while (pNodo != NULL) {
        operacion(pNodo->informacion);
        pNodo = pNodo->anterior;
    }

}

void *retiraNodoInicio(Lista *pLista) {
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    res = pLista->inicio->informacion;
    q = pLista->inicio;
    pLista->inicio = q->siguiente;
    pLista->inicio->anterior = NULL;
    q->siguiente = NULL;
    free(q); q=NULL;
    return res;
}

void *retiraNodoFinal(Lista *pLista) {
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    res = pLista->fin->informacion;
    q = pLista->fin;
    pLista->fin->anterior->siguiente = NULL;
    pLista->fin = q->anterior;
    free(q);
    q->siguiente = NULL;
    return res;
}

void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) ){
    Nodo *pNodo;

    pNodo = pLista->inicio;
    while (pNodo!=NULL) {
        if (igualdad(valor,pNodo->informacion)==1)
            return pNodo->informacion;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}

void *retirarElPrimerValor(Lista *pLista, char *eliminar,  int (igualdad) (Heroe *h, char *eliminar)) {
    Nodo *pNodo;
    Nodo *pAnterior;
    void *res;
    if (vacia(pLista))
        return NULL;
    if (igualdad(pLista->inicio->informacion,eliminar))
        return retiraNodoInicio(pLista);
    if (igualdad(pLista->fin->informacion,eliminar))
        return retiraNodoFinal(pLista);

    pAnterior = pLista->inicio;
    pNodo = pLista->inicio->siguiente;

    while (pNodo != pLista->fin) {
        if (igualdad(pNodo->informacion,eliminar)==1) {
            pAnterior->siguiente = pNodo->siguiente; //pAnterior en su propiedad siguiente apunta al nodo siguiente a pNodo
            pAnterior->siguiente->anterior = pAnterior; //El nodo siguiente que apuntaba en su propiedad anterior a pNodo ahora apunta a pAnterior.
            res = pNodo->informacion;
            free(pNodo);
            return res;
        }
        pAnterior = pNodo;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}

int agregarNodoAntesDe(Lista *pLista,void *clave, void *antes, int (igualdad) (Heroe *h1, Heroe *h2)) {
    Nodo *pNodo, *qNodo;
    if (vacia(pLista)) {
        return 0;
    }
    pNodo = pLista->inicio;
    if (igualdad(pNodo->informacion,antes)==1) {
        agregarNodoInicio(pLista,clave);
        return 1;
    }
    while (pNodo != pLista->fin) {
        if (igualdad(antes, pNodo->siguiente->informacion)==1) {
            qNodo = crearNodo(pLista->tam,clave);
            qNodo->siguiente = pNodo->siguiente;
            pNodo->siguiente = qNodo;
            qNodo->anterior = pNodo;
            qNodo->siguiente->anterior = qNodo;
            return 1;
        }
        pNodo = pNodo->siguiente;
    }
    return 0;
}
int nombresIguales(Heroe *h1, Heroe* h2){
    if (strcmp(h1->nombre, h2->nombre)==0)
        return 1;
    return 0;
}
int igualdadHeroe(Heroe *h, char* s){ //Recibimos el nombre a comparar y los nombres de los heroes
    if (strcmp(s, h->nombre)==0) //Comparamos los nombres, letra por letra y si son iguales retornamos 1
        return 1;
    return 0; //si no son iguales retornamos 0
}





