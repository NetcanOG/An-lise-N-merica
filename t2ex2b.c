#include <stdio.h>
#include <math.h>

double absoluto(double x){
  if(x >= 0.0) return x;
  else return -x; 
}

double f(double x){
    return -2 + 6*x - 4*pow(x,2) + 0.5*pow(x,3);
}

double df(double x){
    return 6 - 8*x + 1.5*pow(x,2);
}

void newton(double x0){
    int iter = 1, precisao = 6;
    double x1 = x0 - (f(x0)/df(x0));
    double erroiter = absoluto(x1-x0), epsilon = pow(0.1,precisao);

    while(erroiter >= epsilon){
        x0 = x1;
        x1 = x0 - f(x0)/df(x0);
        erroiter = absoluto(x1 - x0);
        iter++;
    }

	printf("Metodo de Newton: n = %2d, v = %.*f, erro = %.*f\n", iter, precisao+1, x1, precisao+1, erroiter);
}

int main(){
    newton(3.5);
    newton(6.5);
    newton(4.4);
}
