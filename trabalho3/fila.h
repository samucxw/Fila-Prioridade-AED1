#ifndef FILA_H
#define FILA_H

// Estrutura do nó da lista duplamente encadeada
typedef struct No {
    int idade;           // Idade do cliente (a gente tá focado nos idosos aqui)
    struct No* prox;     // Ponteiro pro próximo nó (ou seja, quem tá atrás dele na fila)
    struct No* ant;      // Ponteiro pro nó anterior (quem tá na frente na fila)
} No;

// Estrutura da fila
typedef struct Fila {
    No* inicio;          // Onde começa a fila (primeiro cliente a ser atendido)
    No* fim;             // Onde termina a fila (último cliente a chegar)
    int tamanho;         // Contador de quantas pessoas estão na fila
} Fila;

// Inicializa a fila vazia (cria a estrutura e deixa tudo zerado)
Fila* inicializaFila();

// Insere uma idade no final da fila
// Exemplo: fila cheia, cliente idoso entra no final (lado direito)
void insereFila(Fila* fila, int idade);

// Remove o cliente do início da fila (lado esquerdo)
// Exemplo: fila anda, o próximo cliente sai e é atendido
int removeFila(Fila* fila);

// Ordena a fila de maior pra menor usando bubble sort
// Exemplo: "Os mais velhos primeiro!" (prioridade pros idosos)
void ordenaFila(Fila* fila);

// Libera toda a memória alocada pela fila
// Exemplo: Fecha a loja, limpa o espaço, nada de memória vazando
void liberaFila(Fila* fila);

#endif
