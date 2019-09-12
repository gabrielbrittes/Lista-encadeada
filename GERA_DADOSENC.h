/***********************************************/ 
/* Biblioteca para Lista Encadeada             */
/* Profa Daniela Bagatini                      */
/***********************************************/ 
#include <string.h>
#include <time.h>

/************************************************
 * aleatorio                                    *
 * objetivo: rotina para gerar um n�mero        *
 * aleat�rio de um valor m�ximo estipulado      *
 * entrada : max                                *
 * sa�da   : n�mero aleat�rio                   *
 ************************************************/
int aleatorio( int max ){
	
	int ret = rand() % max; // gera n�mero com base em max = n�mero m�ximo
	return ret;
}


/************************************************
 * gera_dados                                   *
 * objetivo: rotina para ler dados dos registros*
 * entrada : lista                              *
 * sa�da   : lista atualizado com dados         *
 ***********************************************/
void gera_dados( NODO **l ){
	 
	char  nomeTemp[50];                        // armazena nome e sobrenome temporariamente
	int   i, x;                                // i= �ndice da lista; x= armazena n�mero sorteado 
	
	//Fonte dos nomes: https://petitebox.com.br/blog/100-nomes-mais-comuns-no-brasil-em-2016/
	char *nomes[] = {"Miguel",
"Arthur",
"Davi",
"Bernardo",
"Heitor",
"Gabriel",
"Pedro",
"Lorenzo",
"Lucas",
"Matheus",
"Enzo",
"Theo",
"Benjamin",
"Rafael",
"Nicolas",
"Guilherme",
"Gustavo",
"Samuel",
"Henrique",
"Felipe",
"Murilo",
"Joaquim",
"Joao Pedro",
"Joao Miguel",
"Enzo Gabriel",
"Daniel",
"Isaac",
"Pietro",
"Pedro Henrique",
"Lucca",
"Eduardo",
"Benicio",
"Leonardo",
"Vitor",
"Joao Lucas",
"Bryan",
"Joao",
"Caua",
"Davi Lucca",
"Anthony",
"Vicente",
"Vinicius",
"Caio",
"Antonio",
"Davi Lucas",
"Bento",
"Joao Gabriel",
"Joao Vitor",
"Noah",
"Francisco",
"Calebe",
"Gael",
"Emanuel",
"Ian",
"Luiz Miguel",
"Enrico",
"Thiago",
"Augusto",
"Otavio",
"Joao Guilherme",
"Ryan",
"Yuri",
"Levi",
"Vitor Hugo",
"Erick",
"Bruno",
"Nathan",
"Raul",
"Henry",
"Davi Luiz",
"Luiz Felipe",
"Thomas",
"Rodrigo",
"Davi Miguel",
"Andre",
"Fernando",
"Alexandre",
"Pedro Lucas",
"Breno",
"Arthur Miguel",
"Carlos Eduardo",
"Kaique",
"Yago",
"Kaue",
"Luan",
"Igor",
"Luiz Henrique",
"Luiz Gustavo",
"Arthur Gabriel",
"Mathias",
"Lucas Gabriel",
"Pedro Miguel",
"Arthur Henrique",
"Ruan",
"Tomas",
"Danilo",
"Enzo Miguel",
"Luiz Otavio",
"Ricardo",
"Oliver",
"Alice",
"Sophia",
"Laura",
"Valentina",
"Helena",
"Isabella",
"Manuela",
"Julia",
"Luiza",
"Livia",
"Giovanna",
"Maria Luiza",
"Heloisa",
"Maria Eduarda",
"Maria Clara",
"Lara",
"Lorena",
"Beatriz",
"Mariana",
"Melissa",
"Cecilia",
"Ana Clara",
"Ana Julia",
"Yasmin",
"Maria Julia",
"Isadora",
"Rafaela",
"Emanuelly",
"Ana Luiza",
"Esther",
"Lavinia",
"Sarah",
"Isabelly",
"Elisa",
"Eloah",
"Nicole",
"Maria Alice",
"Gabriela",
"Maria",
"Rebeca",
"Leticia",
"Clara",
"Marina",
"Isis",
"Ana",
"Alicia",
"Liz",
"Antonella",
"Maria Cecilia",
"Agatha",
"Catarina",
"Ana Laura",
"Larissa",
"Ana Beatriz",
"Maria Fernanda",
"Maite",
"Luna",
"Olivia",
"Vitoria",
"Bianca",
"Lais",
"Allana",
"Maria Valentina",
"Emilly",
"Ana Sophia",
"Clarice",
"Milena",
"Pietra",
"Fernanda",
"Carolina",
"Amanda",
"Maria Vitoria",
"Maria Helena",
"Eduarda",
"Malu",
"Maria Sophia",
"Stella",
"Camila",
"Maya",
"Gabrielly",
"Mirella",
"Mariah",
"Ana Livia",
"Maria Flor",
"Ayla",
"Isabel",
"Sophie",
"Giulia",
"Luana",
"Bruna",
"Ana Vitoria",
"Joana",
"Maria Laura",
"Maria Isis",
"Louise",
"Perola",
"Natalia",
"Ana Cecilia",
"Aurora",
"Barbara"
};

	//Fonte dos nomes: http://www.tiltedlogic.org/Familia/surnames.php
	char *sobre[] = {"Altoe",
"Sossai",
"Agrizzi",
"De Angeli",
"Ferreira",
"da Silva",
"Della Coletta",
"Zampirolli",
"Fernandes",
"Braga",
"Alves",
"Costalonga",
"Botteon",
"Caliman",
"de Oliveira",
"Zanette",
"Salvador",
"Silva",
"Pesca",
"Zandonadi",
"Tosi",
"da Costa",
"Gomes",
"Calmon",
"de Souza",
"Sossai detto Pegorer",
"de Almeida",
"Pereira",
"Falqueto",
"Martins"};
	
	srand( time(NULL) );                 // inicia o gerador rand�mico com a hora atual
	*l= NULL;                            // cria nova lista
	int massa;                           // informa quantidade de dados a ser cadastrados
	printf("\n Cria nova lista. Defina a massa de dados [at� 100]: ");
	do{
	   	fflush(stdin);
   	    scanf("%d", &massa);
   	}while( massa < 1 || massa > 100 );  // valida massa de dados entre 1 e 100
	      
	for( i= 0; i < massa; i++ ){         // la�o para gera��o aleat�ria dos nomes e c�digos
		 //lista->info[ i ].codigo = i + 1;// gerar c�digo autom�tico sequencial 
		 x = aleatorio( 199 );
	 	 strcpy( nomeTemp, nomes[ x ] ); // nome aleat�rio
		 strcat( nomeTemp, " ");         // espa�o entre nome e sobrenome 
		 x = aleatorio( 29 );
		 strcat( nomeTemp, sobre[ x ] ); // concatena no nome o sobrenome aleat�rio
		 
		 NODO *no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espa�o em mem�ria
		 if( no != NULL ){                                 // verifica se conseguiu alocar mem�ria para o novo registro
		     strcpy( no->info.nome, nomeTemp );       // registra nome completo na lista
		     no->info.codigo = aleatorio( 199 ) + 1;  // gerar c�digo autom�tico
		     no->prox = *l;                           // novo aponta para o primeiro existente ou para NULL (se lista vazia)
             *l = no;                                 // in�cio aponta para o novo registro
        }else // fim if ( no != NULL )
             printf( "\n Lista cheia!" );
	} // fim for ( i= 0; i < massa; i++ )
	printf( "\n Gerados %d registros. ", i );         // informa n�mero de registros gerados
}
