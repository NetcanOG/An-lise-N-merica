#include <stdio.h>
#include <math.h>

double a = 0.0, b = 3.0;
double M_integral_rect = 1.26038; //calculado externamente

double func(double x){
	return sin(cos(sin(cos(pow(x,2.0)))));
}

unsigned long intervalo_rect(double epsilon){
	unsigned long n = 1; // numero de subintervalos
	double h = (double)(b - a)/n; // tamanho de cada subintervalo
	double erro = (double)((b - a)/2.0 * h * M_integral_rect);
	
	while( erro > epsilon ){
		n <<= 1;
		h = (double)(b - a)/n;
		erro = (double)((b - a)/2.0 * h * M_integral_rect);
	}
	
	printf("%li\n",n);
	return n;
}

double integral_rect(double epsilon){
	unsigned long n = intervalo_rect(epsilon);
	double h = (double)(b - a)/n;
	double value = 0.0;
	
	for(unsigned long i = 1; i <= n ; i++){
		value += func(a + (i-1)*h);
	}
	
	return value*h;
}

int main(){
	printf("%.15f\n",integral_rect(pow(10,-5)));
	printf("%.15f\n",integral_rect(pow(10,-7)));
	printf("%.15f\n",integral_rect(pow(10,-9)));
}
