#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

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

int addTelefone (listaTelefone *&ponteiroTelefone, char Telefone[])
{
	if(ponteiroTelefone == NULL)
	{
		listaTelefone *telefoneAux = (struct listaTelefone*) malloc (sizeof(listaTelefone*));
		strcpy(telefoneAux->telefone, Telefone);
	
		telefoneAux-> proxTel = ponteiroTelefone;
	
		ponteiroTelefone = telefoneAux;
		
		return 0;
	
	}
	
	addTelefone (ponteiroTelefone->proxTel, Telefone);
}

int addTelefoneExtra(listaTelefone *ponteiroTelefone)
{
	char Telefone[20]= "C";
	
	printf ("Digite 0 e aperte <ENTER> para sair.\n\n");

	while(true)
	{
		printf ("Qual o seu telefone?\n");
		fflush(stdin);
		scanf("%s",Telefone);
		
		if(strcmp(Telefone,"0")==0)
		{
			break;
		}else{
			addTelefone(ponteiroTelefone->proxTel, Telefone);
		}
	}	
}

int addDisciplina (listaDisciplina *&ponteiroDisciplina, char Disciplina[])
{
	if(ponteiroDisciplina == NULL)
	{
		listaDisciplina *DisciplinaAux = (struct listaDisciplina*) malloc (sizeof(listaDisciplina*));
		strcpy(DisciplinaAux->disciplina, Disciplina);
	
		DisciplinaAux->proxDiscp = ponteiroDisciplina;
	
		ponteiroDisciplina = DisciplinaAux;
		
		return 0;
	
	}
	
	addDisciplina (ponteiroDisciplina->proxDiscp, Disciplina);
}

int addDisciplinaExtra(listaDisciplina *ponteiroDisciplina)
{
	char Disciplina[50];
	printf ("Digite 0 e aperte <ENTER> para sair.\n\n");
	
	while(true)
	{
		printf ("Qual a disciplina?\n");
		fflush(stdin);
		scanf("%s",&Disciplina);
		
		if(strcmp(Disciplina,"0")==0)
		{
			break;
		}else{
			addDisciplina(ponteiroDisciplina->proxDiscp,Disciplina);
		}
	}	
}

int addLista(listaAluno *&ponteiroEncadeada, char Nome[], int Matricula, char Telefone[], char Email[], char Curso[], char Disciplina[])
{
	if(ponteiroEncadeada==NULL)
	{
		listaAluno *novaPessoa = (struct listaAluno*) malloc (sizeof(listaAluno*));
		
		novaPessoa->tel = NULL;
		novaPessoa->discp = NULL;
		
		addTelefone(novaPessoa->tel,Telefone);
		addDisciplina(novaPessoa->discp,Disciplina);
		
		novaPessoa->matricula = Matricula;
		
		strcpy(novaPessoa->nome, Nome);
		strcpy(novaPessoa->email, Email);
		strcpy(novaPessoa->curso, Curso);
		
		novaPessoa -> proximo = ponteiroEncadeada;
		
		ponteiroEncadeada = novaPessoa;
		
		return 0;
	}
	
	addLista(ponteiroEncadeada->proximo, Nome, Matricula, Telefone, Email, Curso, Disciplina);
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

int imprimeListaTelefone(listaTelefone *ponteiroTelefone)
{
	if(ponteiroTelefone==NULL)
	{
		return 0;
	}
	printf (" %s; ",ponteiroTelefone->telefone);	
	
	imprimeListaTelefone(ponteiroTelefone->proxTel);
}

int imprimeListaDisciplina(listaDisciplina *ponteiroDisciplina)
{
	if(ponteiroDisciplina==NULL)
	{
		return 0;
	}
	
	printf (" %s; ",ponteiroDisciplina->disciplina);	
	
	imprimeListaDisciplina(ponteiroDisciplina->proxDiscp);
}

void imprimeAluno (listaAluno *ponteiroEncadeada)
{
	printf("\nNome: %s",ponteiroEncadeada->nome);
	printf("\nMatrícula: %i",ponteiroEncadeada->matricula);
	printf("\nTelefone:");
	
	imprimeListaTelefone(ponteiroEncadeada->tel);
	
	printf("\nEmail: %s",ponteiroEncadeada->email);
	printf("\nCurso: %s",ponteiroEncadeada->curso);
	
	printf("\nDisciplina:");
	
	imprimeListaDisciplina(ponteiroEncadeada->discp);
	
}
	
int imprimeLista(listaAluno *ponteiroEncadeada)
{
	if(ponteiroEncadeada==NULL)
	{
		printf ("\n\n------------FIM LISTA--------------\n\n");
		return 0;
	}
	
	printf ("\n------------------------------------\n");
	imprimeAluno(ponteiroEncadeada);
	imprimeLista(ponteiroEncadeada->proximo);
	
}

listaAluno *procuraMatricula(listaAluno *ponteiroEncadeada, int Matricula)
{
	if(ponteiroEncadeada->matricula == Matricula)
	{		
		return ponteiroEncadeada;
		
	}else if(ponteiroEncadeada->proximo==NULL){
		
		printf ("\nA matrícula [%i] não foi encontrada!", Matricula);
		
		return 0;
	}
	
	procuraMatricula(ponteiroEncadeada->proximo, Matricula);
}

int procuraNome(listaAluno *ponteiroEncadeada, char Nome[])
{
	if(strcmpi(ponteiroEncadeada->nome,Nome)==0)
	{
		printf ("\n------------------------------------\n");
		imprimeAluno(ponteiroEncadeada);
	
		if(ponteiroEncadeada->proximo==NULL){
			return 0;
		}
		
	}else if(ponteiroEncadeada->proximo==NULL){
		printf ("\nO aluno [%s] não foi encontrado!",Nome);
		
		return 0;
	}
	
	procuraNome(ponteiroEncadeada->proximo, Nome);
}

int procuraLetra(listaAluno *ponteiroEncadeada, char Letra)
{
	if((ponteiroEncadeada->nome[0])==toupper(Letra))
	{
		printf ("\n------------------------------------\n");
		imprimeAluno(ponteiroEncadeada);
		
		if(ponteiroEncadeada->proximo==NULL){
			return 0;
		}
		
	}else if(ponteiroEncadeada->proximo==NULL){
		return 0;
	}
	
	procuraLetra(ponteiroEncadeada->proximo, Letra);
}

int main()
{
	setlocale(LC_ALL,"Portuguese");

	//Variáveis
	
	int Escolha, Matricula;
	char Nome[50], Telefone[12], Email[50], Curso[50], Disciplina[50], Letra;

	listaAluno *ponteiroEncadeada = NULL;
	
	do
	{
		system("cls");
		printf ("***********AGENDA DE ALUNOS DA UEG*************");
		printf ("\n\nDADOS DO ALUNO: ");
		
		printf ("\n\n[1]. Inserir um novo aluno");
		printf ("\n[2]. Adicionar novos dados");
		printf ("\n[3]. Excluir...");
		printf ("\n[4]. Procurar...");
		printf ("\n[5]. Listar os alunos existentes");
		printf ("\n[6]. Sair");
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
				
				printf ("Telefone: ");
				fflush(stdin);
				scanf ("%s",&Telefone);
				
				printf ("Email: ");
				fflush(stdin);
				scanf ("%s",&Email);
				
				printf ("Curso: ");
				fflush(stdin);
				scanf ("%s",&Curso);
				
				printf ("Disciplina: ");
				fflush(stdin);
				scanf ("%s",&Disciplina);
				
				addLista(ponteiroEncadeada, Nome, Matricula, Telefone, Email, Curso, Disciplina);
				
				break;
			
			case 2:
				
					printf ("*************ADICIONAR NOVOS DADOS*************\n\n");
					
					if(ponteiroEncadeada == NULL)
					{
						printf ("LISTA VAZIA! Nenhum aluno foi encontrado para exclusão");
						break;
					}
					
					printf ("Digite o número da matrícula e pressione <ENTER>: ");
					scanf("%i", &Matricula);
					
					do{
						system("cls");	
						printf ("*************ADICIONAR NOVOS DADOS*************\n\n");
						
						printf ("1. Telefone\n");
						printf ("2. Disciplina\n");
						printf ("\nDigite o número: ");
						scanf("%i",&Escolha);
						
						system("cls");	
						printf ("*************ADICIONAR NOVOS DADOS*************\n\n");
						
						switch(Escolha)
						{
							case 1:
							
								addTelefoneExtra(procuraMatricula(ponteiroEncadeada, Matricula)->tel);
								
								break;
							case 2:
								
								addDisciplinaExtra(procuraMatricula(ponteiroEncadeada,Matricula)->discp);
								
								break;
							default:
								
								printf ("Opção inválida! Digite novamente.\n");
								break;
						}
					}while(Escolha!=1&&Escolha!=2);
					
					printf ("\n-------------------------------\n");
					
				break;
				
			case 3:
				printf ("*************REMOVER MATRÍCULA*************\n\n");
				
				if(ponteiroEncadeada == NULL)
				{
					printf ("LISTA VAZIA! Nenhum aluno foi encontrado para exclusão\n\n");
					system("pause");
					
					break;
				}
				
				printf ("Digite o número da matrícula e pressione <ENTER>: ");
				scanf("%i", &Matricula);
				
				remove(ponteiroEncadeada, Matricula);
				
				printf ("A Matrícula [%i] foi removida com sucesso! \n\n", Matricula);
				system("pause");
				break;
			
			case 4:	
				
				printf ("*************PROCURAR ALUNO*************\n\n");
				
				if(ponteiroEncadeada == NULL)
				{
					printf ("LISTA VAZIA! Nenhum aluno foi encontrado\n\n");
					system("pause");
					break;
				}
				
				do{
					system("cls");
				
					printf ("*************PROCURAR ALUNO*************\n\n");
					printf ("1. Matrícula");
					printf ("\n2. Nome");
					printf ("\n3. Letra");
					printf ("\n\nEscolha um número e pressione <ENTER>: ");
		
					scanf ("%i",&Escolha);
		
					system("cls");
		
					switch(Escolha)
					{
						case 1: 
							printf ("*************PROCURAR ALUNO - MATRÍCULA*************\n\n");
							printf ("Digite o número da matrícula e pressione <ENTER>: ");
							scanf("%i", &Matricula);
												
							imprimeAluno (procuraMatricula(ponteiroEncadeada, Matricula));
							
							printf ("\n-------------------------------\n\n");
							
							system("pause");
							break;
					
						case 2:
							printf ("*************PROCURAR ALUNO - NOME*************\n\n");
							
							printf ("Digite o nome do aluno e pressione <ENTER>: ");
							fflush(stdin);
							scanf("%s", &Nome);
							
							procuraNome(ponteiroEncadeada,Nome);
							
							printf ("\n-------------------------------\n\n");
							system("pause");
							
							break;
						case 3:
							printf ("*************PROCURAR ALUNO - LETRA*************\n\n");
							
							printf ("Digite uma letra e pressione <ENTER>: ");
							fflush(stdin);
							scanf("%c", &Letra);
							
							procuraLetra(ponteiroEncadeada,Letra);
							
							printf ("\n-------------------------------\n\n");
							system("pause");
							
							break;
						default:
							printf ("Opção inválida! Digite novamente.\n\n");
							system("pause");
							break;
					}
				}while(Escolha!=1&&Escolha!=2&&Escolha!=3);
				
			
				break;
			case 5:
				
				printf ("*************LISTA DE ALUNOS*************\n\n");
				
				if(ponteiroEncadeada == NULL)
				{
					printf ("LISTA VAZIA! Nenhum aluno foi encontrado\n\n");
					system("pause");
					break;
				}
				
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
