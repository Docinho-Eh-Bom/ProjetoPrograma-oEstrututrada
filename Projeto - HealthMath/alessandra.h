//Header
void header();

//Talvez um futuro array com as opções de menu para limpar um pouco o main

// Função para calcular o Indíce de Massa Corporal 
float calcularIMC(float peso, float altura);

//Display a tabela do IMC
void tabelaIMC();

// Função para calcular a Taxa Metabólica Basal (quantidade de calorias necessárias para o corpo em estado padrão/repouso)
float calcularTMB(char sexo, float peso, float altura, int idade);

//Função para imprimir as opções do fator de atividade fisica
void imprimirAtividadeFisica();

// Função para calcular a Necessidade Calórica Total (agora levando em conta o nível de atividade física realizado pela pessoa)
float calcularNecessidadeCalorica(float tmb, float atividadeFisica);

//Futura função em relação a necessidade calorica?
//Necessidade calorica na semana/mes
//Necessidade calorica variando conforme o nivel de atividade fisica em cada dia/mes

// Função para calcular o consumo de água (taxa de hidratação necessária em conta do peso)
//35 ml a cada 1kg
float calcularConsumoAgua(float peso);

//Array para armazenar a ingestão semanal de calorias de acordo com a dieta
void calcularIngestaoSemanal(float *ingestaoSemanal, float caloriasDiarias, int diaAtual, int numSemanas);

//Função (novamente recursiva) para imprimir os resultados do array (index)
void imprimirIngestaoSemanal(float *ingestaoSemanal, int numSemanas, int index);

//Função para imprimir resultados gerais, não incluindo a ingestão semanal e o nome
void imprimirResumoResultados(float imc, float tmb, float necessidadeCalorica, float consumoAgua);

// Função recursiva para calcular (padrão de 100g) o valor calórico total dos alimentos inseridos no array
// 4 calorias para cada 1g de carboidrato e proteina
// 9 calorais para cada 1g de gordura
//Separar valores totais individuais em um array futuramente
float calcularValorCalorico(float *carboidratos, float *proteinas, float *gorduras, int numAlimentos, int index);

// Função para imprimir o valor calórico total dos alimentos no array
void imprimirValorCaloricoTotal(float valorTotal);

//Função para limpar a tela
void limpa();
