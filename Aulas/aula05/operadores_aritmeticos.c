#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

int main() {
    // Vari�veis de livros
    int livros_id[MAX_LIVROS];
    int livros_ano[MAX_LIVROS];
    char livros_titulo[MAX_LIVROS][100];
    char livros_autor[MAX_LIVROS][100];
    char livros_editora[MAX_LIVROS][100];
    char livros_isbn[MAX_LIVROS][14]; // Campo para ISBN

    // Vari�veis de usu�rios
    int usuarios_id[MAX_USUARIOS];
    char usuarios_nome[MAX_USUARIOS][50];
    char usuarios_email[MAX_USUARIOS][100];
    char usuarios_telefone[MAX_USUARIOS][16];

    // Vari�veis de empr�stimos
    int emprestimos_livro_id[MAX_EMPRESTIMOS];
    int emprestimos_usuario_id[MAX_EMPRESTIMOS];
    char emprestimos_data[MAX_EMPRESTIMOS][11];
    char emprestimos_prazo[MAX_EMPRESTIMOS][11];

    // Contadores
    int contador_livros = 0;
    int contador_usuarios = 0;
    int contador_emprestimos = 0;

    // Vari�vel de op��o do menu
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
        getchar(); // Limpar buffer do teclado ap�s o n�mero

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

            // Valida��o do ISBN
            int isbn_valido = 0;
            do {
                printf("Informe o ISBN (10 a 13 caracteres num�ricos): ");
                fgets(livros_isbn[contador_livros], sizeof(livros_isbn[contador_livros]), stdin);
                strtok(livros_isbn[contador_livros], "\n");

                int isbn_tamanho = strlen(livros_isbn[contador_livros]);
                isbn_valido = (isbn_tamanho >= 10 && isbn_tamanho <= 13);

                for (int i = 0; i < isbn_tamanho && isbn_valido; i++) {
                    if (!isdigit(livros_isbn[contador_livros][i])) {
                        isbn_valido = 0;
                    }
                }

                if (!isbn_valido) {
                    printf("ISBN invalido. Tente novamente.\n");
                }
            } while (!isbn_valido);

            // Valida��o do ano
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
                    printf("ID: %d | Titulo: %s | Autor: %s | Editora: %s | ISBN: %s | Ano: %d\n", 
                           livros_id[i], livros_titulo[i], livros_autor[i], livros_editora[i], 
                           livros_isbn[i], livros_ano[i]);
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar a tecla ENTER ser pressionada

        } else if (opcao == 3) { // Cadastrar usu�rio
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

        } else if (opcao == 4) { // Listar usu�rios
            if (contador_usuarios == 0) {
                printf("Nao ha usuarios cadastrados.\n");
            } else {
                printf("\n=== Usuarios Cadastrados ===\n");
                for (int i = 0; i < contador_usuarios; i++) {
                    printf("ID: %d | Nome: %s | Email: %s | Telefone: %s\n", 
                           usuarios_id[i], usuarios_nome[i], usuarios_email[i], usuarios_telefone[i]);
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar a tecla ENTER ser pressionada

        } else if (opcao == 5) { // Registrar empr�stimo
            if (contador_livros == 0 || contador_usuarios == 0) {
                printf("Nao ha livros ou usuarios cadastrados para realizar emprestimos.\n");
                continue;
            }

            printf("ID do Livro para emprestimo: ");
            int id_livro, id_usuario;
            scanf("%d", &id_livro);
            getchar();

            if (id_livro <= 0 || id_livro > contador_livros) {
                printf("Livro nao encontrado.\n");
                continue;
            }

            printf("ID do Usuario para emprestimo: ");
            scanf("%d", &id_usuario);
            getchar();

            if (id_usuario <= 0 || id_usuario > contador_usuarios) {
                printf("Usuario nao encontrado.\n");
                continue;
            }

            printf("Data do emprestimo (dd/mm/aaaa): ");
            fgets(emprestimos_data[contador_emprestimos], sizeof(emprestimos_data[contador_emprestimos]), stdin);
            strtok(emprestimos_data[contador_emprestimos], "\n");

            // Calcular prazo de devolu��o
            printf("Prazo de devolucao (dd/mm/aaaa): ");
            fgets(emprestimos_prazo[contador_emprestimos], sizeof(emprestimos_prazo[contador_emprestimos]), stdin);
            strtok(emprestimos_prazo[contador_emprestimos], "\n");

            emprestimos_livro_id[contador_emprestimos] = id_livro;
            emprestimos_usuario_id[contador_emprestimos] = id_usuario;
            contador_emprestimos++;

            printf("Emprestimo registrado com sucesso!\n");

        } else if (opcao == 6) { // Listar empr�stimos
            if (contador_emprestimos == 0) {
                printf("Nao ha emprestimos registrados.\n");
            } else {
                printf("\n=== Emprestimos Realizados ===\n");
                for (int i = 0; i < contador_emprestimos; i++) {
                    printf("Livro ID: %d | Usuario ID: %d | Data Emprestimo: %s | Prazo: %s\n",
                           emprestimos_livro_id[i], emprestimos_usuario_id[i], 
                           emprestimos_data[i], emprestimos_prazo[i]);
                }
            }
            printf("\nPressione ENTER para voltar ao menu...\n");
            getchar(); // Esperar a tecla ENTER ser pressionada

        } else if (opcao != 7) {
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 7);

    printf("Encerrando o sistema.\n");
    return 0;
}
