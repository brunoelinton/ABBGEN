#ifndef ABBGEN_H
#define ABBGEN_H

// INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÃO DA ESTRUTURA QUE REPRESENTA UM NÓ GENÉRICO DA ABBGEN
typedef struct no{
    void *info;
    struct no *esq;
    struct no *dir;
}No;

/*
--------------------------------------------------------------------------------------------------------------------
                                                >> DEFINIÇÃO DAS FUNÇÕES <<
--------------------------------------------------------------------------------------------------------------------
*/

/* >> DEFINIÇÃO DA FUNÇÃO QUE CRIA UM NÓ PARA A ABBGEN << */
No *criaNo(void *v);

/* >> DEFINIÇÃO DA FUNÇÃO QUE INSERE UM NÓ NA ABBGEN << */
No *insereNo(No *T, void *v, int (*compara) (void *p1, void *p2));

/* >> DEFINIÇÃO DA FUNÇÃO QUE BUSCA UMA CHAVE NA ÁRVORE << */
No *busca(No *T, No **pai, int (*compara) (void *, void *), void *novoNo);

/* >> DEFINIÇÃO DA FUNÇÃO QUE IMPRIME A ÁRVORE << */
void imprimeArvore(No *T, int nivel, void (*acessa_elemento) (void *));

/* >> DEFINIÇÃO DA FUNÇÃO QUE BUSCA O SUCESSOR DE UM NÓ NA ABBGEN << */
No *sucessor(No *P, No **paiP);

/* >> DEFINIÇÃO DA FUNÇÃO QUE REMOVE UM NÓ DA ABBGEN << */
No *removeNo(No *T, void *novoNo, int (*compara) (void *p1, void *p2));

#endif // ABBGEN_H
