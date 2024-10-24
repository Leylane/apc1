#include<stdio.h>
#include<stdlib.h>

int main(){

    int opcao = 0;

    while (opcao != 5) {
        opcao = 0;
        system("clear");
        printf("\n\n MENU PRINCIPAL \n\n");
        printf("1 - Consultar Saldo\n");
        printf("2 - Fazer recarga\n");
        printf("3 - Ver recados\n");
        printf("4 - Ultimas ligacoes\n");
        printf("5 - Sair\n");
        printf("Entre com uma opcao => \n\n");
        scanf("%i", &opcao);
        while(getchar() != '\n');

        switch(opcao) {
        case 1: {
            system("clear");
            printf("Consulta Saldo \n\n");
            printf("Seu saldo eh de BRL 10.00\n\n"); break;
        }
        case 2: printf("Escolha um valor de recarga:\n\n"); break;
        case 3: printf("Voce nao tem recados\n\n"); break;
        case 4: printf("99999-000\n99999-1111\n\n"); break;
        case 5: printf("Ate logo!\n\n"); break;
        default: printf("Opcao invalida. Tente de novo.\n\n");
        }

        if (opcao != 5) {
            printf("Pressione ENTER para continuar... \n\n");
            getchar();
        }
    }

    return 0;
}