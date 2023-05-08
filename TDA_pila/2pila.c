#include<stdio.h>
#include<stdlib.h>
#include"tda_pila.h"
#define MAX_SIZE 100

void copiarPila(tipoPila pila1, tipoPila *pila2){
    tipoPila aux = pila1;
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
        for(i = i -1; i >= 0; i--){
            apilar(pila2, arrayaux[i]);
        }

    }
}

int main(){
    tipoPila pila1, pila2;
    crear(&pila1);
    crear(&pila2);
    pila2 = NULL;
    pila1 = NULL;
    int n;
    printf("Cuantos elementos queres apilar?: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&pila1, num);  
    }
    copiarPila(pila1, &pila2);
    printf("Primer pila:\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", pila1->info);
        pila1 = pila1->sig;
    }
    printf("Segunda pila:\n");
        for(int i = 0; i < n; i++){
        printf("%d\n", pila2->info);
        pila2 = pila2->sig;
    }
    return 0;
}