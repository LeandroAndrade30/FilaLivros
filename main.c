#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 5

typedef struct {
  char livros[MAX_TAM][20];
  int inicio;
  int fim;
} FilaLivros;

void inicializarFilaDeLivros(FilaLivros *fila)
{
  fila->inicio = 0;
  fila->fim = 0;
}

void adicionarLivroFila(FilaLivros *fila, const char *livro)
{
  if (fila->fim == MAX_TAM) {
    printf("A fila de livros está cheia não foi possível adicionar mais livros.\n");
    return;
  }
  strcpy(fila->livros[fila->fim], livro);
  fila->fim++;
  printf("\n\n Livros adicionados na Fila:\n\n");
  printf("'%s' adicionado a fila de livros.\n", livro);
}

void removerLivroFila(FilaLivros *fila)
{
  if (fila->inicio == fila->fim)
  {
    printf("A fila de livros está vazia não foi possível remover nenhum Livro.\n");
  }
  else
  {
    printf("\nLivros removidos da fila de livros.\n");
    printf("'%s' \nremovido da fila de livros.\n", fila->livros[fila->inicio]);
    strcpy(fila->livros[fila->inicio], "");
    fila->inicio++;
  }
}

void exibirLivrosFila(FilaLivros *fila)
{
  printf("\n\nLivros na fila de livros:\n\n");

  for (int i = fila->inicio; i < fila->fim; i++)
  {
    printf("%s \n", fila->livros[i]);
  }
  printf("\n");
}

int main()
{
  FilaLivros fila;
  inicializarFilaDeLivros(&fila);

  printf("\n");

  adicionarLivroFila(&fila, "Livro 1");
  adicionarLivroFila(&fila, "Livro 2");
  adicionarLivroFila(&fila, "Livro 3");
  adicionarLivroFila(&fila, "Livro 4");
  adicionarLivroFila(&fila, "Livro 5");

  printf("\n");

  exibirLivrosFila(&fila);

  removerLivroFila(&fila);
  removerLivroFila(&fila);

  exibirLivrosFila(&fila);

  return 0;
}



