/***********************************************/ 
/* Lista Encadeada                             */
/* objetivo: cadastro de pessoas               */
/* programador: Daniela Bagatini               */
/* criado em: 01/04/2016                       */
/* data da ultima alteracao: 01/08/2019        */
/***********************************************/ 


#include <stdio.h>         // entrada e saída padrão: printf, scanf
#include <stdlib.h>		   // exit, malloc, system
#include <string.h>	  	   // strcmp
#include <locale.h>        // setlocale
//#include <ctype.h>       // toupper
//#include <conio.h>       // getch
//#include <time.h>        // rand   


// bibliotecas incluídas, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOENC.h"     // modelo de dados
#include "GERA_DADOSENC.h" // gera dados para povoar lista de forma automática 

#define True 1


/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/ 
void  entrada_dados  ( NODO *aux );           // lê dados de entrada
void  imprime_lista  ( NODO *aux );           // visualiza lista em tela
void  cria_lista     ( NODO* *l );            // inicializa lista com NULL
void  destroi_lista  ( NODO* *l );            // apaga lista e libera memória
void  inclui_fim     ( NODO* *l );            // inclui novo registro no final da lista
void  inclui_inicio  ( NODO* *l );            // inclui novo registro no início da lista
NODO* procura_nodo   ( NODO* l, int cod );    // procura na lista por uma código
void  exclui_nodo    ( NODO* *l );            // exclui regitro por código 
void  ordena_lista   ( NODO* *l );            // ordena lista por código
void  inclui_ordenado( NODO* *l );            // inclui registro na lista ordenado por código
void  inverte        ( NODO* *l );            // inverte referência dos registros
void  consulta_nome  ( NODO* l );             // consulta por nome
void  inserir_antes  ( NODO* *l );            // insere registro antes de uma código de referência
void  inserir_depois ( NODO* *l );            // insere registro depois de uma código de referência
void  conta_nodo     ( NODO* *l );            // conta número de registros existentes na lista
// crie sua própria função aqui!


/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void ){
    int op;                                   // opção do menu                               
    NODO* l;                                  // declaração da lista - ponteiro
    setlocale(LC_ALL, "Portuguese");	      // alterar idioma para português
    
    while( True ){
         printf( "\n /----------------------------------------------------/" );  // menu
         printf( "\n Programa registro - Menu                              " );
         printf( "\n [1 ]  Cria lista                                      " );
         printf( "\n [2 ]  Inclui registro no final da lista               " );
         printf( "\n [3 ]  Inclui registro no início da lista              " );
         printf( "\n [4 ]  Exclui registro                                 " );
         printf( "\n [5 ]  Ordena lista                                    " );
         printf( "\n [6 ]  Inlcui ordenado                                 " );
         printf( "\n [7 ]  Inverte lista                                   " );         
         printf( "\n [8 ]  Consulta nome                                   " );         
         printf( "\n [9 ]  Inserir antes                                   " );           
         printf( "\n [10]  Inserir depois                                  " );     
         printf( "\n [11]  Conta registros                                 " );           
         printf( "\n [12]  Crie sua própria função aqui!                   " ); 
         printf( "\n [13]  Gera dados                                      " );  
         printf( "\n [14]  Destroi lista                                   " );
         printf( "\n [15]  Imprime lista                                   " );
		 printf( "\n [0 ]  Para sair do programa                           " );
         printf( "\n /----------------------------------------------------/" );      
         printf( "\n Opção: " );
         fflush( stdin );
         scanf("%d", &op); // tecla de opção do menu
         
         switch( op ) {
            case 1: // rotina cria lista       
                    cria_lista( &l );
                    break;
                                
            case 2:  // rotina inclui registro no final da lista
                    inclui_fim( &l );   
                    break;
          
            case 3:  // rotina inclui registro no início da lista
                    inclui_inicio( &l );
                    break;
                
            case 4:  // rotina exclui registro da lista
                    exclui_nodo( &l );
                    break;
                  
            case 5:  // rotina ordena lista
                    ordena_lista( &l );// para alterar valores
                    break;

            case 6:  // rotina inclui ordenado
                    inclui_ordenado( &l );
                    break;
                                                                                   
            case 7: // rotina inverte lista                 
                    inverte( &l ); 
                    break;                                
                    
            case 8: // rotina consultar por um nome                 
                    consulta_nome( l ); 
                    break;             

            case 9: // rotina inserir antes de um código                 
                    inserir_antes( &l ); 
                    break; 

            case 10: // rotina inserir depois de um código                 
                    inserir_depois( &l ); 
                    break; 
                                                                               
            case 11: // rotina contar o número de registros na lista                 
                    conta_nodo( &l ); 
                    break; 

            case 12:                  
                    // crie sua própria função aqui! 
                    break;
                    
            case 13: // rotina gera dados de forma automática para povoar a lista
                    gera_dados( &l );
                    break;                    

            case 14: // rotina destroi lista                 
                    destroi_lista( &l );     
                    break;    

            case 15: // rotina imprime lista                 
                    imprime_lista( l );     
                    break;
										                    
            case 0: // término do programa                                          
                    exit( True ); 
                    break;
                
            default : 
                    printf( "\n Digite uma opção!" ); // não foi digitado uma opção válida
                    break;
         } // fim switch( op )

        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
 return 0;     
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : nodo com dados                     *
 ************************************************/
void entrada_dados( NODO *aux ){
      
    printf( "\n\n Digite a código: " ); 
    fflush( stdin );                         // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->info.nome );
  
    aux->prox = NULL;                        // não aponta
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saida   : nenhuma                             *
 *************************************************/     
void imprime_lista( NODO *aux ){
     
    int i= 0;                       // indica número de registro na lista
	 
    if( aux == NULL )               // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	    printf("\n Relatório Geral ----------------------------------------- ");
        while( aux != NULL ){       // ponteiro auxiliar para percorrer a lista
               printf( "\n\n Registro[%d] \t End: [%#p] \t Prox: [%#p]", i, aux, aux->prox );               
               printf( "\n\t\t Código: %d", aux->info.codigo );
			   printf( "\t\t Nome.: %s", aux->info.nome );
               aux = aux->prox;     // aponta para o próximo registro da lista
               i++;
		 } // fim while( aux != NULL )
	} // fim if( aux == NULL )
	getchar();                      // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : lista                              *
 * saída   : NULL (inicializa lista)            *
 ************************************************/ 
void cria_lista( NODO* *l ){
     
    *l = NULL;                                        // lista criada, início não aponta
    printf( "\n Lista criada! " );
}



/*************************************************
 * destroi_lista                                 *
 * objetivo: rotina para apagar lista            *
 * entrada : lista                               *
 * saida   : lista vazia                         *
 *************************************************/ 
void destroi_lista  ( NODO* *l ){
	  
    int i= 0;                      // indica número de registro na lista
	 
    if( *l == NULL )               // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	    NODO *aux = *l;
        while( aux != NULL ){      // ponteiro auxiliar para percorrer a lista
               printf( "\n Destroi Registro[%d]", i );
               printf( "\t Código: %d", aux->info.codigo );
			   printf( "\t Nome.: %s", aux->info.nome );
			   *l = aux->prox;     // aponta para o próximo registro da lista
               free( aux );        // libera memória
			   aux = *l;           // reposiciona ponteiro auxiliar no início      
               i++;
		 } // fim while( aux != NULL )
	} // fim if( aux == NULL )
	getchar();                     // parada da tela
}



/************************************************ 
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saida   : lista com novo registro            *
 ************************************************/ 
void inclui_fim( NODO* *l ){
    
     
	NODO *no= (NODO* ) malloc (sizeof(NODO));
	if( no != NULL ){
		entrada_dados( no );
		NODO *p= *l;
		if( *l != NULL){
		
		
		while(p->prox != NULL){
		
			p= p->prox;
		}
		p->prox = no;
	}else
		*l= no;
				
		printf("Registro incluido! ");	
		
	}else
		printf("Lista cheia!!");
} 




/*************************************************** 
 * inclui_inicio                                   *
 * objetivo: rotina para inserir no inicio da lista*
 * entrada : referencia de lista                   *
 * saída   : referencia lista com novo registro    *
 ***************************************************/ 
void inclui_inicio( NODO* *l ){
 
    NODO* no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espaco em memória
    if( no != NULL ){                                 // verifica se conseguiu alocar memória para o novo registro
             entrada_dados( no );                     // lê dados
             no->prox = *l;                           // novo aponta para o primeiro existente ou para Null
             *l = no;                                 // início aponta para o novo registro
             printf( "\n Registro incluido!" );
        } // fim if( no != NULL )
    else
        printf( "\n Lista cheia!" );
}



/************************************************ 
 * procura_nodo                                 *
 * objetivo: achar um registro por código       *
 * entrada : lista e código a ser procurado     *
 * saída   : posição ou NULL (não encontrou)    *
 ************************************************/ 
NODO* procura_nodo( NODO* p, int cod ){
           
    while( p != NULL )                                   // anda pela lista até o final ou até encontrar código desejado
    {
      if( p->info.codigo == cod ) return (p);
          p = p->prox;                           // passa para o próximo   
    }         
    return (NULL); // nodo de referência
}



/*************************************************** 
 * exclui_nodo                                     *
 * objetivo: rotina para excluir nodo da lista     *
 * entrada : lista                                 *
 * saida   : lista                                 *
 ***************************************************/ 
void exclui_nodo( NODO** l ){
     

}



/*************************************************** 
 * ordena_lista                                    *
 * objetivo: rotina para ordenar a lista           *
 * entrada : lista                                 *
 * saida   : lista ordenada por codigo             *
 ***************************************************/ 
void ordena_lista( NODO** l ){
	
      if( *l == NULL )                                // verifica se a lista está vazia 
        printf( "\n Lista vazia!" );
    else {
        if( (*l)->prox == NULL )                    // verifica se a lista tem apenas um registro 
             printf( "\n Lista com apenas 1 elemento!" );
        else{
             INFORMACAO aux;                        // auxiliar para a troca de dados
             NODO *ant = *l;                        // posiciona ponteiro auxiliar ant (anterior) no início da lista
             NODO *p   = ant->prox;                 // posiciona ponteiro auxiliar p (posterior) após ant, para que possa ser feita a comparação
    
             while( ant->prox != *l ){              // enquanto não for o último registro da lista circular
                    while( p != *l ){               // enquanto não for o primeiro registro da lista circular
                           if( strcmp(p->info.nome, ant->info.nome) < 0 ){ // se código de p for menor do que o código de ant, realiza a troca de conteúdo
                               aux      = p->info;  // faz a troca (algoritmo de ordenação Método Bolha)
                               p->info  = ant->info;
                               ant->info= aux;
                           } // fim if( p->info.codigo < ant.info.codigo )
                           p= p->prox;
                    } // fim while ( p != *l )  
                    ant= ant->prox;                 // atualiza ponteiros, ant para para o próximo registro
                    p= ant->prox;                   // p passa para o próximo de ant (permanece a frente do ponteiro ant)
             } // fim while ( ant->prox != *l )                      
         } // fim else
    }

}



/*************************************************** 
 * inclui_ordenado                                 *
 * objetivo: rotina para inserir em ordem de codigo*
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inclui_ordenado( NODO** l ){
     

}



/*************************************************** 
 * inverte referencia                              *
 * objetivo: rotina para inverter referencia do reg*
 * entrada : lista                                 *
 * saida   : lista com referencia invertida        *
 ***************************************************/ 
void inverte( NODO** l ){
     

}



/*************************************************** 
 * consulta nome                                   *
 * objetivo: rotina para consultar                 *
 * entrada : lista                                 *
 * saida   : lista                                 *
 ***************************************************/ 
void consulta_nome( NODO *l ){
	int flag = 0;
       if(l == NULL)
       printf("\nLista não encontrada");
    else{
        char nome[30];
        printf("Digite o nome: ");
        scanf("%s", &nome);    	
        NODO *p = l; // POINT AUXILIAR    
	    flag = 0; // flag para avisar se encontrou nome na lista
	    while (p != NULL){    	 // percorrer
			  if (strcmp(nome, p->info.nome)== 0){
			    printf("Encontrado %s", p->info.nome);
			    getchar();
			    flag= 1;
			   }
		      p = p->prox;
		}	
   }
   if( flag == 0 )
       printf("\nNome não encontrado");
       getchar();
   }



/*************************************************** 
 * inserir antes                                   *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_antes( NODO** l ){
     

}



/*************************************************** 
 * inserir depois                                  *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_depois( NODO** l ){
     
 
}


/*************************************************** 
 * conta_nodo                                      *
 * objetivo: rotina para contar numero de registros*
 * entrada : lista                                 *
 * saida   : nenhuma                               *
 **************************************************/ 
void conta_nodo( NODO** l ){
     

}
