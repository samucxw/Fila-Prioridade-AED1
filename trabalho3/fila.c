#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Inicializa uma fila vazia
Fila* inicializaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila)); // Reserva memória pra estrutura
    fila->inicio = NULL; // Começo vazio
    fila->fim = NULL;    // Fim vazio
    fila->tamanho = 0;   // Tamanho inicial é zero (ninguém na fila ainda)
    return fila;         // Tá pronto, devolve a fila vazia
}

// Insere um novo cliente no final da fila
void insereFila(Fila* fila, int idade) {
    No* novo = (No*)malloc(sizeof(No)); // Cria um nó pra guardar a idade do cliente
    novo->idade = idade;   // Salva a idade do cliente no nó
    novo->prox = NULL;     // O próximo do novo nó é NULL (ele tá no final da fila)
    novo->ant = fila->fim; // O anterior é o nó que já estava no final da fila

    if (fila->fim) {
        fila->fim->prox = novo; // Conecta o último nó atual ao novo nó
    } else {
        fila->inicio = novo; // Se a fila tava vazia, o novo nó é o primeiro também
    }

    fila->fim = novo; // Atualiza o fim da fila pro novo nó
    fila->tamanho++;  // Aumenta o tamanho da fila
}

// Remove o primeiro cliente da fila
int removeFila(Fila* fila) {
    if (fila->inicio == NULL) { // Verifica se a fila tá vazia
        printf("Fila vazia! Não tem ninguém pra atender.\n");
        return -1;
    }

    No* removido = fila->inicio; // Pega o primeiro nó da fila
    int idade = removido->idade; // Salva a idade do cliente que vai sair
    fila->inicio = removido->prox; // O segundo nó vira o novo início

    if (fila->inicio) {
        fila->inicio->ant = NULL; // Remove a referência ao nó antigo
    } else {
        fila->fim = NULL; // Se a fila ficou vazia, ajusta o fim também
    }

    free(removido); // Libera a memória do nó removido
    fila->tamanho--; // Diminui o tamanho da fila
    return idade; // Devolve a idade do cliente atendido
}

// Ordena a fila em ordem decrescente (maior para menor)
void ordenaFila(Fila* fila) {
    if (fila->tamanho < 2) return; // Nada pra ordenar se tiver 0 ou 1 elemento

    int trocou; // Marca se houve troca
    do {
        trocou = 0; // Começa assumindo que tá tudo em ordem
        No* atual = fila->inicio;

        while (atual && atual->prox) { // Percorre a lista até o penúltimo nó
            if (atual->idade < atual->prox->idade) { // Se o próximo for maior...
                // Troca as idades (quem é maior passa pra frente)
                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                trocou = 1; // Marca que teve troca
            }
            atual = atual->prox; // Passa pro próximo nó
        }
    } while (trocou); // Repete enquanto houver troca
}

// Libera a memória da fila
void liberaFila(Fila* fila) {
    while (fila->inicio) { // Remove todos os elementos
        removeFila(fila);
    }
    free(fila); // Libera a estrutura da fila
}
