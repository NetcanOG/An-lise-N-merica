//clear && gcc -Werror -o 1 1.c -lm && ./1 && rm 1
// possivel optimizaçao no fact para memorizaçao embora as intancias maximas tem sido 23
#include <stdio.h>
#include <math.h>

double fact(int n){
	double t = 1.0;
	while(n != 0) t*=n--;
	return t;
}

void serie(int precisao){
   double somatorio = 0.0, termo = 1.0, epsilon = pow(0.1,precisao);
   int k;
   
   for(k=1; ;k++) {
      termo = 18.0 * pow(fact(k),2) / (pow(k,2) * fact(2*k));
      if(termo < epsilon) break;
      somatorio += termo;
   }
   
   printf("N de termos somados = %d\n",k-1);
   printf("Valor final = %.*f +- 10^-%d\n",precisao+1,somatorio,precisao);
   //printf("pi^2 =        %.*f\n",precisao+1,M_PI*M_PI);
}

int main(){
   for (int i=8; i<=15; i++) serie(i);
}
