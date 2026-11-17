
#ifndef JOGO_H
#define JOGO_H

#define MAX 100

typedef struct {
    int codigo;
    char titulo[50];
    char desenvolvedora[50];
    float preco;
    float horas;
} Jogo;

void exibirJogo(Jogo *jogo);
void cadastrarJogo(Jogo *jogo);
Jogo *buscarJogo(Jogo *jogos[], int codigo);
void relatorioJogos(Jogo *jogos[]);
void salvarJogos(Jogo *jogos[]);    
void carregarJogos(Jogo *jogos[]);
#endif

