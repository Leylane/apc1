#include <stdio.h>
#include <string.h>

int main(){

char primeiro_nome[11];
char ultimo_nome[11];
char nome[31];

scanf("%s", &primeiro_nome);
scanf("%s", &ultimo_nome);

strcpy(nome, primeiro_nome);
strcat(nome, " ");

return 0;

}