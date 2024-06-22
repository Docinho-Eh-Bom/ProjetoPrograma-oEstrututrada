#include <stdio.h>
#include <stdlib.h>
#include "alessandra.h"

//Fase I
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

    printf("Semana %d: %.2f calorias\n\n", index + 1, *(ingestaoSemanal + index));
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

    
    return valorCaloricoAlimento + calcularValorCalorico(carboidratos, proteinas, gorduras, numAlimentos, index + 1);
}

void imprimirValorCaloricoTotal(float valorTotal){
    printf("\nValor calorico total dos alimentos: %.2f calorias\n", valorTotal);
}

void limpa(){
	system("cls");
}

//Fase II

void exibirMenuDietas(){
    printf("\nEscolha o tipo de dieta digitando o seu nome:\n");
    printf("1 - Vegetariana\n");
    printf("2 - Vegana\n");
    printf("3 - Pescetariana\n");
    printf("4 - Normal\n");
    printf("5 - Montar\n");
    printf("0 - Sair\n");
}

void exibirMenuPerfil(){
    printf("Escolha o perfil:\n");
    printf("1 - Perfil 1 Masculino medio\n");
    printf("2 - Perfil 2 Feminino medio\n");
    printf("0 - Sair\n");
}


void exibirPerfil(int idade, char sexo, float peso, float altura, float imc, float tmb){
	printf("\nIdade: %d\n",idade);
	printf("Sexo: %c\n",sexo);
	printf("Peso: %.2f\n",peso);
	printf("Altura: %.2f\n",altura);
	printf("IMC: %.2f\n", imc);
	printf("Taxa Metabolica Basal: %.3f calorias\n\n", tmb);
	
}



void montarDietaVegetariana(float tmb, float *resultado){
    printf("Dieta Vegetariana:\n");
    printf("Todos os valores sao uma simulacao da realidade!\n\n");

    //Café da manhã
    printf("Cafe da manha:\n");
    printf("Aveia com frutas e sementes de chia\n");
    printf("Total de calorias: 425 calorias\n");
    float caloriasCafeDaManha = 425.0; 
    float percentCafeDaManha = (caloriasCafeDaManha * 100.0) / tmb;
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentCafeDaManha);

    //Almoço
    printf("Almoco:\n");
    printf("Salada de quinoa, abacate, grao-de-bico, espinafre,\n tomate, pepino e molho de tahine(semente de gergelim)\n");
    printf("Total de calorias: 432 calorias\n");
    float caloriasAlmoco = 432.0;
    float percentAlmoco = (caloriasAlmoco * 100.0) / tmb;
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentAlmoco);

    //Fome da tarde
    printf("Lanche da tarde:\n");
    printf("Iogurte grego com nozes e mel\n");
    printf("Total de calorias: 214 calorias\n");
    float caloriasLancheTarde = 214.0; 
    float percentLancheTarde = (caloriasLancheTarde * 100.0) / tmb;
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheTarde);

    //Jantar
    printf("Jantar:\n");
    printf("Tofu grelhado com legumes e arroz integral\n");
    printf("Total de calorias: 475-500 calorias\n");
    float caloriasJantar = 488.0;
    float percentJantar = (caloriasJantar * 100.0) / tmb;
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentJantar);
    
    // Total
    printf("Resumo Geral:\n");
    float caloriasTotais = caloriasCafeDaManha + caloriasAlmoco + caloriasLancheTarde + caloriasJantar;
    float percentTotal = (caloriasTotais * 100.0) / tmb;
    printf("Total de calorias diarias estimado: %.2f calorias\n", caloriasTotais);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentTotal);
    
    *resultado = caloriasTotais;
}

void montarDietaVegana(float tmb, float *resultado){
    printf("Dieta Vegana:\n");
    printf("Todos os valores sao uma simulacao da realidade!\n\n");

    //Café da Manhã
    printf("Cafe da Manha:\n");
    printf("Aveia cozida com leite de amendoa \n");
    float caloriasCafeDaManha = 342.0;
    float percentCafeDaManha = (caloriasCafeDaManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasCafeDaManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentCafeDaManha);

    //Fome da Manhã
    printf("Lanche da Manha:\n");
    printf("Iogurte de soja com framboesas\n");
    float caloriasLancheManha = 150.0;
    float percentLancheManha = (caloriasLancheManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheManha);

    //Almoço
    printf("Almoco:\n");
    printf("Quinua cozida com feijao-preto, brocolis cozido e \nsalada com folhas verdes, tomate, pepino e azeite de oliva\n");
    float caloriasAlmoco = 330.0;
    float percentAlmoco = (caloriasAlmoco * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasAlmoco);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentAlmoco);

    //Fome da Tarde
    printf("Lanche da Tarde:\n");
    printf("Mix de oleaginosas (amêndoas, nozes, castanhas)\n");
    float caloriasLancheTarde = 180.0;
    float percentLancheTarde = (caloriasLancheTarde * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheTarde);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheTarde);

    //Jantar
    printf("Jantar:\n");
    printf("Hamburguer vegano com batata-doce assada \ne salada com folhas verdes e azeite de oliva\n");
    float caloriasJantar = 550.0;
    float percentJantar = (caloriasJantar * 100.0) / tmb;
    printf("Total de calorias do jantar: %.2f calorias\n", caloriasJantar);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentJantar);

    //Total
    float caloriasTotais = caloriasCafeDaManha + caloriasLancheManha + caloriasAlmoco + caloriasLancheTarde + caloriasJantar;
    float percentTotal = (caloriasTotais * 100.0) / tmb;
    printf("Resumo Geral:\n");
    printf("Total de calorias diarias estimado: %.2f calorias\n", caloriasTotais);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentTotal);
    
    *resultado = caloriasTotais;
}


void montarDietaPescetariana(float tmb, float *resultado){
	printf("Dieta Pescetariana:\n");
    printf("Todos os valores sao uma simulacao da realidade!\n\n");

    //Café da Manhã
    printf("Cafe da Manha:\n");
    printf("Omelete de ovos (2 ovos) com espinafre e tomate\n");
    float caloriasCafeDaManha = 330.0;
    float percentCafeDaManha = (caloriasCafeDaManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasCafeDaManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentCafeDaManha);

    //Fome da Manhã
    printf("Lanche da Manha:\n");
    printf("Uma banana e meia \n");
    float caloriasLancheManha = 133.5;
    float percentLancheManha = (caloriasLancheManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheManha);

    //Almoço
    printf("Almoco:\n");
    printf("File de salmao grelhado com quinoa cozida e broccolis cozidos \n");
    float caloriasAlmoco = 420.0;
    float percentAlmoco = (caloriasAlmoco * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasAlmoco);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentAlmoco);

    //Fome da Tarde
    printf("Lanche da Tarde:\n");
    printf("Duas macas\n");
    float caloriasLancheTarde = 104.0;
    float percentLancheTarde = (caloriasLancheTarde * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheTarde);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheTarde);

    //Jantar
    printf("Jantar:\n");
    printf("Atum com salada de folhas verdes e molho a base de azeite de oliva e quinoa cozida\n");
    float caloriasJantar = 340.0;
    float percentJantar = (caloriasJantar * 100.0) / tmb;
    printf("Total de calorias do jantar: %.2f calorias\n", caloriasJantar);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentJantar);

    //Total
    float caloriasTotais = caloriasCafeDaManha + caloriasLancheManha + caloriasAlmoco + caloriasLancheTarde + caloriasJantar;
    float percentTotal = (caloriasTotais * 100.0) / tmb;
    printf("Resumo Geral:\n");
    printf("Total de calorias diarias estimado: %.2f calorias\n", caloriasTotais);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentTotal);
    
    *resultado = caloriasTotais;
}

void montarDietaNormal(float tmb, float *resultado){
	printf("Dieta 'Normal':\n");
     printf("Todos os valores sao uma simulacao da realidade!\n\n");

    // Café da Manhã
   	printf("Cafe da Manha:\n");
    printf("Omelete de ovos (2 ovos) com espinafre e tomate\n");
    float caloriasCafeDaManha = 330.0;
    float percentCafeDaManha = (caloriasCafeDaManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasCafeDaManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentCafeDaManha);

    // Lanche da Manhã
    printf("Lanche da Manha:\n");
    printf("3 peras\n");
    float caloriasLancheManha = 151.0;
    float percentLancheManha = (caloriasLancheManha * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheManha);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheManha);

    // Almoço
    printf("Almoco:\n");
    printf("Peito de frango grelhado com quinua cozida, brocolis cozidos \ne salada com folhas verdes, tomate, pepino e azeite de oliva\n");
    float caloriasAlmoco = 510.0;
    float percentAlmoco = (caloriasAlmoco * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasAlmoco);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentAlmoco);

    // Lanche da Tarde
    printf("Lanche da Tarde:\n");
    printf("2 abacates\n");
    float caloriasLancheTarde = 320.0;
    float percentLancheTarde = (caloriasLancheTarde * 100.0) / tmb;
    printf("Total de calorias: %.2f calorias\n", caloriasLancheTarde);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentLancheTarde);

    // Jantar
    printf("Jantar:\n");
    printf("Salmao grelhado, abobrinha grelhada e quinua cozida \n");
    float caloriasJantar = 474.0;
    float percentJantar = (caloriasJantar * 100.0) / tmb;
    printf("Total de calorias do jantar: %.2f calorias\n", caloriasJantar);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentJantar);

    // Total diário
    float caloriasTotais = caloriasCafeDaManha + caloriasLancheManha + caloriasAlmoco + caloriasLancheTarde + caloriasJantar;
    float percentTotal = (caloriasTotais * 100.0) / tmb;
    printf("Resumo Geral:\n");
    printf("Total de calorias diarias estimado: %.2f calorias\n", caloriasTotais);
    printf("Percentagem das calorias da TMB: %.2f%%\n\n", percentTotal);
    
    *resultado = caloriasTotais;
}

//Fase III
int lerArquivoAlimentos(Alimento **alimentos, const char *nomeArquivo){
	int i;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(!arquivo){
        printf("Erro ao abrir o arquivo de alimentos");
        return 0;
    }

    int numTotalAlimentos = 0;
    char linha[256];
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        numTotalAlimentos++;
    }

    *alimentos = malloc(sizeof(Alimento) * numTotalAlimentos);
    if (!*alimentos) {
        printf("Erro ao alocar memoria para os alimentos");
        fclose(arquivo);
        return 0;
    }

    fseek(arquivo, 0, SEEK_SET);

    for(i = 0; i < numTotalAlimentos; i++){
        fscanf(arquivo, "%99s%f%f%f%f", (*alimentos)[i].nome, &(*alimentos)[i].calorias, &(*alimentos)[i].proteinas, &(*alimentos)[i].gorduras, &(*alimentos)[i].carboidratos);
    }

    fclose(arquivo);
    return numTotalAlimentos;
}

void imprimirDetalhesAlimento(const Alimento *alimento){
    printf("Detalhes do Alimento:\n");
    printf("Nome: %s\n", alimento->nome);
    printf("Calorias: %.2f\n", alimento->calorias);
    printf("Proteinas: %.2f\n", alimento->proteinas);
    printf("Gorduras: %.2f\n", alimento->gorduras);
    printf("Carboidratos: %.2f\n", alimento->carboidratos);
}

void imprimirListaAlimentos(Alimento *alimentos, int numAlimentos){
	int i;
    printf("\nLista de Alimentos Disponiveis:\n\n");
    for(i = 0; i < numAlimentos; i++){
        printf("%s\n", alimentos[i].nome);
    }
}

void montarDieta(Alimento *alimentos, int numAlimentos){
	int i;
    char escolha[100];
    Alimento *dietaEscolhida = malloc(sizeof(Alimento) * numAlimentos);
    int numDieta = 0;

    while (1) {
        scanf("%99s", escolha);
        if (stricmp(escolha, "fim") == 0) {
            break;
}

        int encontrado = 0;
        for (i = 0; i < numAlimentos; i++) {
            if (stricmp(escolha, alimentos[i].nome) == 0) {
                dietaEscolhida[numDieta++] = alimentos[i];
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Alimento nao encontrado. Tente novamente.\n");
        }
    }
	
	limpa();
	
	if(numDieta > 0){
			printf("\nDieta Escolhida:\n");
	    for(i = 0; i < numDieta; i++){
	        imprimirDetalhesAlimento(&dietaEscolhida[i]);
	        printf("\n");
	    }
	}else{
		printf("Nenhum alimento escolhido na dieta.\n\n");
	}
    

    free(dietaEscolhida);
}

