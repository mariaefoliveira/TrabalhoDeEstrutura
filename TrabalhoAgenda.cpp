#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct listaAluno{
	char nome[50];
	int matricula;
	char email[50];
	char curso[50];
	
	struct listaAluno *proximo;
	struct listaTelefone *tel; 
	struct listaDisciplina *discp;
};

struct listaTelefone{
	char telefone[50];
	struct listaTelefone *proxTel;
};

struct listaDisciplina{
	char disciplina[50];
	struct listaDisciplina *proxDiscp;
};

int addLista(listaAluno *&ponteiroEncadeada, char Nome[], int Matricula)
{
	
	if(ponteiroEncadeada==NULL)
	{
		listaAluno *novaPessoa = (struct listaAluno*) malloc (sizeof(listaAluno*));
		
		novaPessoa->matricula = Matricula;
		strcpy(novaPessoa->nome, Nome);
		
		novaPessoa -> proximo = ponteiroEncadeada;
		
		ponteiroEncadeada = novaPessoa;
		
		return 0;
	}
	
	addLista(ponteiroEncadeada->proximo, Nome, Matricula);
}

int contador (listaAluno *ponteiroEncadeada, int Matricula, int Cont)
{
	if(ponteiroEncadeada->matricula==Matricula)
	{
		return Cont;
		
	}
	
	contador (ponteiroEncadeada->proximo, Matricula, ++Cont);
}

int remove(listaAluno *&ponteiroEncadeada, int Matricula)
{
	
	int Posicao = contador(ponteiroEncadeada, Matricula, 0);
	listaAluno *p=ponteiroEncadeada;
	
	for(int i=0; i<=Posicao; i++)
	{
		if(i == Posicao-1)
		{
			listaAluno *aux = (struct listaAluno*) malloc (sizeof(listaAluno*));
			
			aux = p->proximo;
			p->proximo = aux->proximo;
			
			free(aux);
			
			return 0;
		}
		
		if(i==Posicao)
		{
			ponteiroEncadeada = ponteiroEncadeada->proximo;
		}
		
		p=p->proximo;
	}
}
					
int imprimeLista(listaAluno *ponteiroEncadeada)
{
	if(ponteiroEncadeada==NULL)
	{
		printf ("\n------------FIM LISTA--------------\n\n");
		return 0;
	}
	
	printf ("\n-------------------------------\n");
		printf ("\nNome: %s ",ponteiroEncadeada->nome );
		printf ("\nMatrícula: %i ",ponteiroEncadeada->matricula );
	imprimeLista(ponteiroEncadeada->proximo);
}

int procuraMatricula(listaAluno *ponteiroEncadeada, int Matricula)
{
	if(ponteiroEncadeada->matricula == Matricula)
	{
		printf ("\nNome: %s",ponteiroEncadeada->nome);
		printf ("\nMatrícula: %i",ponteiroEncadeada->matricula);
			
		return 0;
		
	}else if(ponteiroEncadeada->proximo==NULL){
		printf ("\nA matrícula [%i] não foi encontrada!",Matricula);
		
		return 0;
	}
	
	procuraMatricula(ponteiroEncadeada->proximo, Matricula);
}

int main()
{
	setlocale(LC_ALL,"Portuguese");

	//Variáveis
	
	int Escolha, Matricula;
	char Nome[50], Telefone[12], SegundoNome[50], Email[50], Curso[50], Disciplina[50];

	listaAluno *ponteiroEncadeada = NULL;
	listaTelefone *ponteiroTelefone = NULL;
	listaDisciplina *ponteiroDisciplina = NULL;
	
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
		
		scanf ("%i",&Escolha);
		
		system("cls");
		
		switch(Escolha)
		{
			case 1:
				
				printf ("*************INSERIR NOVO ALUNO*************\n\n");
				
				printf ("Nome: ");
				fflush(stdin);
				scanf ("%s",&Nome);
				
				printf ("Matrícula: ");
				scanf ("%i", &Matricula);
				
				addLista(ponteiroEncadeada, Nome, Matricula);
				
				break;
			
			case 3:
				printf ("*************REMOVER MATRÍCULA*************\n\n");
				
				if(ponteiroEncadeada == NULL)
				{
					printf ("LISTA VAZIA! Nenhum aluno foi encontrado para exclusão");
					break;
				}	
				
				printf ("Digite o número da matrícula e pressione <ENTER>: ");
				scanf("%i", &Matricula);
				
				remove(ponteiroEncadeada, Matricula);
				
				printf ("A Matrícula [%i] foi removida com sucesso! ", Matricula);
				break;
			
			case 4:
				printf ("*************PROCURAR MATRÍCULA*************\n\n");
				
				if(ponteiroEncadeada == NULL)
				{
					printf ("LISTA VAZIA! Nenhum aluno foi encontrado");
					system("pause");
					break;
				}	
				
				printf ("Digite o número da matrícula e pressione <ENTER>: ");
				scanf("%i", &Matricula);
				
				procuraMatricula(ponteiroEncadeada, Matricula);
				
				printf ("\n-------------------------------\n");
				system("pause");
				
				break;
			case 5:
				printf ("*************LISTA DE ALUNOS*************\n\n");
				
				imprimeLista(ponteiroEncadeada);
				
				system("pause");
				break;
			case 6:
				
				printf ("PROGRAMA ENCERRADO COM SUCESSO!!!\n\n");
				system("cls");
				break;
			default: 
				printf ("\n\nOpção inválida! digite novamente.\n\n");
				system("pause");
		}
	}while (Escolha!=6);

	return 0;
}
