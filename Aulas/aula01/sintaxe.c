
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
  //1. entrada: identificacao de tipos de informacoes necessarias
    //ex: char, int, float
    //ex: variaveis
    //ex: leitura das informacoes inseridas

  int primeiro_numero;
  int segundo_numero;

  primeiro_numero = 5;
  segundo_numero = 6;
  
  //2. Processamento: 
    // calculos: soma, subtracao, multiplicacao etc
  int soma = primeiro_numero + segundo_numero;
    
  //3. saida:
    // escrita do resultado
  printf("A soma de %i com %i ate %i\n", primeiro_numero, segundo_numero, soma);
  
  return 0;        // return fim do programa
}