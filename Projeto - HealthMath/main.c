#include <stdio.h>
#include <stdlib.h>
#include "alessandra.h"


int main(){
	//Fase I
    int escolhaPerfil, idade;
    char sexo;
    float peso, altura;
    float imc, tmb;
    //Fase II
    int escolhaDieta;
    int continuar = 1;//verdadeiro
    char dieta[30];
    int numSemanas = 3;
    float ingestaoSemanal[numSemanas];
    float caloriasTotais;
    //Fase III
    Alimento *alimentos;
    int numAlimentos = lerArquivoAlimentos(&alimentos, "alimentosData.txt");
    int i;

    
    header();

	do{
	    exibirMenuPerfil();
	    scanf("%d", &escolhaPerfil);
	
	    if(escolhaPerfil == 0){
	        printf("Saindo do programa. Obrigado!\n");
	        footer();
	        return 0;
	    }else if(escolhaPerfil < 1 || escolhaPerfil > 2){
	        limpa();
	        header();
	        printf("Opcao de perfil invalida. Tente novamente.\n\n");
	        continue;
	    }
	
	    if(escolhaPerfil == 1){
	        // Perfil Masculino
	        idade = 30;
	        sexo = 'M';
	        peso = 70.0;
	        altura = 1.75;
	    }else if (escolhaPerfil == 2){
	        // Perfil Feminino
	        idade = 25;
	        sexo = 'F';
	        peso = 60.0;
	        altura = 1.61;
	    }
	
	    imc = calcularIMC(peso, altura);
	    tmb = calcularTMB(sexo, peso, altura, idade);
	
	    exibirPerfil(idade, sexo, peso, altura, imc, tmb / 1000);
	
	    do{
	        exibirMenuDietas();
	        printf("\n");
	        scanf("%s", dieta);
	
	        if(stricmp(dieta, "sair") == 0){
	            printf("Saindo do programa. Obrigado!\n");
	            footer();
	            return 0;
	        }else if(stricmp(dieta, "vegetariana") == 0){
	            limpa();
	            header();
	            montarDietaVegetariana(tmb, &caloriasTotais);
	            calcularIngestaoSemanal(ingestaoSemanal, caloriasTotais, 0, numSemanas);
	            printf("\nIngestao Semanal de calorias de acordo com a dieta:\n");
	            imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
	        }else if(stricmp(dieta, "vegana") == 0){
	            limpa();
	            header();
	            montarDietaVegana(tmb, &caloriasTotais);
	            calcularIngestaoSemanal(ingestaoSemanal, caloriasTotais, 0, numSemanas);
	            printf("\nIngestao Semanal de calorias de acordo com a dieta:\n");
	            imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
	        }else if(stricmp(dieta, "pescetariana") == 0){
	            limpa();
	            header();
	            montarDietaPescetariana(tmb, &caloriasTotais);
	            calcularIngestaoSemanal(ingestaoSemanal, caloriasTotais, 0, numSemanas);
	            printf("\nIngestao Semanal de calorias de acordo com a dieta:\n");
	            imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
	        }else if(stricmp(dieta, "normal") == 0){
	            limpa();
	            header();
	            montarDietaNormal(tmb, &caloriasTotais);
	            calcularIngestaoSemanal(ingestaoSemanal, caloriasTotais, 0, numSemanas);
	            printf("\nIngestao Semanal de calorias de acordo com a dieta:\n");
	            imprimirIngestaoSemanal(ingestaoSemanal, numSemanas, 0);
	        }else if(stricmp(dieta, "montar") == 0){
	            limpa();
	            imprimirListaAlimentos(alimentos, numAlimentos);
	            printf("Digite o nome dos alimentos desejados como estao escritos para escolher (digite 'fim' para encerrar):\n");
	
	            if(numAlimentos > 0){
	                montarDieta(alimentos, numAlimentos);
	            }else{
	                printf("Erro ao ler o arquivo de alimentos.\n");
	            }
	            printf("Deseja continuar? (1 - Sim / 0 - Nao): ");
	            scanf("%d", &continuar);
	        }else{
	        	printf("Opcao invalida, tente novamente.\n");
			}
	    }while(continuar);
	    printf("Saindo do programa. Obrigado!\n");
	    footer();
	    return 0;
	}while(continuar);

}

        
        




