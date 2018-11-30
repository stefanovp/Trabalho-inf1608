#include <math.h>
#include "pendulo.h"
#include <stdio.h>
#define G 9.8
#define L 10.0
#define PI 3.14159265358979323846

double pendulo (double t, double h, double* theta, double* w){
	
	double k1[2], k2[2], k3[2], k4[2];

	k1[0] = *w*h;
	k1[1] = (-(G/L)*sin(*theta))*h;

	k2[0] = (*w + k1[1]/2)*h;
	k2[1] = (-(G/L)*sin(*theta + k1[0]/2))*h;

	k3[0] = (*w + k2[1]/2)*h;
	k3[1] = (-(G/L)*sin(*theta + k2[0]/2))*h;

	k4[0] = (*w + k3[1])*h;
	k4[1] = (-(G/L)*sin(*theta + k3[0]))*h;

	*theta = *theta + (k1[0] + 2*k2[0] + 2*k3[0] + k4[0])/6;
	*w = *w + (k1[1] + 2*k2[1] + 2*k3[1] + k4[1])/6;

	return t+h;

}

double periodo (double theta_0){

	double theta=theta_0;
	double T=0, t1=0, t2=0, w1=0, w2=0, h=0.001;
	int i=0;

	theta=theta*PI/180;
	
	//10 inversoes
	while(i<10){
		w1=w2;
		t1=t2;

		t2=pendulo (t1,h, &theta, &w2);

		if(w1*w2<0){
			i++;
		}
	}

	T=(2*(t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1)));

	return T/10;

}

double periodo_simplificado (double theta0){
	return 2*PI*sqrt(L/G);
}