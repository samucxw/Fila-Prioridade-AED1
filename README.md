# Fila Virtual Prioritária

Este projeto implementa um sistema de **Fila Virtual Prioritária** em C, desenvolvido como parte do **Trabalho Prático 3** da disciplina de **Algoritmos e Estruturas de Dados 1 (AED1)**, ministrada pelo professor **Juan Collona**.  
A fila utiliza uma **lista duplamente encadeada** para gerenciar os clientes, priorizando idosos automaticamente após a inserção, com uma abordagem eficiente de manipulação de ponteiros.

---

## 🚀 **Funcionalidades**

- **Inserção de Clientes**  
  Adiciona um novo cliente ao final da fila seguindo o conceito FIFO.  

- **Prioridade por Idade**  
  Reorganiza automaticamente a fila para colocar os clientes mais velhos no início, manipulando diretamente os ponteiros da lista.  

- **Atendimento**  
  Remove o cliente mais prioritário da fila e exibe sua idade no terminal.  

---

## 📂 **Estrutura do Projeto**

- **`fila.h`**: Declaração das funções e estruturas de dados utilizadas na fila.  
- **`fila.c`**: Implementação das funções da TAD, incluindo a manipulação dinâmica de ponteiros.  
- **`main.c`**: Arquivo principal que simula o sistema de atendimento.  

---

## 🛠 **Como Executar**

### 1. Compilação:
Certifique-se de ter um compilador C instalado. Use o comando:  
```bash
gcc main.c fila.c -o fila_virtual
