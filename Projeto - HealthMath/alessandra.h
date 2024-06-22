//Fase I

//Header
void header();

//Talvez um futuro array com as op��es de menu para limpar um pouco o main

// Fun��o para calcular o Ind�ce de Massa Corporal 
float calcularIMC(float peso, float altura);

//Display a tabela do IMC
void tabelaIMC();

// Fun��o para calcular a Taxa Metab�lica Basal (quantidade de calorias necess�rias para o corpo em estado padr�o/repouso)
float calcularTMB(char sexo, float peso, float altura, int idade);

//Fun��o para imprimir as op��es do fator de atividade fisica
void imprimirAtividadeFisica();

// Fun��o para calcular a Necessidade Cal�rica Total (agora levando em conta o n�vel de atividade f�sica realizado pela pessoa)
float calcularNecessidadeCalorica(float tmb, float atividadeFisica);

//Futura fun��o em rela��o a necessidade calorica?
//Necessidade calorica na semana/mes
//Necessidade calorica variando conforme o nivel de atividade fisica em cada dia/mes

// Fun��o para calcular o consumo de �gua (taxa de hidrata��o necess�ria em conta do peso)
//35 ml a cada 1kg
float calcularConsumoAgua(float peso);

//Array para armazenar a ingest�o semanal de calorias de acordo com a dieta
void calcularIngestaoSemanal(float *ingestaoSemanal, float caloriasDiarias, int diaAtual, int numSemanas);

//Fun��o (novamente recursiva) para imprimir os resultados do array (index)
void imprimirIngestaoSemanal(float *ingestaoSemanal, int numSemanas, int index);

//Fun��o para imprimir resultados gerais, n�o incluindo a ingest�o semanal e o nome
void imprimirResumoResultados(float imc, float tmb, float necessidadeCalorica, float consumoAgua);

// Fun��o recursiva para calcular (padr�o de 100g) o valor cal�rico total dos alimentos inseridos no array
// 4 calorias para cada 1g de carboidrato e proteina
// 9 calorais para cada 1g de gordura
//Separar valores totais individuais em um array futuramente
float calcularValorCalorico(float *carboidratos, float *proteinas, float *gorduras, int numAlimentos, int index);

// Fun��o para imprimir o valor cal�rico total dos alimentos no array
void imprimirValorCaloricoTotal(float valorTotal);

//Fun��o para limpar a tela
void limpa();


//Fase II

//Fun��o para exibir as op��es de dieta
void exibirMenuDietas();

//Fun��o para exibir os perfils
void exibirPerfil(int idade, char sexo, float peso, float altura, float imc, float tmb);

//Fun��o escolha perfil
void exibirMenuPerfil();

//Dieta Vegetariana (n�o tem diferen�a entre os perfils (ta no masculino a principio), fiquei louca s� de pesquisar, na terceira fase ajusto melhor)
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

//Le as informa��es dos alimentos
int lerArquivoAlimentos(Alimento **alimentos, const char *nomeArquivo);

//Fun��o para imprimir os detalhes dos alimentos da dieta escolhida
void imprimirDetalhesAlimento(const Alimento *alimento);

//Fun��o apra imprimir os alimentos disponiveis para a dieta 
void imprimirListaAlimentos(Alimento *alimentos, int numAlimentos);

//Fun��o para mostrar a dieta escolhida (alimentos e informa��es dos mesmos)
void montarDieta(Alimento *alimentos, int numAlimentos);

