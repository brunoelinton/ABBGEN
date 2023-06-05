#include "cliente.h"

int main()
{

    No *T = NULL;
    T = insere_elemento(T, 40);
    T = insere_elemento(T, 35);
    T = insere_elemento(T, 25);
    T = insere_elemento(T, 39);
    T = insere_elemento(T, 37);
    T = insere_elemento(T, 59);
    T = insere_elemento(T, 45);
    T = insere_elemento(T, 69);
    T = insere_elemento(T, 75);
    imprime(T);

    printf("\n\n");

    T = remove_elemento(T, 59);
    imprime(T);



    return 0;
}
