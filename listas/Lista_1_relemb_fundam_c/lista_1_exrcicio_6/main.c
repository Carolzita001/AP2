#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int vetor[10];

    for (int i = 0; i < 10; i++) {
        vetor[i] = (i == 2 || i == 3 || i == 5 || i == 7) ? 1 : 0;
    }

    printf("Vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}