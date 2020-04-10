#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); //utilizo esta func. para que no se repitan los numeros.
  int F=15, C= rand()%11 +5; //num. de columnas entre 5 y 15.
  int Matriz[F][C], *puntMatriz= &Matriz[0][0] ;
  int Pares[F], cont;
 
  printf("NUMERO DE COLUMNAS %d\n", C);

  for(int i=0; i<F; i++){
    cont=0;
    for(int j=0; j<C; j++){
      *puntMatriz = rand()%900 +100; //num. aleatorio entre 100 y 999.
      printf("%d ", *puntMatriz);
      if(*puntMatriz % 2 == 0){
        cont++;
      }
      puntMatriz++;
    }
    printf("\n"); //salto de filas
    Pares[i] = cont;
  }

  printf("Cantidad de numeros pares por fila\n");
  for(int k=0; k<F; k++){
     printf("%d ", Pares[k]);
  }
  

  return 0;
}