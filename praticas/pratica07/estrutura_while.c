#include <stdio.h>

int main(){
    int nota;
    printf("Insira uma nota entre 1 e 10: \n");
    scanf("%i", &nota);
    while(nota < 1 || nota > 10)
    {
        printf("Nota invalida. Tente novamente!\n");
        scanf("%i", &nota);
    }

    return 0;
}