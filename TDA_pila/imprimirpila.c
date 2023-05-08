
void imprimirPila(tipoPila P) {
    while (!esVacia(P)) {
        printf("[%d]\n", P->info);
        P = P->sig;
    }
}