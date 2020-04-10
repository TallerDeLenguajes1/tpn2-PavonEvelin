#include<stdio.h>
#define N 4
#define M 5

int main(){
	double mt[N][M], *punt_mt;
    int aux=4;
    punt_mt = &mt[0][0];

    for(int i=0; i<(M*N); i++){
        printf("%lf ", *punt_mt);
        punt_mt++;
        if(i == aux){
            printf("\n");
            aux +=5;
        }
    }
	
	
	return 0;
}


