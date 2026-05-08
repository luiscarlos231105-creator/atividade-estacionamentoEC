#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char placa[20];
    char placaBusca[20];
    char tipoVeiculo[20];

    int veiculo = 1;
    int codigo = 1000;
    int caixa;
    int ticket;
    int pagamento;

    int horaEntrada;
    int minutoEntrada;

    int horaSaida;
    int minutoSaida;

    int entradaTotal;
    int saidaTotal;
    int minutosPermanencia;

    int horas;
    int minutos;

    float valorHora;
    float horasPermanencia;
    float valorBase;
    float valorFinal;
    float desconto = 0;
    float multa = 0;

    printf("Olá! Bem-vindo ao LC Shopping\n");

inicio:

    printf("\n========= ESTACIONAMENTO =========");
    printf("\n| 1 - Carro      | R$ 5.00/hora |");
    printf("\n| 2 - Moto       | R$ 3.00/hora |");
    printf("\n| 3 - Camionete  | R$ 8.00/hora |");
    printf("\n| 4 - Sair                      |");
    printf("\n==================================");

    printf("\nAperte o botão --> ");
    scanf("%d", &veiculo);

    switch (veiculo)
    {
        case 1:
            valorHora = 5;
            strcpy(tipoVeiculo, "Carro");
            break;

        case 2:
            valorHora = 3;
            strcpy(tipoVeiculo, "Moto");
            break;

        case 3:
            valorHora = 8;
            strcpy(tipoVeiculo, "Camionete");
            break;

        case 4:
            printf("\nSaindo...\n");
            return 0;

        default:
            printf("\nEssa opção não existe.\n");
            goto inicio;
    }

    printf("\nDigite a placa do veículo -> ");
    scanf("%s", placa);

    if (strlen(placa) > 7)
    {
        printf("\nEssa placa não existe. Tente novamente.\n");
        goto inicio;
    }

    /* HORÁRIO DE ENTRADA */

    do {
        printf("\nDigite o horário de entrada (hh:mm)");
        printf("\n-> ");
        scanf("%d:%d", &horaEntrada, &minutoEntrada);

        if (horaEntrada < 0 || horaEntrada > 23 ||
            minutoEntrada < 0 || minutoEntrada > 59)
        {
            printf("\nHorário inválido! Tente novamente.\n");
        }

    } while (horaEntrada < 0 || horaEntrada > 23 ||
             minutoEntrada < 0 || minutoEntrada > 59);

    codigo++;

    printf("\n\n=================================");
    printf("\n Ticket gerado com sucesso!");
    printf("\n Código -> %d", codigo);
    printf("\n=================================");

    printf("\n\nBoas compras ;)\n");

    printf("\n\n\n# ALGUMAS HORAS DEPOIS #");
    printf("\n| | | | | |");
    printf("\nV V V V V V\n");

caixa:

    printf("\n========= TAG CAIXA =========");
    printf("\n| 1 - Ler código de barras |");
    printf("\n| 2 - Digitar placa        |");
    printf("\n| 3 - Sair                 |");
    printf("\n=============================");

    printf("\nAperte o botão --> ");
    scanf("%d", &caixa);

    switch (caixa)
    {
        case 1:

            printf("\nDigite o código do ticket -> ");
            scanf("%d", &ticket);

            if (ticket != codigo)
            {
                printf("\nCódigo inválido!\n");
                goto caixa;
            }

            break;

        case 2:

            printf("\nDigite a placa do veículo -> ");
            scanf("%s", placaBusca);

            if (strcmp(placaBusca, placa) != 0)
            {
                printf("\nPlaca não encontrada!\n");
                goto caixa;
            }

            printf("\nPlaca encontrada com sucesso!\n");

            break;

        case 3:

            printf("\nVolte sempre!\n");
            return 0;

        default:

            printf("\nEssa opção não existe.\n");
            goto caixa;
    }

    /* HORÁRIO DE SAÍDA */

    do {
        printf("\nDigite o horário de saída (hh:mm)");
        printf("\n-> ");
        scanf("%d:%d", &horaSaida, &minutoSaida);

        if (horaSaida < 0 || horaSaida > 23 ||
            minutoSaida < 0 || minutoSaida > 59)
        {
            printf("\nHorário inválido! Tente novamente.\n");
        }

    } while (horaSaida < 0 || horaSaida > 23 ||
             minutoSaida < 0 || minutoSaida > 59);

    /* transforma tudo em minutos */
    entradaTotal = (horaEntrada * 60) + minutoEntrada;
    saidaTotal = (horaSaida * 60) + minutoSaida;

    /* verifica se virou o dia */
    if (saidaTotal < entradaTotal)
    {
        saidaTotal = saidaTotal + (24 * 60);
    }

    minutosPermanencia = saidaTotal - entradaTotal;

    /* separa horas e minutos */
    horas = minutosPermanencia / 60;
    minutos = minutosPermanencia % 60;

    horasPermanencia = minutosPermanencia / 60.0;

    /* valor base */
    valorBase = valorHora * horasPermanencia;

    /* até 1 hora */
    if (horasPermanencia <= 1)
    {
        valorBase = valorHora;
    }

    valorFinal = valorBase;

    /* desconto */
    if (horasPermanencia > 5)
    {
        desconto = valorBase * 0.10;
        valorFinal = valorFinal - desconto;
    }

    /* multa */
    if (horasPermanencia > 10)
    {
        multa = 20;
        valorFinal = valorFinal + multa;
    }

    /* RESUMO DA ESTADIA */

    printf("\n\n====================================");
    printf("\n         RESUMO DA ESTADIA");
    printf("\n====================================");

    printf("\nTempo permanecido: %02d:%02d",
           horas,
           minutos);

    printf("\nValor atual: R$ %.2f", valorFinal);

    printf("\n====================================");

    /* PAGAMENTO */

    printf("\n\n========= FORMA DE PAGAMENTO =========");
    printf("\n| 1 - CRÉDITO                        |");
    printf("\n| 2 - DÉBITO                         |");
    printf("\n| 3 - PIX                            |");
    printf("\n======================================");

    printf("\nEscolha -> ");
    scanf("%d", &pagamento);

    switch (pagamento)
    {
        case 1:
            printf("\nPagamento realizado no CRÉDITO!\n");
            break;

        case 2:
            printf("\nPagamento realizado no DÉBITO!\n");
            break;

        case 3:
            printf("\nPagamento realizado no PIX!\n");
            break;

        default:
            printf("\nForma de pagamento inválida!\n");
    }

    /* NOTA FISCAL */

    printf("\n\n====================================");
    printf("\n          NOTA FISCAL");
    printf("\n====================================");

    printf("\nPlaca: %s", placa);
    printf("\nTipo do veículo: %s", tipoVeiculo);

    printf("\nEntrada: %02d:%02d",
           horaEntrada,
           minutoEntrada);

    printf("\nSaída: %02d:%02d",
           horaSaida,
           minutoSaida);

    printf("\nTempo permanecido: %02d:%02d",
           horas,
           minutos);

    printf("\nValor base: R$ %.2f", valorBase);
    printf("\nDesconto: R$ %.2f", desconto);
    printf("\nMulta: R$ %.2f", multa);

    printf("\n------------------------------------");
    printf("\nVALOR FINAL: R$ %.2f", valorFinal);
    printf("\n====================================");

    printf("\n\nLC Shopping agradece sua visita!\n");

    return 0;
}