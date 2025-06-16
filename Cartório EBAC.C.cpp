#include <stdio.h>    // Biblioteca padrão para entrada e saída de dados
#include <stdlib.h>   // Biblioteca para alocação de memória e comandos como system()
#include <locale.h>   // Biblioteca para configurar a localidade (acentos, por exemplo)
#include <string.h>   // Biblioteca para manipulação de strings (como strcpy)

int registro()
{
	setlocale(LC_ALL, "Portuguese"); // Permite uso de acentos e caracteres do português
	
	// Declaração das variáveis que irão armazenar os dados
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Armazena o CPF digitado
	
	strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo que será criado
	
	FILE *file; // Declara um ponteiro para o arquivo
	file = fopen(arquivo, "w"); // Cria um novo arquivo com o nome do CPF
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo
	
	// Adiciona vírgula como separador
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); // Lê o nome
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo append (adicionar ao final)
	fprintf(file, nome); // Escreve o nome
	fclose(file);
	
	file = fopen(arquivo, "a"); // Adiciona vírgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // Lê o sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // Lê o cargo
	
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
	scanf("%s", cpf); // Lê o CPF para procurar o arquivo
	
	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo do CPF no modo leitura
	
	if(file == NULL)
	{
		// Caso o arquivo não exista
		printf("O arquivo não foi localizado (tente novamente). \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		// Lê e exibe o conteúdo do arquivo linha por linha
		printf("\nEssas são as infomações do usuário: ");
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
		// Arquivo não encontrado, ou seja, o usuário não existe
		printf("O usuário não se encontra no sistema!\n");
	}
	else
	{
		fclose(file); // Fecha antes de deletar

		if (remove(cpf) == 0) // Se conseguiu deletar
		{
			printf("USUÁRIO DELETADO COM SUCESSO\n");
		}
		else
		{
			printf("Erro ao deletar o usuário\n");
		}
	}
	
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Variável que guarda a opção escolhida pelo usuário
	int x=1;     // (não utilizada no código final, mas declarada)
	
	for(;;) // Loop infinito para manter o programa rodando até o usuário fechar
	{
		system("cls"); // Limpa a tela a cada repetição
		
		setlocale(LC_ALL, "Portuguese"); // Para exibir corretamente os acentos
		
		// Menu principal do sistema
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha uma das opções desejadas no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("opção: ");
		
		scanf("%d", &opcao); // Lê a opção do menu
		
		system("cls"); // Limpa a tela após a escolha
		
		// Estrutura de decisão baseada na opção do usuário
		switch(opcao)
		{
			case 1:
				registro(); // Chama a função de registrar nomes
				break;
				
			case 2:
				consulta(); // Chama a função de consultar nomes
				break;
				
			case 3:
				deletar(); // Chama a função de deletar nomes
				
				break;
			
			default:
				// Caso o usuário escolha uma opção inválida
				printf("Você escolheu uma opção invalida\n");
				system("pause");
				break;
		}
		
		// Mensagem final na tela principal
		printf("\t\t\t\t Esse Software é de uso livre");
	}
}
