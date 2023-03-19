#include <stdio.h>

float soma (float x, float y)
{
	return x + y;
}

float subtracao (float x, float y)
{
	return x - y;
}

float multiplicacao (float x, float y)
{
	return x * y;
}

float divisao (float x, float y)
{
	if ( y == 0)
		return -1;
	else
		return x / y;
}

float decisao (float x, float y, int sel)
{
		switch (sel)
	{
		case 1:
			return soma (x,y);
			break;
		case 2:
			return subtracao (x,y);
			break;
		case 3:
			return multiplicacao (x,y);
			break;
		case 4:
			return divisao (x,y);
			break;
		default:
			printf ("Input invalido\n");
			return -1;
	}
}

int main ()
{
	int sel = 0;
	float x = 0, y = 0, res = 0;
	printf ("Digite a operacao desejada: \n");
	printf ("*** Soma - 1  |  Subtracao - 2  |  Multiplicacao - 3  |  Divisao - 4 ***\n");
	scanf ("%d", &sel);
	printf ("Digite o primeiro valor: ");
	scanf ("%f", &x);
	printf ("Digite o segundo valor: ");
	scanf ("%f", &y);
	printf ("\n\n");
	res = decisao(x, y, sel);
	printf ("O resultado da operacao eh: %.2f\n\n", res);
	printf ("\n\n\n\n");
	int b = A;
	printf ("%d", b);
	return 0;
}