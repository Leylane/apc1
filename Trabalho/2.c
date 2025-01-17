#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Definindo o m�ximo de livros e usu�rios
    #define MAX_LIVROS 100
    #define MAX_USUARIOS 100

    // Estruturas de dados
    typedef struct {
        char nome[100];
        char autor[100];
        int ano_publicacao;
        char editora[100];
        char isbn[14];  // ISBN com 13 d�gitos + 1 para o '\0'
        int estoque;
    } Livro;

    typedef struct {
        char nome[100];
        char email[100];
        char telefone[15];
        int livros_emprestados;
    } Usuario;

    // Arrays para armazenar livros e usu�rios
    Livro biblioteca[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int totalLivros = 0, totalUsuarios = 0;

    // Fun��es internas
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
        printf("2. Cadastrar Usu�rio\n");
        printf("3. Realizar Empr�stimo\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
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

                // Ano de publica��o
                printf("Digite o ano de publica��o: ");
                while (scanf("%d", &livro.ano_publicacao) != 1 || !validarAno(livro.ano_publicacao)) {
                    printf("Ano inv�lido. Digite um ano entre 1500 e 2024: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Editora do livro
                printf("Digite o nome da editora: ");
                getchar();  // Limpar o buffer ap�s o scanf
                fgets(livro.editora, 100, stdin);
                livro.editora[strcspn(livro.editora, "\n")] = 0;  // Remover o '\n'

                // ISBN do livro
                printf("Digite o ISBN (13 d�gitos): ");
                while (scanf("%13s", livro.isbn) != 1 || !validarISBN(livro.isbn)) {
                    printf("ISBN inv�lido. Digite um ISBN com 13 d�gitos num�ricos: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Estoque
                printf("Digite o n�mero de exemplares no estoque: ");
                while (scanf("%d", &livro.estoque) != 1 || livro.estoque < 0) {
                    printf("Quantidade inv�lida. Digite um valor positivo: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Adicionar livro ao sistema
                if (totalLivros < MAX_LIVROS) {
                    biblioteca[totalLivros++] = livro;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Estoque de livros cheio. N�o � poss�vel cadastrar mais livros.\n");
                }
                break;
            }
            case 2: {
                Usuario usuario;

                // Cadastro de Usu�rio
                printf("Cadastro de Usu�rio:\n");

                // Nome do usu�rio
                printf("Digite o nome do usu�rio: ");
                fgets(usuario.nome, 100, stdin);
                usuario.nome[strcspn(usuario.nome, "\n")] = 0;  // Remover o '\n'

                // E-mail do usu�rio
                printf("Digite o e-mail do usu�rio: ");
                fgets(usuario.email, 100, stdin);
                usuario.email[strcspn(usuario.email, "\n")] = 0;  // Remover o '\n'

                // Telefone do usu�rio
                printf("Digite o telefone do usu�rio (formato (XX) XXXXX-XXXX): ");
                while (scanf("%14s", usuario.telefone) != 1 || !validarTelefone(usuario.telefone)) {
                    printf("Telefone inv�lido. Digite no formato (XX) XXXXX-XXXX: ");
                    while(getchar() != '\n');  // Limpar o buffer
                }

                // Inicializar o contador de livros emprestados
                usuario.livros_emprestados = 0;

                // Adicionar usu�rio ao sistema
                if (totalUsuarios < MAX_USUARIOS) {
                    usuarios[totalUsuarios++] = usuario;
                    printf("Usu�rio cadastrado com sucesso!\n");
                } else {
                    printf("N�mero m�ximo de usu�rios atingido. N�o � poss�vel cadastrar mais usu�rios.\n");
                }
                break;
            }
            case 3: {
                int idUsuario, idLivro;

                // Realizar Empr�stimo de Livro
                printf("Empr�stimo de Livro:\n");

                // Sele��o do usu�rio
                printf("Digite o ID do usu�rio (0 a %d): ", totalUsuarios - 1);
                while (scanf("%d", &idUsuario) != 1 || idUsuario < 0 || idUsuario >= totalUsuarios) {
                    printf("ID de usu�rio inv�lido. Tente novamente: ");
                    while(getchar() != '\n');
                }

                // Sele��o do livro
                printf("Digite o ID do livro (0 a %d): ", totalLivros - 1);
                while (scanf("%d", &idLivro) != 1 || idLivro < 0 || idLivro >= totalLivros) {
                    printf("ID de livro inv�lido. Tente novamente: ");
                    while(getchar() != '\n');
                }

                // Verificar disponibilidade de estoque
                if (biblioteca[idLivro].estoque > 0) {
                    biblioteca[idLivro].estoque--;
                    usuarios[idUsuario].livros_emprestados++;
                    printf("Empr�stimo realizado com sucesso! Livro emprestado: %s\n", biblioteca[idLivro].nome);
                } else {
                    printf("Livro sem estoque dispon�vel para empr�stimo.\n");
                }
                break;
            }
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
