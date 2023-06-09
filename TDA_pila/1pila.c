#include<stdio.h>
#include<stdlib.h>
#include"tda_pila.h"

void impInver(tipoPila Pila){
    if (esVacia(Pila)) {
        printf("La pila está vacia \n");
    }
    else{
        tipoPila pilaaux, aux;  //pilaaux es la pila invertida y aux es de donde sacamos los valores de la pila original 
        crear(&pilaaux);
        pilaaux = NULL;
        crear(&aux);
        aux = Pila;
        int i = 0;
        int arrayaux[50];        
        while(!esVacia(aux)){      
            arrayaux[i] = aux->info;
            aux = aux->sig;
            i++;
        }
        for(int m = 0; m < i; m++){        // de esta forma se carga la pila invertida a la original, empezando desde el final del array
            apilar(&pilaaux, arrayaux[m]);
        }
        printf("Pila Invertida:\n");
        while (!esVacia(pilaaux)) {     // imprime la nueva pila
            printf("[%d]\n", pilaaux->info);
            pilaaux = pilaaux->sig;
        }
    }
}

int main(){
    tipoPila pila;
    int n;
    crear(&pila);
    pila = NULL;
    printf("Cuantos elementos queres apilar?: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&pila, num);  
    }
    impInver(pila);
    printf("Pila Normal:\n");
    for(int i = 0; i < n; i++){
        printf("[%d]\n", pila->info);
        pila = pila->sig;
    }



    return 0;
}