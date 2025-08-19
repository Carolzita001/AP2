#ifndef BIBLI_H
#define BIBLI_H

// Função recursiva para calcular a pontuação
int calcularPontuacao(int acertos, int totalAcertos)
{
    // Caso base: se não houver mais acertos, retorna a pontuação total
    if (acertos == 0)
    {
        return totalAcertos;
    }
    // Chamada recursiva, adicionando um ponto por acerto
    return calcularPontuacao(acertos - 1, totalAcertos + 1);
}

#endif // BIBLI_H
