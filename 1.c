//clear && gcc -Werror -o 1 1.c -lm && ./1 && rm 1

#include <stdio.h>
#include <math.h>

double fact(int n){
	double t = 1.0;
	while(n != 0) t*=n--;
	return t;
}

void serie(int precisao){
   double sum = 0.0, termo, epsilon = pow(0.1,precisao);
   int k;
   
   for(k=1;;k++) {
      termo = 18.0 * pow(fact(k),2) / (pow(k,2) * fact(2*k));
      if(termo < epsilon) break;
      sum += termo;
   }
   
   printf("N = %d E = 10^-%d\n",--k,precisao);
   printf("         S = %.*f\n",precisao+1,sum);
   printf("|pi^2 - S| = %.*f\n\n",precisao+1,pow(M_PI,2) - sum);
}

int main(){
   for (int i=8;i<=15;i++) serie(i);
}
