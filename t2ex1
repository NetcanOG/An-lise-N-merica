/* Separem graficamente as raı́zes de F (x) = 0 e determinem um intervalo I de amplitude 10^−1 que contenha a maior delas.

[1.6;1.7]
VALOR CORRETO = 1.61002255591604 */

#include <stdio.h>
#include <math.h>

double func(double x){
   return pow(x,2) - x - sin(x + 0.15);
}

// b >= a
void bissec_suc(double a, double b){
   int i,precisao = 8;
   double m,f_m,f_a, epsilon = 5 * pow(0.1,precisao), erro = b - a;
   for(i=0; erro > epsilon; i++){
      m = (a + b)/2.0;
      f_m = func(m);
      f_a = func(a);
      if(f_m == 0.0) erro = 0.0;
      else if((f_m * f_a) < 0.0) b = m;
      else a = m;
      erro /= 2;
   }
   printf("n = %d, v = %.*f\n",i,precisao+1,m);
}

int main(){
   bissec_suc(1.6,1.7);
}
