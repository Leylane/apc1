#include <stdio.h> //biblioteca de entrada e saída na console

int main() {
  printf ("Um texto entre aspas duplas\n");

  //imprime um numero
  printf("%i\n", 10);
  printf("%i %i \n", 50, 100);
  printf("%5i \n", 0001);
  printf("%05i \n", 21);

  // imprime um número decimal

  printf("%f \n", 8.5);
  printf("%.3f \n", 3.14159);
  printf("%8.2f \n", 110.5);
  printf("%8.2f \n", 2556.86);

  // imprime um caractere

  printf("%c \n", 'A');
  printf("%c \n", 68); // ASCII table

  // imprime uma string

  printf("%s \n", "Boa Noite");
  printf("%30s! \n", "Quero Café");
  printf("%-30s! \n", "Quero Café");

  return 0;
}

