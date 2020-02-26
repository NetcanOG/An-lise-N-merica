#include <stdio.h>

int main(){
   int n = 20;
   double sol = 9.0,temp = 0.0;
   
   printf("Para k = 1, sol = %.20f, temp = %.20f\n",sol,temp);
   for(int k=2; k<=n; k++){
      temp =(double) k * k / ((2*k+1)*(2*k+2));
      sol += temp;
      printf("Para k = %d, sol = %.20f, temp = %.20f\n",k,sol,temp);
   }
   
   printf("\nValor final = %.20f +- percisao\n",sol);
}
