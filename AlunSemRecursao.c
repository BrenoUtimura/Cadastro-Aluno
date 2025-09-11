#include <stdio.h>
#include <stdlib.h>

int main(void){

    float * vetor;
    int n, i;

    scanf("%d", &n);

    vetor = (float *) malloc(sizeof(float) * n);

    if(vetor == NULL){
        printf("Não foi possível alocar memória para o vetor!\n");
        return 0;
    }

    for(i = 0; i < n; i++){
        scanf("%f", &vetor[i]);
    }

    for(i = 0; i < n; i++){
        printf("%.2f\n", vetor[i]);
    }

    free(vetor);

    return 0;
}