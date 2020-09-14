#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int ehPrimo(long num) {
   long divisor;

   if( num <= 1 )
    return 0;
   else
    if(num > 3){
      if(num % 2 == 0)
        return 0;
      long max_divisor = sqrt(num);
      for(divisor = 3; divisor <= max_divisor; divisor += 2)
	    if (num % divisor == 0)
	       return 0;
    }
   return 1;
}

int main() {
  long LIMITE_MAX = 2000000;
  long contaPrimo;
  long soma;
  int n;
  double tempo = 0;

  tempo = omp_get_wtime();
  if (LIMITE_MAX <= 1)
    soma = 0;
  else {
    soma = 1;
    /*#pragma omp parallel for private (contaPrimo) 
    for (n = 3; n < LIMITE_MAX; n += 2){
      contaPrimo = ehPrimo(n);
      #pragma omp critical
      soma = soma + contaPrimo;
    }*/
    
    /*#pragma omp parallel for private (contaPrimo) 
    for (n = 3; n < LIMITE_MAX; n += 2){
      contaPrimo = ehPrimo(n);
      #pragma omp critical
      soma = soma + contaPrimo;
    }*/

    #pragma omp parallel for reduction(+:soma) schedule (dynamic,100)
    for (n = 3; n < LIMITE_MAX; n += 2){
      contaPrimo = ehPrimo(n);
      soma = soma + contaPrimo;
    }
  }
  tempo -= omp_get_wtime();
  printf("%lf\n", tempo);
  printf("Número total de primos: %ld\n", soma);

  return 0;
}

