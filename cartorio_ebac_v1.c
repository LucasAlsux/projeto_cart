#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alicação de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <strings.h> //biblioteca responsavel pelo gerenciamento de strings

int registro()
{
    setlocale(LC_ALL, "Portuguese"); //definindo linguagem 

	char arquivo[40]; //variaveis que serão utilizadas
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\t- Selecionado: Registrar usuário\n\n");
    system("pause");
    system("cls");
    
	printf("Digite seu CPF: "); //pede ao usuario que insira cpf
	scanf("%s", cpf); //armazrena o cpf do usuario na variavel cpf
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //comando para criar arquivo
	file = fopen(arquivo, "w"); //arquivo criado
	fprintf(file, "CPF: "); //recurso visual
	fprintf(file, cpf); //indica o que será salvo no arquivo
	fclose(file); //fecha o arquivo

	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo e indica que sera adcionada uma nova informação
	fprintf(file, "\nNome: "); //apenas um recurso visual :)
	fprintf(file, nome); //salva nome do usuario no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // abre arquivo
	fprintf(file, "\nSobrenome: "); //recurso visual
	fprintf(file, sobrenome); //salva sobremone
	fclose(file); //fecha arquivo
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file, "\nCargo: "); //recurso visual
	fprintf(file, cargo); //salva cargo do usuario
	fclose(file); //fecha arquivo
	
	printf("\n"); //recurso visual
	
	printf("Registrado com sucesso :)\n");
	
	system("pause"); //congela a tela
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\t- Selecionado: Consultar usuário\n\n");
    system("pause");
    system("cls");    
    
	printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	printf("Essas são as informações do usuário:\n\n");
	
	if (file == NULL)
	{
		printf("CPF não encontrado!\n\n");
	} 
	
	while(fgets(conteudo, 200, file) != NULL)
    {
	printf("\n\n");
	printf("%s", conteudo);
	printf("\n\n");
    }
    
	fclose(file);
	system("pause");
    
}

int deletar()
{
    char cpf[40];
    
	printf("\t- Selecionado: Deletar usuário\n\n");
    system("pause");
    system("cls"); 
    
    printf("Digite o CPF do usuário que deseja deletar: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file==NULL)
    {
    	system("cls");
    	printf("Usuário não encontrado\n\n");
    	system("pause");
    	system("cls");
	}

    fclose(file);
}


int main()
{

int opcao=0; //definindo variaveis 

int loop=1;

    for (loop=1; loop=1;)
    { 
      
    setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
    system("cls");
	printf("\t- Cartório EBAC -\n\n"); //inicio do menu
    printf("Escolha qual função deseja executar:\n\n");
	printf("\t1 - Registrar usuário;\n");
    printf("\t2 - Consultar usuário;\n");
    printf("\t3 - Deletar usuário;\n");
    printf("\t4 - Sair do programa.\n\n\n");     
  
    printf("Opção: "); //final do menu
    
	scanf("%d", &opcao); //armazenando escolha do usuário
    
    system("cls");
    
	switch(opcao)
	{
		case 1: 
		registro();
    	break;
    	
    	case 2:
        consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4: 
		printf("Obrigado!");
		return 0;
		break;
			
		default: 	
	    printf("\t- Opção indisponível =(  \n\n");
	    system("pause");
		break;
			
	}
    	
    }
}
