#include <stdio.h>
#include <stdlib.h>
#include "placeholder.h"


//Ajustar tudo depois, arrumar fun��es e testar resultados

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

    printf("Escolha o n�vel de atividade:\n");
    printf("1 - Sedent�rio (pouca ou nenhuma atividade)\n");
    printf("2 - Levemente ativo (exerc�cios leves 1-3 dias/semana)\n");
    printf("3 - Moderadamente ativo (exerc�cios moderados 3-5 dias/semana)\n");
    printf("4 - Muito ativo (exerc�cios intensos 6-7 dias/semana)\n");
    printf("5 - Extremamente ativo (exerc�cios intensos diariamente, ou exerc�cio f�sico + trabalho f�sico)\n");
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
            printf("N�vel de atividade inv�lido.\n");
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
    printf("Necessidade cal�rica total: %.2f calorias\n", necessidadeCalorica);
    printf("Consumo de �gua recomendado: %.2f ml\n", consumoAgua);

    
    for (int i = 0; i < numAlimentos; i++) {
        printf("Informe o nome do alimento %d: ", i + 1);
        scanf("%s", nomes[i]);

        printf("Informe a quantidade de carboidratos (g) do alimento %d: ", i + 1);
        scanf("%f", &carboidratos[i]);

        printf("Informe a quantidade de prote�nas (g) do alimento %d: ", i + 1);
        scanf("%f", &proteinas[i]);

        printf("Informe a quantidade de gorduras (g) do alimento %d: ", i + 1);
        scanf("%f", &gorduras[i]);
    }
    
    float valorCaloricoTotal = 0.0;
    for (int j = 0; j < numAlimentos; j++) {
        valorCaloricoTotal += calcularValorCalorico(carboidratos[j], proteinas[j], gorduras[j]);
    }

    printf("O valor cal�rico total da refei��o �: %.2f calorias\n", valorCaloricoTotal);

    return 0;
	
	
}
