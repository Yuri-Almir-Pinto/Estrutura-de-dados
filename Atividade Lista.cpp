#include <stdio.h>
#include <string.h>
#define ITENS 10
#define TAM 40
int sair = 0;
int codAtu = 1;
int init = 0;
typedef char list[ITENS][TAM];
struct lista {
	list l;
	int codigo;
	int posicao = -1;
} tabela[10];

int main();
int checarSeCheio(int sel);

int funGetSel ()
{
	char selC;
	int sel;
	fflush(stdin);
	scanf ("%c", &selC);
	fflush(stdin);
	sel = selC - '0';
	if (sel != 1 && sel != 2 && sel != 3 && sel != 4 && sel != 5 && sel != 6 && sel != 7 && sel != 8 && sel != 9 && sel != 10)
	{
		printf ("\nInput invalido!\n");
		main();
	}
	else
		return sel;
}

int funMostraLista ()
{
	int sel = 0;
	printf ("\nSelecione a lista:\n");
	for (int i = 1; i < codAtu;i++)
	{
		printf (" - Lista %d -\n", i);
	}
	//scanf ("%d", &sel);
	//if (sel != 1 || sel != 2 || sel != 3 || sel != 4 || sel != 5 || sel != 6 || sel != 7 || sel != 8 || sel != 9 || sel != 10)
	//{
	//	printf ("Lista invalida!\n");
	//	main();
	//}
	sel = funGetSel();
	return sel;
}

void funMostraItens (int sel)
{
	for (int i = 0; i < 10; i++)
	{
		printf ("%d - %s\n", i+1, tabela[sel-1].l[i]);
	}
}

void criarLista ()
{
	if (codAtu == 11)
	{
		printf ("\nQuantia maxima de listas atingida.\n");
		return;	
	}
	tabela[codAtu-1].codigo = codAtu;
	for (int i = 0 ; i < 10 ; i++)
	{
		tabela[codAtu-1].l[i][0] = '\0';
	}
	tabela[codAtu-1].posicao = 0;
	printf ("\nLista codigo numero %d criada com sucesso.\n", codAtu);
	codAtu++;
}

void inserirElemento ()
{
	int sel = 0;
	int max;
	sel = funMostraLista();
	max = checarSeCheio(sel);
	if (max == 10)
	{
		printf ("\nQuantidade maxima de elementos atingida!\n");
		main();
	}
	printf ("\nDigite o item para inserir:\n");
	fflush(stdin);
	fgets (tabela[sel-1].l[tabela[sel-1].posicao], sizeof(tabela[sel-1].l), stdin);
	fflush(stdin);
	tabela[sel-1].l[tabela[sel-1].posicao][strlen(tabela[sel-1].l[tabela[sel-1].posicao])-1] = '\0';
	tabela[sel-1].posicao++;
}

void exibirLista ()
{
	int sel = 0;
	sel = funMostraLista();
	printf ("\n");
	funMostraItens(sel);
}

void retirarElemento ()
{
	int sel = 0;
	char deletar[TAM];
	int del;
	sel = funMostraLista();
	printf ("Escreva o item que deseja excluir: \n");
	funMostraItens(sel);
	fflush(stdin);
	fgets (deletar, sizeof(deletar), stdin);
	fflush(stdin);
	deletar[strlen(deletar)-1] = '\0';
	for (int i = 0 ; i < 11 ; i++)
	{
		del = strcmp(deletar, tabela[sel-1].l[i]);
		if (del == 0)
		{
			del = i;
			break;
		}
		else if (i == 10)
		{
			printf ("\nItem nao encontrado!\n");
			main();
		}
	}
	tabela[sel-1].l[del][0]= '\0';
	for (; del < 10 ; del++)
	{
		if (tabela[sel-1].l[del][0] != '\0')
		{
			strcpy (deletar, tabela[sel-1].l[del]);
			strcpy (tabela[sel-1].l[del-1], deletar);
			tabela[sel-1].l[del][0] = '\0';
		}
	}
	tabela[sel-1].posicao--;
}

int contarElementosLista ()
{
	int sel = 0;
	int contagem = 0;
	sel = funMostraLista();
	for (int i = 0; i < 10 ; i++)
	{
		if (tabela[sel-1].l[i][0] != '\0' || tabela[sel-1].l[i][0] != NULL)
			contagem++;
	}
	printf ("\nQuantidade de itens na lista %d: %d\n", sel, contagem);
	return contagem;
}

int checarSeCheio (int sel)
{
	int contagem = 0;
	for (int i = 0; i < 10 ; i++)
	{
		if (tabela[sel-1].l[i][0] != '\0' || tabela[sel-1].l[i][0] != NULL)
			contagem++;
	}
	return contagem;
}
int main ()
{
	if (init == 0)
		criarLista();
	init++;
	int sel = 0;
	while (sair == 0)
	{
		printf ("\nSelecione uma operacao:\n");
		printf ("1 - Inserir Elemento\n");
		printf ("2 - Retirar Elemento\n");
		printf ("3 - Criar Lista\n");
		printf ("4 - Contar Elementos da Lista\n");
		printf ("5 - Exibir Conteudo da Lista\n");
		printf ("6 - Sair\n");
		sel = funGetSel();
		switch (sel)
		{
			case 1:
				inserirElemento();
				break;
			case 2:	
				retirarElemento();
				break;
			case 3:
				criarLista();
				break;
			case 4:
				contarElementosLista();
				break;
			case 5:
				exibirLista();
				break;
			case 6:
				sair = 1;
				break;
			default:
				printf ("\nInput invalido.!\n");
				break;
		}
		
	}
	return 0;
}