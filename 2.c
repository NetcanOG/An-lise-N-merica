//clear && gcc -Werror -o 2 2.c -lm && ./2 && rm 2

#include <stdio.h>
#include <math.h>

double d_abs(double n){
   if(n>=0) return n;
   else return -n;
}

int serie(int precisao){
   double sum=0.0,temp,epsilon = pow(0.1,precisao);
   int k;

   for(k=1;;k++){
      temp = 12.0/pow(k,2);
      if(temp < epsilon) break;
      if(k%2 == 0) sum-=temp;
      else sum+=temp;
   }
   
   printf("N = %d E = 10^-%d\n",--k,precisao);
   printf("         S = %.*f\n",precisao+1,sum);
   printf("|pi^2 - S| = %.*f\n\n",precisao+1,d_abs(M_PI*M_PI - sum));
}

int main(){
   for(int i=8;i<=15;i++) serie(i);
}
