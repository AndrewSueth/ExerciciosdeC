struct Node {
    int conteudo;
    struct Node *prox;
};

typedef struct Node node;

int EMPTY(node *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

node* ENQUEUE(node *FILA, int tam) {
    node *novo = (node*) malloc(sizeof(node));
    novo->prox = NULL;
    printf("Novo Item da fila: ");
    scanf("%d", &novo->conteudo);

     if (EMPTY(FILA)) {
        FILA->prox = novo;
    } else {
        node *tmp = FILA->prox;
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
    return novo;
}
void DEQUEUE(node *FILA, int tam) {
    if (FILA->prox == NULL) {
        printf("Fila está vazia\n");
        return;
    } else {
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
    printf("\nDesenfileira com Sucesso!\n");
}

void IMPRIME(node *FILA, int tam) {
    node *tmp = FILA->prox;
    printf("Fila: ");
    while (tmp != NULL) {
        printf("%d ", tmp->conteudo);
        tmp = tmp->prox;
        tam++;
    }
    printf("\nTamanho da fila é de : %d",tam);
    printf("\n\n");
}

void LimparFila(node *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila já está vazia!\n\n");
        return;
    }

    node *tmp = FILA->prox;
    while (tmp != NULL) {
        node *proximo = tmp->prox;
        free(tmp);
        tmp = proximo;
    }

    FILA->prox = NULL;

    printf("Fila limpa com sucesso!\n");
}

void imprimirMaiorElemento(node *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila vazia!\n");
        return;
    }
    
    int maior = FILA->prox->conteudo;  
    node *tmp = FILA->prox;
    
    while (tmp != NULL) {
        if (tmp->conteudo > maior) {
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    
    printf("Maior elemento da fila: %d\n", maior);
}

void imprimirMenorElemento(node *FILA) {
    if (EMPTY(FILA)) {
        printf("Fila vazia!\n");
        return;
    }
    
    int menor = FILA->prox->conteudo;  
    node *tmp = FILA->prox;
    
    while (tmp != NULL) {
        if (tmp->conteudo < menor) {
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    
    printf("Menor elemento da fila: %d\n", menor);
}


