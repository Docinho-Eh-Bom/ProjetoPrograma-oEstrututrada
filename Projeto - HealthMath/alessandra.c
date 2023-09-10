#include <stdio.h>
#include <stdlib.h>
#include "alessandra.h"

void header(){
	printf("\n-------------------- HealthMath --------------------\n\n");
}

void footer(){
	printf("\n-------------------- HealthMath Encerrado --------------------\n\n");
}

float calcularIMC(float peso, float altura){
    return peso / (altura * altura);
}

void tabelaIMC(){
    printf("\nTabela do IMC (Indice de Massa Corporal):\n");
    printf("-----------------------------------------------------\n");
    printf("  IMC\t   Categoria\n");
    printf("-----------------------------------------------------\n");
    printf("  < 18.5\t Abaixo do peso\n");
    printf("  18.5 - 24.9\t Peso normal\n");
    printf("  25.0 - 29.9\t Sobrepeso\n");
    printf("  30.0 - 34.9\t Obesidade Grau I\n");
    printf("  35.0 - 39.9\t Obesidade Grau II (severa)\n");
    printf("  >= 40.0\t Obesidade Grau III (morbida)\n");
    printf("-----------------------------------------------------\n");
}

float calcularTMB(char sexo, float peso, float altura, int idade){
    if (sexo == 'M' || sexo == 'm') {
        return 66 + (13.75 * peso) + (5 * altura * 100) - (6.75 * idade); // TMB Masculino
    } else if (sexo == 'F' || sexo == 'f') {
        return 655 + (9.56 * peso) + (1.85 * altura * 100) - (4.68 * idade); // TMB Feminino
    } else {
        return 0; 
    }
}

//Futuro array coma ativididades físicas e seus gastos caloricos para opções mais específicos
void imprimirAtividadeFisica(){
	printf("\nEscolha o seu nivel de atividade:\n");
    printf("1 - Sedentario (pouca ou nenhuma atividade)\n");
    printf("2 - Levemente ativo (exercicios leves 1-3 dias/semana)\n");
    printf("3 - Moderadamente ativo (exercicios moderados 3-5 dias/semana)\n");
    printf("4 - Muito ativo (exercicios intensos 6-7 dias/semana)\n");
    printf("5 - Extremamente ativo (exercicios intensos diariamente, ou exercicio fisico + trabalho fisico)\n");
}

float calcularNecessidadeCalorica(float tmb, float fatorAtividade){
    return tmb * fatorAtividade;
}


float calcularConsumoAgua(float peso){
    return (35 * peso)/1000;
}

void calcularIngestaoSemanal(float *ingestaoSemanal, float caloriasDiarias, int diaAtual, int numSemanas) {
    if (diaAtual == numSemanas) {
        return; // Se chegar no numero de dias inserido, ele encerra a chamada para o calculo
    }

    *(ingestaoSemanal + diaAtual) = caloriasDiarias * 7;
    calcularIngestaoSemanal(ingestaoSemanal, caloriasDiarias, diaAtual + 1, numSemanas); // Chamada recursiva para o próximo dia
}

void imprimirIngestaoSemanal(float *ingestaoSemanal, int numSemanas, int index){
    if (index == numSemanas){
        return; // Se chegar no numero de dias inserido, ele encerra a chamada, pois ja percorreu o array
    }

    printf("Semana %d: %.2f calorias\n", index + 1, *(ingestaoSemanal + index));
    imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, index + 1); // Chamada recursiva para a próxima posição(dia)
}

void imprimirResumoResultados(float imc, float tmb, float necessidadeCalorica, float consumoAgua){
	printf("Indice de Massa Muscular total de: %.2f\n", imc);
	printf("Taxa Metabolica Basal:  %.2f calorias\n", tmb);
	printf("Necessidade calorica total aproximadamente de: %.2f calorias\n", necessidadeCalorica);
	printf("Consumo de agua recomendado: %.2f L\n\n", consumoAgua);
}

// Função recursiva toda vida agora
float calcularValorCalorico(float *carboidratos, float *proteinas, float *gorduras, int numAlimentos, int index){
    if (index == numAlimentos){
        return 0;
    }
   
    float valorCaloricoAlimento = (4 * carboidratos[index]) + (4 * proteinas[index]) + (9 * gorduras[index]);

    //Soma com anterior, não armazena resultados individuais
    return valorCaloricoAlimento + calcularValorCalorico(carboidratos, proteinas, gorduras, numAlimentos, index + 1);
}

void imprimirValorCaloricoTotal(float valorTotal){
    printf("\nValor calorico total dos alimentos: %.2f calorias\n", valorTotal);
}

void limpa(){
	system("cls");
}
