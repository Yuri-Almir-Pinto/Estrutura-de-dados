#include <stdio.h>

struct elemento {
	int dado;
	struct elemento *prox;
};

typedef struct elemento nodo;
typedef nodo *lista;

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

lista inserirElemento (lista l)
{
	lista p;
	lista ant;
	lista novo;
	int dados;
	printf ("\nDigite o dado a ser inserido: ");
	scanf ("%d", &dados);
	p = l;
	ant = p;
	while (p != NULL && dados > p -> dado)
	{
		ant = p;
		p = p -> prox;
	}
	novo = malloc(sizeof(struct elemento));
	novo -> dado = dados;
	novo -> prox = p;
	if (p == l)
	{
		l = novo;
	}
	else
		ant -> prox = novo;
	return l;
}

void exibirLista (lista l)
{
	lista p;
	printf("\nItens da lista\n");
	p = l;
	while (p != NULL)
	{
		printf("%d - ",p->dado);
		p = p->prox;
	}
	printf("\n");
}

lista retirarElemento (lista l)
{
	int retirar;
	exibirLista(l);
	printf ("\nDigite o dado que deseja retirar: ");
	scanf ("%d", &retirar);
	lista p = l;
	lista ant = p;
	while (p != NULL && p -> dado != retirar)
	{
		ant = p;
		p = p -> prox;
	}
	if (p == NULL)
	{
		printf ("\nNumero nao encontrado.\n");
		return l;
	}
	if (p == l)
	{
		l = l -> prox;
		free(p);
		return l;
	}
	else
	{
		ant -> prox = p -> prox;
		free(p);
	}
	return l;
}

lista buscarElemento (lista l)
{
	int buscar;
	int i = 0;
	lista p = l;
	exibirLista(l);
	printf ("\nDigite o numero que deseja buscar: ");
	scanf ("%d", &buscar);
	while (p != NULL && p -> dado != buscar)
	{
		p = p -> prox;
	}
	if (p != NULL) {
		printf ("\nDado encontrado na lista na posicao de memoria: %d\n", p);
	}
	else 
		printf ("\nDado nao encontrado na lista. Posicao NULL\n");
	return l;
}

lista contarElementos (lista l)
{
	lista p = l;
	int i = 0;
	while (p != NULL)
	{
		p = p -> prox;
		i++;
	}
	printf ("\nNumero de elementos na lista: %d\n", i);
	return l;
}

int main ()
{
	lista l = NULL;
	int sel = 0;
	while (sel != 6)
	{
		printf ("\nSelecione uma operacao:\n");
		printf ("1 - Inserir Elemento\n");
		printf ("2 - Retirar Elemento\n");
		printf ("3 - Buscar Elemento\n");
		printf ("4 - Imprimir Lista\n");
		printf ("5 - Contar Numero de Elementos na lista\n");
		printf ("6 - Sair\n");
		sel = funGetSel();
		
		switch (sel)
		{
			case 1:
				l = inserirElemento(l);
				break;
			case 2:
				l = retirarElemento(l);
				break;
			case 3:
				l = buscarElemento(l);
				break;
			case 4:
				exibirLista(l);
				break;
			case 5:
				l = contarElementos(l);
				break;
			case 6:
				break;
			default:
				printf ("\nInput invalido!\n");
				break;
		}
		
	}
	return 0;
}

