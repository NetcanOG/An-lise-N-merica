#include <stdio.h>

int* fat_boost;

int fat(int n){
   if(fat_boost[n]!=0) return fat_boost[n];
   fat_boost[n] = n*fat(n-1);
   return fat_boost[n];
}

void build_fatBoost(int n){
   fat_boost = (int *)malloc(2*n*sizeof(int));
   for(int i=1; i<2*n; i++) fat_boost[i] = 0;
   fat_boost[0] = 1;
}

int main(){
   int k;
   
   build_fatBoost(k);
   
}
