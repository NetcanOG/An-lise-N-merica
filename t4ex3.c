#include <stdio.h>
#include <math.h>

double a = 0.0, b = 3.0;
double M_integral_simps = 3385; //calculado externamente

double func(double x){
	return sin(cos(sin(cos(pow(x,2.0)))));
}

unsigned long intervalo_simps(double epsilon){
	unsigned long n = 1; // numero de subintervalos
	double h = (double)(b - a)/n; // tamanho de cada subintervalo
	double erro = (double)((pow(h,4.0)/180)*(b - a)* M_integral_simps);

	while( erro > epsilon ){
		n <<= 1;
		h = (double)(b - a)/n;
		erro = (double)((pow(h,4.0)/180)*(b - a)* M_integral_simps);
	}

	printf("%li\n",n);
	return n;
}
//maximize fourth derivate sin(cos(sin(cos(x^2)))) over [2.854120,2.854128]
//3384.8
double integral_simps(double epsilon){
	unsigned long n = intervalo_simps(epsilon);
	double h = (double)(b - a)/n;
	double value = 0.0;

	for(unsigned long i = 1; i <= n-1 ; i++){
    if(i%2!=0) value += 4*func(a + i*h);
    else value += 2*func(a + i*h);
  }
  value+= func(a)+func(b);
	return value*h/3;
}

int main(){
	printf("%.15f\n",integral_simps(pow(10,-5)));
	printf("%.15f\n",integral_simps(pow(10,-7)));
	printf("%.15f\n",integral_simps(pow(10,-9)));
}
