#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

/*int* fat_boost;
double fat(int n){
   if(fat_boost[n]!=0) return fat_boost[n];
   fat_boost[n] = n*fat(n-1);
   return (double)fat_boost[n];
}

void build_fatBoost(int n){
   fat_boost = (int *)malloc(2*n*sizeof(int));
   for(int i=1; i<2*n; i++) fat_boost[i] = 0;
   fat_boost[0] = 1;
}*/

int main(){
   int n =20;
   
   //build_fatBoost(n);
   
   double sol = 9.0;
   double temp;
   
   for(int k=2; k<=n; k++){
      temp =1.0 * k * k / ((2*k+1)*(2*k+2));
      sol += temp;
      printf("Para k = %d, sol = %f, temp = %f\n",k,sol,temp);
   }
}
