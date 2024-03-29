/*
6. Faça um programa em C que calcule as raízes de uma equação do 2° grau através da fórmula de Bhaskara (-b +/- raiz_quadrada(b² - 4ac)/2a).
*/

#include <stdio.h>
#include <math.h>

int main () {

  int a;
  int b;
  int c;

  printf("Entre com o valor de a: ");
  int deu_certo = scanf("%i", &a);
  
  printf("Entre com o valor de b: ");
  deu_certo = scanf("%i", &b);

  printf("Entre com o valor de c: ");
  deu_certo = scanf("%i", &c);
  
  int delta = (b * b) - (4 * a * c);
  printf("O valor de delta é %i\n", delta);

  int x1 = (-b + sqrt(delta)) / (2 * a);

  printf("O valor de x1 é %i\n", x1);
  int x2 = (-b - sqrt(delta)) / (2 * a);
  printf("O valor de x2 é %i\n", x2);
  

  return 0;
}