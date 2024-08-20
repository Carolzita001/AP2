#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portugues_Brazil");

    int horas, segundos;

    printf("Insira as horas inteiras:\n");
    scanf("%d", &horas);

    segundos = horas * 3600;

    printf("As horas inseridas em segundos são: %d\n", segundos);

    return 0;
}