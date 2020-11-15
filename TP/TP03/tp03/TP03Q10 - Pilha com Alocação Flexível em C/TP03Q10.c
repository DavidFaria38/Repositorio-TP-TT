#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




/* ============================================================================= */
/* ===================== (Inicio) Definições Struct player ===================== */
/* ============================================================================= */

typedef struct Player {
	int id;
	int altura;
	int peso;
	int anoNascimento;
	char* nome;
	char* universidade;
	char* cidadeNascimento;
	char* estadoNascimento;
} Jogador; 

/* ================= (Start) Construtores ================= */
Jogador* newJogador(){
	Jogador* newJ = (Jogador*)malloc(sizeof(Jogador));

	newJ->nome             = (char*)malloc(80  * sizeof(char));
	newJ->universidade     = (char*)malloc(100 * sizeof(char));
	newJ->cidadeNascimento = (char*)malloc(100 * sizeof(char));
	newJ->estadoNascimento = (char*)malloc(100 * sizeof(char));

	newJ->id = -1;
	newJ->altura = -1;
	newJ->peso = -1;
	newJ->anoNascimento = -1;

	return newJ;
} // end newJogador()

Jogador* newJogadorContent(int id, char* nome, int alt, int peso, char* uni, int anoNasc, char* cidadeNasc, char* estadoNasc){
	Jogador* newJ = (Jogador*)malloc(sizeof(Jogador));

	newJ->nome             = (char*)malloc(80  * sizeof(char));
	newJ->universidade     = (char*)malloc(100 * sizeof(char));
	newJ->cidadeNascimento = (char*)malloc(100 * sizeof(char));
	newJ->estadoNascimento = (char*)malloc(100 * sizeof(char));

	newJ->id = id;
    newJ->altura = alt;
    newJ->peso = peso;
    newJ->anoNascimento = anoNasc;
    strcpy(newJ->nome, nome);
    strcpy(newJ->universidade, uni);
    strcpy(newJ->cidadeNascimento, cidadeNasc);
    strcpy(newJ->estadoNascimento, estadoNasc);
    return newJ;
} // end newJogadorContent()
/* ================= (End) Construtores ================= */


/**
 * - Função recebe Struct e impressa.
 * @param jogador - Struct a ser impressa.
 */
void imprimir(Jogador* jogador){
	printf("## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n", jogador->nome, jogador->altura, jogador->peso, jogador->anoNascimento, jogador->universidade, jogador->cidadeNascimento, jogador->estadoNascimento);
} // end imprimir()

/**
 * - Função cria nova instacia (clona) um jogador.
 * @param copy - Struct a ser copiada.
 * @return - Nova instacia de copy
 */
Jogador* clone(Jogador* copy){
	Jogador* tmp = newJogador();

	tmp->id = copy->id;
	tmp->altura = copy->altura;
	tmp->peso = copy->peso;
	tmp->anoNascimento = copy->anoNascimento;
	strcpy(tmp->nome, copy->nome);
	strcpy(tmp->universidade, copy->universidade);
	strcpy(tmp->cidadeNascimento, copy->cidadeNascimento);
	strcpy(tmp->estadoNascimento, copy->estadoNascimento);

	return tmp;
} // end clone

/* ================= (Start) Funcoes Ler ================= */

/**
 * - Função percorre por linha a procura de marcadores de cada elemento (virgulas).
 * @param line - Linha ser procurada.
 * @param indexMarkers - Array de inteiro com o index de cada marcador.
 */
void getVirgulas(char* line, int* indexMarkers){
	int i, count = 0;
	for(i = 1; i < strlen(line); i++)
		if(line[i] == ','){
			indexMarkers[count] = i;
			count++;
		} // end if
} // end getVirgulas()

int getIdFromLine(char* line){
	int i, count = 0;
	char temp;
	char* valueStr = (char*)malloc(4 * sizeof(char));
	for(i = 0; i < 4; i++){
		if(line[i] != ','){
			valueStr[count] = line[i];
			count++;	
		} else
			i = 4;
	} // end for
	return atoi(valueStr);
} // end getIdFromLine()
int getAlturaFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[1];
	int maior = indexMarker[2];
	char* valueStr = (char*)malloc(5 * sizeof(char));
	for(i = menor + 1; i < maior; i++){
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getAlturaLine()
int getPesoFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[2];
	int maior = indexMarker[3];
	char* valueStr = (char*)malloc(5 * sizeof(char));
	for(i = menor + 1; i < maior; i++){
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getPesoLine()
int getAnoNascimentoFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[4];
	int maior = indexMarker[5];
	char* valueStr = (char*)malloc(5 * sizeof(char));
	for(i = menor + 1; i < maior; i++){
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getAnoNascimentoLine()
char* getNomeFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[0];
	int maior = indexMarker[1];
	char* valueStr = (char*)malloc(80 * sizeof(char));
	for(i = menor + 1; i < maior; i++){
		//if(line[i] != '*'){  // remove os * da string
			valueStr[count] = line[i];
			count++;
		//} // end if
	} // end for
	return valueStr;
} // end getNomeLine()
char* getUniversidadeFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[3];
	int maior = indexMarker[4];
	char* valueStr = (char*)malloc(100 * sizeof(char));
	if((menor + 1) != maior){
		for(i = menor + 1; i < maior; i++){
			valueStr[count] = line[i];
			count++;
		} // end for
	} else
		strcpy(valueStr, "nao informado");
	return valueStr;
} // end getUniversidadeLine()
char* getCidadeNascimentoFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[5];
	int maior = indexMarker[6];
	char* valueStr = (char*)malloc(100 * sizeof(char));
	if((menor + 1) != maior){
		for(i = menor + 1; i < maior; i++){
		    valueStr[count] = line[i];
            count++;
        } // end for
    } else
         strcpy(valueStr, "nao informado");
	
	return valueStr;
} // end getCidadeNascimentoLine()
char* getEstadoNascimentoFromLine(char* line, int* indexMarker){
	int i, count = 0;
	int menor = indexMarker[6];
	int maior = strlen(line); 
	char* valueStr = (char*)malloc(100 * sizeof(char));
	
	for(i = menor + 1; i < maior; i++){
		if(line[i] != '\n' && line[i] != '\r'){	
			valueStr[count] = line[i];
			count++;
		} // end if
	} // end for

	if(strcmp(valueStr, "") == 0)
		strcpy(valueStr, "nao informado");

	return valueStr;
} // end getEstadoNascimentoLine()

/**
 * - Função recebe char* line que transforma linha em valores para Struct.
 * @param line - Linha a ser transformada.
 * @return Struct dos elementos da linha. 
 */
Jogador* makeJogador(char* line){
	int* indexMarkers = (int*)malloc(7*sizeof(int));
	getVirgulas(line, indexMarkers);
	Jogador* j = newJogador();

	j->id = getIdFromLine(line);
	j->altura = getAlturaFromLine(line, indexMarkers);
	j->peso = getPesoFromLine(line, indexMarkers);
	j->anoNascimento = getAnoNascimentoFromLine(line, indexMarkers);
	strcpy(j->nome, getNomeFromLine(line, indexMarkers));
	strcpy(j->universidade, getUniversidadeFromLine(line, indexMarkers));
	strcpy(j->cidadeNascimento, getCidadeNascimentoFromLine(line, indexMarkers));
	strcpy(j->estadoNascimento, getEstadoNascimentoFromLine(line, indexMarkers));

	return j;	
} // end makeJogador()

/**
 * - Função recebe inteiro idInput e percorre arquivo a procura do mesmo.
 * @param idInput - ID do elemento a ser procurado.
 * @return Struct com elementos da id procurado. 
 */
Jogador* ler(int idInput){
	char* file = strdup("/tmp/players.csv");
	int len = 300;
	bool idFound = false;
	char* line; // = (char*)malloc(len * sizeof(char));
	FILE* fr = fopen(file, "r");
	
	Jogador* jogador = newJogador();
	
	while(!idFound && !feof(fr)){
		line = (char*)malloc(len * sizeof(char));
		
		fgets(line, len, fr);	
		if(line != NULL && idInput == getIdFromLine(line)){
			idFound = true;	
		//	printf("%s", line);
		} // end if
	} // end while

	if(idFound == true)
		jogador = clone(makeJogador(line));
	else
		jogador = clone(ler(idInput - 1));
	
	return jogador;
} // end ler

/* ================= (End) Funcoes Ler ================= */


/* ========================================================================== */
/* ===================== (FIM) Definições Struct player ===================== */
/* ========================================================================== */

typedef struct CelulaSimples{
	Jogador* elemento;
	struct CelulaSimples* prox;
} Celula;

Celula* newCelula(Jogador* player){
	Celula* nova = (Celula*)malloc(sizeof(Celula));
	nova->elemento = clone(player);
	nova->prox = NULL;
	return nova;
} // end newCelula()


typedef struct PilhaDinamicaSimples{
	Celula* topo;
} Pilha;

Pilha newPilha(){
	Pilha nova;
	nova.topo = newCelula(newJogador());
	return nova;
} // end newPilha()

/**
 * - Funcao que retorna o tamanho (inteiro) de uma pilha.
 * 
 * @param pilha - lista dupla
 * @return int - tamanho da lista
 */
int tamanho(Pilha* pilha){
	int tam = 0;
	for(Celula* i = pilha->topo->prox; i != NULL; i = i->prox, tam++);
	return tam;
} // end tamanho()

void mostrarPilha_recursivo(Celula* i, int j){
	if(i != NULL){
		mostrarPilha_recursivo(i->prox, j-=1);
		printf("[%i] ", j); 
		imprimir(i->elemento);
	} // end if
} // end mostrarPilha_recursivo()

/**
 * Funcao que mostra na tela os jogadores na Pilha
 * @param Pilha - Pilha dupla
 */
void mostrarPilha(Pilha* pilha){
	mostrarPilha_recursivo(pilha->topo->prox, tamanho(pilha));
} // end mostrarPilha()

void inserir(Pilha* pilha, Jogador* player){
	Celula* tmp = newCelula(player);
	tmp->prox = pilha->topo->prox;
	pilha->topo->prox = tmp;
} // end inserir()

Jogador* remover(Pilha* pilha){
	Jogador* playerTmp;
	if(pilha->topo->prox == NULL){
		printf("ERRO: (R) Pilha nao esta populada\n");
	} else{
		Celula* celTmp = pilha->topo->prox;
		playerTmp = celTmp->elemento;
		pilha->topo->prox = celTmp->prox;
		celTmp = celTmp->prox = NULL;
	} // end else
	return playerTmp;
} // end Remover()


/* ========================================================================== */
/* ==================== (INICIO) Definições Struct player =================== */
/* ========================================================================== */


/**
 * - Função recebe String e verifica se ela é igual a "FIM".
 * @param str - String a ser manipulada.
 * @return true ou false, caso str seja igual a "FIM".
 */
bool isFIM(char* str){
	return(strcmp(str, "FIM") == 0);
} // end isFIM()

/**
 * Metodo retorna o codigo de comando de uma string.
 * 
 * @param line 
 * @return int 
 */
int getCodigo(char* line){
	int result = 0;

	if(line[0] == 'I'){
		result = 1;
	} else if(line[0] == 'R'){
		result = 2;
	} // end else

	// printf("Codigo: %s (%i)\n", line, result);

	return result;
} // end getCodigo()

/**
 * Metodo retorna a ID de uma string.
 * 
 * @param codigo 
 * @param line 
 * @return int 
 */
int getIdentidade(int codigo, char* line){
	int result = 0;
	if(codigo == 1){
		char* strLine = (char*)malloc(25 * sizeof(char));
		char* strId;

		strcpy(strLine, line);

		strId = strtok(strLine, " ");
		strId = strtok('\0' , " ");

		result = atoi(strId);

		free(strLine);
	} // end else

	return result;
} // end getIdentidade()

/**
 * Metodo que manipula e efetua as acoes na fila.
 * 
 * @param fila - fila a ser manipulada
 * @param codigo - codigo de comando
 * @param id - id a ser inserido
 * @param posicao - posicao da fila a ser inserida/removida
 */
void manipularPilha(Pilha* pilha, int codigo, int id){
	Jogador* tmp;
	switch (codigo){
	case 1:
		inserir(pilha, ler(id));
		break;
	case 2:
		tmp = remover(pilha);
		if(tmp != NULL)
			printf("(R) %s\n", tmp->nome);
		tmp = NULL;	
		break;
	
	default:
		break;
	} // end switch
} // end manipularPilha()

/**
 * - Função que lê a priemira parte da entrada padrão. 
 * @param fila - fila linear.
 */
void getPrimeiraEntrada(Pilha* Pilha){
	int idInt;
	char* idInputStr = (char*)malloc(8 * sizeof(char));

	scanf("%s", idInputStr);

	while(!isFIM(idInputStr)){
		idInt = atoi(idInputStr);
		
		// printf("%i \n", idInt);
		inserir(Pilha, ler(idInt));

		scanf("%s", idInputStr);
	} // end while
	free(idInputStr);
} // end getPrimeiraEntrada()

/**
 * - Função que lê a segunda parte da entrada padrão. 
 * @param fila - fila linear.
 */
void getSegundaEntrada(Pilha* pilha){
	int loop, id;
	int codigo = 0;
	char* inputStr = (char*)malloc(25 * sizeof(char));
	/* diagrama de codigos para comando: */ 
	// (I) Inserir = 1
	// (R) Remover = 2 

	getchar();
	scanf("%i", &loop);
	getchar();

	while(loop >= 0){
		fgets(inputStr, 25, stdin);

		codigo = getCodigo(inputStr);
		id = getIdentidade(codigo, inputStr);
		
		manipularPilha(pilha, codigo, id);

		loop--;
	} // end while

	free(inputStr);
} // end getSegundaEntrada()

int main(void){

	Pilha pilhaSimples = newPilha();
	Pilha* pilha = &pilhaSimples;

	getPrimeiraEntrada(pilha);
	getSegundaEntrada(pilha);

	mostrarPilha(pilha);

	return 0;
} // end main()








