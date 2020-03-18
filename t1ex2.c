//clear && gcc -Werror -o 2 2.c -lm && ./2 && rm 2

#include <stdio.h>
#include <math.h>

double d_abs(double n){
   if(n>=0) return n;
   else return -n;
}

void serie(){
   int k,precisao = 8;
   double sum = 0.0,termo,epsilon = pow(0.1,precisao);

   for(k=1;precisao <=15;k++){
      termo = 12.0/pow(k,2);
      if(termo < epsilon){
         printf("N = %d E = 10^-%d\n",k-1,precisao);
         printf("         S = %.*f\n",precisao+1,sum);
         printf("|pi^2 - S| = %.*f\n\n",precisao+1,d_abs(pow(M_PI,2) - sum));
         
         precisao++;
         epsilon *= 0.1;
      }
      if(k%2 == 0) sum-=termo;
      else sum+=termo;
   }
}

int main(){
   serie();
}
