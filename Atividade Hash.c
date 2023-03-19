# include <stdio.h>
# include <stdlib.h>
# define TAM 20

struct elemento {
	int valor;
	struct elemento *prox;
};

typedef struct elemento *lista;

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

int userQuery (){
	int dado;
	printf ("\nDigite o dado desejado: ");
	scanf ("%d", &dado);
	return dado;
}

lista criaLista() {
	return NULL;
}

void exibirLista (lista l)
{
	lista p;
	p = l;
	while (p != NULL)
	{
		printf("%d - ",p->valor);
		p = p->prox;
	}
	printf("\n");
}

lista inserirLista (lista l, int dado)
{
	lista p;
	lista ant;
	lista novo;
	p = l;
	ant = p;
	while (p != NULL && dado > p -> valor)
	{
		ant = p;
		p = p -> prox;
	}
	novo = malloc(sizeof(struct elemento));
	novo -> valor = dado;
	novo -> prox = p;
	if (p == l)
	{
		l = novo;
	}
	else
		ant -> prox = novo;
	return l;
}

lista retirarLista (lista l, int retirar)
{
	lista p = l;
	lista ant = p;
	while (p != NULL && p -> valor != retirar)
	{
		ant = p;
		p = p -> prox;
	}
	if (p == NULL)
	{
		printf ("\nDado nao encontrado.\n");
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

void criaHash (lista *h) {
	for (int i=0;i<TAM;i++) {
		h[i] = criaLista();
	}
}

int hash(int chave) {
	return (chave % TAM);
}

void inserirHash (lista *h, int chave) {
	int posicao = hash(chave);
	h[posicao] = inserirLista(h[posicao], chave);
}

void retirarHash (lista *h, int chave) {
	int posicao = hash(chave);
	h[posicao] = retirarLista(h[posicao], chave);
}

void imprimirHash (lista *h) {
	printf("\n");
	for (int i=0;i<TAM;i++) {
		printf("Hash[%d]: ", i);
		exibirLista(h[i]);
	}
}

void buscarHash (lista *h, int chave) {
	printf ("\n");
	int posicao = hash(chave);
	if (h[posicao] != NULL && h[posicao] -> valor == chave) {
		printf("Valor encontrado na posicao %d do vetor.\n", posicao);
	}
	else {
		printf("Valor nao encontrado.\n");
	}
}
int main () {
	int sel = 0;
	lista hash[TAM];
	criaHash(hash);
	while (sel != 5)
	{
		printf ("\nSelecione uma operacao:\n");
		printf ("1 - Inserir Elemento\n");
		printf ("2 - Retirar Elemento\n");
		printf ("3 - Buscar Elemento\n");
		printf ("4 - Imprimir todos os elementos\n");
		printf ("5 - Sair\n");
		sel = funGetSel();
		
		switch (sel)
		{
			case 1:
				inserirHash(hash, userQuery());
				break;
			case 2:
				retirarHash(hash, userQuery());
				break;
			case 3:
				buscarHash(hash, userQuery());
				break;
			case 4:
				imprimirHash(hash);
				break;
			case 5:
				break;
			default:
				printf ("\nInput invalido!\n");
				break;
		}
		
	}
	return 0;
}