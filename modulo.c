
#include <stdio.h>
#include <string.h>
#include "modulo.h"
#include <stdlib.h>


//exibir os game
void exibirJogo(Jogo *jogo)
{
    printf("\n===== CATALOGO DE JOGOS =====\n");

    printf("Codigo: %d\n", jogo->codigo);
    printf("Preco: %.2f\n", jogo->preco);
    printf("Titulo: %s\n", jogo->titulo);
    printf("Desenvolvedora: %s\n", jogo->desenvolvedora);
    printf("Horas: %.2f\n", jogo->horas);
}


void cadastrarJogo(Jogo *jogo)
{
    int resultado;
    int c;

    printf("\n===== CADASTRAR JOGO =====\n");

   
    do
    {
        printf("Digite o codigo: ");
        resultado = scanf("%d", &jogo->codigo);

        if (resultado == EOF)
        {
            printf("Entrada encerrada!\n");
            return;
        }

        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        if (resultado != 1 || jogo->codigo <= 0)
        {
            printf("Codigo invalido! Tente novamente.\n");
        }

    } while (resultado != 1 || jogo->codigo <= 0);

    
    do
    {
        printf("Digite o preco do game: ");
        resultado = scanf("%f", &jogo->preco);

        if (resultado == EOF)
        {
            printf("Entrada encerrada!\n");
            return;
        }

        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        if (resultado != 1 || jogo->preco < 0)
        {
            printf("Preco invalido! Tente novamente.\n");
        }

    } while (resultado != 1 || jogo->preco < 0);

  
    do
    {
        printf("Digite as horas jogadas no game: ");
        resultado = scanf("%f", &jogo->horas);

        if (resultado == EOF)
        {
            printf("Entrada encerrada!\n");
            return;
        }

        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        if (resultado != 1 || jogo->horas < 0)
        {
            printf("Horas invalidas! Tente novamente.\n");
        }

    } while (resultado != 1 || jogo->horas < 0);


    printf("Digite o nome do game: ");

    if (fgets(jogo->titulo, 50, stdin) == NULL)
    {
        printf("Erro ao ler o titulo!\n");
        return;
    }

    jogo->titulo[strcspn(jogo->titulo, "\n")] = '\0';


    printf("Digite o nome da desenvolvedora: ");

    if (fgets(jogo->desenvolvedora, 50, stdin) == NULL)
    {
        printf("Erro ao ler a desenvolvedora!\n");
        return;
    }

    jogo->desenvolvedora[strcspn(jogo->desenvolvedora, "\n")] = '\0';
}


Jogo *buscarJogo(Jogo *jogos[], int codigo)
{
    for (int i = 0; i < MAX; i++)
    {
        if (jogos[i] != NULL &&
            jogos[i]->codigo == codigo)
        {
            return jogos[i];
        }
    }

    return NULL;
}


void relatorioJogos(Jogo *jogos[])
{
    float soma = 0;
    float media;
    int quantidade = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (jogos[i] != NULL)
        {
            soma += jogos[i]->preco;
            quantidade++;
        }
    }

    if (quantidade > 0)
    {
        media = soma / quantidade;
        printf("Media dos precos: R$ %.2f\n", media);
    }
    else
    {
        printf("Nenhum jogo cadastrado!\n");
    }
}

void salvarJogos(Jogo *jogos[])
{
    FILE *arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (jogos[i] != NULL)
        {
            fprintf(arquivo, "%d;%s;%s;%.2f;%.2f\n",
                    jogos[i]->codigo,
                    jogos[i]->titulo,
                    jogos[i]->desenvolvedora,
                    jogos[i]->preco,
                    jogos[i]->horas);
        }
    }

    fclose(arquivo);

    printf("Jogos salvos com sucesso!\n");

}


void carregarJogos(Jogo *jogos[])
{
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nenhum arquivo de jogos encontrado.\n");
        return;
    }

    char linha[256];
    int i = 0;

    while (i < MAX && fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        Jogo *jogo = malloc(sizeof(Jogo));

        if (jogo == NULL)
        {
            printf("Erro ao alocar memoria!\n");
            break;
        }

        int resultado = sscanf(linha, "%d;%49[^;];%49[^;];%f;%f",
            &jogo->codigo,
            jogo->titulo,
            jogo->desenvolvedora,
            &jogo->preco,
            &jogo->horas);

        if (resultado == 5)
        {
            jogos[i] = jogo;
            i++;
        }
        else
        {
            free(jogo);
        }
    }

    fclose(arquivo);

    printf("%d jogo(s) carregado(s)!\n", i);
}

