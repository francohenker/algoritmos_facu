#include<stdio.h>
#include<stdlib.h>
#include"tda_pila.h"
#define MAX_SIZE 100

void carga(tipoPila *pila){
    int n;
    printf("Cuantos elementos queres ingresar?: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(pila, num);
    }
}

void Par(tipoPila pila, tipoPila *pila2){
    tipoPila aux = pila;
    if (esVacia(aux)) {
        printf("Esta vacia la pila.\n");
    }
    else{
        int arrayaux[MAX_SIZE], i = 0;
        while(!esVacia(aux)){      
            arrayaux[i] = aux->info;
            aux = aux->sig;
            i++;
        }
        for(int m = 0; m < i; m++){
            int n = arrayaux[m]%2;
            if(n == 0){
                apilar(pila2, arrayaux[m]);
            }
        }

    }
}

int main(){
    tipoPila pila1, pilaPares;
    crear(&pila1);
    crear(&pilaPares);
    pila1 = NULL;
    pilaPares = NULL;
    carga(&pila1);
    Par(pila1, &pilaPares);
    printf("Pila normal:\n");
    while(pila1 != NULL){
        printf("%d\n", pila1->info);
        pila1 = pila1->sig;
    }
    printf("Pila pares:\n");
        while(pilaPares != NULL){
        printf("%d\n", pilaPares->info);
        pilaPares = pilaPares->sig;
    }
    return 0;
}