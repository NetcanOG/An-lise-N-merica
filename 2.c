#include <stdio.h>

int main(){
int k;
double sum=1.0,temp,sol,epsilon=1.0;
int precisao;

printf("intruduza a precisao.\n10^-");
  scanf("%d",&precisao);


  for(int i=0; i<precisao; i++)
    epsilon *=(double) 1.0/10.0;


for(k=2;;k++){

    temp = (double) (1.0/(k*k));
    printf("%.15f\n",temp);

    if(temp < epsilon)
      break;

      else{
     if(k%2 == 0)
        sum-=temp;
        else
          sum+=temp;
}
}

printf("termos somados %d\n", k);

sol=12 * sum;

printf("%.15f\n",sol);
return 0;
}
