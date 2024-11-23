#include <stdio.h>

int main(){
char string[30];

printf("Entre com seu nome: ");
scanf("%s", string);
string[30] = '\0';
printf("Ola %s!\n", string);

for(int i=0; i<30; i++) {
    printf("%c ", string[i]);
}
return 0;
}