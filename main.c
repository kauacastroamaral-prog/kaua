#include <stdio.h>
#include "calculadora.c"
#include "boletim.c"
#include "banco.c"
#include "estacionamento.c"
#include "treino.c"

int main(void)
{
    int n1;
    char resposta;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("Qual sistema deseja utilizar:\n");
        printf("1 - Calculadora\n");
        printf("2 - Boletim\n");
        printf("3 - Banco\n");
        printf("4 - Estacionamento\n");
        printf("5 - Sistema de treino\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &n1);

        switch (n1)
        {
            case 1:
                calculadora();
                break;

            case 2:
                boletim();
                break;

            case 3:
                banco();
                break;

            case 4:
                estacionamento();
                break;

            case 5:
                sistema();
                break;

            case 0:
                printf("\nObrigado por usar nosso sistema!\n");
                return 0;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

        if (n1 != 0)
        {
            printf("\nQuer fazer outro sistema? (s/n): ");
            scanf(" %c", &resposta);
        }
        else
        {
            resposta = 'n';
        }

    } while (resposta == 's' || resposta == 'S');

    printf("\nObrigado por usar nosso sistema!\n");

    return 0;
}
