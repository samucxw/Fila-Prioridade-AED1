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
    if (fila->tamanho < 2) return; // Nada pra ordenar se houver 0 ou 1 elemento

    int trocou;
    do {
        trocou = 0; // Assume que a lista está ordenada
        No* p1 = fila->inicio; // Ponteiro inicial para percorrer a lista

        while (p1 && p1->prox) { // Enquanto houver nós para comparar
            No* p2 = p1->prox; // Ponteiro para o próximo nó

            if (p1->idade < p2->idade) { // Se precisar trocar...
                // Ajustar os ponteiros para trocar os nós p1 e p2
                if (p1->ant) p1->ant->prox = p2;
                else fila->inicio = p2; // Atualiza o início da fila se necessário

                if (p2->prox) p2->prox->ant = p1;
                else fila->fim = p1; // Atualiza o fim da fila se necessário

                // Troca os ponteiros de p1 e p2
                p1->prox = p2->prox;
                p2->ant = p1->ant;
                p2->prox = p1;
                p1->ant = p2;

                trocou = 1; // Marca que houve troca
            }

            p1 = p2; // Avança para o próximo par
        }
    } while (trocou); // Continua enquanto houver trocas
}

// Libera a memória da fila
void liberaFila(Fila* fila) {
    while (fila->inicio) { // Remove todos os elementos
        removeFila(fila);
    }
    free(fila); // Libera a estrutura da fila
}
