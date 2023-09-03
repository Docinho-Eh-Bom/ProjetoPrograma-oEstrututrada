#include <stdio.h>
#include <stdlib.h>
#include "placeholder.h"


//Ajustar tudo depois, arrumar funções e testar resultados

int main() {

	char nome[100];
    int idade;
    char sexo;
    float peso, altura;
    int nivelAtividade;
    int numAlimentos;
    
    char nomes[numAlimentos][100];
    float carboidratos[numAlimentos];
    float proteinas[numAlimentos];
    float gorduras[numAlimentos];
    
    

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura (m): ");
    scanf("%f", &altura);

    printf("Escolha o nível de atividade:\n");
    printf("1 - Sedentário (pouca ou nenhuma atividade)\n");
    printf("2 - Levemente ativo (exercícios leves 1-3 dias/semana)\n");
    printf("3 - Moderadamente ativo (exercícios moderados 3-5 dias/semana)\n");
    printf("4 - Muito ativo (exercícios intensos 6-7 dias/semana)\n");
    printf("5 - Extremamente ativo (exercícios intensos diariamente, ou exercício físico + trabalho físico)\n");
    scanf("%d", &nivelAtividade);



    float fatorAtividade;
    
    switch (nivelAtividade){
        case 1:
            fatorAtividade = 1.2;
            break;
        case 2:
            fatorAtividade = 1.375;
            break;
        case 3:
            fatorAtividade = 1.466;
            break;
		 case 4:
            fatorAtividade = 1.775;
            break;
		 case 5:
            fatorAtividade = 1.9;
            break;    
        default:
            printf("Nível de atividade inválido.\n");
            return 1;
    }

    float imc;
    calcularIMC(peso, altura, &imc);

    float tmb;
    calcularTMB(sexo, peso, altura, idade, &tmb);

    float necessidadeCalorica = calcularNecessidadeCalorica(tmb, fatorAtividade);
    float consumoAgua = calcularConsumoAgua(peso);

    printf("\nResumo dos resultados para %s:\n", nome);
    printf("IMC: %.2f\n", imc);
    printf("TMB: %.2f calorias\n", tmb);
    printf("Necessidade calórica total: %.2f calorias\n", necessidadeCalorica);
    printf("Consumo de água recomendado: %.2f ml\n", consumoAgua);

    
    for (int i = 0; i < numAlimentos; i++) {
        printf("Informe o nome do alimento %d: ", i + 1);
        scanf("%s", nomes[i]);

        printf("Informe a quantidade de carboidratos (g) do alimento %d: ", i + 1);
        scanf("%f", &carboidratos[i]);

        printf("Informe a quantidade de proteínas (g) do alimento %d: ", i + 1);
        scanf("%f", &proteinas[i]);

        printf("Informe a quantidade de gorduras (g) do alimento %d: ", i + 1);
        scanf("%f", &gorduras[i]);
    }
    
    float valorCaloricoTotal = 0.0;
    for (int j = 0; j < numAlimentos; j++) {
        valorCaloricoTotal += calcularValorCalorico(carboidratos[j], proteinas[j], gorduras[j]);
    }

    printf("O valor calórico total da refeição é: %.2f calorias\n", valorCaloricoTotal);

    return 0;
	
	
}
