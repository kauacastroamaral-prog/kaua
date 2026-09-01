#include <stdio.h>
#include <string.h>

void sistema()
{
    struct treino
    {
        char nome[50];
        int quantidade;
        int tipo;
    };
    struct treino Produtos[100];
    int totalProdutos = 0;

    int opcao;

    do
    {
        printf("=======================================================\n");
        printf("          SISTEMA DE LOJAS MAGAZINE\n");
        printf("=======================================================\n");

        printf("Opcao - 1 Cadastrar produto!\n");
        printf("Opcao - 2 Listar produto!\n");
        printf("Opcao - 3 Buscar produto!\n");
        printf("Opcao - 4 Entrada de estoque!\n");
        printf("Opcao - 5 Saida de estoque!\n");
        printf("Opcao - 6 Sair!\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            printf("Nome do Produto: ");
            scanf(" %49s[^\n]", Produtos[totalProdutos].nome);

            printf("Quantidade: ");
            scanf("%d", &Produtos[totalProdutos].quantidade);

            printf("Tipo:\n");
            printf("1 - Grande\n");
            printf("2 - Medio\n");
            printf("3 - Pequeno\n");
            scanf("%d", &Produtos[totalProdutos].tipo);

            totalProdutos++;

            break;

        case 2:
            printf("=======================================================\n");
            printf("               Lista de produtos\n");
            printf("=======================================================\n");

            if (totalProdutos == 0)
            {
                printf("Nenhum produto cadastrado!\n");
            }
            else
            {
                for (int i = 0; i < totalProdutos; i++)
                {
                    printf("\nProduto %d\n", i + 1);
                    printf("Nome: %s\n", Produtos[i].nome);
                    printf("Quantidade: %d\n", Produtos[i].quantidade);
                    printf("Tipo: %d\n", Produtos[i].tipo);
                }
            }

            break;

        case 3:
            printf("=======================================================\n");
            printf("           Buscar produto\n");
            printf("=======================================================\n");

            if (totalProdutos == 0)
            {
                printf("Produto não Localizado!\n");
            }
            else
            {
                char nomebusca[50];
                int encontrado = 0;

                printf("Escreva o nome do produto:\n");
                scanf("%49s", nomebusca);

                for (int i = 0; i < totalProdutos; i++)
                {
                    if (strcmp(Produtos[i].nome, nomebusca) == 0)
                    {
                        printf("\nProduto encontrado!\n");
                        printf("Nome: %s\n", Produtos[i].nome);
                        encontrado = 1;
                    }
                    break;
                }
                if (!encontrado)
                {
                    printf("Produto não encontrado!!");
                    
                }
            }

            break;

        case 4:
            printf("Entrada de estoque\n");
            break;

        case 5:
            printf("Saida de estoque\n");
            break;

        case 6:
            printf("Saindo do sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 6);
}
