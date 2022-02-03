#include <stdio.h>
#include <math.h>

double a = 0.0, b = 3.0;
double M_integral_trap = 11.26; //calculado externamente

double func(double x){
	return sin(cos(sin(cos(pow(x,2.0)))));
}

unsigned long intervalo_trap(double epsilon){
	unsigned long n = 1; // numero de subintervalos
	double h = (double)(b - a)/n; // tamanho de cada subintervalo
	double erro = (double)(pow(h,2)/12.0 * (b - a) * M_integral_trap);
	
	while( erro > epsilon ){
		n <<= 1;
		h = (double)(b - a)/n;
		erro = (double)(pow(h,2)/12.0 * (b - a) * M_integral_trap);
	}
	
	return n;
}

double integral_trap(double epsilon){
	unsigned long n = intervalo_trap(epsilon);
	double h = (double)(b - a)/n;
	double value = 0.0;
	
	for(unsigned long i = 1; i < n ; i++){
		value += func(a + (i)*h);
	}
	
	value = value*h + h/2.0*(func(a) + func(b));
	printf("n = %li\n",n);
	printf("value = %.15f\n\n", value);
	return value;
}

int main(){
	integral_trap(pow(10,-5));
	integral_trap(pow(10,-7));
	integral_trap(pow(10,-9));
}

