#include <stdio.h>

int main(){
  //Entrada
  int numero;
  printf("Entre com um numero: ");
  int deu_certo = scanf("%i", &numero);

    // Processamento
    // numero = numero + 1;
    int incremento = numero;
    incremento++; // ou ++incremento;
    int pre_incremento = ++incremento;
    int pos_incremento = incremento++;
    // numero = numero - 1;
    int decremento = numero;
    decremento--;
    int pre_decremento = --decremento;
    int pos_decremento = decremento--;
  

    // Saida
    printf("Incremento de %i ate %i\n", numero, incremento);
    printf("Pre-incremento de %i ate %i\n", numero, pre_incremento);
    printf("Pos-incremento de %i ate %i\n", numero, pos_incremento);
    printf("Decremento de %i ate %i\n", numero, decremento);
    printf("Pre-decremento de %i ate %i \n", numero, pre_decremento);
    printf("Pos-decremento de %i ate %i\n", numero, pos_decremento);
  

    return 0;
}