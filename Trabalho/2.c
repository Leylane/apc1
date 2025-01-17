#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Definindo o máximo de livros e usuários
    #define MAX_LIVROS 100
    #define MAX_USUARIOS 100

    // Estruturas de dados
    typedef struct {
        char nome[100];
        char autor[100];
        int ano_publicacao;
        char editora[100];
        char isbn[14];  // ISBN com 13 dígitos + 1 para o '\0'
        int estoque;
    } Livro;

    typedef struct {
        char nome[100];
        char email[100];
        char telefone[15];
        int livros_emprestados;
    } Usuario;

    // Arrays para armazenar livros e usuários
    Livro biblioteca[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int totalLivros = 0, totalUsuarios = 0;

    // Funções internas
    int validarAno(int ano) {
        return (ano > 1500 && ano <= 2024);
    }

    int validarISBN(char isbn[]) {
        if (strlen(isbn) != 13) return 0;
        for (int i = 0; i < 13; i++) {
            if (!isdigit(isbn[i])) return 0;
        }
        return 1;
    }

    int validarTelefone(char telefone[]) {
        if (strlen(telefone) != 14) return 0;
        for (int i = 0; i < 14; i++) {
            if (i == 0 && telefone[i] != '(') return 0;
            if (i == 3 && telefone[i] != ')') return 0;
            if (i == 9 && telefone[i] != '-') return 0;
            if (i != 0 && i != 3 && i != 9 && !isdigit(telefone[i])) return 0;
        }
        return 1;
    }

    int opcao;

    do {
        printf("\n--- Sistema de Controle de Biblioteca ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Realizar Empréstimo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');  // Limpar o buffer

        switch(opcao) {
            case 1: {
                Livro livro;

                // Cadastro de Livro
                printf("Cadastro de Livro:\n");

                // Nome do livro
                printf("Digite o nome do livro: ");
                fgets(livro.nome, 100, stdin);
                livro.nome[strcspn(livro.nome, "\n")] = 0;  // Remover o '\n'

                // Autor do livro
                printf("Digite o nome do autor: ");
                fgets(livro.autor, 100, stdin);
                livro.autor[strcspn(livro.autor, "\n")] = 0;  // Remover o '\n'

                // Ano de publicação
                printf("Digite o ano de publicação: ");
                while (scanf("%d", &livro.ano_publicacao) != 1 || !validarAno(livro.ano_publicacao)) {
                    printf("Ano inválido. Digite um ano entre 1500 e 2024: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Editora do livro
                printf("Digite o nome da editora: ");
                getchar();  // Limpar o buffer após o scanf
                fgets(livro.editora, 100, stdin);
                livro.editora[strcspn(livro.editora, "\n")] = 0;  // Remover o '\n'

                // ISBN do livro
                printf("Digite o ISBN (13 dígitos): ");
                while (scanf("%13s", livro.isbn) != 1 || !validarISBN(livro.isbn)) {
                    printf("ISBN inválido. Digite um ISBN com 13 dígitos numéricos: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Estoque
                printf("Digite o número de exemplares no estoque: ");
                while (scanf("%d", &livro.estoque) != 1 || livro.estoque < 0) {
                    printf("Quantidade inválida. Digite um valor positivo: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Adicionar livro ao sistema
                if (totalLivros < MAX_LIVROS) {
                    biblioteca[totalLivros++] = livro;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Estoque de livros cheio. Não é possível cadastrar mais livros.\n");
                }
                break;
            }
            case 2: {
                Usuario usuario;

                // Cadastro de Usuário
                printf("Cadastro de Usuário:\n");

                // Nome do usuário
                printf("Digite o nome do usuário: ");
                fgets(usuario.nome, 100, stdin);
                usuario.nome[strcspn(usuario.nome, "\n")] = 0;  // Remover o '\n'

                // E-mail do usuário
                printf("Digite o e-mail do usuário: ");
                fgets(usuario.email, 100, stdin);
                usuario.email[strcspn(usuario.email, "\n")] = 0;  // Remover o '\n'

                // Telefone do usuário
                printf("Digite o telefone do usuário (formato (XX) XXXXX-XXXX): ");
                while (scanf("%14s", usuario.telefone) != 1 || !validarTelefone(usuario.telefone)) {
                    printf("Telefone inválido. Digite no formato (XX) XXXXX-XXXX: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Inicializar o contador de livros emprestados
                usuario.livros_emprestados = 0;

                // Adicionar usuário ao sistema
                if (totalUsuarios < MAX_USUARIOS) {
                    usuarios[totalUsuarios++] = usuario;
                    printf("Usuário cadastrado com sucesso!\n");
                } else {
                    printf("Número máximo de usuários atingido. Não é possível cadastrar mais usuários.\n");
                }
                break;
            }
            case 3: {
                int idUsuario, idLivro;

                // Realizar Empréstimo de Livro
                printf("Empréstimo de Livro:\n");

                // Seleção do usuário
                printf("Digite o ID do usuário (0 a %d): ", totalUsuarios - 1);
                while (scanf("%d", &idUsuario) != 1 || idUsuario < 0 || idUsuario >= totalUsuarios) {
                    printf("ID de usuário inválido. Tente novamente: ");
                    while(getchar() != '\n');
                }

                // Seleção do livro
                printf("Digite o ID do livro (0 a %d): ", totalLivros - 1);
                while (scanf("%d", &idLivro) != 1 || idLivro < 0 || idLivro >= totalLivros) {
                    printf("ID de livro inválido. Tente novamente: ");
                    while(getchar() != '\n');
                }

                // Verificar disponibilidade de estoque
                if (biblioteca[idLivro].estoque > 0) {
                    biblioteca[idLivro].estoque--;
                    usuarios[idUsuario].livros_emprestados++;
                    printf("Empréstimo realizado com sucesso! Livro emprestado: %s\n", biblioteca[idLivro].nome);
                } else {
                    printf("Livro sem estoque disponível para empréstimo.\n");
                }
                break;
            }
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
