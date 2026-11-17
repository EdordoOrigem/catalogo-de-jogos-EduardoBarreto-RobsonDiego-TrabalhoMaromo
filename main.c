
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modulo.h"

int main()
{
    Jogo *jogos[MAX] = {NULL};

    carregarJogos(jogos); // carregar os games que ja estao no arquivo game

    int opcao;

    do
    {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Cadastrar novo jogo\n");
        printf("2 - Listar todos os jogos\n");
        printf("3 - Buscar jogo por codigo\n");
        printf("4 - Relatorio de jogos\n");
        printf("5 - Salvar e sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            int pos = -1;

            // Procurar uma posicao vazia
            for (int i = 0; i < MAX; i++)
            {
                if (jogos[i] == NULL)
                {
                    pos = i;
                    break;
                }
            }

            // Verificar se o catalogo esta cheio
            if (pos == -1)
            {
                printf("Catalogo cheio!\n");
                break;
            }

            // Reservar memoria para o novo jogo
            jogos[pos] = malloc(sizeof(Jogo));

            if (jogos[pos] == NULL)
            {
                printf("Erro ao alocar memoria!\n");
                break;
            }

            cadastrarJogo(jogos[pos]);

            printf("Jogo cadastrado!\n");

            break;
        }

        case 2:
            for (int i = 0; i < MAX; i++)
            {
                if (jogos[i] != NULL)
                {
                    exibirJogo(jogos[i]);
                }
            }
            break;

        case 3:
        {
            int codigoBusca;

            printf("Digite o codigo do jogo: ");
            scanf("%d", &codigoBusca);

            Jogo *encontrado = buscarJogo(jogos, codigoBusca);

            if (encontrado != NULL)
            {
                exibirJogo(encontrado);
            }
            else
                printf("Jogo não encontrado!");

            break;
        }

        case 4:
            relatorioJogos(jogos);
            break;

        case 5:
            salvarJogos(jogos);
            printf("Encerrando programa...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    for (int i = 0; i < MAX; i++)
    {
        if (jogos[i] != NULL)
        {
            free(jogos[i]);
            jogos[i] = NULL;
        }
    }

    return 0;
}
