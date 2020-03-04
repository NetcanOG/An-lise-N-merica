//clear && gcc -Werror -o 2 2.c -lm && ./2 && rm 2
//calcula sem underflow 10^-9

#include <stdio.h>

int main(){
   double sum=1.0,temp,sol,epsilon=1.0;
   int precisao,k;

   printf("Introduza a precisao.\n10^-");
   scanf("%d",&precisao);
   for(k=0; k<precisao; k++) epsilon *=(double) 1.0/10.0;

   for(k=2;;k++){
      temp = (double) (1.0/(k*k));
      if(temp < epsilon) break;
      //printf("%.15f > %.15f\n",temp,epsilon);
      if(k%2 == 0) sum+=temp;
      else sum-=temp;
   }
   //printf("%.52f < %.52f\n",temp,epsilon);
   
   printf("\nN de termos somados = %d\n",--k);

   sol= sum * 12;
   printf("Valor final = %.*f +- 10^-%d\n",precisao+1,sol,precisao);
}
