#include <stdio.h>
#include <math.h>
#include "pendulo.h"

int main(void)
{
	//essa main não é' minha, mas serve para testar. Espero que não seja um problema.
	double Tc;
	double T;
	double theta = 1;
	printf("Teste para Theta = 1\n");
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 3\n");
	theta=3;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 5\n");
	theta=5;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 10\n");
	theta=10;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 30\n");
	theta=30;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 60\n");
	theta=60;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);

	printf("Teste para Theta = 90\n");
	theta=90;
	T = periodo_simplificado(theta);
	Tc = periodo (theta);
	printf("Periodo da formula: %lf\n",T);
	printf("Periodo: %lf\n\n",Tc);
}