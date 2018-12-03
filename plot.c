#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "pendulo.h"
#include "plot.h"

#define N_COMANDOS 5

int plot_Gnuplot(double theta){
    char * comandosGnuplot[N_COMANDOS] = {"set title 'theta_0 = 1.234567'", "set key above", "set xlabel 'Tempo (s)'", "set ylabel 'theta'", "plot 'theta_1.234567.data' title 'Sol numerica' with lines, 1.234567*cos(sqrt(9.8/10)*x) title 'Sol analituca aprox"};
    char buffer_comando0[120];
    char buffer_comando4[120];

    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    snprintf(buffer_comando0, 120, "set title 'theta_0 = %f'", theta);
    comandosGnuplot[0] = buffer_comando0;

    snprintf(buffer_comando4, 120, "plot 'theta_%f.data' title 'Sol numerica' with lines, %f*cos(sqrt(9.8/10)*x) title 'Sol analituca aprox", theta, theta);
    comandosGnuplot[4] = buffer_comando4;

    for (int i=0; i < N_COMANDOS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", comandosGnuplot[i]); //Send commands to gnuplot one by one.
    }
    fflush(gnuplotPipe);
    return 0;
}

double geraData_SolucaoNumerica (double theta_0,double e)
{
    double t1,t2,w1,w2 = 0;
    int cont=0; 

    //cria arquivo 'dump' com nome de acordo com theta
    char fnome[40];
    snprintf(fnome, 40, "theta_%f.data", theta_0);
    FILE * fdata = fopen(fnome, "w");
    if (fdata == NULL){
        printf("erro na criacao do arquivo de dados para plot\n");
        exit(-1);
    }

    t2 = 0;

    while(cont<4)
    {
        w1 = w2;
        t1 = t2;

        if(cont==0)
            fprintf(fdata, "%lf %lf \n", t2, theta_0);

        t2 = adaptPendulo (t1,0.01, &theta_0,&w2,e);
        if(w1*w2<0){
            cont++;
        }
    }
    //fecha arquivo
    fclose(fdata);

    return  (t1 +(fabs(w1)/(fabs(w1)+fabs(w2)))*(t2-t1))/5;
}
