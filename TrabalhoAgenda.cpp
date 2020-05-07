/*Elabore uma programa em C para implementar uma Agenda Eletrônica dos alunos da UEG. 
Serão armazenados os seguintes dados de cada aluno: Matricula, Nome, Telefone, 
e-mail, curso, disciplinas e outros que acharem necessários. 
A Agenda deverá ser implementada através de uma Lista Encadeada. Como um aluno pode ter vários 
telefones e disciplinas, estes campos também devem ser implementados como uma Lista cada. 
Colocar todas as funções de manipulação da lista (criar, incluir, excluir, buscar, listar); 
Trabalhar através de menu.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<iostream>
#include<new>

using namespace std;

struct estruturaAluno{
	
	char nomeAluno[50];
	int matricula;
	char email[50];
	int telefone;	
	char curso[50];
	char disciplina[50];
	
	struct estruturaAluno *proximo;
};

int imprimeEncadeada(estruturaAluno *ponteiroEncadeada)
{
	//estruturaAluno *p = ponteiroEncadeada;
	
	if(ponteiroEncadeada==NULL)
	{
		return 0;
	}
	
	cout << "\nMatrícula: "<<ponteiroEncadeada->matricula;
	
	imprimeEncadeada(ponteiroEncadeada->proximo);
}
	
estruturaAluno *criaNovaListaFim(int Matricula, int Telefone)
{
	estruturaAluno *novaPessoa = new estruturaAluno;
	
	novaPessoa -> matricula = Matricula;
	novaPessoa -> telefone = Telefone;
	novaPessoa -> proximo = NULL;
	
}

/***estruturaAluno *adicionaFimLista(estruturaAluno *ponteiroEncadeada, char Nome[], int Matricula, char Email[], int Telefone, char Curso[], char Disciplina[])
{
	if(ponteiroEncadeada==NULL)
	{
		ponteiroEncadeada = criaNovaListaFim(Matricula, Telefone);
		return ponteiroEncadeada;
	}
	
	adicionaFimLista(ponteiroEncadeada ->proximo, Nome, Matricula, Email, Telefone, Curso, Disciplina);
}***/

int main ()
{
	setlocale(LC_ALL,"Portuguese");
	
	//Criando o início da lista
	estruturaAluno *ponteiroEncadeada = new estruturaAluno;
	
	//Variáveis
	
	int Escolha, Telefone, Matricula;
	char Nome[50], Email[50], Curso[50], Disciplina[50];
	
	//Cria um novo valor (Eu poderia utilizar o new que tem a mesma função em JAVA?)
	
	//estruturaAluno *novoValor = (struct estruturaAluno*) malloc(sizeof(struct estruturaAluno));
	estruturaAluno *novoValor = new estruturaAluno;
	
	novoValor -> matricula = 1234;
	novoValor -> proximo = NULL;
	
	//Fará ponteiro da lista encadeada irá apontar para o primeiro valor
	
	ponteiroEncadeada = novoValor;
	
	//Cria um segundo valor
	
	//estruturaAluno *novoSegundoValor = (struct estruturaAluno*) malloc(sizeof(struct estruturaAluno));
	estruturaAluno *novoSegundoValor = new estruturaAluno;
	
	novoSegundoValor -> matricula = 3215;
	novoSegundoValor -> proximo = NULL;
	
	//Junta os valores com um encadeamento
	novoValor -> proximo = novoSegundoValor;
	
	//Imprime a lista encadeada (deve passar comoo parâmetro o ponteiro principal)
	imprimeEncadeada(ponteiroEncadeada);
	
	
	//Mostrando o menu
	do
	{
		system("cls");
		printf ("***********AGENDA*************");
		printf ("\n\nDADOS DO ALUNO: ");
		printf ("\n\n1. Inserir um novo aluno");
		printf ("\n2. Adicionar novos dados");
		printf ("\n3. Excluir...");
		printf ("\n4. Procurar...");
		printf ("\n5. Listar os alunos existentes");
		printf ("\n6. Sair");
		printf ("\n\nEscolha um número e pressione <ENTER>: ");
		scanf ("%i", &Escolha);
		
		
		switch(Escolha)
		{
			case 1:
				system("cls");
				
				printf ("*************INSERIR NOVO ALUNO*************\n\n");
			
				/**printf ("Nome: ");
				scanf ("%s", &Nome);
			
				printf ("Matrícula: ");
				scanf ("%i",&Matricula);
			
				printf ("\nEmail: ");
				scanf ("%s", &Email);
			
				printf ("\nTelefone: ");
				scanf ("%i", &Telefone);
			
				printf ("\nCurso: ");
				scanf ("%s", &Curso);
				
				printf ("\nDisciplina: ");
				scanf ("%s", &Disciplina);**/
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				system("cls");
				break;
			case 5:
				
				system("cls");
				printf ("*************ALUNOS*************\n\n");
				imprimeEncadeada(ponteiroEncadeada);
				cout<<"\n";
				system ("pause");
				
				break;
			case 6:
				system("cls");
				break;
			default: 
				printf ("\n\nOpção inválida! digite novamente.\n\n");
				system("pause");
		}
	}while (Escolha!=6);

	
	
	return 0;
}
