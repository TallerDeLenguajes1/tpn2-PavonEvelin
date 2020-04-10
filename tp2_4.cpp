#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

struct compu {
int velocidad;//entre 1 y 3 Gherz
int anio;//entre 2000 y 2017
int cantidad;//entre 1 y 4
char *tipo_cpu;//valores del arreglo tipos
};

void cargarPC(struct compu *puntCompus, int cant, char *puntTipos);
void mostrarPC(struct compu *puntCompus, int cant);
void verPC(struct compu PC);
void pcMasVieja(struct compu *puntCompus, int cant);
void pcMasVeloz(struct compu *puntCompus, int cant);

int main(void) {
  srand(time(NULL));
  char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
  char *puntTipos;
  struct compu Compus[MAX]; //arreglo de estructura.
  struct compu *puntCompus; //puntero al arreglo de estructura.
  int cant;
  
  printf("Ingrese la cantidad de PCs, no debe ser mayor a 10\n");
  scanf("%d", &cant);
 
  //CARGO EL ARREGLO DE ESTRUCTURA
  puntCompus = &Compus[0];
  puntTipos = &tipos[0][0];
  cargarPC(puntCompus,cant,puntTipos);

  //MOSTRAR LAS PCs
  puntCompus = &Compus[0];
  mostrarPC(puntCompus,cant);

  //MOSTRAR PC MAS VIEJA
  puntCompus = &Compus[0];
  pcMasVieja(puntCompus,cant);

  //MOSTRAR PC MAS VELOZ
  puntCompus = &Compus[0];
  pcMasVeloz(puntCompus, cant);

  return 0;
}

void cargarPC(struct compu *puntCompus, int cant, char *puntTipos){
  int aux;
  for(int i=0; i<cant; i++){
    puntCompus->velocidad = rand()%3 +1;
    puntCompus->anio = rand()%18 +2000;
    puntCompus->cantidad = rand()%4 +1;
    aux = (rand()%6)*10;
    puntCompus->tipo_cpu = (puntTipos+aux);

    puntCompus++;
  }
}

void mostrarPC(struct compu *puntCompus, int cant){
  for(int i=0; i<cant; i++){
    printf("PC %d\n",i+1);
    printf("Velocidad de procesamiento en GHz: %d GHz\n", puntCompus->velocidad);
    printf("Año de fabricación: %d\n", puntCompus->anio);
    printf("Cantidad de núcleos: %d\n", puntCompus->cantidad);
    printf("Tipo de procesador: %s\n\n", puntCompus->tipo_cpu);

    puntCompus++;
  }
}

void verPC(struct compu PC){
  printf("Velocidad de procesamiento en GHz: %d GHz\n", PC.velocidad);
  printf("Año de fabricación: %d\n", PC.anio);
  printf("Cantidad de núcleos: %d\n", PC.cantidad);
  printf("Tipo de procesador: %s\n\n", PC.tipo_cpu);
}

void pcMasVieja(struct compu *puntCompus, int cant){
  struct compu PCVieja, PC;
  PCVieja.anio = 2020;
  
  for(int i=0; i<cant; i++){
    PC = *puntCompus;
    if(PC.anio < PCVieja.anio){
      PCVieja = PC;
    }
    puntCompus++;
  }

  printf("La PC mas vieja es:\n");
  verPC(PCVieja);
  
}

void pcMasVeloz(struct compu *puntCompus, int cant){
  struct compu PCMasVeloz, PC;
  PCMasVeloz.velocidad = 0;

  for(int i=0; i<cant; i++){
    PC = *puntCompus;
    if(PC.velocidad > PCMasVeloz.velocidad){
      PCMasVeloz = PC;
    }
    puntCompus++;    
  }

  printf("La PC con mayor velocidad de procesamiento es::\n");
  verPC(PCMasVeloz);

}