#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

int main() {
    // Variáveis de livros
    int livros_id[MAX_LIVROS];
    int livros_ano[MAX_LIVROS];
    char livros_titulo[MAX_LIVROS][100];
    char livros_autor[MAX_LIVROS][100];
    char livros_editora[MAX_LIVROS][100];

    // Variáveis de usuários
    int usuarios_id[MAX_USUARIOS];
    char usuarios_nome[MAX_USUARIOS][50];
    char usuarios_email[MAX_USUARIOS][100];
    char usuarios_telefone[MAX_USUARIOS][16];

    // Variáveis de empréstimos
    int emprestimos_livro_id[MAX_EMPRESTIMOS];
    int emprestimos_usuario_id[MAX_EMPRESTIMOS];
    char emprestimos_data[MAX_EMPRESTIMOS][11];
    char emprestimos_prazo[MAX_EMPRESTIMOS][11];

    // Contadores
    int contador_livros = 0;
    int contador_usuarios = 0;
    int contador_emprestimos = 0;

    // Variável de opção do menu
    int opcao;

    do {
        // Menu principal
        printf("\n=================================\n");
        printf("\n===== Sistema de Biblioteca =====\n");
        printf("\n=================================\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Cadastrar Usuario\n");
        printf("4. Listar Usuarios\n");
        printf("5. Registrar Emprestimo\n");
        printf("6. Listar Emprestimos\n");
        printf("7. Sair\n\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do teclado após o número

        if (opcao == 1) { // Cadastrar livro
            if (contador_livros >= MAX_LIVROS) {
                printf("Nao e possivel cadastrar mais livros.\n");
                continue;
            }
            livros_id[contador_livros] = contador_livros + 1;

            printf("Titulo do livro: ");
            fgets(livros_titulo[contador_livros], sizeof(livros_titulo[contador_livros]), stdin);
            strtok(livros_titulo[contador_livros], "\n");

            printf("Autor do livro: ");
            fgets(livros_autor[contador_livros], sizeof(livros_autor[contador_livros]), stdin);
            strtok(livros_autor[contador_livros], "\n");

            printf("Editora do livro: ");
            fgets(livros_editora[contador_livros], sizeof(livros_editora[contador_livros]), stdin);
            strtok(livros_editora[contador_livros], "\n");

            // Validação do ano
            printf("Ano de publicacao (entre 1500 e 2024): ");
            while (scanf("%d", &livros_ano[contador_livros]) != 1 || 
                   livros_ano[contador_livros] < 1500 || 
                   livros_ano[contador_livros] > 2024) {
                printf("Ano invalido. Tente novamente: ");
                while(getchar() != '\n'); // Limpar buffer
            }
            getchar(); // Limpar buffer do teclado

            contador_livros++;
            printf("Livro cadastrado com sucesso!\n");

        } else if (opcao == 2) { // Listar livros
            if (contador_livros == 0) {
                printf("Nao ha livros cadastrados.\n");
            } else {
                printf("\n=== Livros Cadastrados ===\n");
                for (int i = 0; i < contador_livros; i++) {
                    printf("ID: %d\n", livros_id[i]);
                    printf("Titulo: %s\n", livros_titulo[i]);
                    printf("Autor: %s\n", livros_autor[i]);
                    printf("Editora: %s\n", livros_editora[i]);
                    printf("Ano: %d\n", livros_ano[i]);
                    printf("--------------------------\n");
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar o pressionamento de ENTER antes de continuar

        } else if (opcao == 3) { // Cadastrar usuário
            if (contador_usuarios >= MAX_USUARIOS) {
                printf("Nao e possivel cadastrar mais usuarios.\n");
                continue;
            }
            usuarios_id[contador_usuarios] = contador_usuarios + 1;

            printf("Nome do usuario: ");
            fgets(usuarios_nome[contador_usuarios], sizeof(usuarios_nome[contador_usuarios]), stdin);
            strtok(usuarios_nome[contador_usuarios], "\n");

            do {
                printf("Email do usuario: ");
                fgets(usuarios_email[contador_usuarios], sizeof(usuarios_email[contador_usuarios]), stdin);
                strtok(usuarios_email[contador_usuarios], "\n");
                if (strchr(usuarios_email[contador_usuarios], '@') == NULL || 
                    strchr(usuarios_email[contador_usuarios], '.') == NULL) {
                    printf("Email invalido. Tente novamente.\n");
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Telefone do usuario (8 a 15 digitos): ");
                fgets(usuarios_telefone[contador_usuarios], sizeof(usuarios_telefone[contador_usuarios]), stdin);
                strtok(usuarios_telefone[contador_usuarios], "\n");
                int telefone_len = strlen(usuarios_telefone[contador_usuarios]);
                int valid = 1;
                for (int i = 0; i < telefone_len; i++) {
                    if (!isdigit(usuarios_telefone[contador_usuarios][i])) {
                        valid = 0;
                        break;
                    }
                }
                if (telefone_len >= 8 && telefone_len <= 15 && valid) break;
                printf("Telefone invalido. Tente novamente.\n");
            } while (1);

            contador_usuarios++;
            printf("Usuario cadastrado com sucesso!\n");

        } else if (opcao == 4) { // Listar usuários
            if (contador_usuarios == 0) {
                printf("Nao ha usuarios cadastrados.\n");
            } else {
                printf("\n=== Usuarios Cadastrados ===\n");
                for (int i = 0; i < contador_usuarios; i++) {
                    printf("ID: %d\n", usuarios_id[i]);
                    printf("Nome: %s\n", usuarios_nome[i]);
                    printf("Email: %s\n", usuarios_email[i]);
                    printf("Telefone: %s\n", usuarios_telefone[i]);
                    printf("--------------------------\n");
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar o pressionamento de ENTER antes de continuar

        } else if (opcao == 5) { // Registrar empréstimo
            if (contador_emprestimos >= MAX_EMPRESTIMOS) {
                printf("Nao e possivel registrar mais emprestimos.\n");
                continue;
            }

            int id_livro, id_usuario;

            printf("ID do livro: ");
            scanf("%d", &id_livro);
            getchar();

            if (id_livro < 1 || id_livro > contador_livros) {
                printf("Livro nao encontrado.\n");
                continue;
            }

            printf("ID do Usuario: ");
            scanf("%d", &id_usuario);
            getchar();

            if (id_usuario < 1 || id_usuario > contador_usuarios) {
                printf("Usuario nao encontrado.\n");
                continue;
            }

            printf("Data do Emprestimo (dd/mm/aaaa): ");
            fgets(emprestimos_data[contador_emprestimos], sizeof(emprestimos_data[contador_emprestimos]), stdin);
            strtok(emprestimos_data[contador_emprestimos], "\n");

            printf("Prazo do Emprestimo (dd/mm/aaaa): ");
            fgets(emprestimos_prazo[contador_emprestimos], sizeof(emprestimos_prazo[contador_emprestimos]), stdin);
            strtok(emprestimos_prazo[contador_emprestimos], "\n");

            emprestimos_livro_id[contador_emprestimos] = id_livro;
            emprestimos_usuario_id[contador_emprestimos] = id_usuario;

            contador_emprestimos++;
            printf("Emprestimo registrado com sucesso!\n");

        } else if (opcao == 6) { // Listar empréstimos
            if (contador_emprestimos == 0) {
                printf("Nao ha emprestimos registrados.\n");
            } else {
                printf("\n=== Emprestimos Registrados ===\n");
                for (int i = 0; i < contador_emprestimos; i++) {
                    printf("ID Livro: %d, ID Usuario: %d\n", emprestimos_livro_id[i], emprestimos_usuario_id[i]);
                    printf("Data: %s, Prazo: %s\n", emprestimos_data[i], emprestimos_prazo[i]);
                    printf("--------------------------\n");
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar o pressionamento de ENTER antes de continuar

        }

    } while (opcao != 7);

    printf("Saindo do sistema...\n");
    return 0;
}
