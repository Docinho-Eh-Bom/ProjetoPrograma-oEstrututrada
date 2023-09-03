#include <stdio.h>
#include "placeholder.h"

//Fun��o para calcular o IMC
float calcularIMC(float peso, float altura, float *imc) {
    *imc = peso / (altura * altura);
}

//Fun��o para calcular o TMB (Taxa Metab�lica Basal)
void calcularTMB(char sexo, float peso, float altura, int idade, float *tmb) {
    if (sexo == 'M') {
        *tmb = 66 + (13.75 * peso) + (5 * altura * 100) - (6.75 * idade);
    } else if (sexo == 'F') {
        *tmb = 655 + (9.56 * peso) + (1.85 * altura * 100) - (4.68 * idade);
    } else {
        *tmb = 0; // Sexo inv�lido
    }
}
//
float calcularNecessidadeCalorica(float tmb, float fatorAtividade) {
    return tmb * fatorAtividade;
}

float calcularConsumoAgua(float peso) {
    return 35 * peso;
}

float calcularValorCalorico(float carboidratos, float proteinas, float gorduras) {
    return (carboidratos * 4) + (proteinas * 4) + (gorduras * 9);
}

// Fun��o para imprimir a tabela de �ndices de IMC
void imprimirTabelaIMC() {
    printf("�ndice de Massa Corporal (IMC) e Classifica��o\n");
    printf("--------------------------------------------\n");
    printf("IMC < 16.0: Magreza grave\n");
    printf("16.0 <= IMC < 16.9: Magreza moderada\n");
    printf("17.0 <= IMC < 18.4: Magreza leve\n");
    printf("18.5 <= IMC < 24.9: Saud�vel\n");
    printf("25.0 <= IMC < 29.9: Sobrepeso\n");
    printf("30.0 <= IMC < 34.9: Obesidade Grau I\n");
    printf("35.0 <= IMC < 39.9: Obesidade Grau II (severa)\n");
    printf("IMC >= 40.0: Obesidade Grau III (m�rbida)\n");
}
