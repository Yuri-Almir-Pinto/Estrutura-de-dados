#include <stdio.h>
#include <string.h>

int roda = 0; //Variavel para contolar o While do Switch principal.
int sel = 0; //Variavel de selecao do While.
int atual = 0; //Variavel que define qual o index do struct atual.
struct aluno 
{
	char nome[40];
	int matricula;
	float nota1;
	float nota2;
	float media;
	int falta;
	char situacao;
} aluno[40];

struct aluno inserirAl() 
{
	struct aluno a;
	printf  ("Nome: ");
	fflush(stdin);
	fgets (a.nome, sizeof(a.nome), stdin);
	fflush(stdin);
	a.nome[strlen(a.nome)-1] = '\0';
	printf ("Matricula: ");
	scanf ("%d", &a.matricula);
	printf ("Nota 1: ");
	scanf ("%f", &a.nota1);
	printf ("Nota 2: ");
	scanf ("%f", &a.nota2);
	a.media = (a.nota1+a.nota2)/2;
	printf ("Faltas: ");
	scanf ("%d", &a.falta);
	if (a.media >= 6 && a.falta <= 20)
		a.situacao = 'A';
	else if (a.media < 6 || a.falta > 20)
		a.situacao = 'R';
	
	return a;
}

void listarAl ()
{
	for (int i = 0; i < atual; i++)
	{
		printf ("\nNome: %s\n", aluno[i].nome);
		printf ("Matricula: %d\n", aluno[i].matricula);
		printf ("Nota 1: %.1f\n", aluno[i].nota1);
		printf ("Nota 2: %.1f\n", aluno[i].nota2);
		printf ("Media: %.1f\n", aluno[i].media);
		printf ("Faltas: %d\n", aluno[i].falta);
		printf ("Situacao: %c\n", aluno[i].situacao);
	}
}

void salvarDadosAl ()
{
	FILE *turma;
	turma = fopen ("TurmaCadastro.txt", "w");
	if (turma == NULL)
	{
		printf ("\n\nErro na abertura do arquivo.\n\n");
		return;
	}
	fwrite(&aluno[0], sizeof(struct aluno),atual,turma);
	
	fclose(turma);
}
int carregarDadosAl ()
{
	FILE *turma;
	turma = fopen ("TurmaCadastro.txt", "r");
	if (turma == NULL)
	{
		printf ("\n\nErro na abertura do arquivo.\n\n");
		return -1;
	}
	int j = 0;
	int lido;
	do {
			lido = fread(&aluno[j], sizeof(struct aluno),1,turma);
			j++;
		} while (lido == 1);
	fclose(turma);
	return j-1;
}

int main ()
{
	while (roda==0)
	{
		printf ("\nDigite a opcao desejada: \n");
		printf ("\n---------------------------\n");
		printf ("\n1 - Inserir alunos.\n");
		printf ("2 - Listar alunos.\n");
		printf ("3 - Salvar dados.\n");
		printf ("4 - Carregar dados.\n");
		printf ("5 - Sair do programa.\n");
		scanf ("%d", &sel);
		switch (sel)
		{
			case 1:
				aluno[atual] = inserirAl();
				atual++;
				break;
			case 2:	
				listarAl();
				break;
			case 3:
				salvarDadosAl();
				break;
			case 4:
				atual = carregarDadosAl();
				break;
			case 5:
				roda = 1;
				break;
		}
	}

}
