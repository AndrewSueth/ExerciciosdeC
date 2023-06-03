struct NodePILHA{
    int item;
    struct NodePILHA *prox;
};
typedef struct NodePILHA nodepilha;

int vazia(nodepilha *PILHA){
    if(PILHA -> prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

nodepilha* Empilhar(nodepilha *PILHA, int tam){
    nodepilha *novo=(nodepilha*) malloc(sizeof(nodepilha));
    novo->prox = NULL;
    
    printf("Novo Item: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA))
        PILHA -> prox = novo;
    else{
        nodepilha* tmp = PILHA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
    return novo;
}


void DESEMPILHAR(nodepilha *PILHA, int tam){
    if(PILHA->prox ==NULL){
        printf("PILHA ja vazia\n\n");
        return;
    }else{
         nodepilha *ultimo = PILHA->prox;
        nodepilha *penultimo = NULL;
        while (ultimo->prox != NULL) {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        tam--;
        
       
    } 
     printf("\n Desempilhado com Sucesso!\n");
    }


void IMPRIMIR(nodepilha *PILHA, int tam){
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
    return;
    }
    nodepilha *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA:");
    while(tmp != NULL){
        printf("%3d", tmp->item);
        tmp = tmp-> prox;
        tam++;
        }
    printf("\nQtde itens PILHA: %d", tam);
    printf("\n");
}

void LimparPilha(nodepilha *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA já está vazia!\n\n");
        return;
    }

    nodepilha *tmp = PILHA->prox;
    while (tmp != NULL) {
        nodepilha *proximo = tmp->prox;
        free(tmp);
        tmp = proximo;
        
    }

    PILHA->prox = NULL;

    printf("PILHA limpa com sucesso!\n");
}

void imprimirTopo(nodepilha *PILHA) {
    if (vazia(PILHA)) {
        printf("PILHA vazia!\n");
        return;
    }
    
    nodepilha *tmp = PILHA->prox;
    while (tmp->prox != NULL) {
        tmp = tmp->prox;
    }
    
    printf("O Topo da PILHA: %d\n", tmp->item);
}


