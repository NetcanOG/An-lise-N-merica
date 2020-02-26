#include <stdio.h>

int main(){
   int k=2,precisao;
   double sol = 9.0,epsilon=1.0;
   
   printf("intruduza a precisao.\n10^-");
   scanf("%d",&precisao);
   for(int i=0; i<precisao; i++) epsilon *=(double) 1/10;
   
   do {
      sol *= (double) (k * k) / ((2*k+1)*(2*k+2));
      k++;
   } while (sol > epsilon);
   
   printf("\nN de termos somados = %d\n",--k);
   printf("Valor final = %.*f +- 5*10^-%d\n",precisao-1,sol,precisao);
}
