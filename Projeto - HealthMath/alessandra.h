//Fase I

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


//Fase II

//Função para exibir as opções de dieta
void exibirMenuDietas();

//Função para exibir os perfils
void exibirPerfil(int idade, char sexo, float peso, float altura, float imc, float tmb);

//Função escolha perfil
void exibirMenuPerfil();

//Dieta Vegetariana (não tem diferença entre os perfils (ta no masculino a principio), fiquei louca só de pesquisar, na terceira fase ajusto melhor)
void montarDietaVegetariana(float tmb, float *resultado);

//Dieta Vegana
void montarDietaVegana(float tmb, float *resultado);

//Dieta Pescetariana
void montarDietaPescetariana(float tmb, float *resultado);

//Deita 'Normal'
void montarDietaNormal(float tmb, float *resultado);

//Fase III
//Struct dos alimentos
typedef struct {
    char nome[100];
    float calorias;
    float proteinas;
    float gorduras;
    float carboidratos;
} Alimento;

//Le as informações dos alimentos
int lerArquivoAlimentos(Alimento **alimentos, const char *nomeArquivo);

//Função para imprimir os detalhes dos alimentos da dieta escolhida
void imprimirDetalhesAlimento(const Alimento *alimento);

//Função apra imprimir os alimentos disponiveis para a dieta 
void imprimirListaAlimentos(Alimento *alimentos, int numAlimentos);

//Função para mostrar a dieta escolhida (alimentos e informações dos mesmos)
void montarDieta(Alimento *alimentos, int numAlimentos);

