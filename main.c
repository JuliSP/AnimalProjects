/***************************************************************************************************
....................................................................................................
....................................................................................................
................:+:...........;;:..................................:xx...........:x+................
................;::+.........+:::..............:;;;;:..............;+:X:........;+:X................
................;:::+++;++x++::::.........:+$Xx:.....+$$x;.........;+::X;;:..:;;+;:X................
................;:;;;;;;+;;;;;;::......;$XXXXX+:....:+XXXXX$;......;X;.:;XXXXXX;..;X................
................;;;;;;;;;;;;;;;;:....+$XXX$XXX;;....;;XXXXXXXX+....;..xXXXXXXXXXX;.::...............
................+;;;;:;;;;;;::;;+...;XXX$XXXX:;::...;;.X$XXXXXX+...:.+X$$:XXXXX$;X:.:...............
...............;;;;:$X;;X;;X$;;;;....;$XXXXX;;&;:..::&x;XXXXXX+....;.XXx+XX$$XX+XX+.+...............
......++++.....+;;;;;;:++;:;;;;;;......XXX;;;;:..xX:.:;;;;X$X:.....:.+XX$XX$$XX$XX:.;.....XXX+......
......+;;;;:...;;;;;;+$$$$$;;;;;;+......:+;;;;..:;;:..:;;;+:......;...+XX$XXX$XXX;..::..:XXXXX:.....
......;;;;;;..:;;;;;;;;+++;;;;;;;+......;;;;;;;;::::;;;;;;;:......;....:;XXXXXx:....::..:;;;X;......
.......++++;..:;;;;;;;;;;;;;;;;;;;......X;;;;;;;;;;;;;;;;;;x......:.................::..:...;.......
.......:;;+:..+++;;;;;;;;;;;;;;;++;....:++;;;;;;;;;;;;;;;++X:....++;...............;;+..::.::.......
.......::::.;;;;;;;:::::::::::+;;;;;.:;;;;;+:::::::::::;+;;;;+.;XXXXX;...........;XXXXX;.:..:.......
....        .;+;;;:           :;;;;; .;;;+;:            :+;;;; .;XXX+:           .;XXX+:        ....
....                                                                                            ....
....						 _       _ _    _____ _____                                         ....
....						| |     | (_)  / ____|  __ \                                       .....
....						| |_   _| |_  | (___ | |__) |                                       ....
....					_   | | | | | | |  \___ \|  ___/                                       .....
....				   | |__| | |_| | | |  ____) | |                                            ....
....					\____/ \__,_|_|_| |_____/|_|          ESTGL - IPV    @2018             .....              
.....                                                                                           ....
....................................................................................................
....................................................................................................
....................................................................................................
****************************************************************************************************/                                                                               
                                                                                                    
#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

 // definição da struct animal
typedef struct animal                            
{
	int id;
	int id_cliente;
	char nome[MAX];
	float peso;
} t_animal;


// definição da struct cliente
typedef struct cliente
{
	int id;
	char nome[MAX];
} t_cliente;


// protótipos de funções
/*---------------------------------------------------------------------------
 *         Função: Exibir um menu com todas as opções do programa
 *         Retorno: um caractere do numero correspondente à opção
 *         Parâmetros: resp - opção de menu
 * ------------------------------------------------------------------------ */
char menu();

/*---------------------------------------------------------------------------
 *         Função: Registo de um cliente pedindo apenas o nome
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void registar_cliente();

/*---------------------------------------------------------------------------
 *         Função: Registar um animal com nome e especie
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void registar_animal();

/*----------------------------------------------------------------------------------------------
 *         Função: Mostra todos os animais registados e as informações de internamento
 *         Retorno: 
 *         Parâmetros: 
 * ---------------------------------------------------------------------------------------------- */
void listar_animais();


/*---------------------------------------------------------------------------
 *         Função: Exibe todos os clientes registados
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void listar_clientes();


/*----------------------------------------------------------------------------------------------
 *         Função: Procura um animal pelo id do animal
 *         Retorno: um ponteiro para o animal encontrado ou NULL caso o ID não exista
 *         Parâmetros: arq_animais: ponteiro para um ficheiro aberto
 *                             id_animal: ID do animal que será procurado
 * -------------------------------------------------------------------------------------------- */
t_animal *obter_animal(FILE *arq_animais, int id_animal);


/*---------------------------------------------------------------------------------------------
 *         Função: Procura um cliente pelo seu id
 *         Retorno: um ponteiro para o cliente encontrado ou NULL caso o ID não exista
 *         Parâmetros: arq_clientes: ponteiro para um ficheiro aberto
 *                             id_cliente: ID do cliente que será procurado
 * -------------------------------------------------------------------------------------------- */
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente);


/*---------------------------------------------------------------------------
 *         Função: Pesquisa um animal e exibe suas informações
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void pesquisar_animal();

/*---------------------------------------------------------------------------
 *         Função: Pesquisa um cliente e exibe suas informações
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void pesquisar_cliente();

/*---------------------------------------------------------------------------
 *         Função: Procura um animal pelo seu id e informa se ele foi encontrado
 *         Retorno: 1 para animal encontrado ou 0 caso o ID não exista
 *         Parâmetros: arq_animais: ponteiro para um ficheiro aberto
 *                              id_animal: ID do animal que será procurado
 * ------------------------------------------------------------------------ */
int existe_animal(FILE *arq_animais, int id_animal);

/*------------------------------------------------------------------------------------
 *         Função: Procura um cliente pelo seu id e informa se ele foi encontrado
 *         Retorno: 1 se o cliente existe ou 0 caso o ID não exista
 *         Parâmetros: arq_clientes: ponteiro para um ficheiro aberto
 *                              id_cliente: ID do cliente que será procurado
 * ----------------------------------------------------------------------------------- */
int existe_cliente(FILE *arq_clientes, int id_cliente);

/*---------------------------------------------------------------------------
 *         Função: Atualiza as informações do animal no ficheiro
 *         Retorno: 
 *         Parâmetros: arq_animais: ponteiro para um ficheiro aberto
 *                             animal_internado: ponteiro para o animal que será atualizado
 * ------------------------------------------------------------------------ */
void atualizar_animais(FILE *arq_animais, t_animal *animal_internado);


/*---------------------------------------------------------------------------
 *         Função: Interna um animal e atualiza o ficheiro
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void internar_animal();

/*--------------------------------------------------------------------------------------------
 *         Função: Entrega  um animal ao cliente e atualiza as informações no ficheiro
 *         Retorno: 
 *         Parâmetros: 
 * -------------------------------------------------------------------------------------------- */
void entregar_animal();

/*---------------------------------------------------------------------------
 *         Função: Exclui um animal do ficheiro
 *         Retorno: 
 *         Parâmetros: 
 * ------------------------------------------------------------------------ */
void excluir_animal();

/*---------------------------------------------------------------------------
 *         Função: Informa se a string é um número
 *         Retorno: str: ponteiro para uma cadeia de caracteres
 *         Parâmetros: 1 se a string só conter números ou 0 caso contrário
 * ------------------------------------------------------------------------ */
int str_somente_numeros(char str[]);


int main(int argc, char *argv[])
{
	char resp;

	while(1)   {                          	// ciclo infinito do programa
		resp = menu();                      // obtém a escolha do utilizador
		if(resp == '1')                    		// testa o valor de "resp"
			registar_animal();
		else if(resp == '2')
			registar_cliente();
		else if(resp == '3')
			listar_animais();
		else if(resp == '4')
			listar_clientes();
		else if(resp == '5')
			pesquisar_animal();
		else if(resp == '6')
			pesquisar_cliente();
		else if(resp == '7')
			internar_animal();
		else if(resp == '8')
			entregar_animal();
		else if(resp == '9')
			excluir_animal();
		else if(resp == '0') // se for igual a 0, então sai do ciclo while
			break;
		else  {
			printf("\nOpcao invalida! Pressione <Enter> para continuar...");
			scanf("%*c");
			// uma forma de "limpar" o buffer de entrada
			fseek(stdin, 0, SEEK_END); // não recomendável o uso
		}
		system(limpar_tela);
	}

	return 0;
}


/**********************************************************************************
 *         Função: Exibir um menu com todas as opções do programa
 *         Retorno: um caractere do numero correspondente à opção
 *         Parâmetros: resp - opção de menu
***********************************************************************************/
char menu()
{
	char resp[2];                                        //  string de tamanho 2, um catater numero e \0
    int i=0;
       printf ("%s", "\n\t");
    for (i=0; i<43;i++ )
        putchar('+');
    // muda de linha, faz tabulação e eimprime no ecran
    printf ("%s", "\n\tPrograma de gestao de internamento animal\n\t");         

    for (i=0; i<43;i++ )
        putchar('+');
    printf("%s","\n\n\t1 - Registar um animal\n\n");                                          // printf neste caso para ser na forma segura deve conter %s no inicio
	printf("%s","\t2 - Registar um cliente\n\n");                                                     // Alternativa: intrução puts ("  ");
	printf("%s","\t3 - Listar todos os animais\n\n");
	printf("%s","\t4 - Listar todos os clientes\n\n");
	printf("%s","\t5 - Pesquisar por animal\n\n");
	printf("%s","\t6 - Pesquisar por cliente\n\n");
	printf("%s","\t7 - Internar um animal\n\n");
	printf("%s","\t8 - Entregar um animal\n\n");
	printf("%s","\t9 - Excluir um animal\n\n");
	printf("%s","\t0 - Sair\n\n");
	printf("\tDigite o numero da opcao: ");
	scanf("%1s%*c", resp);                        // o *c pega no Enter e descarta

	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END);           // não recomendável o uso

	        // se chegou aqui, é porque a opção é válida
	return resp[0];
}

/*****************************************************************************************************
 *         Função: Informa se a string contém somente número
 *         Retorno: str: ponteiro para uma cadeia de caracteres
 *         Parâmetros: 1 se a string só conter números ou 0 caso contrário
******************************************************************************************************/
int str_somente_numeros(char str[])
{
	int i = 0;
	int len_str = strlen(str);

	for(i = 0; i < len_str; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

/******************************************************************************************************
 *          Função: Registar cliente em dado estruturado e guarda em ficheiro
 *          Retorno: t_cliente
 *          Parâmetros: cliente.id, cliente.nome 
*******************************************************************************************************/
void registar_cliente()
{
	// abre o ficheiro para escrita, a+b => acrescenta dados ao final do ficheiro ou cria um ficheiro binária para leitura e escrita
	FILE *arq_clientes = fopen("clientes.bin", "a+b");


	if(arq_clientes == NULL)	        // testa a abertura do ficheiro
	{
		printf("\nFalha ao abrir ficheiro(s)!\n");
		exit(1); // aborta o programa
	}
	/*
		O utilizador não deve introduzir o ID do cliente, deve ser gerado automático a partir do  ID do último cliente registado
	*/
	int cont_bytes = 0;                                                     // cont irá guardar o número total de bytes
	fseek(arq_clientes, 0, SEEK_END);                             // seta o ponteiro do ficheiro para o final do ficheiro
	cont_bytes = ftell(arq_clientes);                             // pegamos a quantidade de bytes com a função ftell

	t_cliente cliente;

	if(cont_bytes == 0)                                               // se for 0, então não existe cliente registado
	{
		cliente.id = 1;                                                  // coloca o ID a começar em 1
	}
	else
	{
		t_cliente ultimo_cliente;
		fseek(arq_clientes, cont_bytes - sizeof(t_cliente), SEEK_SET);        // função fseek para posicionar o ficheiro
		                                                                                                    // cont_bytes - sizeof(t_cliente) serve para posicionar
                                                                                                            // para que possamos ler o último cliente registado
		fread(&ultimo_cliente, sizeof(t_cliente), 1, arq_clientes);                      // ler o cliente

		cliente.id = ultimo_cliente.id + 1;            		// o ID do cliente é o ID do último cliente acrescido em 1
	}
	
	printf("\nDigite o nome do cliente: ");                              // obtém o nome do cliente
	scanf("%99[^\n]%*c", cliente.nome);                                 // ^\n indica para ler até a quebra de linha (enter) , %*c descarta o enter
	
	fseek(stdin, 0, SEEK_END);                                         // uma forma de "limpar" o buffer de entrada (não recomendável o uso)

	fseek(arq_clientes, 0, SEEK_END);                                       // se o ponteiro não estiver no final do ficheiro nada é escrito
	
	fwrite(&cliente, sizeof(t_cliente), 1, arq_clientes);          // escreve no ficheiro

	fclose(arq_clientes);                                                      // fecha o ficheiro

	printf("\nCliente \"%s\" registado com sucesso!\n", cliente.nome);    // escreve no ecran 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c"); 

	fseek(stdin, 0, SEEK_END);                 // uma forma de "limpar" o buffer de entrada (não recomendável o uso)
}


/******************************************************************************************************
 *          Função: Registar animal em dado estruturado e guarda em ficheiro
 *          Retorno: t_animal , internado: sim/não
 *          Parâmetros: cliente.id, cliente.nome 
*******************************************************************************************************/
void registar_animal()
{
	// abre o ficheiro para escrita , a+b => acrescenta dados ao final do ficheiro ou cria um ficheiro binária para leitura e escrita
	FILE *arq_animais = fopen("animais.bin", "a+b");

	if(arq_animais == NULL)  	            // testa a abertura do ficheiro
	{
		printf("\nFalha ao abrir ficheiro(s)!\n");
		exit(1); // aborta o programa
	}
	t_animal animal;

// O utilizador não deve introduzir o ID doanimal, deve ser gerado automático a partir do  ID do último animal registado
	int cont_bytes = 0;

	fseek(arq_animais, 0, SEEK_END);   	// seta o ponteiro do ficheiro para o final do ficheiro

	cont_bytes = ftell(arq_animais);       	// cont irá guardar o número total de bytes

	if(cont_bytes == 0)                       // se for 0, então não existe animal registado
	{
		animal.id = 1;                     // coloca ID a começar  de 1
	}
	else
	{
		t_animal ultimo_animal;

		fseek(arq_animais, cont_bytes - sizeof(t_animal), SEEK_SET);          //  função fseek para posicionar o ficheiro
                                                                                                                // cont_bytes - sizeof(t_cliente) serve para posicionar
		                                                                                                       // para que possa ler o último animal registado
		fread(&ultimo_animal, sizeof(t_animal), 1, arq_animais);                	// ler o animal

		animal.id = ultimo_animal.id + 1;                                     // o ID do animal é o ID do último animal acrescido em 1
	}

	printf("\nDigite o nome do animal: ");                      // obtém o nome do animal
	scanf("%99[^\n]%*c", animal.nome);                             // ^\n indica para pegar até a quebra de linha (enter), %*c descarta o enter

	fseek(stdin, 0, SEEK_END); 

	do
	{
		char str_peso[5];
		float float_peso;
		int somente_numeros = 1;

		// obtém o peso do animal
		printf("\nDigite o peso do animal sem virgulas:\t\t\t exempo: 2,45 deve digitar 245\n ");
		scanf("%4s%*c", str_peso);

		fseek(stdin, 0, SEEK_END); // não recomendável o uso

		// verifica se o peso possui somente números
		somente_numeros = str_somente_numeros(str_peso);
		// verifica se o peso contém somente números
		if(somente_numeros == 1)
		{
			// se chegou aqui, é porque tudo está validado
			// preencho a variável float_peso com o valor de str_peso
			int int_peso;
			// exemplo: 19,50 deve digitar 1950
			sscanf(str_peso, "%d", &int_peso);
			float_peso = int_peso / 100.0;
			animal.peso = float_peso;
			break;
		}
	}
    
	while(1);

	// inicializa o id_cliente com -1 indicando que o animal NÃO está internado
	animal.id_cliente = -1;

	// se o ponteiro não estiver no final do ficheiro nada é escrito
	fseek(arq_animais, 0, SEEK_END);
	// escreve no ficheiro
	fwrite(&animal, sizeof(t_animal), 1, arq_animais);

	// fecha o ficheiro
	fclose(arq_animais);

	printf("\nanimal \"%s\" registado com sucesso!\n", animal.nome);
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c"); // pega o Enter e descarta

	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}

/******************************************************************************************************
 *          Função: Listar todos os clientes
 *          Retorno: listagem
 *          Parâmetros: 
******************************************************************************************************/

void listar_clientes()
{
	FILE *arq_clientes = fopen("clientes.bin", "rb");         // rb => abre ficheiro binário para leitura apenas

	if(arq_clientes == NULL)	          // testa a abertura do ficheiro
	{
		printf("\nFalha ao abrir ficheiro(s) ou ");
		printf("Nenhum cliente registado.\n");
		printf("\nPressione <Enter> para continuar...");
		scanf("%*c"); // pega no Enter e descarta

		fseek(stdin, 0, SEEK_END); 		//  "limpar" o buffer de entrada
		return;
	}

	int encontrou_clientes = 0;        	// variável que indica se encontrou pelo menos 1 cliente
	t_cliente cliente;
	printf("\nA listar todos os clientes...\n");
        printf("\nID do cliente: \t Nome do cliente: \n ");

	while(1)                      	// ciclo para percorrer o ficheiro
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);        		// fread retorna o número de elementos lidos com sucesso

		if(result == 0)                         		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;

		encontrou_clientes = 1;		// atualiza a variável indicando que encontrou  pelo menos um cliente
		printf("\n\t %d\t  %s\n ", cliente.id, cliente.nome);	 	// mostra os dados do cliente
	}

	if(encontrou_clientes == 0)
		printf("\nNenhum cliente registado.\n");

	fclose(arq_clientes);
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END); //"limpar" o buffer de entrada
}

/******************************************************************************************************
 *          Função: Procurar um cliente pelo ID
 *          Retorno: cliente
 *          Parâmetros:  id cliente
*******************************************************************************************************/
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente)
{
	rewind(arq_clientes);             	// vai para o início do ficheiro
	t_cliente *cliente;

	// ciclo para percorrer o ficheiro
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	// aloca espaço mesmo sem saber se o cliente existe
	cliente = (t_cliente *)malloc(sizeof(t_cliente));
	while(1)
	{
		size_t result = fread(cliente, sizeof(t_cliente), 1, arq_clientes);	// fread retorna o número de elementos lidos com sucesso

		if(result == 0)         		// se for 0, é porque não há mais elemento, então sai do ciclo
		{
			free(cliente); // libera a mémoria, pois o cliente não foi encontrado
			return NULL;
		}
		if(cliente->id == id_cliente)		// verifica se os ID's são iguais
			break;
	}
	return cliente;
}

/******************************************************************************************************
 *          Função: Listar todos os animais
 *          Retorno: listagem
 *          Parâmetros: 
*******************************************************************************************************/

void listar_animais()                          // lista de todos os animais
{

	FILE *arq_animais = fopen("animais.bin", "rb");  // rb => abre para leitura somente, ponteiro para o início do ficheiro
	FILE *arq_clientes = fopen("clientes.bin", "rb");

	if(arq_animais == NULL)	                           // se o ficheiro de animais não existe
	{
		printf("\nFalha ao abrir ficheiro ou ");
		printf("Nenhum animal registado.\n");
		printf("\nPressione <Enter> para continuar...");
		scanf("%*c"); // pega no Enter e descarta

		fseek(stdin, 0, SEEK_END);                		// forma de "limpar" o buffer de entrada
		return;
	}
	
	int encontrou_animais = 0;                           // variável que indica se encontrou pelo menos 1 animal
	printf("\n A listar todos os animais...\n");
	
	t_animal animal;
	while(1)                                                             // ciclo para percorrer o ficheiro
	{

		size_t result = fread(&animal, sizeof(t_animal), 1, arq_animais);	 	// fread retorna o número de elementos lidos com sucesso

		if(result == 0)          		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;

		encontrou_animais = 1;             		// atualiza a variável indicando que encontrou pelo menos um animal

		printf("\nID do animal: %d\n", animal.id);                         // mostra os dados do animal
		printf("Nome do animal: %s\n", animal.nome);
		printf("peso: %.2f\n", animal.peso);

		// se id_cliente for diferente de -1, então o animal está internado, pois
		// possui algum id válido do cliente que internou o animal.
		// se id_cliente for igual a -1, indica que o animal não está internado,
		// pois o id -1 NÃO é um id válido
		if(animal.id_cliente != -1)
		{
			// se o ficheiro de clientes não existir, atenção esse teste
			// não pode ser realizado no início da função, pois pode acontecer de
			// todos os animais não estarem internados
			if(arq_clientes == NULL)
			{
				printf("\nFalha ao abrir ficheiro!\n");
				fclose(arq_animais);                         // liberta recursos
				exit(1);                                         // aborta o programa
			}
			t_cliente *cliente = obter_cliente(arq_clientes, animal.id_cliente);
			printf("Internado? Sim. Cliente: %s\n", cliente->nome);
			free(cliente);                         // evita vazamento de memória
		}
		else
			printf("Internado? Nao\n");
	}


	if(encontrou_animais == 0)	        // verifica se encontrou pelo menos um animal
		printf("\nNenhum animal registado.\n");


	if(arq_clientes != NULL)      // apenas se  foi aberto
		fclose(arq_clientes);    
	fclose(arq_animais);	               // fecha os ficheiros em ordem inversa que foram abertos

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");


	fseek(stdin, 0, SEEK_END);             	// uma forma de "limpar" o buffer de entrada
}

/******************************************************************************************************
 *          Função: Pesquisar por um animal pelo nome
 *          Retorno: animal
 *          Parâmetros: nome_animal
*******************************************************************************************************/

void pesquisar_animal()
{
	char nome[MAX];
	int encontrou_animal = 0;
	FILE *arq_animais = fopen("animais.bin", "rb");          	// rb => abre para leitura somente
	FILE *arq_clientes = fopen("clientes.bin", "rb");
	if(arq_animais == NULL)        	// testa a abertura do ficheiro para verificar se há registos
	{
		printf("\nFalha ao abrir ficheiro(s)!\n");
		exit(1); 
	}
	printf("\nDigite o nome do animal: ");
	scanf("%99[^\n]%*c", nome);
	printf("\nAnimais com o nome \"%s\":\n\n", nome);
	t_animal animal;
	while(1)                                   	// ciclo para percorrer o ficheiro
	{                                                   // busca linear, pois o campo nome não possui índice
		size_t result = fread(&animal, sizeof(t_animal), 1, arq_animais); 		// fread retorna o número de elementos lidos com sucesso
		if(result == 0)  		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;
		char nome_aux[MAX];
		strcpy(nome_aux, animal.nome);         		// faz uma cópia para não alterar animal.nome
		if(strcmp(strupr(nome_aux), strupr(nome)) == 0)             		// verifica se é igual
		{
			printf("ID do animal: %d\n", animal.id); 			// mostra os dados do animal
			printf("peso: %.2lf\n", animal.peso);
			if(animal.id_cliente != -1)
			{
				if(arq_clientes == NULL)				// se o ficheiro de clientes não existir
				{
					printf("\nFalha ao abrir ficheiro!\n");
					fclose(arq_animais); // liberta recursos
					exit(1); // aborta o programa
				}
				t_cliente *cliente = obter_cliente(arq_clientes, animal.id_cliente);
				printf("internado? Sim. Cliente: %s\n", cliente->nome);
				free(cliente); // evita vazamento de memória
			}
			else
            printf("internado? Nao\n");
			encontrou_animal = 1;
			printf("\n");
		}
	}

	if(encontrou_animal == 0)
		printf("Nenhum animal encontrado.\n\n");

	fclose(arq_animais);

	printf("Pressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);	// "limpar" o buffer de entrada
}

/******************************************************************************************************
 *          Função: Pesquisar por um cliente
 *          Retorno: cliente
 *          Parâmetros: nome do cliente
*******************************************************************************************************/
void pesquisar_cliente()
{
	char nome[MAX];
	int encontrou_cliente = 0;
	FILE *arq_clientes = fopen("clientes.bin", "rb");         	// rb+ => abre para leitura somente
	if(arq_clientes == NULL)                           	                  // testa a abertura do ficheiro
	{
		printf("\nFalha ao abrir ficheiro(s)!\n");
		exit(1); // aborta o programa
	}
	printf("\nDigite o nome do cliente: ");
	scanf("%99[^\n]%*c", nome);
	printf("\nClientes com o nome \"%s\":\n\n", nome);
	t_cliente cliente;   
	while(1)                                     	// ciclo para percorrer o ficheiro
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);		// fread retorna o número de elementos lidos com sucesso
		if(result == 0)            		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;
		char nome_aux[MAX];
		strcpy(nome_aux, cliente.nome);		// faz uma cópia para não alterar cliente->nome
		if(strcmp(strupr(nome_aux), strupr(nome)) == 0)             		// verifica se é igual
		{
			printf("ID do cliente: %d\n\n", cliente.id);         	// mostra os dados do cliente
			encontrou_cliente = 1;
		}
	}
	if(encontrou_cliente == 0)
    printf("Nenhum cliente encontrado.\n\n");
	fclose(arq_clientes);	 // fecha o ficheiro
	printf("Pressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END);                                           // limpar" o buffer de entrada
}


/******************************************************************************************************
 *          Função: Verifica se um animal existe
 *          Retorno: retorna 0 se NÃO existe e 1 caso contrário
 *          Parâmetros: Id animal
*******************************************************************************************************/

int existe_animal(FILE *arq_animais, int id_animal)
{
	rewind(arq_animais);	// vai para o início do ficheiro, pois não sabemos a posição do ponteiro no ficheiro
	t_animal animal;
	while(1)                                         	// ciclo para percorrer o ficheiro
                                                         	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	{
		size_t result = fread(&animal, sizeof(t_animal), 1, arq_animais);		// fread retorna o número de elementos lidos com sucesso
		if(result == 0) 	                                                                          	// se for 0, é porque não há mais elemento, então sai do ciclo
			break;

		if(animal.id == id_animal)                                		// verifica se o ID é igual
			return 1;
	}                                                      	// se chegou aqui é porque NÃO existe o animal, então retorna 0
	return 0;
}


/******************************************************************************************************
 *          Função: Verifica se um cliente existe
 *          Retorno: retorna 0 se NÃO existe e 1 caso contrário
 *          Parâmetros: Id cliente
*******************************************************************************************************/
int existe_cliente(FILE *arq_clientes, int id_cliente)
{
	rewind(arq_clientes);	// vai para o início do ficheiro
	t_cliente cliente;
	// ciclo para percorrer o ficheiro
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	while(1)
	{
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);		// fread retorna o número de elementos lidos com sucesso
		if(result == 0)     		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;
		if(cliente.id == id_cliente)  		// verifica se o ID é igual
			return 1;
	}
	// se chegou aqui é porque NÃO existe o cliente, então retorna 0
	return 0;
}

/******************************************************************************************************
 *          Função: Obter um animal pelo ID
 *          Retorno: animal
 *          Parâmetros: Id animal
*******************************************************************************************************/

t_animal *obter_animal(FILE *arq_animais, int id_animal)
{
	rewind(arq_animais);                               	// vai para o início do ficheiro

	// ciclo para percorrer o ficheiro
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	t_animal *animal;


	animal = (t_animal *)malloc(sizeof(t_animal));        	// aloca espaço mesmo sem saber se o animal existe
	while(1)
	{
		size_t result = fread(animal, sizeof(t_animal), 1, arq_animais);   		// fread retorna o número de elementos lidos com sucesso
		if(result == 0)                                                                		// se for 0, é porque não há mais elemento, então sai do ciclo
			break;
		if(animal->id == id_animal)                                                		// verifica se os ID's são iguais
			return animal;
	}
	free(animal);           // liberta recursos
	return NULL;
}



/******************************************************************************************************
 *          Função: Actualizar um animal
 *          Retorno: retorna 0 se NÃO existe e 1 caso contrário
 *          Parâmetros: ponteiro para o ficheiro e o animal
*******************************************************************************************************/ 
void atualizar_animais(FILE *arq_animais, t_animal *animal_internado)   // recebe o ponteiro para o ficheiro e o animal
{
	// vai para o início do ficheiro
	rewind(arq_animais);

	t_animal animal;
	while(1) // ciclo para percorrer o ficheiro
	{

		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&animal, sizeof(t_animal), 1, arq_animais);

		// se for 0, é porque não há mais elemento, então sai do ciclo
		if(result == 0)
			break;

		// verifica se os ID's são iguais
		if(animal.id == animal_internado->id)
		{
			// fseek posiciona o ficheiro
			fseek(arq_animais, - sizeof(t_animal), SEEK_CUR);
			// atualiza o animal
			fwrite(animal_internado, sizeof(t_animal), 1, arq_animais);
			break; // sai do ciclo
		}
	}
}


/******************************************************************************************************
 *          Função: Internamento dos nimais
 *          Retorno: 
 *          Parâmetros: 
*******************************************************************************************************/
void internar_animal()
{
	char str_id_cliente[10];
	int id_cliente;
	FILE *arq_animais = fopen("animais.bin", "rb+");             	// rb+ abre para leitura/atualização
	FILE *arq_clientes = fopen("clientes.bin", "rb+");

	if(arq_animais == NULL)	            // se não conseguiu abrir, então cria o ficheiro
	{
		arq_animais = fopen("animais.bin", "wb+");        	// wb+ abre para escrita/atualização (cria o ficheiro se ele NÃO existir)
		if(arq_animais == NULL)
		{
			printf("\nFalha ao criar ficheiro(s)!\n");
			exit(1); // aborta o programa
		}
	}

	if(arq_clientes == NULL)
	{
		arq_clientes = fopen("clientes.bin", "wb+");
		if(arq_clientes == NULL)
		{
			printf("\nFalha ao criar ficheiro(s)!\n");
			exit(1); // aborta o programa
		}
	}


	printf("\nDigite o ID do cliente: ");   	// obtém o ID do cliente
	scanf("%10s%*c", str_id_cliente);

	fseek(stdin, 0, SEEK_END); // não recomendável o uso

	if(str_somente_numeros(str_id_cliente) == 1)
	{
		// se caiu aqui é porque o ID possui somente números, então
		// preenche a variável "id_cliente" com o valor de "str_id_cliente"
		sscanf(str_id_cliente, "%d", &id_cliente);


		if(existe_cliente(arq_clientes, id_cliente))	                 	// verifica se o ID do do cliente existe
		{
			char str_id_animal[10];
			int id_animal;

			printf("\nDigite o ID do animal: ");
			scanf("%10s%*c", str_id_animal);

			fseek(stdin, 0, SEEK_END); // não recomendável o uso

			if(str_somente_numeros(str_id_animal) == 1)				// se chegou aqui é porque o ID do animal é válido
			{
				sscanf(str_id_animal, "%d", &id_animal);
				t_animal *animal = obter_animal(arq_animais, id_animal);				// obtém o animal pelo ID

				if(animal != NULL) 				// testa se o animal existe...
				{				// se chegou aqui é porque o animal existe
					if(animal->id_cliente != -1)					// testa se o animal já está internado
						printf("\nO animal \"%s\" ja esta internado!\n", animal->nome);
					else
					{
						// se o animal NÃO está internado, então seta o
						// id_cliente do animal para associar o cliente
						// ao aluguel do animal em questão
						animal->id_cliente = id_cliente;
						atualizar_animais(arq_animais, animal); // atualiza o animal no ficheiro
						printf("\nanimal \"%s\" internado com sucesso!\n", animal->nome);
					}
					free(animal); // libera o animal alocado
				}
				else
					printf("\nNao existe animal com o ID \"%d\".\n", id_animal);
			}
			else
				printf("\nO ID so pode conter numeros!\n");
		}
		else
			printf("\nNao existe cliente com o ID \"%d\".\n", id_cliente);
	}
	else
		printf("\nO ID so pode conter numeros!\n");

	// fecha os ficheiros
	fclose(arq_clientes);
	fclose(arq_animais);

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}

/******************************************************************************************************
 *          Função: Entregar  um animal (dar alta)
 *          Retorno: 
 *          Parâmetros: 
*******************************************************************************************************/
void entregar_animal()
{
	char str_id_animal[10];
	int id_animal;
	FILE *arq_animais = fopen("animais.bin", "rb+"); 	// rb+ abre para leitura/atualização



	if(arq_animais == NULL)                      	// se não conseguiu abrir, então cria o ficheiro
	{
		arq_animais = fopen("animais.bin", "wb+");    	// wb+ abre para escrita/atualização (cria o ficheiro se ele NÃO existir)
		if(arq_animais == NULL)
		{
			printf("\nFalha ao criar ficheiro(s)!\n");
			exit(1); // aborta o programa
		}
	}

	printf("\nDigite o ID do animal: ");
	scanf("%10s%*c", str_id_animal);

	fseek(stdin, 0, SEEK_END); // não recomendável o uso

	if(str_somente_numeros(str_id_animal) == 1)
	{
		sscanf(str_id_animal, "%d", &id_animal);	                               	// se chegou aqui é porque o ID do animal é válido
		t_animal *animal = obter_animal(arq_animais, id_animal);	                         	// obtém o animal pelo ID


		if(animal != NULL)                                      		// testa se o animal existe...
		{                                                    			// se chegou aqui é porque o animal existe


			if(animal->id_cliente == -1)                                   			// testa se o animal já foi entregue
				printf("\nO animal \"%s\" ja esta disponivel para alta medica!\n", animal->nome);
			else  
			{                                                                               // se o animal NÃO foi entregue, então seta o
				animal->id_cliente = -1;     	                            // id_cliente para -1 para indicar que ele foi entregue
				atualizar_animais(arq_animais, animal);                                    // atualiza o animal no ficheiro
				printf("\nanimal \"%s\" entregue com sucesso!\n", animal->nome);
			}
			free(animal); // liberta memória
		}
		else
			printf("\nNao existe animal com o ID \"%d\".\n", id_animal);
	}
	else
		printf("\nO ID so pode conter numeros!\n");
        
	fclose(arq_animais);	                        // fecha o ficheiro

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END); 
}


/******************************************************************************************************
 *          Função: Excluir um animal (morte)
 *          Retorno: 
 *          Parâmetros: 
*******************************************************************************************************/
void excluir_animal()
{
	char str_id_animal[10];
	int id_animal;

	printf("\nDigite o ID do animal: ");
	scanf("%10s%*c", str_id_animal);

	fseek(stdin, 0, SEEK_END); 
    
	if(str_somente_numeros(str_id_animal) == 1)	                                   // verifica se str_id_animal só contém números
	{
		// se chegou aqui é porque o ID do animal é válido
		sscanf(str_id_animal, "%d", &id_animal);
		FILE *arq_animais = fopen("animais.bin", "rb");               		// rb abre para leitura (o ficheiro deve existir)

		if(arq_animais == NULL)
		{
			printf("\nFalha ao abrir ficheiro(s)!\n");
			exit(1); // aborta o programa
		}
        
		if(existe_animal(arq_animais, id_animal) == 1)                 		// verifica se o animal existe
		{
			char nome_animal[MAX];
			FILE *arq_temp = fopen("temp_animais.bin", "a+b");	  		// abre um novo ficheiro temporário
			if(arq_temp == NULL)
			{
				printf("\nFalha ao criar ficheiro temporario!\n");
				fclose(arq_animais);
				exit(1); // aborta o programa
			}
			rewind(arq_animais); // vai para o início do ficheiro

			t_animal animal;
			while(1) // ciclo para percorrer o ficheiro
			{
				size_t result = fread(&animal, sizeof(t_animal), 1, arq_animais);				// fread retorna o número de elementos lidos com sucesso

				if(result == 0)				// se for 0, é porque não há mais elemento, então sai do ciclo
					break;
				if(animal.id != id_animal)				// só copia para novo ficheiro se for diferente
				{
					fwrite(&animal, sizeof(t_animal), 1, arq_temp); 					// escreve no ficheiro temporário
				}
				else
					strcpy(nome_animal, animal.nome);
			}



			fclose(arq_animais);	                                  // antes de fazer operações de remover ficheiro e renomear,
			fclose(arq_temp);	                                     // é preciso fechar os dois ficheiros
			if(remove("animais.bin") != 0)	                        		// depois de fechar o ficheiro, então tentamos remover
				printf("\nErro ao eliminar o ficheiro \"animais.bin\"\n");
			else
			{
				int r = rename("temp_animais.bin", "animais.bin");				// renomeia o ficheiro
				if(r != 0)
				{
					printf("\nPermissao negada para renomear o ficheiro!\n");
					printf("Feche esse programa bem como o ficheiro \"temp_animais.bin\" e renomeie manualmente para \"animais.bin\"\n");
				}
				else
					printf("\nanimal \"%s\" removido com sucesso!\n", nome_animal);
			}
		}
		else
		{
			fclose(arq_animais);
			printf("\nNao existe animal com o ID \"%d\".\n", id_animal);
		}
	}
	else
		printf("\nO ID so pode conter numeros!\n");

	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END); 
}
