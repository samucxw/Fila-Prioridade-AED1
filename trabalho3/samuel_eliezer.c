#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    // Passo 1: Inicializa a fila (tá vazia, ninguém na fila ainda)
    Fila* fila = inicializaFila();

    // Passo 2: Abre o arquivo com as idades
    FILE* arquivo = fopen("clientes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return 1; // Sai do programa se o arquivo não abrir
    }

    // Passo 3: Lê as idades e insere na fila
    printf("Adicionando clientes na fila:\n");
    printf("+-----------------------+\n");
    int idade;
    while (fscanf(arquivo, "%d", &idade) == 1) {
        printf("| Cliente com idade %3d |\n", idade);
        insereFila(fila, idade);
    }
    fclose(arquivo); // Fecha o arquivo, já lemos tudo
    printf("+-----------------------+\n\n");

    // Passo 4: Ordena a fila (prioridade pros mais velhos)
    printf("Ordenando a fila por prioridade (idosos primeiro)...\n\n");
    ordenaFila(fila);

    // Passo 5: Atende os clientes, removendo da fila um por um
    printf("Atendendo os clientes:\n");
    printf("+-------------------------+\n");
    while (fila->inicio) {
        int atendido = removeFila(fila);
        printf("| Atendido: %3d anos      |\n", atendido);
    }
    printf("+-------------------------+\n\n");

    // Passo 6: Limpa a memória
    liberaFila(fila);
    printf("Fila vazia! Memoria liberada. Tudo limpo e organizado.\n");

    return 0;
}