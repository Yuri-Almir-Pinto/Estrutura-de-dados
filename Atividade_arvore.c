#include <stdio.h>
#include <stdlib.h>

struct elemento {
	int dado;
	struct elemento *esq;
	struct elemento *dir;
};

typedef struct elemento *arvore;

arvore criaArvore () {
	return NULL;
}

int userQuery (){
	int dado;
	printf ("\nDigite o dado desejado: ");
	scanf ("%d", &dado);
	return dado;
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

arvore insereArvore (arvore *a, int info) {
	if ( (*a) == NULL) {
		(*a) = malloc(sizeof(struct elemento));
		(*a) -> dado = info;
		(*a) -> esq = NULL;
		(*a) -> dir = NULL;
	}
	
	else if (info < (*a) -> dado){
		insereArvore(&((*a) -> esq), info);
	}
	
	else if (info > (*a) -> dado){
		insereArvore(&((*a) -> dir), info);
	}
	
	else{
		printf("\nDado ja existente.\n");
	}
}

int buscarElemento (arvore a, int info) {
	if (a == NULL) {
		return NULL;
	}
	else if (a -> dado < info) {
		return buscarElemento(a -> dir, info);
	}
	else if (a -> dado > info) {
		return buscarElemento(a -> esq, info);
	}
	else {
		return a -> dado;
	}
}

int retirarElemento (arvore *a, int info) {
	arvore aux;
	
	if ((*a) == NULL) { // Verifica se a árvore é nula, ou se o elemento não foi encontrado.
		return NULL;
	}
	else if (info > (*a) -> dado) { // Se o dado a ser retirado for maior, vai para o nodo da direita
		retirarElemento(&((*a) -> dir), info);
	}
	else if (info < (*a) -> dado) { // Se  o dado a ser retirado for menor, vai para o nodo da esquerda
		retirarElemento(&((*a) -> esq), info);
	}
	else { // Ao encontrar o dado a ser retirado: 
		if ((*a) -> dir == NULL) { // Se o mesmo não tiver nenhum dado a direita, usar o dado a esquerda como substituto
			aux = *a;
			*a = aux -> esq;
			free(aux);
			return info;
		}
		else if ((*a) -> esq == NULL) { // Se o mesmo não tiver nenhum dado a esquerda, usar o dado a direita como substituto
			aux = *a;
			*a = aux -> dir;
			free(aux);
			return info;
		}
		else { // Se o nodo tiver ambos os lados com dados (Ou nenhum):
			antecessor(&(*a), &((*a) -> esq) );
			return info;
		}
		
	}
}

void antecessor (arvore *a, arvore *cand) {
	arvore aux;
	
	if ((*cand) -> dir != NULL) { // Se este não é o maior dado deste galho:
		antecessor(&(*a), &((*cand) -> dir));
	}
	else { // Se for o maior dado deste galho:
		(*a) -> dado = (*cand) -> dado; // O dado a ser removido é substituido pelo dado candidato
		aux = *cand; // Auxiliar recebe o endereço das informações do dado candidato
		*cand = aux -> esq; // O dado candidato recebe o endereço do dado a sua esquerda, para preserva-lo, caso exista.
		free(aux); // Auxiliar deleta as informações repetidas dos dados que agora estão guardados em *x
	}
}

void preOrdem (arvore a) {
	if (a != NULL) {
		printf ("%d - ", a -> dado);
		preOrdem(a -> esq);
		preOrdem(a -> dir);
	}
}

void posOrdem (arvore a) {
	if (a != NULL) {
		posOrdem(a -> esq);
		posOrdem(a -> dir);
		printf ("%d - ", a -> dado);
	}
}

void inOrdem (arvore a) {
	if (a != NULL) {
		inOrdem(a -> esq);
		printf ("%d - ", a -> dado);
		inOrdem(a -> dir);
	}
}

int main ()
{
	int sel = 0;
	arvore raiz = criaArvore();
	int result = 0;
	while (sel != 7)
	{
		printf ("\nEscolha a operacao desejada -\n");
		printf ("1 - Inserir Elemento\n");
		printf ("2 - Retirar Elemento\n");
		printf ("3 - Buscar Elemento\n");
		printf ("4 - Imprimir Pre-ordem\n");
		printf ("5 - Imprimir In-ordem (Crescente)\n");
		printf ("6 - Imprimir Pos-ordem\n");
		printf ("7 - Sair do programa\n");
		sel = funGetSel();
		switch (sel)
		{
			case 1:
				insereArvore(&raiz, userQuery());
				break;
			case 2:
				result = retirarElemento(&raiz, userQuery());
				if (result == NULL) {
					printf("\nArvore nula ou elemento nao existente.\n");
				}
				else {
					printf ("\nElemento %d retirado com sucesso.\n", result);
				}
				break;
			case 3:
				result = buscarElemento(raiz, userQuery());
				if (result != NULL) {
					printf("\nElemento %d encontrado na arvore.\n", result);
				}
				else {
					printf("\nElemento nao encontrado.\n");
				}
				break;
			case 4:
				preOrdem(raiz);
				break;
			case 5:
				inOrdem(raiz);
				break;
			case 6:
				posOrdem(raiz);
				break;
			case 7:
				break;
			default:
				printf ("Valor inputado invalido.\n");
		}
	}
}