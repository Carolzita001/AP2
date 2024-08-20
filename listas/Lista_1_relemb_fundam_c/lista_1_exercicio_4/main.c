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
        printf("Você é um estudante jovem\n");
    }
    else if (idade >= 18 && idade < 25 && horas_estudadas >= 10)
    {
        printf("Você é um estudante adulto\n");
    }
    else if (idade >= 25 && horas_estudadas < 10 && horas_estudadas > 5)
    {
        printf("Você é um estudante sênior\n");
    }
    else if (idade > 0 && horas_estudadas <= 5)
    {
        printf("Você é um estudante desmotivado");
    }
    else {
        printf("Aluno não categorizado");
    }
    
    return 0;
}