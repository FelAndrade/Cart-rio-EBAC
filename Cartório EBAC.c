#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de aLocação de espaço em memória
#include <locale.h> // biblioteca de aLocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registrar() // função de registro
{
	//início criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se às strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valore das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write (escrever)
	fprintf(file, cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar() // funççao de consulta
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o CPF, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //função de deletar
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}

}

int main () //função principal
{
	int opcao=0; //definindo variáveis
	int laco=1; //definindo repetição

	for(laco=1;laco=1;)
	{
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - excluir nomes\n"); 
		printf("\t4 - sair do sistema\n\n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registrar(); //chamada de funções
			break;
		
			case 2:
			consultar();
			break;

			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
		
		
			default:
			printf("Essa opção não está disponível. Escolha 1, 2 ou 3!\n"); //fim da seleção
			system("pause");
			break;
		}
	}
}

