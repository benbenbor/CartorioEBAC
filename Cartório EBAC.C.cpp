#include <stdio.h>    // Biblioteca padr�o para entrada e sa�da de dados
#include <stdlib.h>   // Biblioteca para aloca��o de mem�ria e comandos como system()
#include <locale.h>   // Biblioteca para configurar a localidade (acentos, por exemplo)
#include <string.h>   // Biblioteca para manipula��o de strings (como strcpy)

int registro()
{
	setlocale(LC_ALL, "Portuguese"); // Permite uso de acentos e caracteres do portugu�s
	
	// Declara��o das vari�veis que ir�o armazenar os dados
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Armazena o CPF digitado
	
	strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo que ser� criado
	
	FILE *file; // Declara um ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Cria um novo arquivo com o nome do CPF
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	// Adiciona v�rgula como separador
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); // L� o nome
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo append (adicionar ao final)
	fprintf(file, nome); // Escreve o nome
	fclose(file);
	
	file = fopen(arquivo, "a"); // Adiciona v�rgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // L� o sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // L� o cargo
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); // Escreve o cargo no arquivo
	fclose(file);
	
	system("pause"); // Pausa o sistema antes de voltar ao menu
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultada: ");
	scanf("%s", cpf); // L� o CPF para procurar o arquivo
	
	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo do CPF no modo leitura
	
	if(file == NULL)
	{
		// Caso o arquivo n�o exista
		printf("O arquivo n�o foi localizado (tente novamente). \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		// L� e exibe o conte�do do arquivo linha por linha
		printf("\nEssas s�o as infoma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r"); // Verifica se o arquivo existe
	
	if(file == NULL)
	{
		// Arquivo n�o encontrado, ou seja, o usu�rio n�o existe
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	else
	{
		fclose(file); // Fecha antes de deletar

		if (remove(cpf) == 0) // Se conseguiu deletar
		{
			printf("USU�RIO DELETADO COM SUCESSO\n");
		}
		else
		{
			printf("Erro ao deletar o usu�rio\n");
		}
	}
	
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Vari�vel que guarda a op��o escolhida pelo usu�rio
	int x=1;     // (n�o utilizada no c�digo final, mas declarada)
	
	for(;;) // Loop infinito para manter o programa rodando at� o usu�rio fechar
	{
		system("cls"); // Limpa a tela a cada repeti��o
		
		setlocale(LC_ALL, "Portuguese"); // Para exibir corretamente os acentos
		
		// Menu principal do sistema
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha uma das op��es desejadas no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("op��o: ");
		
		scanf("%d", &opcao); // L� a op��o do menu
		
		system("cls"); // Limpa a tela ap�s a escolha
		
		// Estrutura de decis�o baseada na op��o do usu�rio
		switch(opcao)
		{
			case 1:
				registro(); // Chama a fun��o de registrar nomes
				break;
				
			case 2:
				consulta(); // Chama a fun��o de consultar nomes
				break;
				
			case 3:
				deletar(); // Chama a fun��o de deletar nomes
				
				break;
			
			default:
				// Caso o usu�rio escolha uma op��o inv�lida
				printf("Voc� escolheu uma op��o invalida\n");
				system("pause");
				break;
		}
		
		// Mensagem final na tela principal
		printf("\t\t\t\t Esse Software � de uso livre");
	}
}
