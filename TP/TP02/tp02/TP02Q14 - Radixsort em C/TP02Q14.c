#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* ================= (Inicio) Definições Struct StatusAlgoritmo ================= */
typedef struct StatusOrdenacao
{
	int comp;
	int mov;
	clock_t start;
	clock_t end;
} StatusOrd;

StatusOrd *newStatusOrd()
{
	StatusOrd *newSO = (StatusOrd *)malloc(sizeof(StatusOrd));

	newSO->comp = 0;
	newSO->mov = 0;

	return newSO;
} // end newStatusOrd()

void startClock(StatusOrd *status) { status->start = clock(); }
void endClock(StatusOrd *status) { status->end = clock(); }

/**
 * - Função que grava em um arquivo o tempo de execução do algoritmo de ordenação, movimentações e comparações.
 * @param status - Struct contendo os dados para serem armazenados.
 * @param fileName - Nome do arquivo.
 */
double recordTime(StatusOrd *status, char *fileName)
{
	FILE *f = fopen(fileName, "w");
	double runTime = (double)(status->end - status->start) / CLOCKS_PER_SEC;
	fprintf(f, "%s\t%lf\t%i\t%i", "699415", runTime, status->comp, status->mov);
	fclose(f);
	return runTime;
} // end recordTime()
/* ================= (FIM) Definições Struct StatusAlgoritmo ================= */

/* ===================== (Inicio) Definições Struct player ===================== */
typedef struct Player
{
	int id;
	int altura;
	int peso;
	int anoNascimento;
	char *nome;
	char *universidade;
	char *cidadeNascimento;
	char *estadoNascimento;
} Jogador;

/* ================= (Start) Construtores ================= */
Jogador *newJogador()
{
	Jogador *newJ = (Jogador *)malloc(sizeof(Jogador));

	newJ->nome = (char *)malloc(80 * sizeof(char));
	newJ->universidade = (char *)malloc(100 * sizeof(char));
	newJ->cidadeNascimento = (char *)malloc(100 * sizeof(char));
	newJ->estadoNascimento = (char *)malloc(100 * sizeof(char));

	newJ->id = -1;
	newJ->altura = -1;
	newJ->peso = -1;
	newJ->anoNascimento = -1;

	return newJ;
} // end newJogador()

Jogador *newJogadorContent(int id, char *nome, int alt, int peso, char *uni, int anoNasc, char *cidadeNasc, char *estadoNasc)
{
	Jogador *newJ = (Jogador *)malloc(sizeof(Jogador));

	newJ->nome = (char *)malloc(80 * sizeof(char));
	newJ->universidade = (char *)malloc(100 * sizeof(char));
	newJ->cidadeNascimento = (char *)malloc(100 * sizeof(char));
	newJ->estadoNascimento = (char *)malloc(100 * sizeof(char));

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
void imprimir(Jogador *jogador)
{
	printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", jogador->id, jogador->nome, jogador->altura, jogador->peso, jogador->anoNascimento, jogador->universidade, jogador->cidadeNascimento, jogador->estadoNascimento);
} // end imprimir()

/**
 * - Função recebe dois Structs e copia um para o outro.
 * @param copyTo - Struct para ser copiada.
 * @param copy - Struct a ser copiada.
 */
void clone(Jogador *copyTo, Jogador *copy)
{
	copyTo->id = copy->id;
	copyTo->altura = copy->altura;
	copyTo->peso = copy->peso;
	copyTo->anoNascimento = copy->anoNascimento;
	strcpy(copyTo->nome, copy->nome);
	strcpy(copyTo->universidade, copy->universidade);
	strcpy(copyTo->cidadeNascimento, copy->cidadeNascimento);
	strcpy(copyTo->estadoNascimento, copy->estadoNascimento);
} // end clone

/* ================= (Start) Funcoes Ler ================= */

/**
 * - Função percorre por linha a procura de marcadores de cada elemento (virgulas).
 * @param line - Linha ser procurada.
 * @param indexMarkers - Array de inteiro com o index de cada marcador.
 */
void getVirgulas(char *line, int *indexMarkers)
{
	int i, count = 0;
	for (i = 1; i < strlen(line); i++)
		if (line[i] == ',')
		{
			indexMarkers[count] = i;
			count++;
		} // end if
} // end getVirgulas()

int getIdFromLine(char *line)
{
	int i, count = 0;
	char temp;
	char *valueStr = (char *)malloc(4 * sizeof(char));
	for (i = 0; i < 4; i++)
	{
		if (line[i] != ',')
		{
			valueStr[count] = line[i];
			count++;
		}
		else
			i = 4;
	} // end for
	return atoi(valueStr);
} // end getIdFromLine()
int getAlturaFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[1];
	int maior = indexMarker[2];
	char *valueStr = (char *)malloc(5 * sizeof(char));
	for (i = menor + 1; i < maior; i++)
	{
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getAlturaLine()
int getPesoFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[2];
	int maior = indexMarker[3];
	char *valueStr = (char *)malloc(5 * sizeof(char));
	for (i = menor + 1; i < maior; i++)
	{
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getPesoLine()
int getAnoNascimentoFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[4];
	int maior = indexMarker[5];
	char *valueStr = (char *)malloc(5 * sizeof(char));
	for (i = menor + 1; i < maior; i++)
	{
		valueStr[count] = line[i];
		count++;
	} // end for
	return atoi(valueStr);
} // end getAnoNascimentoLine()
char *getNomeFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[0];
	int maior = indexMarker[1];
	char *valueStr = (char *)malloc(80 * sizeof(char));
	for (i = menor + 1; i < maior; i++)
	{
		//if(line[i] != '*'){  // remove os * da string
		valueStr[count] = line[i];
		count++;
		//} // end if
	} // end for
	return valueStr;
} // end getNomeLine()
char *getUniversidadeFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[3];
	int maior = indexMarker[4];
	char *valueStr = (char *)malloc(100 * sizeof(char));
	if ((menor + 1) != maior)
	{
		for (i = menor + 1; i < maior; i++)
		{
			valueStr[count] = line[i];
			count++;
		} // end for
	}
	else
		strcpy(valueStr, "nao informado");
	return valueStr;
} // end getUniversidadeLine()
char *getCidadeNascimentoFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[5];
	int maior = indexMarker[6];
	char *valueStr = (char *)malloc(100 * sizeof(char));
	if ((menor + 1) != maior)
	{
		for (i = menor + 1; i < maior; i++)
		{
			valueStr[count] = line[i];
			count++;
		} // end for
	}
	else
		strcpy(valueStr, "nao informado");

	return valueStr;
} // end getCidadeNascimentoLine()
char *getEstadoNascimentoFromLine(char *line, int *indexMarker)
{
	int i, count = 0;
	int menor = indexMarker[6];
	int maior = strlen(line);
	char *valueStr = (char *)malloc(100 * sizeof(char));

	for (i = menor + 1; i < maior; i++)
	{
		if (line[i] != '\n' && line[i] != '\r')
		{
			valueStr[count] = line[i];
			count++;
		} // end if
	}	  // end for

	if (strcmp(valueStr, "") == 0)
		strcpy(valueStr, "nao informado");

	return valueStr;
} // end getEstadoNascimentoLine()

/**
 * - Função recebe char* line que transforma linha em valores para Struct.
 * @param line - Linha a ser transformada.
 * @return Struct dos elementos da linha. 
 */
Jogador *makeJogador(char *line)
{
	int *indexMarkers = (int *)malloc(7 * sizeof(int));
	getVirgulas(line, indexMarkers);
	Jogador *j = newJogador();

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
Jogador *ler(int idInput)
{
	char *file = strdup("/tmp/players.csv");
	int len = 300;
	bool idFound = false;
	char *line; // = (char*)malloc(len * sizeof(char));
	FILE *fr = fopen(file, "r");

	Jogador *jogador = newJogador();

	while (!idFound && !feof(fr))
	{
		line = (char *)malloc(len * sizeof(char));

		fgets(line, len, fr);
		if (line != NULL && idInput == getIdFromLine(line))
		{
			idFound = true;
			//	printf("%s", line);
		} // end if
	}	  // end while

	if (idFound == true)
		clone(jogador, makeJogador(line));
	else
		clone(jogador, ler(idInput - 1));

	return jogador;
} // end ler

/* ================= (End) Funcoes Ler ================= */
/* ===================== (FIM) Definições Struct player ===================== */

/**
 * - Função recebe String e verifica se ela é igual a "FIM".
 * @param str - String a ser manipulada.
 * @return true ou false, caso str seja igual a "FIM".
 */
bool isFIM(char *str)
{
	return (strcmp(str, "FIM") == 0);
} // end isFIM()

/**
 * - Função que realiza a troca de elementos de dois Struct. 
 * @param player - array de Struc que sera feita a troca.
 * @param menor - index do array player qual sera feita a troca.
 * @param i - index do array player qual sera feita a troca.
 */
void swap(Jogador **player, int menor, int i)
{
	Jogador *temp = newJogador();

	clone(temp, player[i]);
	clone(player[i], player[menor]);
	clone(player[menor], temp);
} // end swap()

/**
 * - Função que lê a priemira parte da entrada padrão e os armazena. 
 * @param player - Array de Struct a ser armazenado.
 * @return - Numero inteiro com a quantidade de entrada lidas.
 */
int getPrimeiraEntrada(Jogador **player)
{
	int idInt, n = 0;
	char *idInputStr = (char *)malloc(8 * sizeof(char));

	scanf("%s", idInputStr);

	// entrada de "objetos"
	while (!isFIM(idInputStr))
	{
		idInt = atoi(idInputStr);

		player[n] = ler(idInt);
		//imprimir(player[n]);
		n++;

		scanf("%s", idInputStr);
	} // end while

	free(idInputStr);
	return n;
} // end getPrimeiraEntrada()

int findLargestNum(Jogador **player, int size, StatusOrd *status)
{
	int i, largestNum = -1;

	for (i = 0; i < size; i++){
		if (player[i]->id > largestNum){
			largestNum = player[i]->id;
			status->mov += 1;
		} // end if
		status->comp += 1;
	} // end for

	return largestNum;
} // end findLargestNum()

/**
 * - Função realiza ordenação radixsort de players tendo como chave primaria o ano de nascimento do jogador.
 * @param player - Array de Struct contendo jogadores.
 * @param size - Quantidade de jogadores contido em player
 * @param status - Struct usada para armazenar comparações e movimentações
 */
void radixsort(Jogador **player, int size, StatusOrd *status)
{
	// Base 10 is used
	int i;
	int significantDigit = 1;
	int largestNum = findLargestNum(player, size, status);
	Jogador *semiSorted[size]; //= (Jogador*)malloc(size * sizeof(Jogador));

	for (int i = 0; i < size; i++){
		Jogador *tmp = newJogador();
		semiSorted[i] = tmp;
		status->mov += 1;
	} // end for

	// Loop until we reach the largest significant digit
	while (largestNum / significantDigit > 0){
		int bucket[10] = {0};
		status->mov += 1;

		// Counts the number of "keys" or digits that will go into each bucket
		for (i = 0; i < size; i++){
			bucket[(player[i]->id / significantDigit) % 10]++;
			status->mov += 2;
		} // end for

		for (i = 1; i < 10; i++){
			bucket[i] += bucket[i - 1];
			status->mov += 2;
		} // end for

		// Use the bucket to fill a "semiSorted" array
		for (i = size - 1; i >= 0; i--){
			clone(semiSorted[--bucket[(player[i]->id / significantDigit) % 10]], player[i]);
			status->mov += 6;
		} // end for
		for (i = 0; i < size; i++){
			clone(player[i], semiSorted[i]);
			status->mov += 3;
		} // end for

		// Move to next significant digit
		significantDigit *= 10;
	} // end while
} // end radixsort()

int main(void)
{
	int nPlayer;

	// for(int i = 100000; i > 0; i/=10)
	// 	printf("%i mod %i \t=%i\n", 12345, i, 123456%i);

	StatusOrd *status = newStatusOrd();
	Jogador *player[500];

	nPlayer = getPrimeiraEntrada(player);

	startClock(status);
	radixsort(player, nPlayer, status);
	endClock(status);

	for (int i = 0; i < nPlayer; i++)
		imprimir(player[i]);

	recordTime(status, strdup("699415_radixsort.txt"));

	return 0;
} // end main()
