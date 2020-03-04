//clear && gcc -Werror -o 2 2.c -lm && ./2 && rm 2

#include <stdio.h>

int main(){
   double sum=0.0,temp,sol,epsilon=1.0;
   int precisao,k;

   printf("intruduza a precisao.\n10^-");
   scanf("%d",&precisao);
   for(int i=0; i<precisao; i++) epsilon *=(double) 1.0/10.0;

   for(k=2;;k++){
      temp = (double) (1.0/(k*k));
      printf("%.15f\n",temp);

      if(temp < epsilon) break;

      if(k%2 == 0) sum+=temp;
      else sum-=temp;
   }

   printf("\ntermos somados %d\n", k);

   sol= sum; //* 12;

   printf("%.15f\n",sol);
}
