C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> // Para a função usleep

#define MAX_PALAVRAS 1000
#define MAX_COMPRIMENTO 50

// ... (Outras funções e variáveis globais)

// Estrutura para representar um nível
typedef struct {
    int velocidade; // Em milissegundos
    int comprimento_min;
    int caracteres_especiais;
} Nivel;

// Estrutura para representar uma palavra
typedef struct {
    char texto[MAX_COMPRIMENTO];
    int nivel;
} Palavra;

// Função para ler o banco de dados de um arquivo
void ler_banco_dados(Palavra *palavras, int *num_palavras, const char *nome_arquivo) {
    // ... (Implementar a lógica para ler o arquivo e preencher o array de palavras)
}

// Função para escolher uma palavra aleatória de acordo com o nível
void escolher_palavra(char *palavra, Palavra *palavras, int num_palavras, int nivel) {
    // Encontrar o índice da primeira palavra do nível atual
    int inicio_nivel = 0;
    for (int i = 0; i < num_palavras; i++) {
        if (palavras[i].nivel == nivel) {
            inicio_nivel = i;
            break;
        }
    }

    // Encontrar o índice da última palavra do nível atual
    int fim_nivel = inicio_nivel;
    while (fim_nivel < num_palavras && palavras[fim_nivel].nivel == nivel) {
        fim_nivel++;
    }

    // Escolher uma palavra aleatória dentro do intervalo do nível
    int indice_aleatorio = inicio_nivel + rand() % (fim_nivel - inicio_nivel);
    strcpy(palavra, palavras[indice_aleatorio].texto);

    escolher_palavra(palavra_atual, palavras, num_palavras, nivel);
}

void inserir_caracteres_especiais(char *palavra, char *caracteres_especiais, int num_caracteres) {
    int tamanho_palavra = strlen(palavra);
    for (int i = 0; i < num_caracteres; i++) {
        int posicao = rand() % tamanho_palavra;
        palavra[posicao] = caracteres_especiais[rand() % strlen(caracteres_especiais)];
    }
}

// Função para configurar um nível
void configurar_nivel(Nivel *nivel, int dificuldade) {
    // Limita a dificuldade a um valor máximo (por exemplo, 10)
    dificuldade = (dificuldade > 10) ? 10 : dificuldade;

    // Define os valores de forma mais precisa e escalável
    nivel->velocidade = 1000 * pow(2, dificuldade - 1); // Aumenta exponencialmente com a dificuldade
    nivel->comprimento_min = 5 + dificuldade; // Aumenta linearmente com a dificuldade
    nivel->caracteres_especiais = rand() % (dificuldade * 2); // Número aleatório de caracteres especiais

    // Array com caracteres especiais
    char caracteres_especiais[] = "!@#$%^&*()_-+=<>?";

    // Adiciona mais caracteres especiais conforme a dificuldade aumenta
    if (dificuldade >= 5) {
        // Gera um número aleatório de caracteres especiais a serem adicionados
        int num_caracteres_especiais = rand() % (dificuldade - 4); // Garante pelo menos um caractere especial a partir do nível 5

       inserir_caracteres_especiais(palavra, caracteres_especiais, num_caracteres_especiais);
    }
}

int main() {
    // ... (Inicialização do jogo)

    Palavra palavras[MAX_PALAVRAS];
    int num_palavras = 0;
    int modo_jogo = 1; // 1: contra o relógio, 2: modo infinito, 3: modo desafio
    int nivel = 1;
    Nivel niveis[3]; // Array para armazenar as configurações de cada nível
    int palavras_corretas = 0;
    int palavras_para_proximo_nivel = 10; // Ajuste este valor conforme necessário
    time_t inicio, fim;
    double tempo_decorrido;
    double tempo_para_proximo_nivel = 60.0; // 60 segundos

    // Configurar os níveis
    configurar_nivel(&niveis[0], 1); // Nível fácil
    configurar_nivel(&niveis[1], 2); // Nível médio
    configurar_nivel(&niveis[2], 3); // Nível difícil

    //ler o banco de dados
    ler_banco_dados(palavras, &num_palavras, "banco_de_palavras.txt");

    // ... (no início do jogo)
    inicio = time(NULL);

    while (1) {
        // ... (Escolher a palavra, mostrar na tela, ler a resposta do usuário)

        // Aumentar a dificuldade a cada X palavras
        if (palavra_digitada_corretamente) {
        palavras_corretas++;
    }

    if (palavras_corretas >= palavras_para_proximo_nivel) {
        nivel++;
        palavras_corretas = 0; // Reinicia a contagem para o próximo nível
        if (nivel > 3) {
            nivel = 3;
        }
    }

     fim = time(NULL);
    tempo_decorrido = difftime(fim, inicio);

    if (tempo_decorrido >= tempo_para_proximo_nivel) {
        nivel++;
        inicio = time(NULL); // Reinicia o cronômetro
        if (nivel > 3) {
            nivel = 3;
        }
    }

        // Ajustar a velocidade de acordo com o nível
        usleep(niveis[nivel - 1].velocidade * 1000); // Pausa em microsegundos
    }

    return 0;
}
