/**
 * - Class para gravar valores de movimentações e comparações.
 */
class RecordAlgoritmo{
	private int comp;
	private int mov;
	private double start;
	private double end;

/* ================= Construtores ================= */
	public RecordAlgoritmo(){
		mov = comp = 0;
	} // end RecordAlgoritmo()

/* ================= Metodos get ================= */
	public int getCmp(){return this.comp;}
	public int getMov(){return this.mov;}
	
/* ================= Metodos set ================= */
	public void sumCmp(int value){this.comp += value;}
	public void sumMov(int value){this.mov += value;}

/* ================= Metodos time ================= */
	public void startCurrentTime(){this.start = System.currentTimeMillis(); } 
	public void endCurrentTime(){this.end = System.currentTimeMillis(); }
	
/* ================================================ */
	/**
	 * - Metodo que grava em um arquivo o tempo de execução do algoritmo de ordenação, movimentações e comparações.
	 * @param fileWrite - Nome do arquivo.
	 */
	public void recordTime(String fileWrite){
		Arq.openWrite(fileWrite);
		Arq.println("699415\t" + (end-start)/1000 + "\t" + this.comp + "\t" + this.mov);
		Arq.close();
	} // end recordTime()
} // end recordAlgoritmo

class Jogador{
	private int id;
	private int altura;
	private int peso;
	private int anoNascimento;
	private String nome;
	private String universidade;
	private String cidadeNascimento;
	private String estadoNascimento;

/* ================= Construtores ================= */
	public Jogador(){
		this.id     = -1;
		this.altura = -1;
		this.peso   = -1;
		this.anoNascimento = -1;
		this.nome = "";
		this.universidade = "";
		this.cidadeNascimento = "";
		this.estadoNascimento = "";
	} // end Jogador()

	public Jogador(int id, String nome, int altura, int peso, int anoNasc, String uni, String cidadeNasc, String estadoNasc){
		this.id     = id;
		this.altura = altura;
        this.peso   = peso;
        this.anoNascimento = anoNasc;
        this.nome = nome;
        this.universidade = uni;
        this.cidadeNascimento = cidadeNasc;
        this.estadoNascimento = estadoNasc;
	} // end Jogador()

/* ================= Metodos get ================= */
	public int getId(){return this.id;}
	public int getAltura(){return this.altura;}
	public int getPeso(){return this.peso;}
	public int getAnoNascimento(){return this.anoNascimento;}
	public String getNome(){return this.nome;}
	public String getUniversidade(){return this.universidade;}
	public String getCidadeNascimento(){return this.cidadeNascimento;}
	public String getEstadoNascimento(){return this.estadoNascimento;}

/* ================= Medotos set ================= */	
	public void setId(int id){this.id = id;}
    public void setAltura(int alt){this.altura = alt;}
    public void setPeso(int peso){this.peso = peso;}
    public void setAnoNascimento(int anoNasc){this.anoNascimento = anoNasc;}
    public void setNome(String nome){this.nome = nome;}
    public void setUniversidade(String uni){this.universidade = uni;}
    public void setCidadeNascimento(String cidadeNasc){this.cidadeNascimento = cidadeNasc;}
    public void setEstadoNascimento(String estadoNasc){this.estadoNascimento = estadoNasc;}

/* ================= Metodo clone ================= */
	/**
	  * - Clone dados do obj parametro para this.
	 */
	public Jogador clone(Jogador obj){
		Jogador tmp = new Jogador();
		tmp.id     = obj.getId();
        tmp.altura = obj.getAltura();
        tmp.peso   = obj.getPeso();
        tmp.anoNascimento = obj.getAnoNascimento();
        tmp.nome = obj.getNome();
        tmp.universidade = obj.getUniversidade();
        tmp.cidadeNascimento = obj.getCidadeNascimento();
		tmp.estadoNascimento = obj.getEstadoNascimento();
		return tmp;
	} // end clone()

/* ================= Metodo imprimir ================= */
	/**
	  * - Imprime todos elementos contidos no obejeto.
	  */
	public void imprimir(){
		System.out.printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", this.id, this.nome, this.altura, this.peso, this.anoNascimento, this.universidade, this.cidadeNascimento, this.estadoNascimento);
	} // end imprimir()

/* ============== (Start) ler ============== */
	/**
	 * - Metodo que retorna um array com os index dos marcadores dos elementos de uma linha
	 * @param line - Linha a ser manipulada.
	 * @return Array com os index dos marcadores dos elementos.
	 */
	static int[] getVirgulas(String line){
		int[] indexVirg = new int[7];
		for(int i = 0; i < indexVirg.length; i++){
			if(i == 0)
				indexVirg[i] = line.indexOf(',');
			else
				indexVirg[i] = line.indexOf(',', indexVirg[i-1] + 1);
			//MyIO.print(indexVirg[i] + " ");
		} // end for		
		return indexVirg;
	} // end getVirgulas()

	/**
	 * - Metodo que retorna o id em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	public static int getIdFromLine(String fileLine){
		String strId = "";
		
		for(int i = 0; i < 4; i++){
			if(fileLine.charAt(i) != ',')
				strId += fileLine.charAt(i);
			else
				i = 4;
		} // end for
		return Integer.parseInt(strId); 
	} // end getIdFromLine()

	/**
	 * - Metodo que retorna o nome em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static String getNomeFromLine(String line, int[] indexMarker){
		int i = indexMarker[0] + 1;
		String str = "";
		while(i < indexMarker[1]){
			str += line.charAt(i);
			i++;
		} // end while
		
		if(str.equals(""))
			str += "nao informado";

		return str;
	} // end getIdFromLine()
	
	/**
	 * - Metodo que retorna o altura em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static int getAlturaFromLine(String line, int[] indexMarker){
		int i = indexMarker[1] + 1;
		String str = "";
		while(i < indexMarker[2]){
			str += line.charAt(i);
			i++;
		} // end while
		
		return Integer.parseInt(str);
   	} // end getIAlturaFromLine()

	/**
	 * - Metodo que retorna o peso em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static int getPesoFromLine(String line, int[] indexMarker){
		int i = indexMarker[2] + 1;
		String str = "";
		while(i < indexMarker[3]){
			str += line.charAt(i);
			i++;
		} // end while
		
		return Integer.parseInt(str);
   	} // end getIPesoFromLine()

	/**
	 * - Metodo que retorna o Ano de Nascimento em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static int getAnoNascimentoFromLine(String line, int[] indexMarker){
		int i = indexMarker[4] + 1;
		String str = "";
		while(i < indexMarker[5]){
			str += line.charAt(i);
			i++;
		} // end while
		
		return Integer.parseInt(str);
   	} // end getAnoNascimentoFromLine()

	/**
	 * - Metodo que retorna a Universidade em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static String getUniversidadeFromLine(String line, int[] indexMarker){
		int i = indexMarker[3] + 1; 
		String str = "";
		
		while(i < indexMarker[4]){
			str += line.charAt(i);
			i++;
		} // end while
		
		if(str.equals(""))
			str += "nao informado";
		
		return str;
   	} // end getUniversidadeFromLine()

	/**
	 * - Metodo que retorna a Cidade de Nascimento em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static String getCidadeNascimentoFromLine(String line, int[] indexMarker){
		int i = indexMarker[5] + 1;
		String str = "";

		while(i < indexMarker[6]){
			str += line.charAt(i);
			i++;
		} // end while
		
		if(str.equals(""))
			str += "nao informado";
		
		return str;
   	} // end getCidadeNascimentoFromLine()

	/**
	 * - Metodo que retorna o Estado de Nascimento em uma linha.
	 * @param line - Linha a ser pego o elemento desejado.
	 * @param indexMarker - Index dos marcadores dos elementos da linha 
	 * @return O elemento desejado
	 */
	static String getEstadoNascimentoFromLine(String line, int[] indexMarker){
		int i = indexMarker[6] + 1;
		String str = "";
		while(i < line.length()){
			str += line.charAt(i);
			i++;
		} // end while
		
		if(str.equals(""))
			str += "nao informado";
		
		return str ;
   	} // end getEstadoNascimentoFromLine()

	/**
	* - Metodo que procura em um arquivo o ID de um jogador e cria um objeto Jogador para o mesmo
	* @param idInput - Id do jogador
	* @param fileName - Diretorio do arquivo
	*/
	public void ler(int idInput){
		int idFile = 0;
		String fileLine = "", fileName = "/tmp/players.csv";
		boolean idFound = false;

		idFound = false;

		Arq.openRead(fileName);
		Arq.readLine();

		while(idFound == false && Arq.hasNext()){
			fileLine = Arq.readLine();
	
			idFile = Jogador.getIdFromLine(fileLine); 
			if(idFile == idInput)
				idFound = true;
		} // end while
		
		Arq.close();

		if(idFound == true)
			makeJogador(fileLine);
		else
			ler(idInput - 1);
			
		
	} // end ler()

/* ============== (End) ler ============== */
	/**
	 * - Metodo que seleciona cada elemento de uma String e os passa para um objeto Jogador
	 * @param fileLine
	 */
	void makeJogador(String fileLine){
		int[] indexMarker = getVirgulas(fileLine);
		
		this.setId(getIdFromLine(fileLine));
		this.setNome(getNomeFromLine(fileLine, indexMarker));
		this.setAltura(getAlturaFromLine(fileLine, indexMarker));
		this.setPeso(getPesoFromLine(fileLine, indexMarker));
		this.setAnoNascimento(getAnoNascimentoFromLine(fileLine, indexMarker));
		this.setUniversidade(getUniversidadeFromLine(fileLine, indexMarker));
		this.setCidadeNascimento(getCidadeNascimentoFromLine(fileLine, indexMarker));
		this.setEstadoNascimento(getEstadoNascimentoFromLine(fileLine, indexMarker));
	} // end makeJogador()
} // end Jogador


class TP02Q09{
	/**
	 * - Metodo verifica se String é igual a "FIM".
	 * @param s
	 * @return true ou false caso String seja igual a "FIM"
	 */
	static boolean isFIM(String s){
		return(s.equals("FIM"));
	} // end isFIM()

	/**
	 * - Metodo que imprime todos objetos dentro do array.
	 * @param player - Array de objetos.
	 * @param n - Tamanho do array.
	 */
	static void printPlayers(Jogador[] player, int n){
		for(int i = 0; i < n; i++)
			player[i]. imprimir();
	} // end printPlayers()

	/**
	 * - Metodo que troca de posicao dois elementos de um array.
	 * @param player - Array de Jogador a ser manipulado
	 * @param a - index a
	 * @param b - index b
	 */
	static void swap(Jogador []player, int a, int b){
		Jogador tmp = new Jogador();
		tmp       = tmp.clone(player[a]);
		player[a] = player[a].clone(player[b]);
		player[b] = player[b].clone(tmp);
	} // end swap()


	/**
	 * - Metodo para pegar a primeira parte da entrada, realiza o registo dos jogadores.
	 * @param player - Array de objeto
	 * @return Valor inteiro representando a quantidade de registros realizados.
	 */
	static int getPrimeiraEntrada(Jogador[] player){
		int id, n = 0;
		String input = "";

		input = MyIO.readLine();
		while(!isFIM(input)){
			id = Integer.parseInt(input);	

			player[n] = new Jogador();

			player[n].ler(id);
			//player[iPlayer].imprimir();
			n++;
			
			input = MyIO.readLine();
		} // end while
		return n;
	} // end getPrimeira Entrada()

	static void constroi(Jogador []player, int tamHeap, RecordAlgoritmo record){
		for(int i = tamHeap; (i > 1) && (player[i].getAltura() > player[i/2].getAltura() || 
										 ((player[i].getAltura() == player[i/2].getAltura()) && 
										  (player[i].getNome().compareTo(player[i/2].getNome()) > 0))); i /= 2){
			swap(player, i, i/2);
			record.sumMov(3);
			record.sumCmp(3);
		} // end for
	} // end constroi()

	static int getMaiorFilho(Jogador []player, int i, int tamHeap, RecordAlgoritmo record){
		int filho;
		if( (2*i == tamHeap) || 
			((player[2*i].getAltura() > player[2*i+1].getAltura()) || 
			 ((player[2*i].getAltura() == player[2*i+1].getAltura()) && 
			  (player[2*i].getNome().compareTo(player[2*i+1].getNome()) > 0))) ){
			filho = 2*i;
		} else {
			filho = 2*i + 1;
		} // end else
		record.sumCmp(3);
		return filho;
	} // end getMaiorFilho()

	static void reconstroi(Jogador []player, int tamHeap, RecordAlgoritmo record){
		int i = 1;
		while(i <= (tamHeap/2)){
			int filho = getMaiorFilho(player, i, tamHeap, record);
			if( (player[i].getAltura() < player[filho].getAltura()) || 
				((player[i].getAltura() == player[filho].getAltura()) && 
				(player[i].getNome().compareTo(player[filho].getNome()) < 0)) ){
				swap(player, i, filho);
				i = filho;
				record.sumMov(3);
			}else{
				i = tamHeap;
			} // end else
			record.sumCmp(3);
		} // end while
	} // end reconstroi()

	/**
	* - Metodo realiza ordenação heapsort de players tendo como chave primaria a altura do jogador.
	* @param player - Array de Struct contendo jogadores.
	* @param n - Quantidade de jogadores contido em player
	* @param record - Struct usada para armazenar comparações e movimentações
	*/
	static Jogador[] heapsort(Jogador []player, int n, RecordAlgoritmo record) {
		//Alterar o vetor ignorando a posicao zero
		Jogador []tmp = new Jogador[n+1];
		for(int i = 0; i < n; i++){
			tmp[i+1] = new Jogador();
			tmp[i+1] = tmp[i+1].clone(player[i]);
			record.sumMov(2);
		} // end for
		player = tmp;
  
		//Contrucao do heap
		for(int tamHeap = 2; tamHeap <= n; tamHeap++)
		   constroi(player, tamHeap, record);
		
  
		//Ordenacao propriamente dita
		int tamHeap = n;
		while(tamHeap > 1){
		   swap(player, 1, tamHeap--);
		   reconstroi(player, tamHeap, record);
		   record.sumMov(3);
		} // end while
  
		//Alterar o vetor para voltar a posicao zero
		tmp = player;
		Jogador []playerNew = new Jogador[n];
		for(int i = 0; i < n; i++){
			playerNew[i] = new Jogador();
			playerNew[i] = playerNew[i].clone(tmp[i+1]);
			record.sumMov(5);
		} // end for

		return playerNew;
	 } // end heapsort()


	public static void main(String []arg){
		int nPlayer = 0;	

		RecordAlgoritmo record = new RecordAlgoritmo();
		Jogador[] player = new Jogador[500];
	
		nPlayer = getPrimeiraEntrada(player);

		record.startCurrentTime();
		player = heapsort(player, nPlayer, record);	
		record.endCurrentTime();
	
		printPlayers(player, nPlayer);	

		record.recordTime("699415_heapsort.txt");
	} // end main()
}









