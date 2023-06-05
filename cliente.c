#include "cliente.h"

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE CRIA UM ELEMENTO PARA A ABBGEN << */
Elemento *cria_elemento(int ch){
    Elemento *novoElemento = (Elemento *)calloc(1, sizeof(novoElemento));
    if(!novoElemento){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novoElemento->chave = ch;
    return novoElemento;
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE INSERE UM NÓ NA ABBGEN << */
No *insere_elemento(No *T, int ch){
    Elemento *novoElemento = cria_elemento(ch);
    return insereNo(T, novoElemento, compara);
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO DE COMPARAÇÃO << */
int compara(void *p1, void *p2){
    Elemento *E1 = (Elemento *)p1;
    Elemento *E2 = (Elemento *)p2;
    if(E1->chave == E2->chave){
        return 0;
    }else if(E1->chave > E2->chave){
        return 1;
    }else{
        return -1;
    }
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE ACESSA O ELEMENTO DA ABBGEN << */
void acessa_elemento(void *p1){
    Elemento *E1 = (Elemento *)p1;
    printf("%d\n", E1->chave);
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO IMPRIME OS ELEMENTOS << */
void imprime(No *T){
    imprimeArvore(T, 4, acessa_elemento);
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE PEGA O ELEMENTO DA ABBGEN << */
int pega_elemento(void *p1){
    Elemento *E1 = (Elemento *)p1;
    return E1->chave;
}



/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE REMOVE UM ELEMENTO DA ABBGEN << */
No *remove_elemento(No *T, int ch){
    Elemento *novoElemento = cria_elemento(ch);
    return removeNo(T, novoElemento, compara);
}
