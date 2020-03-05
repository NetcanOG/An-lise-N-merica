//clear && gcc -Werror -o 2 2.c -lm && ./2 && rm 2

#include <stdio.h>
#include <math.h>

int serie(int precisao){
   double sum=0.0,temp,epsilon = pow(0.1,precisao);
   int k;

   for(k=1;;k++){
      temp = 12.0/pow(k,2);
      if(temp < epsilon) break;
      if(k%2 == 0) sum-=temp;
      else sum+=temp;
   }
   
   printf("N de termos somados = %d\n",--k);
   printf("Valor final = %.*f +- 10^-%d\n",precisao+1,sum,precisao);
   printf("pi^2 =        %.*f\n",precisao+1,M_PI*M_PI);
}

int main(){
   for(int i=8;i<=15;i++) serie(i);
}

