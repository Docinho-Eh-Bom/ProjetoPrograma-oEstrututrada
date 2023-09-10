#include <stdio.h>
#include <stdlib.h>
#include "alessandra.h"

int main() {
	
	
	char nome[100];//Da um bug quando se utiliza espaço
    int idade, nivelAtividade, numSemanas;
    char sexo;
    float peso, altura,caloriasDiarias;
    int menu,continuar,c,f,j;
    int i= 0;
    int l = 1;
    
    
    header();
    
    printf("Digite seu nome: ");
    scanf("%s", &nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    f = 1;
    
    do{
    	printf("Digite seu sexo (M/F): ");
   		scanf(" %c", &sexo);
   			if(sexo == 'm' || sexo == 'M' || sexo == 'f' || sexo == 'F'){
   				break;
			}else{
			   printf("Sexo invalido. Insira novamente:\n");
   				f = 0;
			}		
    }while(f == 0);

    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura (m): ");
    scanf("%f", &altura);
	 
	float ingestaoSemanal[numSemanas];
	
	
	float fatorAtividade;

    do{
	imprimirAtividadeFisica();
    scanf("%d", &nivelAtividade);
    
    c = 1;
    
    switch (nivelAtividade) {
        case 1:
            fatorAtividade = 1.2;
            break;
        case 2:
            fatorAtividade = 1.375;
			break;
        case 3:
            fatorAtividade = 1.55;
			break;
        case 4:
            fatorAtividade = 1.725;
			break;
        case 5:
            fatorAtividade = 1.9;
			break;
        default:
        	limpa();
        	header();
            printf("Nivel de atividade invalido.\n");
            c = 0;
    	}
    }while(c==0);
    
    //Array para armazenar mais de uma pessoa futuramente talvez?
    //Pessoa
    float imc = calcularIMC(peso, altura);
    float tmb = calcularTMB(sexo, peso, altura, idade);
    float necessidadeCalorica = calcularNecessidadeCalorica(tmb, fatorAtividade);
    float consumoAgua = calcularConsumoAgua(peso);
    
    
    //Tentar criarr um array de nomes para melhor organizar futuramente
    //Alimentos
    int numAlimentos;
    float carboidratos[numAlimentos];
    float proteinas[numAlimentos];
    float gorduras[numAlimentos];
    float valorTotal;
    

    system("cls");
    
    do{
    header();
    printf("\nMenu de Opcoes:\n");
    printf("1 - Calcular Indice de Massa Corporal\n");
    printf("2 - Calcular Taxa Metabolica Basal\n");
    printf("3 - Calcular Necessidade Calorica\n");
    printf("4 - Calcular Consumo de Agua\n");
    printf("5 - Calcular Ingestao Calorica semanal de acordo com dieta\n");
    printf("6 - Resumo dos Resultados\n");
    printf("7 - Calcular os valores caloricos de alimentos\n");
    printf("8 - Exibir Tabela do IMC\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("\nIndice de Massa Muscular total de: %.2f\n", imc);
            break;
        case 2:
            printf("\nTaxa Metabolica Basal:  %.2f calorias\n", tmb);
            break;
        case 3:
            printf("\nNecessidade calorica total aproximadamente de: %.2f calorias\n", necessidadeCalorica);
            break;
        case 4:
            printf("\nConsumo de agua recomendado: %.2f ml\n", consumoAgua);
            break;
        case 5:
        	printf("\nDigite o numero de semanas da dieta: ");
			scanf("%d", &numSemanas);
	
			printf("\nDigite a quantidade de calorias semanais da dieta: ");
			scanf("%f", &caloriasDiarias);
			
			printf("\n");
  	
        	calcularIngestaoSemanal(ingestaoSemanal, caloriasDiarias, 0, numSemanas);
			imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
			
			i = 1;
            break;
        case 6:
            if(i == 1){
            printf("\nResumo dos resultados para %s:\n", nome);
            imprimirResumoResultados(imc, tmb, necessidadeCalorica, consumoAgua);
            imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
			}else{
				printf("\nResumo dos resultados para %s:\n", nome);
				imprimirResumoResultados(imc, tmb, necessidadeCalorica, consumoAgua);
			}    
            break;
        case 7:
        	j = 0;
        	
        	printf("\nInsira a quantidade de alimentos que deseja armazenar/calcular: ");
        	scanf("%d",&numAlimentos);
        	
    		do{
        	printf("\nDigite a quantidade de carboidratos para o alimento %d: ", j + 1);
        	
        	scanf("%f", &carboidratos[j]);
        	
			printf("\nDigite a quantidade de proteinas para o alimento %d: ", j + 1);
			scanf("%f", &proteinas[j]);
			
			printf("\nDigite a quantidade de gorduras para o alimento %d: ", j + 1);
			scanf("%f", &gorduras[j]);


			j++;
			
			system("cls");

			}while(j < numAlimentos);

			valorTotal = calcularValorCalorico(carboidratos, proteinas, gorduras, numAlimentos, 0);
			imprimirValorCaloricoTotal(valorTotal);
			break;
        case 8:
            tabelaIMC();
            printf("O seu IMC e de: %.2f\n", imc);
            break;
        case 0:
            printf("Saindo do programa. Obrigado!\n");
            footer();
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }

    if (menu != 0){
        int continuar;
        printf("\nDeseja continuar? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);
        if (continuar == 1) {
            system("cls"); 
        }else{
        	printf("Saindo do programa. Obrigado!\n");
            footer();
        	return 0;
		}
    }

}while(menu != 0);

	
	return 0;
}
