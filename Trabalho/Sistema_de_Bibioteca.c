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
        getchar(); // Limpar buffer do teclado

        if (opcao == 1) { // Cadastrar livro
            if (contador_livros >= MAX_LIVROS) {
                printf("Nao e possivel cadastrar mais livros.\n");
                continue;
            }
            livros_id[contador_livros] = contador_livros + 1;

            printf("Titulo do livro: ");
            fgets(livros_titulo[contador_livros], 100, stdin);
            strtok(livros_titulo[contador_livros], "\n");

            printf("Autor do livro: ");
            fgets(livros_autor[contador_livros], 100, stdin);
            strtok(livros_autor[contador_livros], "\n");

            printf("Editora do livro: ");
            fgets(livros_editora[contador_livros], 100, stdin);
            strtok(livros_editora[contador_livros], "\n");

            printf("Ano de publicacao (entre 1500 e 2024): ");
            scanf("%d", &livros_ano[contador_livros]);
            getchar();

            if (livros_ano[contador_livros] < 1500 || livros_ano[contador_livros] > 2024) {
                printf("Ano invalido. Cadastro nao realizado.\n");
            } else {
                contador_livros++;
                printf("Livro cadastrado com sucesso!\n");
            }

        } else if (opcao == 2) { // Listar livros
            if (contador_livros == 0) {
                printf("Nao ha livros cadastrados.\n");
                continue;
            }
            printf("\n=== Livros Cadastrados ===\n");
            for (int i = 0; i < contador_livros; i++) {
                printf("ID: %d | Titulo: %s | Autor: %s | Editora: %s | Ano: %d\n", 
                       livros_id[i], livros_titulo[i], livros_autor[i], livros_editora[i], livros_ano[i]);
            }

        } else if (opcao == 3) { // Cadastrar usuário
            if (contador_usuarios >= MAX_USUARIOS) {
                printf("Nao e possivel cadastrar mais usuarios.\n");
                continue;
            }
            usuarios_id[contador_usuarios] = contador_usuarios + 1;

            printf("Nome do usuario: ");
            fgets(usuarios_nome[contador_usuarios], 50, stdin);
            strtok(usuarios_nome[contador_usuarios], "\n");

            do {
                printf("Email do usuario: ");
                fgets(usuarios_email[contador_usuarios], 100, stdin);
                strtok(usuarios_email[contador_usuarios], "\n");
                if (strchr(usuarios_email[contador_usuarios], '@') == NULL || strchr(usuarios_email[contador_usuarios], '.') == NULL) {
                    printf("Email invalido. Tente novamente.\n");
                } else {
                    break;
                }
            } while (1);

            do {
                printf("Telefone do usuario (8 a 15 digitos): ");
                fgets(usuarios_telefone[contador_usuarios], 16, stdin);
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
                continue;
            }
            printf("\n=== Usuarios Cadastrados ===\n");
            for (int i = 0; i < contador_usuarios; i++) {
                printf("ID: %d | Nome: %s | Email: %s | Telefone: %s\n", 
                       usuarios_id[i], usuarios_nome[i], usuarios_email[i], usuarios_telefone[i]);
            }

        } else if (opcao == 5) { // Registrar empréstimo
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

            emprestimos_livro_id[contador_emprestimos] = id_livro;
            emprestimos_usuario_id[contador_emprestimos] = id_usuario;

            printf("Data do emprestimo (dd/mm/aaaa): ");
            fgets(emprestimos_data[contador_emprestimos], 11, stdin);
            strtok(emprestimos_data[contador_emprestimos], "\n");

            // Calcular data de devolução (8 dias após)
            int dia, mes, ano;
            sscanf(emprestimos_data[contador_emprestimos], "%d/%d/%d", &dia, &mes, &ano);
            dia += 8; // 8 dias de prazo

            // Verifica o número de dias no mês para ajustar
            if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
                dia -= 30;
                mes++;
            } else if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) { // Ano bissexto
                if (dia > 29) {
                    dia -= 29;
                    mes++;
                }
            } else if (mes == 2 && dia > 28) {
                dia -= 28;
                mes++;
            } else if (dia > 31) {
                dia -= 31;
                mes++;
            }

            if (mes > 12) {
                mes = 1;
                ano++;
            }

            sprintf(emprestimos_prazo[contador_emprestimos], "%02d/%02d/%04d", dia, mes, ano);

            contador_emprestimos++;
            printf("Emprestimo registrado com sucesso!\n");

        } else if (opcao == 6) { // Listar empréstimos
            if (contador_emprestimos == 0) {
                printf("Nao ha emprestimos registrados.\n");
                continue;
            }
            printf("\n=== Emprestimos Registrados ===\n");
            for (int i = 0; i < contador_emprestimos; i++) {
                int id_livro = emprestimos_livro_id[i];
                int id_usuario = emprestimos_usuario_id[i];
                printf("Livro: %s | Usuario: %s | Data de Emprestimo: %s | Data de Devolucao: %s\n", 
                       livros_titulo[id_livro - 1], 
                       usuarios_nome[id_usuario - 1], 
                       emprestimos_data[i], 
                       emprestimos_prazo[i]);
            }

        } else if (opcao != 7) {
            printf("Opcao invalida.\n");
        }
    } while (opcao != 7);

    printf("Encerrando o sistema.\n");
    return 0;
}
