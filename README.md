# Fila Virtual Prioritária - AED1 2024

Este projeto implementa uma **fila virtual** para atendimento online em um banco, com o objetivo de oferecer **prioridade especial** para idosos. Ele foi desenvolvido como parte do **Trabalho Prático 3** do programa de estudos da disciplina **Algoritmos e Estruturas de Dados 1**, ministrada pelo **Professor Juan Collona**.
Uma lista duplamente encadeada foi utilizada para implementar a solução, juntamente com o bubble sort para organizar dinamicamente e de forma eficiente a fila.

---

## 🔧 **Funcionalidades**

- **Inserção de clientes na fila**  
  Os clientes são adicionados no final da fila, conforme o conceito FIFO.

- **Ordenação por prioridade**  
  Após a inserção, a fila é reorganizada, colocando os clientes mais velhos no início, com base em suas idades.

- **Atendimento sequencial**  
  Os clientes são atendidos (removidos) do início da fila, e suas idades são exibidas no terminal.

---

## 📁 **Estrutura do Código**

- **`fila.h`**  
  Declaração das funções da TAD (**Tipo Abstrato de Dados**).

- **`fila.c`**  
  Implementação das funções da TAD, como inserção, remoção e ordenação da fila.

- **`samuel_eliezer.c`**  
  Arquivo principal que utiliza a TAD para simular o sistema de atendimento.

---

## 🛠 **Tecnologias Usadas**

- **Linguagem:** C  
- **Algoritmo de ordenação:** Bubble Sort  
- **Estrutura de Dados:** Lista Duplamente Encadeada  

---

## 📚 **Como Executar**

1. Clone o repositório:  
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
