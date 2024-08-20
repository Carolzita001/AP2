#include <stdio.h>
#include <math.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL,"Portuguese_Brazil");

    int idade; 
    float horas_estudadas;

    printf("Insira sua idade: \n");
    scanf("%d", &idade);

    printf("Insira a quantidade de horas estudadas semanalmente: \n");
    scanf("%f", &horas_estudadas);

    if (idade < 18 && horas_estudadas >= 15)
    {
        printf("Voc� � um estudante jovem\n");
    }
    else if (idade >= 18 && idade < 25 && horas_estudadas >= 10)
    {
        printf("Voc� � um estudante adulto\n");
    }
    else if (idade >= 25 && horas_estudadas < 10 && horas_estudadas > 5)
    {
        printf("Voc� � um estudante s�nior\n");
    }
    else if (idade > 0 && horas_estudadas <= 5)
    {
        printf("Voc� � um estudante desmotivado");
    }
    else {
        printf("Aluno n�o categorizado");
    }
    
    return 0;
}