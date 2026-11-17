# Catálogo de Jogos Digitais

esse sistema permite cadastrar e consultar games por meio de um menu no terminal. Os registros são armazenados em memória durante a execução e salvos em um arquivo de texto para serem recuperados quando o programa for aberto novamente.

## 1. Integrantes

| **[Eduardo Barreto Ferreira Júnior]** 
| **[Robson Diego Fernandes Rocha]** 

## 2. Motivo da escolha do tema

Escolhemos o tema **Catálogo de Jogos Digitais** por nosso amor com games e por ser uma forma prática de aplicar os conteúdos estudados na disciplina com um tema de algo que gostamos. Os dados de cada game permitem trabalhar com diferentes tipos de variáveis, estruturas (`struct`), ponteiros, alocação dinâmica de memória e arquivos de texto.

## 3. Dados armazenados

Cada game é representado por uma estrutura `Jogo`, com os seguintes campos:

| Campo | Tipo | Descrição |
|---|---|---|
| `codigo` | `int` | Identificador usado na busca do jogo |
| `titulo` | `char[50]` | Nome do jogo |
| `desenvolvedora` | `char[50]` | Empresa ou estúdio desenvolvedor |
| `preco` | `float` | Preço do jogo |
| `horas` | `float` | Quantidade de horas jogadas |

O catálogo possui capacidade máxima de **100 registros**, definida pela constante `MAX`.

## 4. Funcionalidades

O menu principal apresenta cinco opções:

1. **Cadastrar novo jogo:** recebe os dados do usuário e cria um registro na memória.
2. **Listar todos os jogos:** mostra os dados de todos os jogos cadastrados.
3. **Buscar jogo por código:** procura e exibe um jogo específico; caso não exista, informa que não foi encontrado.
4. **Relatório de jogos:** calcula e apresenta a média dos preços dos jogos cadastrados.
5. **Salvar e sair:** grava os dados no arquivo `dados.txt` e encerra a aplicação, liberando a memória alocada.

Ao iniciar, o sistema também tenta **carregar automaticamente os registros de `dados.txt`**. Se o arquivo ainda não existir, o catálogo começa vazio.

## 5. Organização dos arquivos

Projeto_EduardoBarreto_Robson_Diego/
├── main.c       # Menu principal e fluxo da aplicação
├── modulo.h     # Struct, constante MAX e protótipos das funções
├── modulo.c     # Implementação das operações do catálogo
├── dados.txt    # Armazenamento dos jogos em texto
└── README.md    # Documentação do projeto
```

A aplicação foi separada em três arquivos de código para seguir a proposta de **modularização e TAD (Tipo Abstrato de Dados)**:

- **`modulo.h`:** declara o tipo `Jogo`, a constante `MAX` e as funções disponíveis.
- **`modulo.c`:** implementa as rotinas de cadastro, exibição, busca, relatório, salvamento e carregamento.
- **`main.c`:** organiza o menu com `do...while` e `switch...case`, chama as funções do módulo e libera a memória antes do encerramento.

### Funções principais

| Função | Responsabilidade |
|---|---|
| `cadastrarJogo()` | Lê os dados de um jogo informado pelo usuário |
| `exibirJogo()` | Mostra as informações de um jogo |
| `buscarJogo()` | Busca um jogo por código e retorna seu ponteiro ou `NULL` |
| `relatorioJogos()` | Calcula a média dos preços cadastrados |
| `salvarJogos()` | Escreve os registros no arquivo `dados.txt` |
| `carregarJogos()` | Lê os registros de `dados.txt` ao iniciar |

## 6. Modelagem e decisões de implementação

Para organizar o problema, definimos primeiro quais informações seriam necessárias para representar um jogo. Em seguida, criamos a `struct Jogo` e separamos as funcionalidades em funções próprias.

Utilizamos um **vetor de ponteiros**, inicialmente preenchido com `NULL`, em vez de reservar todos os registros completos desde o início. Quando um jogo é cadastrado ou carregado do arquivo, usamos `malloc()` para reservar memória apenas para aquele registro. Antes do encerramento, utilizamos `free()` para liberar as posições ocupadas.

Para a persistência, optamos por um arquivo de texto com os campos separados por ponto e vírgula (`;`). A gravação utiliza `fopen()`, `fprintf()` e `fclose()`; a leitura utiliza `fopen()`, `fgets()`, `sscanf()` e `fclose()`.

O código inclui verificações básicas de entrada numérica e de falhas na abertura dos arquivos e na alocação de memória.

### Divisão de tarefas da dupla

> **Preencher esta seção de acordo com o trabalho realmente realizado por cada integrante antes da entrega.**

- **Integrante 1 — [nome]:** [descrever quais partes implementou, testou ou revisou].
- **Integrante 2 — [nome]:** [descrever quais partes implementou, testou ou revisou].
- **Trabalho conjunto:** [descrever decisões tomadas em dupla, integração dos arquivos e testes finais].

## 7. Como compilar e executar

### Requisitos

- Compilador **GCC** para linguagem C.
- Terminal Linux, Ubuntu/WSL ou ambiente equivalente com GCC instalado.
- Não são necessárias bibliotecas externas além das bibliotecas padrão da linguagem C.

Abra o terminal no main.c

**Compilação:**

```bash
gcc -Wall -Wextra main.c modulo.c -o catalogo
```

**Execução:**

```bash
./catalogo
```

Executar com um único comando:

```bash
gcc -Wall -Wextra main.c modulo.c -o catalogo && ./catalogo
```

### Como utilizar

1. Execute o programa e aguarde o carregamento dos jogos salvos, caso exista `dados.txt`.
2. Escolha uma opção digitando seu número no menu.
3. Para cadastrar, informe código, preço, horas jogadas, título e desenvolvedora.
4. Use as opções de listagem, busca e relatório para consultar o catálogo.
5. Escolha **5 — Salvar e sair** para gravar os dados no arquivo de texto.

## 8. Formato do arquivo `dados.txt`

Cada linha corresponde a um jogo, com os campos nesta ordem:

```text
codigo;titulo;desenvolvedora;preco;horas
```

Exemplo:

```text
1;Warframe;Digital Extremes;120.00;2202.00
2;Helldivers 2;Arrow Studios;219.90;10000.00
```

O arquivo é lido automaticamente na inicialização. Ao salvar, ele é reescrito com os jogos presentes no catálogo. Os valores acima são apenas exemplos.

## 9. Testes realizados

Foram realizados testes no terminal para verificar:

- Cadastro e listagem de vários jogos.
- Busca por códigos existentes e inexistentes.
- Cálculo da média dos preços.
- Tratamento básico de entradas numéricas inválidas.
- Salvamento dos registros no `dados.txt`.
- Encerramento e nova execução do programa para confirmar o carregamento dos registros salvos.


