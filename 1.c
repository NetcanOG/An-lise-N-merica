//clear && gcc -Werror -o 1 1.c -lm && ./1 && rm 1

#include <stdio.h>

int main(){
   int k,precisao;
   double sol = 9.0,epsilon=1.0,temp;
   
   printf("intruduza a precisao.\n10^-");
   scanf("%d",&precisao);
   for(int i=0; i<precisao; i++) epsilon *=(double) 1/10;
   
   for(k = 2; ;k++) {
      temp = (double) sol * (k * k) / ((2*k+1)*(2*k+2));
      if(temp < epsilon) break;
      sol = temp;
   }
   
   printf("\nN de termos somados = %d\n",--k);
   printf("Valor final = %.*f +- 10^-%d\n",precisao+1,sol,precisao);
}
