#define PI 3.1415926535897932384
double pendulo (double t, double h, double* theta, double* w);
double periodo (double theta_0,double h);
double periodo_simplificado (void);
double adaptPeriodo (double theta_0,double e);
double anguloMax(double e);