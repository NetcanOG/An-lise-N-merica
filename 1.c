//clear && gcc -Werror -o 1 1.c -lm && ./1 && rm 1

#include <stdio.h>
#include <math.h>

// verifiquei que k <= 25 e suficiente
double mem_fact[51];

void m_fact_init(){
   mem_fact[0] = 1.0;
   for(int i=1; i<50; i++) mem_fact[i] = 0.0;
}

double m_fact(int n){
   if(mem_fact[n] != 0.0) return mem_fact[n];
   mem_fact[n] = n*m_fact(n-1);
   return mem_fact[n];
}

void serie(int precisao){
   double sum = 0.0, termo, epsilon = pow(0.1,precisao);
   int k;
   
   for(k=1;;k++) {
      termo = 18.0 * pow(m_fact(k),2) / (pow(k,2) * m_fact(2*k));
      if(termo < epsilon) break;
      sum += termo;
   }
   
   printf("N = %d E = 10^-%d\n",--k,precisao);
   printf("         S = %.*f\n",precisao+1,sum);
   printf("|pi^2 - S| = %.*f\n\n",precisao+1,pow(M_PI,2) - sum);
}

int main(){
   m_fact_init();
   
   for (int i=8;i<=15;i++) serie(i);
}
