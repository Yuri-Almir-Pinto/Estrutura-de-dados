#include <stdio.h>
#include <string.h>

int main ()
{
	FILE *teste;
	char dec, palavra[20];
	teste = fopen("ArquivoTeste.txt", "a");
	if (teste == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo.");
		return 1;
	}
	printf ("Arquivo aberto com sucesso. Deseja escrever algo nele? ('s' para Sim, e qualquer outra letra para Nao.)\n");
	scanf ("%c", &dec);
	fflush(stdin);
	if (dec == 's')
	{
		printf ("Digite o que deseja gravar no arquivo: \n");
		scanf ("%s", palavra);
		fgets(palavra, sizeof(palavra),stdin);
		fflush(stdin);
		fprintf (teste, "%s", palavra);
	}
	fclose (teste);
	return 0;
}