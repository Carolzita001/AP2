#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int a, b, c, menorAB;

    printf("Insira um valor para a: \n");
    scanf("%d", &a);
    printf("Insira um valor para b: \n");
    scanf("%d", &b);
    printf("Insira um valor para c: \n");
    scanf("%d", &c);


    menorAB = ( a + b - abs(a - b)) / 2;

    printf("%d � o menor n�mero entre A e B \n", menorAB);

    if (menorAB < c)
    {
        printf("%d � menor que %d", menorAB, c);
    }
    else {
        printf("%d � maior que %d", c, menorAB);
    }

    return 0;
}
