#include <stdio.h>
#include <stdlib.h>

struct elemento {
	int dado;
	struct elemento *prox;
};
	
typedef struct elemento *pElemento;

typedef struct {
	pElemento ini;
	pElemento fim;
} fila;

fila criaFila ()
{
	fila f;
	f.ini = NULL;
	f.fim = NULL;
	return f;
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

fila inserirFila (fila fi)
{
	pElemento aux;
	aux = malloc(sizeof(struct elemento));
	int e;
	printf ("Digite o dado (Numero) para ser inserido: ");
	scanf ("%d", &e);
	aux -> dado = e;
	aux -> prox = NULL;
	if (fi.ini == NULL){
		fi.ini = aux;
		fi.fim = aux;
	}
	else {
		fi.fim -> prox = aux;
		fi.fim = aux;
	}	
	return fi;
}

fila retirarFila (fila fi, int *e)
{
	pElemento aux;
	aux = malloc(sizeof(struct elemento));
	if (fi.ini == NULL) {
		printf("\nLista vazia.\n");
		*e = -1;
	}
	else {
		*e = fi.ini -> dado;
		aux = fi.ini;
		fi.ini = fi.ini -> prox;
		free(aux);
		if (fi.fim == NULL) {
			fi.fim = NULL;
		}
		return fi;
	}
}

void imprimeFila (fila fi)
{
	pElemento aux = fi.ini;
	printf ("\n");
	while (aux != NULL){
		printf ("%d - ", aux -> dado);
		aux = aux -> prox;
	}
	printf ("\n");
}



int main ()
{
	fila f = criaFila();
	int sel = 0;
	while (sel != 4)
	{
		printf ("\nEscolha a operacao desejada -\n");
		printf ("1 - Inserir Elemento no final da lista\n");
		printf ("2 - Retirar Elemento no inicio da lista\n");
		printf ("3 - Imprimir conteudo da lista\n");
		printf ("4 - Sair do programa\n");
		sel = funGetSel();
		switch (sel)
		{
			case 1:
				f = inserirFila(f);
				break;
			case 2: ;
				int *e;
				f = retirarFila (f, e);
				printf ("\nElemento retirado: %d\n", *e);
				break;
			case 3:
				imprimeFila(f);
				break;
			case 4:
				break;
			default:
				printf ("Valor inputado invalido.\n");
		}
	}


}