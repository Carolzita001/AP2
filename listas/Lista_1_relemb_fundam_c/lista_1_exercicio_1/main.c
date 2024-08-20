#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int exercicio;

    do
    {
        printf("\nLista de exercícios 1\n");
        printf("1 - Exercício 1\n");
        printf("2 - Exercício 2\n");
        printf("3 - Exercício 3\n");
        printf("4 - Exercício 4\n");
        printf("5 - Exercício 5\n");
        printf("6 - Exercício 6\n");
        printf("7 - Exercício 7\n");
        printf("8 - Exercício 8\n");
        printf("Escolha o seu exercício:\n");
        scanf("%d", &exercicio);

        switch (exercicio)
    {
    case 1:
        printf("EXERCÍCIO 1");
        break;
    case 2:
        printf("EXERCÍCIO 2");
        break;
    case 3:
        printf("EXERCÍCIO 3");
        break;
    case 4:
        printf("EXERCÍCIO 4");
        break;
    case 5:
        printf("EXERCÍCIO 5");
        break;
    case 6:
        printf("EXERCÍCIO 6");
        break;
    case 7:
        printf("EXERCÍCIO 7");
        break;
    case 8:
        printf("EXERCÍCIO 8");
        break;
    
    default:
        break;
    }

    } while (exercicio != 0);

    
    
    return 0;
}