#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int exercicio;

    do
    {
        printf("\nLista de exerc�cios 1\n");
        printf("1 - Exerc�cio 1\n");
        printf("2 - Exerc�cio 2\n");
        printf("3 - Exerc�cio 3\n");
        printf("4 - Exerc�cio 4\n");
        printf("5 - Exerc�cio 5\n");
        printf("6 - Exerc�cio 6\n");
        printf("7 - Exerc�cio 7\n");
        printf("8 - Exerc�cio 8\n");
        printf("Escolha o seu exerc�cio:\n");
        scanf("%d", &exercicio);

        switch (exercicio)
    {
    case 1:
        printf("EXERC�CIO 1");
        break;
    case 2:
        printf("EXERC�CIO 2");
        break;
    case 3:
        printf("EXERC�CIO 3");
        break;
    case 4:
        printf("EXERC�CIO 4");
        break;
    case 5:
        printf("EXERC�CIO 5");
        break;
    case 6:
        printf("EXERC�CIO 6");
        break;
    case 7:
        printf("EXERC�CIO 7");
        break;
    case 8:
        printf("EXERC�CIO 8");
        break;
    
    default:
        break;
    }

    } while (exercicio != 0);

    
    
    return 0;
}