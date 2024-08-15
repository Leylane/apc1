
/* ISSO é diferente de isso

Bloco de comentarios

// calcular a area do retangulo
area_retangulo = base * altura

// main é uma função:
main() {
  linha_de_codigo;
}

// o #include inclui um código que está em outro lugar
//Bilbiotecas são funções que podem ser adicionadas à linguagem

blocos {}
*/
  
#include <stdio.h> // inclui a biblioteca stdio.h

int main(){        // funcao principal
  //1. entrada: identificação de tipos de informações necessárias
    //ex: char, int, float
    //ex: variáveis
    //ex: leitura das informações inseridas

  int primeiro_numero;
  int segundo_numero;

  primeiro_numero = 5;
  segundo_numero = 6;
  
  //2. Processamento: 
    // cálculos: soma, subtração, multiplicação etc
  int soma = primeiro_numero + segundo_numero;
    
  //3. saída:
    // escrita do resultado
  printf("A soma de %i com %i é %i\n", primeiro_numero, segundo_numero, soma);
  
  return 0;        // return fim do programa
}