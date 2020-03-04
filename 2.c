
#include <stdio.h>

int main(){
int k=1;
double sum=0,temp,sol,epsilon;
int precisao;

printf("intruduza a precisao.\n10^-");
  scanf("%d",&precisao);


  for(int i=0; i<precisao; i++)
    epsilon *=(double) 1/10;


for(k=1;;k++){

    temp= (double) (1/(k*k));
    printf("%f",temp);
 if(temp<epsilon) break;
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
