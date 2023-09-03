#include <stdio.h>
#include "placeholder.h"

//Função para calcular o IMC
float calcularIMC(float peso, float altura, float *imc) {
    *imc = peso / (altura * altura);
}

//Função para calcular o TMB (Taxa Metabólica Basal)
void calcularTMB(char sexo, float peso, float altura, int idade, float *tmb) {
    if (sexo == 'M') {
        *tmb = 66 + (13.75 * peso) + (5 * altura * 100) - (6.75 * idade);
    } else if (sexo == 'F') {
        *tmb = 655 + (9.56 * peso) + (1.85 * altura * 100) - (4.68 * idade);
    } else {
        *tmb = 0; // Sexo inválido
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

// Função para imprimir a tabela de índices de IMC
void imprimirTabelaIMC() {
    printf("Índice de Massa Corporal (IMC) e Classificação\n");
    printf("--------------------------------------------\n");
    printf("IMC < 16.0: Magreza grave\n");
    printf("16.0 <= IMC < 16.9: Magreza moderada\n");
    printf("17.0 <= IMC < 18.4: Magreza leve\n");
    printf("18.5 <= IMC < 24.9: Saudável\n");
    printf("25.0 <= IMC < 29.9: Sobrepeso\n");
    printf("30.0 <= IMC < 34.9: Obesidade Grau I\n");
    printf("35.0 <= IMC < 39.9: Obesidade Grau II (severa)\n");
    printf("IMC >= 40.0: Obesidade Grau III (mórbida)\n");
}
