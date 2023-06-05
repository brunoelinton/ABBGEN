#include "abbgen.h"

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE CRIA UM NÓ PARA A ABBGEN << */
No *criaNo(void *v){
    No *novoNo = (No *)calloc(1, sizeof(No));
    if(!novoNo){
        printf("ERRO. NAO FOI POSSIVEL ALOCAR UM NOVO NO!\n");
        exit(1);
    }
    novoNo->info = v;
    return novoNo;
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE BUSCA UMA CHAVE NA ABBGEN << */
No *busca(No *T, No **pai, int (*compara) (void *, void *), void *novoNo){
    if(!T) return NULL;
    if(compara(T->info, novoNo) == 0) return T;
    (*pai) = T;
    if(compara(T->info, novoNo) == 1){
            //printf("Maior\n");
        return busca(T->esq, pai, compara, novoNo);
    }else{
        //printf("Menor\n");
        return busca(T->dir, pai, compara, novoNo);
    }
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE INSERE UM NÓ NA ABBGEN << */
No *insereNo(No *T, void *v, int (*compara) (void *p1, void *p2)){
    No *novoNo = criaNo(v);
    No *pai = NULL;
    No *aux = busca(T, &pai, compara, novoNo->info); // VERIFICA SE O ELEMENTO JA EXISTE NA ABBGEN
    if(!aux) {  // CHAVE NAO EXISTE NA ARVORE
        if(!pai){   // ÁRVORE VAZIA (NÃO POSSUI CHAVES/NOS)
            T = novoNo;
        }else{  // A ÁRVORE NÃO É VAZIA E PODE SER INSERIDA
            if(compara(pai->info, novoNo->info) == 1)
                pai->esq = novoNo;
            else
                pai->dir = novoNo;
        }
    }else{  // CHAVE JÁ EXISTE NA ÁRVORE
        printf("Chave ja existente!\n");
    }
    return T;
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE IMPRIME A ÁRVORE << */
void imprimeArvore(No *T, int nivel, void (*acessa_elemento) (void *)){
    int i = 0;
    if(T){
        imprimeArvore(T->dir, nivel+1, acessa_elemento);
        for(i = 0; i < nivel; i++)
            printf("\t");
        acessa_elemento(T->info);
        imprimeArvore(T->esq, nivel+1, acessa_elemento);
    }
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE BUSCA O SUCESSOR DE UM NÓ NA ABBGEN << */
No *sucessor(No *P, No **paiP){
    if(P){ //   CHAVE ENCONTRADA, INICIA-SE A BUSCA PELO SEU SUCESSOR NA ÁRVORE
        (*paiP) = P;    // E O PAI É ATUALIZADO
        P = P->dir; // DESCE UMA VEZ À DIREITA
        if(P){  // A SUBÁRVORE À DIREITA EXISTE
            while(P->esq){ // DESCE AO MÁXIMO A SUBÁRVORE À ESQUERDA
                (*paiP) = P;    // O PAI É ATUALIZADO
                P = P->esq;     // CONTINUA A DESCIDA
            }
        }
    }
    return P;
}

/* >> IMPLEMENTAÇÃO DA FUNÇÃO QUE REMOVE UM NÓ DA ABBGEN << */
No *removeNo(No *T, void *v, int (*compara) (void *p1, void *p2)){
    No *novoNo = criaNo(v);
    No *paiProc = NULL;
    No *proc = busca(T, &paiProc, compara, novoNo->info);  // INICIA A BUSCA
    if(proc){   // A CHAVE PROCURADA EXISTE -> INICIA-SE O PROCESSO DE REMOÇÃO
        No *paiSuc = NULL;
        No *suc = sucessor(proc, &paiSuc);  // INICIA A BUSCA PELO SUCESSOR
        if(suc){    // O SUCESSOR EXISTE
            proc->info = suc->info;   // TROCAMOS A CHAVE A SER EXCLUIDA PELA CHAVE DO SUCESSOR
            if(suc == paiSuc->esq)
                paiSuc->esq = suc->dir;
            else
                paiSuc->dir = suc->dir;
            free(suc);  // LIBERA O NÓ PARA EXCLUSÃO
        }else{  // NÃO EXISTE SUCESSOR
            if(paiProc){    // O ELEMENTO A SER REMOVIDO NÃO É RAIZ DA ÁRVORE
                if(proc == paiProc->esq)
                    paiProc->esq = proc->esq;
                else
                    paiProc->dir = proc->esq;
            }else{  // O ELEMENTO A SER REMOVIDO É A RAIZ E NÃO HÁ CHAVE MAIOR DO QUE ELE ENTÃO
                T = proc->esq;
            }
            free(proc);
        }
    }
    return T;
}
