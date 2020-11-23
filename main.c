#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "heroe.h"

int main(){
    Heroe unHeroe;
    Heroe otroHeroe;
    Lista misHeroes;
    char HAE;
    iniciarLista(&misHeroes,sizeof(Heroe));

    leer(&unHeroe);
    agregarNodoInicio(&misHeroes,&unHeroe);
    printf("\n");
    leer(&unHeroe);
    agregarNodoInicio(&misHeroes,&unHeroe);
    printf("\n");
    leer(&unHeroe);
    agregarNodoInicio(&misHeroes,&unHeroe);
    printf("\n");
    printf("-> Aqu%c debe ser sanzon:\n", 161);
    leer(&unHeroe); /**** <- sanzon ****/
    agregarNodoFinal(&misHeroes,&unHeroe);
    recorre(&misHeroes,imprime);

  /**** 1o. ****/
  strcpy(otroHeroe.nombre, "sanzon");
  printf("\n\tParte 2:\n\n");
  printf("Ingresa h%croe que estar%c antes de sanzon:\n", 130, 160);
  leer(&unHeroe);
  agregarNodoAntesDe(&misHeroes,&unHeroe, &otroHeroe, nombresIguales);
  printf("\n\n");
  recorreInverso(&misHeroes, imprime);

    printf("\n\n\tParte 3:\n\n");
    printf("%cQu%c h%croe quieres eliminar? ", 168, 130, 130);
    scanf("%s", &HAE);
    retirarElPrimerValor(&misHeroes, &HAE, igualdadHeroe);
    recorre(&misHeroes, imprime);

    return 0;
}

