#include <stdio.h>

struct pilha {
	int dado;
	struct pilha *prox;
};

typedef struct pilha *topo;

topo criarPilha () {
	return NULL;
}

int funGetSel ()
{
	char selC;
	int sel;
	fflush(stdin);
	scanf ("%c", &selC);
	fflush(stdin);
	sel = selC - '0';
	return sel;
}

topo empilharDado (topo inicio)
{
	topo p;
	int dado;
	p = malloc(sizeof(struct pilha));
	printf ("Digite o dado (Numero) para ser inserido: ");
	scanf ("%d", &dado);
	p -> dado = dado;
	p -> prox = inicio;
	return (p);
}

void imprimeLista (topo inicio)
{
	topo p = inicio;
	printf ("\n");
	while (p != NULL)
	{
		printf ("%d - ", p -> dado);
		p = p -> prox;
	}
	printf ("\n");
}

topo desempilha (topo inicio, int *desempilhado)
{
	topo p;
	if (inicio != NULL)
	{
		*desempilhado = inicio -> dado;
		p = inicio;
		inicio = inicio -> prox;
		free(p);
	}
	else 
	{
		*desempilhado = -1;
		printf ("\nPilha vazia.\n");
	}
	return (inicio);
}

int main ()
{
	int* desempilhado;
	int sel = 0;
	topo inicio = criarPilha();
	while (sel != 4)
	{
		printf ("\nEscolha a operacao desejada -\n");
		printf ("1 - Empilhar Elemento\n");
		printf ("2 - Desempilhar Elemento\n");
		printf ("3 - Imprimir conteudo da pilha\n");
		printf ("4 - Sair do programa\n");
		sel = funGetSel();
		switch (sel)
		{
			case 1:
				inicio = empilharDado(inicio);
				break;
			case 2:
				inicio = desempilha(inicio, &desempilhado);
				printf ("\nValor desempilhado: %d\n", desempilhado);
				break;
			case 3:
				imprimeLista(inicio);
				break;
			case 4:
				break;
			default:
				printf ("Valor inputado invalido.\n");
		}
	}
}