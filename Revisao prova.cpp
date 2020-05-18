#include<stdio.h>
#include<stdlib.h>
#define TAM 10

/***************************************************lISTA ESTÁTICA***************************************************/

int Potencia(int NumeroX, int NumeroY)
{
	If(NumeroY==0)
		return 1;

	return NumeroX*potencia(NumeroX, NumeroY-1);
}
void Ordena(int vetor[TAM])
{
	int posicaoDoMenorValor, aux;
	
	for(int i=0; i<TAM; i++)
	{
		
		posicaoDoMenorValor = i;
		
		for(int j=i+1; j<TAM; j++)
		{
			if(vetor[j]<vetor[posicaoDoMenorValor])
			{
				posicaoDoMenorValor = j;
			}
		}
		
		if(posicaoDoMenorValor!=i)
		{
			aux = vetor[i];
			vetor[i] = vetor[posicaoDoMenorValor];
			vetor[posicaoDoMenorValor]=aux;
		}
	}
}

void Fibonacci(int valor)
{
	if(valor==1||valor==2)
		return 1;

	if(valor>2)
		return Fibonacci(valor-1)+Fibonacci(valor-2);
}

void InversaRecursiva(int Vetor1[TAM], int Vetor2[TAM], Cont, ContInverso)
{
	if(Cont<TAM)
	{
		Vetor2 [ContInverso] = Vetor [Cont];
	
		return InversaRecursiva(Vetor, Vetor2,Cont+1,ContInverso-1);
	}

}

void QuantidadeDeVezes(int Vetor[])
{
	int Cont, ElemMaior, ElemMenor, ValorMaior=0, ValorMenor=TAM*10;
	
	for(int I=0; I<TAM;I++)
	{
		Cont=0;
		
		for(int J=0; J<TAM; J++)
		{
			if(Vetor[I]==Vetor[J])
			{
				Cont++;
			}
		}
	
		if(Cont>ValorMaior)
		{
			ValorMaior = Cont;
			ElemMaior = Vetor[I];
		}
		if(Cont<ValorMenor)
		{
			ElemMenor = Vetor[I];
			ValorMenor = Cont;
		}
	}
	
	printf ("\n\nElemento Maior: %i se repetiu %i vezes\n\n",ElemMaior,ValorMaior);
	printf ("\n\nElemento Menor: %i se repetiu %i vezes\n\n",ElemMenor,ValorMenor);
}

void AritmeticaDesvioPadrao(float vet[], int N, float *media, float *desvio)
{

	for(int i=0; i<N; i++)
	{
 		*media = *media+vet[i];
 	}

 	*media = *media/N;

 	for(int i=0; i<N; i++)
 	*desvio = *desvio + (pow(vet[i],2)-*media);

	*desvio = sqrt(*desvio);
}

void InsereSemRepeticao(int Vetor[], int N)
{
	int Aux, Cont, Num;
	for(int i=0; i<N; i++)
	{
		do{
			Cont=0;

			printf ("%i° Numero: ",i+1);
			scanf("%i",&Num);
			
			for(int j=0; j<i; j++)
			{
				if(Num==Vetor[j]||Num<Vetor[j])
				{
					Cont=1;
					
					printf ("Este numero já foi digitado/É menor do que o inserido, insira outro numero\n");
					break;
				}
			}
		}while(Cont==1);
		
		Vetor[i]=Num;
	}

}

void MenorNumero (int Vetor[], int Num, int TAM, int i)
{
	if(i==TAM-1)
 	{
 		return Num;
 	}else if(i==0)
 	{
 		Num = Vetor[i];
 	}else if(Num>Vetor[i]){
 		
		 Num = Vetor[i];
 	}

 	Menor(Vetor,Num, TAM,++i);
}

/*--------------------------------------INSERE-----------------------------------------------*/
void InsereComeco(int Vetor[], int TamanhoDaLista, int novoValor)
{
	int i;
	
	for(i=TamanhoDaLista; i>0; i--)
	{
		if(i>0)
		{
			Vetor[i] = Vetor[i-1];
		}
	}
	
    Vetor[i] = novoValor;
	return TamanhoDaLista+1;
}

void InsereFinal (int Vetor[], int TamanhoDaLista, int novoValor)
{
	Vetor[TamanhoDaLista]=novoValor;
	
	return TamanhoDaLista+1;
}

int InsereNaPosicao (int Vetor[], int TamanhoDaLista, int novoValor, int posicao,int VetorAux[])
{   
    int i;
	
	for( i=0; i<posicao; i++)
	{
	    VetorAux[i]=Vetor[i];
	    
	}
	
	VetorAux[i]=novoValor;
	
	for( i=posicao+1;i<TamanhoDaLista+1;i++)
	{
	    VetorAux[i]=Vetor[i-1];
	    
	}
	
	return i;
}

/*--------------------------------------REMOÇÃO-----------------------------------------------*/
int RemoveComeco(int Vetor[], int TamanhoDaLista)
{   
    int i;
	
	for(i=0;i<TamanhoDaLista-1;i++)
	{
	    Vetor[i]=Vetor[i+1];
	}
	
	return i;
}

int RemoveFim(int Vetor[], int TamanhoDaLista, int VetorAux[])
{
    int i;
	
	for(i=0;i<TamanhoDaLista;i++)
	{
	    VetorAux[i]=Vetor[i];
	}
	
	return i-1;
}

int RemovePosicao(int Vetor[], int TamanhoDaLista, int VetorAux[], int posicao)
{   
    int i;
	
	for(i=0;i<TamanhoDaLista-1;i++)
	{
	    if(i<posicao)
	    {
	        VetorAux[i]=Vetor[i];
	    }else{
	        VetorAux[i]=Vetor[i+1];
	    }
	}
	
	return i;
}

/**************************************************LISTA ENCADEADA***************************************************/

/***************************************************INSERE***************************************************/
struct lista
{
	int numero;
	struct lista *prox;
};

lista *inverte(lista *ponteiroEncadeada)
{
	if(ponteiroEncadeada == NULL)
		return ponteiroEncadeada;
	
	lista *aux;
	aux = inverte(ponteiroEncadeada->próximo);
	
	ponteiroEncadeada->próximo->proximo= ponteiroEncadeada;
	ponteiroEncadeada->próximo = aux->proximo;
	
	return aux;
}

void insereInicio(lista *&ponteiroEncadeada, int Numero)
{
	lista *novoValor = (struct lista*) malloc (sizeof(lista*));
	novoValor->numero = Numero;
	
	if(ponteiroEncadeada==NULL)
		novoValor->prox=NULL;
	else
		novoValor->prox = ponteiroEncadeada;
	
	ponteiroEncadeada = novoValor;	
}

void insereFinal(lista *&ponteiroEncadeada, int Numero)
{
	lista *novoValor = (struct lista*) malloc (sizeof(lista*));
	novoValor->numero = Numero;
	novoValor->prox=NULL;
	
	lista *p = ponteiroEncadeada;
	
	while(p!=NULL)
	{
		if(p->prox==NULL)
		{
			p->prox = novoValor;
			return;
		}
	}
}

void insereLocal(lista *&ponteiroEncadeada, int Numero, int posicao)
{
	lista *novoValor = (struct lista*) malloc (sizeof(lista*));
	novoValor->numero = Numero;
	novoValor->prox=NULL;
	
	lista *p = ponteiroEncadeada;
	
	int Cont=0;
	
	while(Cont<=posicao)
	{
		if(Cont == posicao-1)
		{
			lista *aux = (struct lista*) malloc (sizeof(lista*));
			aux->prox=p->prox;
			p->prox = novoValor;
			novoValor->prox=aux->prox;
			
			free(aux);
		}
		p=p->prox;
		
		Cont++;
	}
		
}

/***************************************************REMOVE***************************************************/
void removeInicio(lista *&ponteiroEncadeada, int Numero)
{
	if(ponteiroEncadeada->prox==NULL)
	{
		lista *novoValor = (struct lista*) malloc (sizeof(lista*));
		novoValor->numero = 0;
		novoValor->prox=NULL;
		
		ponteiroEncadeada = novoValor;
	}
	
	ponteiroEncadeada = ponteiroEncadeada->prox;
}

void removeFim(lista *&ponteiroEncadeada, int Numero)
{
	lista *p = (struct lista*) malloc (sizeof(lista*));
	lista *aux = (struct lista*) malloc (sizeof(lista*));
	
	p = ponteiroEncadeada;
	while(p->prox!=NULL)
	{
		aux=p;
		p=p->prox;
		
	}
	
	aux->prox=NULL;
}

void removePosicao(lista *&ponteiroEncadeada, int posicao)
{
	lista *p = ponteiroEncadeada;
	
	int Cont=0;
	
	while(Cont<=posicao)
	{
		
		if(Cont ==posicao-1)
		{
			lista *aux = (struct lista*) malloc (sizeof(lista*));
			aux = p->prox;
			p->prox = aux->prox;
			
			free(aux);
		}
		p=p->prox;
		Cont++;
	}
}

void Busca(lista *ponteiroEncadeada, int Numero)
{
	lista *p = ponteiroEncadeada;
	
	while(p!=NULL)
	{
		if(p->numero==Numero)
		{
			printf ("%i",p->numero);
		}
		
		p=p->prox;
	}
}
