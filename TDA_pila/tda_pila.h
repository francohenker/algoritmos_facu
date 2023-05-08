#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int info;
    struct nodo *sig;
};
typedef struct nodo *tipoPila;

bool esVacia(tipoPila P){
    if (P == NULL){
        return (true);
    }
    else {
        return (false);
    }
}

int crear(tipoPila *nuevaP){
    *nuevaP = malloc(sizeof(struct nodo));
    if (esVacia(*nuevaP)) {
        printf("Error: no se pudo asignar memoria\n"); //Verifica que se haya asignado correctamente la memoria antes de utilizarla.
        exit(1);
    }
}
void apilar(tipoPila *P, int x) {
    tipoPila nuevoNodo;
    crear(&nuevoNodo);
    nuevoNodo->info = x;
    nuevoNodo->sig = *P;
    *P = nuevoNodo;
}

void desapilar(tipoPila *p, int *x){
    if (esVacia(*p)){
        printf("Esta vacia \n");
    }
    else{
        tipoPila temp = *p;
        *x = (*p)->info;
        *p = (*p)->sig;
        free(temp);

    }
}