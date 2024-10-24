int main(){

    int numero = 0;

    do {
        printf("Entre com um nmero entre 1 e 10: \n\n");
        scanf("%i", &numero);
        while(getchar() != '\n');

        if (numero < 1 || numero > 10) {
            printf("Numero invalido. Tente novamente! \n\n");
        }
    } while (numero < 1 || numero > 10);

    return 0;
}