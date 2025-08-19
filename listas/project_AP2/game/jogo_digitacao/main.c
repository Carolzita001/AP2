#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "bibli.h" //função externa para função pontuação

int numeroAleatorio; //// para gerar numeros aleatorios para embaralhar as palavras do banco de dados

#define MAX_COMPRIMENTO 100
#define MAX_PALAVRAS 90
#define MAX_NIVEIS 3

// Representa uma palavra no jogo e seu nível de dificuldade
typedef struct
{
    char texto[MAX_COMPRIMENTO];
    int nivel;
} Palavra;

// Informações dos níveis do jogo
typedef struct
{
    Palavra *palavras; // Array de palavras para o nível
    int num_palavras;  // Número de palavras
    int tempo_limite;  // Tempo limite para o nível
} Nivel;

// Função para ler o banco de dados de palavras
void ler_banco_dados(Palavra *palavras, Nivel *niveis, int *num_palavras, const char *nome_arquivo)
{
    FILE *arq = fopen(nome_arquivo, "r");

    // Verificação de erro na abertura do arquivo
    if (arq == NULL)
    {
        printf("Arquivo não encontrado. Criando um novo...\n");
        arq = fopen(nome_arquivo, "w");
        if (arq == NULL)
        {
            perror("Erro ao criar o arquivo");
            exit(1); // Encerra o programa se o arquivo não puder ser criado
        }

        // Escreve palavras iniciais no banco de dados
        fprintf(arq, "Nível 1");
        fprintf(arq, "\n");
        fprintf(arq, "gato");
        fprintf(arq, "\n");
        fprintf(arq, "sol");
        fprintf(arq, "\n");
        fprintf(arq, "lua");
        fprintf(arq, "\n");
        fprintf(arq, "mar");
        fprintf(arq, "\n");
        fprintf(arq, "flor");
        fprintf(arq, "\n");
        fprintf(arq, "mel");
        fprintf(arq, "\n");
        fprintf(arq, "pedra");
        fprintf(arq, "\n");
        fprintf(arq, "fogo");
        fprintf(arq, "\n");
        fprintf(arq, "vento");
        fprintf(arq, "\n");
        fprintf(arq, "rio");
        fprintf(arq, "\n");
        fprintf(arq, "seu");
        fprintf(arq, "\n");
        fprintf(arq, "azul");
        fprintf(arq, "\n");
        fprintf(arq, "terra");
        fprintf(arq, "\n");
        fprintf(arq, "folha");
        fprintf(arq, "\n");
        fprintf(arq, "nuvem");
        fprintf(arq, "\n");
        fprintf(arq, "areia");
        fprintf(arq, "\n");
        fprintf(arq, "raio");
        fprintf(arq, "\n");
        fprintf(arq, "monte");
        fprintf(arq, "\n");
        fprintf(arq, "onda");
        fprintf(arq, "\n");
        fprintf(arq, "chama");
        fprintf(arq, "\n");
        fprintf(arq, "\n");
        fprintf(arq, "Nivel 2");
        fprintf(arq, "\n");
        fprintf(arq, "Amigo");
        fprintf(arq, "\n");
        fprintf(arq, "Casa");
        fprintf(arq, "\n");
        fprintf(arq, "Livro");
        fprintf(arq, "\n");
        fprintf(arq, "Coração");
        fprintf(arq, "\n");
        fprintf(arq, "Mãe");
        fprintf(arq, "\n");
        fprintf(arq, "Trabalho");
        fprintf(arq, "\n");
        fprintf(arq, "Jardim");
        fprintf(arq, "\n");
        fprintf(arq, "Feliz");
        fprintf(arq, "\n");
        fprintf(arq, "Carro");
        fprintf(arq, "\n");
        fprintf(arq, "Escola");
        fprintf(arq, "\n");
        fprintf(arq, "Som");
        fprintf(arq, "\n");
        fprintf(arq, "Tempo");
        fprintf(arq, "\n");
        fprintf(arq, "Música");
        fprintf(arq, "\n");
        fprintf(arq, "Criança");
        fprintf(arq, "\n");
        fprintf(arq, "Noite");
        fprintf(arq, "\n");
        fprintf(arq, "Sonho");
        fprintf(arq, "\n");
        fprintf(arq, "Família");
        fprintf(arq, "\n");
        fprintf(arq, "Amizade");
        fprintf(arq, "\n");
        fprintf(arq, "Natureza");
        fprintf(arq, "\n");
        fprintf(arq, "Céu");
        fprintf(arq, "\n");
        fprintf(arq, "Viagem");
        fprintf(arq, "\n");
        fprintf(arq, "História");
        fprintf(arq, "\n");
        fprintf(arq, "Saúde");
        fprintf(arq, "\n");
        fprintf(arq, "Esperança");
        fprintf(arq, "\n");
        fprintf(arq, "Destino");
        fprintf(arq, "\n");
        fprintf(arq, "União");
        fprintf(arq, "\n");
        fprintf(arq, "Brinquedo");
        fprintf(arq, "\n");
        fprintf(arq, "Palavras");
        fprintf(arq, "\n");
        fprintf(arq, "Iniciante");
        fprintf(arq, "\n");
        fprintf(arq, "Conhecimento");
        fprintf(arq, "\n");
        fprintf(arq, "\n");
        fprintf(arq, "Nivel 3");
        fprintf(arq, "\n");
        fprintf(arq, "Programação!");
        fprintf(arq, "\n");
        fprintf(arq, "Inovação#");
        fprintf(arq, "\n");
        fprintf(arq, "TecnologIa*");
        fprintf(arq, "\n");
        fprintf(arq, "Comput@dor");
        fprintf(arq, "\n");
        fprintf(arq, "Aprendiz@do");
        fprintf(arq, "\n");
        fprintf(arq, "Ciência#2024");
        fprintf(arq, "\n");
        fprintf(arq, "Desenvolvimento$");
        fprintf(arq, "\n");
        fprintf(arq, "Mercado@digital");
        fprintf(arq, "\n");
        fprintf(arq, "Inteligência*");
        fprintf(arq, "\n");
        fprintf(arq, "Program@ção");
        fprintf(arq, "\n");
        fprintf(arq, "Comput@ção@avançada");
        fprintf(arq, "\n");
        fprintf(arq, "SistEmas&Seguros");
        fprintf(arq, "\n");
        fprintf(arq, "Autom@ção");
        fprintf(arq, "\n");
        fprintf(arq, "#Aprendizado@Constante");
        fprintf(arq, "\n");
        fprintf(arq, "M@quinas");
        fprintf(arq, "\n");
        fprintf(arq, "Softw@re*");
        fprintf(arq, "\n");
        fprintf(arq, "Computador@");
        fprintf(arq, "\n");
        fprintf(arq, "Robótica#avançada");
        fprintf(arq, "\n");
        fprintf(arq, "Transform@ção*");
        fprintf(arq, "\n");
        fprintf(arq, "CyberSegurança&");
        fprintf(arq, "\n");
        fprintf(arq, "Inovação@Te@cnológica");
        fprintf(arq, "\n");
        fprintf(arq, "Algoritm@");
        fprintf(arq, "\n");
        fprintf(arq, "#Codificação*");
        fprintf(arq, "\n");
        fprintf(arq, "Inteligênci@Artificial");
        fprintf(arq, "\n");
        fprintf(arq, "BigD@ta&");
        fprintf(arq, "\n");
        fprintf(arq, "Cib@rnetica#");
        fprintf(arq, "\n");
        fprintf(arq, "Engenhari@Digital");
        fprintf(arq, "\n");
        fprintf(arq, "Transformação#2024");
        fprintf(arq, "\n");
        fprintf(arq, "@Autonomía*");
        fprintf(arq, "\n");
        fprintf(arq, "#Desenvolvimento@Avançado");
        fprintf(arq, "\n");
        fprintf(arq, "Realidade@Virtual*");
        fprintf(arq, "\n");
        fprintf(arq, "Machine#Learning@");
        fprintf(arq, "\n");
        fprintf(arq, "Inovaç@o&Global");
        fprintf(arq, "\n");
        fprintf(arq, "@Computação#Pervasiva");
        fprintf(arq, "\n");
        fprintf(arq, "Ciênci@deD@dos*");
        fprintf(arq, "\n");
        fprintf(arq, "Robôs&Humanóides");
        fprintf(arq, "\n");
        fprintf(arq, "Sistemas@Integrados#");
        fprintf(arq, "\n");
        fprintf(arq, "Segurança@Digital*");
        fprintf(arq, "\n");
        fprintf(arq, "Evolução#Tecnológica");
        fprintf(arq, "\n");
        fprintf(arq, "Automação@Inteligente*");
        fprintf(arq, "\n");
        fprintf(arq, "Tecnolog@Digital#Avançada");

        fclose(arq); // Fecha o arquivo após escrever

        printf("Arquivo criado com sucesso.\n");
        arq = fopen(nome_arquivo, "r"); // Reabre o arquivo para leitura
    }

    char linha[MAX_COMPRIMENTO];
    int nivelAtual = -1; // Começa com -1 para indicar que ainda não leu um nível

    while (fgets(linha, sizeof(linha), arq)) // Lê uma linha do arquivo arq e armazena no array linha. sizeof(linha)
    {
        linha[strcspn(linha, "\n")] = 0; // Substitui o caractere de nova linha pelo terminador nulo (\0), faz com que a nova linha não seja incluida na proxima

        // Verifica se a linha está em branco
        if (strlen(linha) == 0) /// calcula o compimento da nova linha, se for zero esta branco
        {
            continue; // Pula para a próxima linha
        }

        if (strncmp(linha, "Nível", 5) == 0) // Compara os primeiros 5 caracteres da string linha com a string "Nível".
        {
            nivelAtual++; // Incrementa o índice nivelAtual, indicando que foi detectada uma nova seção ou nível no arquivo.
            if (nivelAtual >= MAX_NIVEIS)
            {
                printf("Aviso: Número de níveis no arquivo excede o limite permitido (%d).\n", MAX_NIVEIS);
                break;
            }
            niveis[nivelAtual].num_palavras = 0; //// acessa o  nível recém-incrementado em niveis e inicializa o contador num_palavras como zero
            continue;
            // faz o loop ir diretamente para a proxima interação
        }

        // Adiciona palavras ao nível atual e ao array global
        if (nivelAtual >= 0 && nivelAtual < MAX_NIVEIS)
        {
            Palavra *atual = &niveis[nivelAtual].palavras[niveis[nivelAtual].num_palavras]; // Obtém o endereço do próximo espaço disponível no array de palavras do nível atual
            strncpy(atual->texto, linha, MAX_COMPRIMENTO - 1);                              //// copia o conteudo variavel linha, para o campo texto da palavra garantindo que não exceda o comprimento máximo (MAX_COMPRIMENTO)
            atual->texto[MAX_COMPRIMENTO - 1] = '\0';                                       // adiciona o caractere nulo ao final da string para assegura que ela está devidamente terminada
            niveis[nivelAtual].num_palavras++;                                              // incrementa o contador num_palavras do nível atual

            // Adiciona também ao array global de palavras
            if (*num_palavras < MAX_PALAVRAS)
            {
                Palavra *global = &palavras[*num_palavras];         // Obtém o endereço do próximo espaço disponível no array global de palavras
                strncpy(global->texto, linha, MAX_COMPRIMENTO - 1); // copia o conteudo variavel texto, para o campo texto da palavra
                global->texto[MAX_COMPRIMENTO - 1] = '\0';          ////adiciona o caractere nulo ao final da string para assegura que ela está devidamente terminada
                (*num_palavras)++;                                  // incrementa o valor apontado por num_palavras
            }
        }
    }

    fclose(arq); // fecha o arquivo
}

void embaralharPalavras(Palavra *palavras, int num_palavras)
{
    for (int i = num_palavras - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Palavra temp = palavras[i];
        palavras[i] = palavras[j];
        palavras[j] = temp;
    }
}

int iniciarNivel(Nivel *nivel, int *nivelAtual)
{
    char palavraUsuario[MAX_COMPRIMENTO];
    time_t inicio, atual;
    int tempoRestante;
    int acertos = 0;     // Contador de acertos
    int pontuacao = 0;   // Pontuação total
    int indiceAtual = 0; // Índice da palavra atual

    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios
    time(&inicio);
    atual = inicio; // Inicializa 'atual' com o tempo de início
    printf("Começando o nível %d! Você tem %d segundos.\n", *nivelAtual, nivel->tempo_limite);

    // Embaralha as palavras
    embaralharPalavras(nivel->palavras, nivel->num_palavras);

    while (1)
    {
        // Verifica se todas as palavras foram usadas
        if (indiceAtual >= nivel->num_palavras)
        {
            printf("Todas as palavras foram usadas!\n");
            return 0;
        }

        // Escolhe a próxima palavra
        Palavra palavraEscolhida = nivel->palavras[indiceAtual];

        // Atualiza o tempo atual e calcula o tempo restante
        time(&atual);
        tempoRestante = nivel->tempo_limite - (int)difftime(atual, inicio);
        if (tempoRestante <= 0)
        {
            return 0; // Sai do loop se o tempo esgotar
        }

        printf("\rTempo restante: %d segundos    \n", tempoRestante);
        printf("\nDigite a palavra: %s\n", palavraEscolhida.texto);
        printf("Sua resposta: ");
        fgets(palavraUsuario, MAX_COMPRIMENTO, stdin);
        palavraUsuario[strcspn(palavraUsuario, "\n")] = 0; // Remove a nova linha

        if (strcmp(palavraEscolhida.texto, palavraUsuario) == 0)
        {
            printf("Correto!\n");
            acertos++; // Incrementa acertos

            // Calcula a pontuação com base nos acertos em sequência, se houver 2 ou mais
            if (acertos >= 1)
            {
                pontuacao += calcularPontuacao(acertos, 0);
                printf("Acertou! Pontuação atual: %d\n", pontuacao);
            }
            else
            {
                pontuacao += 1; // Apenas 1 ponto para o primeiro acerto
            }

            // Verifica se o usuário acertou 10 palavras
            if (pontuacao >= 10)
            {
                printf("Parabéns! Você atingiu 10 pontos e passou de nível!\n");
                (*nivelAtual)++; // Aumenta o nível atual
                return 1;        // Sai da função para iniciar o próximo nível
            }
        }
        else
        {
            printf("Errado. A palavra correta era: %s\n", palavraEscolhida.texto);
            // Calcula a pontuação com base nos acertos em sequência, se houver 2 ou mais

            pontuacao -= 1;
            printf("Pontuação atual: %d\n", pontuacao);
        }

        // Avança para a próxima palavra
        indiceAtual++;
    }

    printf("Tempo esgotado! Você acertou %d palavras!\n", pontuacao);
}

// Função para exibir o menu principal
void exibir_menu()
{
    printf("=== WordWar ===\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Sair\n");
    printf("========================\n");
    printf("Escolha uma opção: ");
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    srand(time(NULL));

    Palavra palavras[MAX_PALAVRAS];
    Nivel niveis[MAX_NIVEIS];
    int num_palavras = 0;

    // Inicializa os níveis
    for (int i = 0; i < MAX_NIVEIS; i++)
    {
        niveis[i].palavras = malloc(MAX_PALAVRAS * sizeof(Palavra));
        if (niveis[i].palavras == NULL)
        {
            perror("Erro ao alocar memória para palavras");
            exit(1);
        }
        niveis[i].num_palavras = 0;
        niveis[i].tempo_limite = 30 - i * 5; // Exemplo de decremento de tempo por nível
    }

    // Lê o banco de dados e organiza palavras
    ler_banco_dados(palavras, niveis, &num_palavras, "banco_de_palavras.txt");

    // Divide palavras entre níveis (exemplo simples, assume palavras sequenciais)
    int offset = 0;
    for (int i = 0; i < MAX_NIVEIS; i++)
    {
        int palavras_por_nivel = (i == 0) ? 20 : (i == 1) ? 30
                                                          : 40;
        if (offset + palavras_por_nivel > num_palavras)
        {
            printf("Erro: Banco de dados não possui palavras suficientes para o nível %d.\n", i + 1);
            exit(1);
        }

        memcpy(niveis[i].palavras, &palavras[offset], palavras_por_nivel * sizeof(Palavra));
        niveis[i].num_palavras = palavras_por_nivel;
        offset += palavras_por_nivel;
    }

    int opcao, nivelAtual = 0;

    while (1)
    {
        exibir_menu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        if (opcao == 1)
        {
            nivelAtual = 1; // Começa no nível 1
            while (nivelAtual <= MAX_NIVEIS)
            {
                printf("\n== Iniciando o Nível %d ==\n", nivelAtual);
                if (!iniciarNivel(&niveis[nivelAtual - 1], &nivelAtual))
                {
                    printf("Você não completou o nível %d. Tente novamente!\n", nivelAtual);
                    break; // Sai do loop se o jogador falhar
                }
            }
            if (nivelAtual > MAX_NIVEIS)
            {
                printf("Parabéns! Você completou todos os níveis!\n");
            }
        }
        else if (opcao == 2)
        {
            printf("Saindo do jogo. Até mais!\n");
            break;
        }
        else
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    // Libera a memória
    for (int i = 0; i < MAX_NIVEIS; i++)
    {
        free(niveis[i].palavras);
    }

    return 0;
}
