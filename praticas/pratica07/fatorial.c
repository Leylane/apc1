#include <stdio.h>

int main(){

    int numero;
    int fatorial;
    printf("Informe um numero para encontrar seu fatorial: \n");
     scanf("%i", &numero);

    for (int i=numero; i>0; i--) {
        fatorial = fatorial * i; 
    }
    printf("Numero %i, Fatorial %i \n", numero, fatorial );
    return 0;
}