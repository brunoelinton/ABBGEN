#ifndef CLIENTE_H
#define CLIENTE_H

// INCLUINDO O PACOTE QUE IMPLEMENTA A ABBGEN
#include "abbgen.h"

// DEFINIÇÃO DA ESTRUTURA QUE REPRESENTA UM ELEMENTO DO CONJUNTO
typedef struct elemento{
    int chave;
}Elemento;

/*
--------------------------------------------------------------------------------------------------------------------
                                                >> DEFINIÇÃO DAS FUNÇÕES <<
--------------------------------------------------------------------------------------------------------------------
*/

/* >> DEFINIÇÃO DA FUNÇÃO QUE CRIA UM ELEMENTO PARA A ABBGEN << */
Elemento *cria_elemento(int ch);

/* >> DEFINIÇÃO DA FUNÇÃO QUE INSERE UM ELEMENTO NA ABBGEN << */
No *insere_elemento(No *T, int ch);

/* >> DEFINIÇÃO DA FUNÇÃO QUE COMPARA DOIS ELEMENTOS DA ABBGEN << */
int compara(void *p1, void *p2);

/* >> DEFINIÇÃO DA FUNÇÃO QUE IMPRIME OS ELEMENTOS DA ABBGEN << */
void imprime(No *T);

/* >> DEFINIÇÃO DA FUNÇÃO QUE ACESSA O ELEMENTO DA ABBGEN << */
void acessa_elemento(void *p1);

/* >> DEFINIÇÃO DA FUNÇÃO QUE PEGA UM ELEMENTO DA ABBGEN << */
int pega_elemento(void *p1);

/* >> DEFINIÇÃO DA FUNÇÃO QUE REMOVE UM ELEMENTO DA ABBGEN << */
No *remove_elemento(No *T, int ch);

#endif // CLIENTE_H
