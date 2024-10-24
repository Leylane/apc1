#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_NOME 50

int main() {
    char nomes[MAX_USUARIOS][MAX_NOME]; // Array para armazenar os nomes
    int idades[MAX_USUARIOS]; // Array para armazenar as idades
    int userCount = 0;
    int choice;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Listar Usuarios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        
        // Verificando se a entrada eh um inteiro valido
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Limpa a linha
            printf("Entrada invalida! Tente novamente.\n");
            continue; // Retorna ao inicio do loop
        }

        switch (choice) {
            case 1:
                if (userCount < MAX_USUARIOS) {
                    printf("Digite o nome do usuario: ");
                    scanf(" %[^\n]s", nomes[userCount]); // Nome com espacos
                    printf("Digite a idade do usuario: ");
                    scanf("%d", &idades[userCount]);

                    // Validação da idade
                    while (idades[userCount] < 0 || idades[userCount] > 120) {
                        printf("Idade invalida! Digite uma idade entre 0 e 120: ");
                        scanf("%d", &idades[userCount]);
                    }

                    userCount++;
                    printf("Usuario cadastrado com sucesso!\n");
                } else {
                    printf("Limite de usuarios alcancado.\n");
                }
                break;

            case 2:
                if (userCount == 0) {
                    printf("Nenhum usuario cadastrado.\n");
                } else {
                    printf("\nLista de usuarios:\n");
                    for (int i = 0; i < userCount; i++) {
                        printf("Nome: %s, Idade: %d\n", nomes[i], idades[i]);
                    }
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao incorreta! Tente novamente.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
