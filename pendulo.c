#include <stdio.h>
#include <math.h>
#include "pendulo.h"

double x(double theta){
	double g=9.8;
	double l=10;
	return (-g/l)*sin(theta);
}

double pendulo (double t, double h, double* theta, double* w)
{
	double kt1, kt2, kt3, kt4;
	double kw1,kw2,kw3,kw4;
	
	kt1=h*(*w);
	kw1=h*x(*theta);
	
	kt2=h*(*w+kw1/2);
	kw2=h*x(*theta+kt1/2);
	
	kt3=h*(*w+kw2/2);
	kw3=h*x(*theta+kt2/2);
	
	kt4=h*(*w+kw3);
	kw4=h*x(*theta+kt3);
	
	*theta=*theta +(kt1+2*kt2+2*kt3+kt4)/6;
	*w=*w +(kw1+2*kw2+2*kw3+kw4)/6;

	return t+h;
}

double periodo (double theta_0,double h)
{
	double t1,t2,w1,w2 = 0;
	int cont=0;	

	while(cont<10)
	{
		w1=w2;
		t1=t2;
		t2=pendulo (t1,h, &theta_0,&w2);
		if(w1*w2<0){
			cont++;
		}
	}
	return 	(t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1))/5;
}

double periodo_simplificado (void)
{
	return 2*PI*sqrt(10/9.8);
}

double adaptPendulo (double t, double h, double* theta, double* w, double e)
{
	double theta1 = *theta;
	double w1=*w;
	double t1;
	double alpha; 

	t1 = pendulo(t,h, &theta1, &w1);

	alpha = sqrt(e/fabs(theta1 - *theta));

	if(alpha < 1)
		return adaptPendulo (t, alpha*h, theta, w, e);
	*theta = theta1;
	*w = w1;
	return t1;
}

double adaptPeriodo (double theta_0,double e)
{
	double t1,t2,w1,w2 = 0;
	int cont=0;	

	while(cont<10)
	{
		w1 = w2;
		t1 = t2;
		t2 = adaptPendulo (t1,0.01, &theta_0,&w2,e);
		if(w1*w2<0){
			cont++;
		}
	}
	return 	(t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1))/5;
}


double anguloMax(double e){
	double b = PI/2;
	double a = 0;
	double erro;
	double med;
	while(1){
		med = (a+b)/2;
		erro = (b-a)/2;
		if(erro <e)
			return med;
		if(fabs(periodo_simplificado()-adaptPeriodo(med,e))<0.001)
			a= med;
		else
			b=med;
		printf("theta %.16lf\t", med);
		printf("erro %.16lf\n", erro);
	}
} 