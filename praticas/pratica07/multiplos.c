#include <stdio.h>

int main(){

    int numero;
    printf("Digite um numero: \n");
    scanf("%i", &numero);
    printf("Estes sao os multiplos de %i: \n", numero);
    for (int i=1; i<101; i++)
    {
        if (i % numero == 0) {
            printf("%i  ", i);
        }
    }gcc
    return 0;
}