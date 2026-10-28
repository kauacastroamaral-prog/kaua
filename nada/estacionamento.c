#include <stdio.h>
#include <string.h>

void estacionamento()
{
    char placaArquivo[18];
    char horario[6];
    int encontrado = 0;
    int sair = 0;
    int opcao;
    char placa[20];
    int carro = 0;
    int moto = 0;
    int vagas = 0;
    int tipo;
    int ocupados;
    int quant;
    int atendidos;
    int totaldecarro;
    int totaldemoto;
    char linha [200];

    float pagamento = 0;
    float faturamento = 0;

    FILE *veiculos;
    FILE *historico;
    FILE *caixa;

    do
    {
        printf("\n======== ESTACIONAMENTO SENAI ========\n");
        printf("Opcao 1 - Registrar entrada\n");
        printf("Opcao 2 - Registrar saida\n");
        printf("Opcao 3 - Consultar situacao\n");
        printf("Opcao 4 - Exibir faturamento\n");
        printf("Opcao 5 - Consultar veículos estacionados\n");
        printf("Opcao 6 - Consultar histórico\n");
        printf("Opcao 7 - Encerrar sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

            // ==========================================
            // REGISTRAR ENTRADA
            // ==========================================

        case 1:
            veiculos = fopen("arquivos/veiculos.txt", "a");
            historico = fopen("arquivos/historico.txt", "a");

            if (veiculos == NULL)
            {
                printf("\nErro ao abrir o arquivo veiculos!\n");
                break;
            }
            if (vagas >= 20)
            {
                printf("\nEstacionamento Lotado!\n");
                break;
            }

            printf("\n=========== ENTRADA DO ESTACIONAMENTO ===========\n");

            printf("Qual a placa do veiculo? ");
            scanf("%19s", placa);

            printf("\nQual o tipo de veiculo?\n");
            printf("1 - Carro\n");
            printf("2 - Moto\n");
            printf("Escolha: ");
            scanf("%d", &tipo);

            char horarioEntrada[6];

            printf("Horario de entrada (HH:MM): ");
            scanf("%5s", horarioEntrada);

            if (tipo == 1)
            {
                carro++;

                fprintf(veiculos,
                        "CARRO;%s;%s;-;0.00\n",
                        placa,
                        horarioEntrada);
                        fprintf(historico,
                        "CARRO;%s;%s;-;0.00\n",
                        placa,
                        horarioEntrada);

                printf("\nCarro registrado com sucesso!\n");
            }
            else if (tipo == 2)
            {
                moto++;

                fprintf(veiculos,
                        "MOTO;%s;%s;-;0.00\n",
                        placa,
                        horarioEntrada);
                        fprintf(historico,
                        "MOTO;%s;%s;-;0.00\n",
                        placa,
                        horarioEntrada);

                printf("\nMoto registrada com sucesso!\n");
            }
            else
            {
                printf("\nTipo de veiculo invalido!\n");
                break;
            }

            fclose(veiculos);
            fclose(historico);

            vagas++;

            printf("Placa: %s\n", placa);
            printf("Horario de entrada: %s\n", horarioEntrada);
            printf("Cadastro realizado!\n");

            break;

            // ==========================================
            // REGISTRAR SAIDA
            // ==========================================

        case 2:

            printf("\n=========== SAIDA DO ESTACIONAMENTO ===========\n");

            printf("Qual a placa do veiculo? ");
            scanf("%19s", placa);

            printf("\nQual o tipo de veiculo?\n");
            printf("1 - Carro\n");
            printf("2 - Moto\n");
            printf("Escolha: ");
            scanf("%d", &tipo);

            int horas;
            char horarioSaida[6];

            printf("Horario de saida (HH:MM): ");
            scanf("%5s", horarioSaida);

            printf("Quantas horas ficou no estacionamento? ");
            scanf("%d", &horas);

            if (horas <= 0)
            {
                printf("Quantidade de horas invalida!\n");
                break;
            }

            if (tipo == 1)
            {
                pagamento = 8 + ((horas - 1) * 5);
            }
            else if (tipo == 2)
            {
                pagamento = 8 + ((horas - 1) * 3);
            }
            else
            {
                printf("Tipo de veiculo invalido!\n");
                break;
            }

            printf("\nValor do pagamento: R$ %.2f\n", pagamento);


            caixa = fopen("arquivos/caixa.txt", "a");
            historico = fopen("arquivos/historico.txt", "a");
            if (caixa == NULL)
            {
                printf("\nErro ao abrir o arquivo caixa!\n");
                break;
            }
            if (tipo == 1)
            {
                carro++;

                fprintf(caixa, "Veiculo: Carro | Placa : %s | Horario de saida: %s| Valor: %.2f\n",
                        placa, horarioSaida, pagamento);
                    fprintf(historico, "Veiculo: Carro | Placa : %s | Horario de saida: %s| Valor: %.2f\n",
                        placa, horarioSaida, pagamento);
            }
            else if (tipo == 2)
            {
                moto++;

                fprintf(caixa, "Veiculo: Moto| Placa : %s | Horario de saida: %s| Valor: %.2f\n",
                        placa, horarioSaida, pagamento);
                        fprintf(historico, "Veiculo: Moto | Placa : %s | Horario de saida: %s| Valor: %.2f\n",
                        placa, horarioSaida, pagamento);
            }
            fclose(caixa);
            fclose(historico);

            faturamento += pagamento;

            if (vagas > 0)
            {
                vagas--;
            }

            printf("Saida registrada!\n");

            break;

            vagas++;

            printf("Placa: %s\n", placa);
            printf("Horario de saida: %s\n", horarioSaida);
            printf("Saida realizado!\n");

            // ==========================================
            // CONSULTAR SITUACAO
            // ==========================================

        case 3:

            printf("\n=========== SITUACAO DO ESTACIONAMENTO ===========\n");

            printf("Vagas totais: 20\n");

            ocupados = vagas;

            printf("Vagas ocupadas: %d\n", ocupados);

            quant = 20 - ocupados;

            printf("Vagas disponiveis: %d\n", quant);

            printf("Carros que entraram: %d\n", carro);

            printf("Motos que entraram: %d\n", moto);

            break;

            // ==========================================
            // FATURAMENTO
            // ==========================================

        case 4:
            caixa = fopen("arquivos/caixa.txt", "r");
            printf("\n============ FATURAMENTO ============\n");

            atendidos = carro + moto;

            printf("\nVeiculos atendidos: %d\n", atendidos);

            printf("Faturamento nesta execucao: R$ %.2f\n",
                   faturamento);
            while (

                fscanf(
                    caixa,
                    "carro %d | moto %d | faturamento %.2f| Valor: %.2f\n",
                    &carro,
                    &moto,
                    &faturamento) == 4

            )
            {

                printf("\nVeiculos %d\n");

                printf("Carro: %s\n", carro);
                printf("Motp: %d\n", moto);
                printf("Fturamento ¨%f\n", faturamento);
                printf("Valor: %.2f\n", pagamento);
            }

            fclose(caixa);
            break;
        // CONSULTAR VEICULOS
        case 5:
            printf("\n=========== VEÍCULOS ESTACIONADOS ===========\n");
            printf("\nDeseja buscar qual veiculo?\n");
            printf("\nOpcão - 1: CARRO!\n");
            printf("\nOpcão -2: MOTO!\n");
            printf("Escolha: ");
            scanf("%d", &tipo);
            veiculos = fopen("arquivos/veiculos.txt", "r");

            if (tipo == 1)
            {
                printf("Escreva a placa: ");
                scanf("%17s", placa);

                rewind(veiculos);

                while (fscanf(veiculos, "CARRO:%17[^;];%5[^;];=%*f",
                              placaArquivo, horario) == 2)
                {
                    if (strcmp(placa, placaArquivo) == 0)
                    {
                        printf("\nVeiculo encontrado!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0)
                {
                    printf("\nVeiculo nao encontrado!\n");
                }
            }
            else if (tipo == 2)
            {
                printf("Escreva a placa: ");
                scanf("%17s", placa);

                char placaArquivo[18];
                char horario[6];
                int encontrado = 0;

                rewind(veiculos);

                while (fscanf(veiculos, "MOTO:%17[^;];%5[^;];=%*f",
                              placaArquivo, horario) == 2)
                {
                    if (strcmp(placa, placaArquivo) == 0)
                    {
                        printf("\nVeiculo encontrado!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0)
                {
                    printf("\nVeiculo nao encontrado!\n");
                }
            }
            else
            {
                printf("\nTipo de veiculo invalido!\n");
            }
        fclose(veiculos);
        case 6:
        historico = fopen("arquivos/historico.txt", "r");
        printf("===========================================\nCONSULTAR HISTORICO DO ESTACIONAMENTO \n===========================================\n");
        while(
            fgets(linha, sizeof(linha), historico) != NULL
        )
        {
            printf(" %s", linha);
        }
            
        fclose(historico);
            // ==========================================
            // SAIR
            // ==========================================

        case 7:

            printf("\n=========== SAIR DO SISTEMA ===========\n");

            printf("Realmente deseja sair?\n");
            printf("1 - SIM\n");
            printf("2 - NAO\n");
            printf("Escolha: ");
            scanf("%d", &sair);

            if (sair == 1)
            {
                printf("\nOBRIGADO POR USAR NOSSO ESTACIONAMENTO!\n");
            }
            else
            {
                sair = 0;
            }

            break;

        default:

            printf("\nOpcao invalida!\n");

            break;
        }

    } while (sair != 1);
}