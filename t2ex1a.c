/* Separem graficamente as raı́zes de F (x) = 0 e determinem um intervalo I de amplitude 10^−1 que contenha a maior delas.
[1.6;1.7]
VALOR CORRETO = 1.61002255591604 */

#include <stdio.h>
#include <math.h>

double absoluto(double x){
  if(x >= 0.0) return x;
  else return -x; 
}

double func(double x){
   return pow(x,2) - x - sin(x + 0.15);
}

//BISSECAO SUCESSIVA
void bissec_suc(double a, double b){
   int i,precisao = 8;
   double m,f_m,f_a, epsilon = 5 * pow(0.1,precisao), erro = absoluto(b - a);
   for(i=0; erro > epsilon; i++){
      m = (a + b)/2.0;
      f_m = func(m);
      f_a = func(a);
      if(f_m == 0.0) erro = 0.0;
      else if((f_m * f_a) < 0.0) b = m;
      else a = m;
      erro /= 2;
   }
   printf("Metodo de bissecao sucessiva: n = %2d, v = %.*f, erro = %.*f\n", i, precisao+1, m, precisao+1, erro);
}

//ITERATIVO SIMPLES
double func_iterativa(double x){
  return 1 + (sin(x + 0.15) / x);
  //Função obtida por manipulação algébrica da função original
}

void iter_simples(double x0, int nmax){
  int i = 1, precisao = 8;
  double x1 = func_iterativa(x0);
  double erroiter = absoluto(x1 - x0), epsilon = 5 * pow(0.1,precisao);

  while( i <= nmax && erroiter > epsilon){
    x0 = x1;
    x1 = func_iterativa(x0);
    erroiter = absoluto(x1 - x0);
    i++;
  }
  
  if(i > nmax) printf("Metodo iterativo simples: não foi possível ao fim de %d iteracoes encontrar a solucao com o erro pretendido\n", i);
  else printf("Metodo iterativo simples:     n = %2d, v = %.*f, erro = %.*f\n", i, precisao+1, x1, precisao+1, erroiter); 
}

//METODO DE NEWTON
double df(double x){
    return 2*x - 1 - cos(x - 0.15);
}

void newton(double x0){
    int iter = 1, precisao = 8;
    double x1 = x0 - (func(x0)/df(x0));
    double erroiter = absoluto(x1-x0), epsilon = 5 * pow(0.1,precisao);

    while(erroiter >= epsilon){
        x0 = x1;
        x1 = x0 - func(x0)/df(x0);
        erroiter = absoluto(x1 - x0);
        iter++;
    }

	printf("Metodo de Newton:             n = %2d, v = %.*f, erro = %.*f\n", iter, precisao+1, x1, precisao+1, erroiter);
}

int main(){
   bissec_suc(1.6,1.7);
   iter_simples(1.6,20);
   newton(1.6);
}
