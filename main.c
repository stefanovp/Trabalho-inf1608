#include <stdio.h>
#include <math.h>
#include "pendulo.h"
#include <sys/time.h>

void getPeriodoPassoConstante(double* theta,double h);
int main(void)
{
	double theta[] = {PI/180,PI/60,PI/36,PI/18,PI/6,PI/3,PI/2};
	struct timeval start, stop;
	double num;
	long milisecs;
	
	printf("Comparacao do valor do periodo calculado\n");

	printf("--------------Simplificado--------------\n");
	gettimeofday(&start, NULL);
	num = periodo_simplificado ();
	gettimeofday(&stop, NULL);
	milisecs = (stop.tv_usec - start.tv_usec)/1000 + 1000* (stop.tv_sec - start.tv_sec);
	
	printf("Simplificada %.16lf\tTempo (ms) %ld\n",num,milisecs);
	printf("----------------------------------------\n");

	printf("-----------------h=0.01-----------------\n");
	getPeriodoPassoConstante(theta,0.01);
	printf("----------------------------------------\n");


	printf("-----------------h=0.001----------------\n");
	getPeriodoPassoConstante(theta,0.001);
	printf("----------------------------------------\n");


	printf("----------------h=0.0001----------------\n");
	getPeriodoPassoConstante(theta,0.0001);
	printf("----------------------------------------\n");


	printf("---------------Adaptativo---------------\n");
	for(int i=0;i<7;i++){
		gettimeofday(&start, NULL);
		num = adaptPeriodo (theta[i],0.00001);
		gettimeofday(&stop, NULL);
		milisecs = (stop.tv_usec - start.tv_usec)/1000 + 1000* (stop.tv_sec - start.tv_sec);
		printf("Theta %lf\tResultado %.16lf\tTempo (ms) %ld\n",theta[i],num,milisecs);
	}
	printf("----------------------------------------\n");

	printf("Angulo inicial maximo para simplifiacao ter erro menor que 0.001\n");
	printf("%.5lf\n", anguloMax(0.00001) );

}

void getPeriodoPassoConstante(double* theta,double h){
	double num;
	struct timeval start, stop;
	long milisecs;
	for(int i=0;i<7;i++){
		gettimeofday(&start, NULL);
		num = periodo (theta[i],h);
		gettimeofday(&stop, NULL);
		milisecs = (stop.tv_usec - start.tv_usec)/1000 + 1000* (stop.tv_sec - start.tv_sec);
		printf("Theta %lf\tResultado %.16lf\tTempo (ms) %ld\n",theta[i],num,milisecs);
	}
}