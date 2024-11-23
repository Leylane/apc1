#include<stdio.h>

int main(){
    int numeros[10];

    for(int i=0; i<10; i++){
        scanf("%i", &numeros[i]);
    }

    int numero;
    scanf("%i", &numero);

    int achou = -1;
    for(int i=0; i<10; i++){
        if (numeros[i] == numero) {
    achou = i;
        }
    }
    if(achou > 0) {
    printf("%i\n", achou);
    } else {
        printf("O numero nao foi encontrado");
    }
    return 0;
 }