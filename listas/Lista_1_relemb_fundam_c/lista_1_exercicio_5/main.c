#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");

    int n, i;
    int fatorial = 1;

    printf("Digite um valor inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: N deve ser um valor inteiro positivo.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        fatorial *= i;
    }

    printf("O fatorial de %d é %d.\n", n, fatorial);

    return 0;
}