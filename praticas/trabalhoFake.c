#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

struct User {
    char name[NAME_LENGTH];
    int age;
};

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    int choice;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Listar Usuários\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        
        // Verificando se a entrada é um inteiro válido
        if (scanf("%d", &choice) != 1) {
            // Se não for, limpa o buffer de entrada
            while (getchar() != '\n'); // Limpa a linha
            printf("Entrada inválida! Tente novamente.\n");
            continue; // Retorna ao início do loop
        }

        switch (choice) {
            case 1:
                if (userCount < MAX_USERS) {
                    printf("Digite o nome do usuário: ");
                    scanf(" %[^\n]s", users[userCount].name); // Lê nome com espaços
                    printf("Digite a idade do usuário: ");
                    scanf("%d", &users[userCount].age);

                    // Validação da idade
                    while (users[userCount].age < 0 || users[userCount].age > 120) {
                        printf("Idade inválida! Digite uma idade entre 0 e 120: ");
                        scanf("%d", &users[userCount].age);
                    }

                    userCount++;
                    printf("Usuário cadastrado com sucesso!\n");
                } else {
                    printf("Limite de usuários alcançado.\n");
                }
                break;

            case 2:
                if (userCount == 0) {
                    printf("Nenhum usuário cadastrado.\n");
                } else {
                    printf("\nLista de Usuários:\n");
                    for (int i = 0; i < userCount; i++) {
                        printf("Nome: %s, Idade: %d\n", users[i].name, users[i].age);
                    }
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção incorreta! Tente novamente.\n");
                break;
        }
    } while (choice != 3);

    return 1;
}
