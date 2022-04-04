#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE       30
#define MATRIX_COL_SIZE 2
#define MATRIX_ROW_SIZE 5

struct Produto
{
  char   nome[NAME_SIZE];
  int    codigo;
  double preco;
};

int main(void)
{
  struct Produto **pProduct = calloc(MATRIX_COL_SIZE, sizeof(struct Produto));

  for(int i = 0; i < MATRIX_ROW_SIZE; i++)
  {
    pProduct[i] = malloc(MATRIX_ROW_SIZE * sizeof(struct Produto));
  }

  for(int i = 0; i < MATRIX_COL_SIZE; i++)
  {
    for(int j = 0; j < MATRIX_ROW_SIZE; j++)
    {
      strcpy(pProduct[0][j].nome, "Pe de Moleque");
      pProduct[0][j].codigo     = 13205;
      pProduct[0][j].preco      = 0.20;

      strcpy(pProduct[1][j].nome, "Cocada Baiana");
      pProduct[1][j].codigo     = 15202;
      pProduct[1][j].preco      = 0.50;
    }
  }

  for(int i = 0; i < MATRIX_COL_SIZE; i++)
  {
    for(int j = 0; j < MATRIX_ROW_SIZE; j++)
    {
      printf("[%d][%d]: \n->Cod: %d\n->Nome: %s\n->Preco: %.2f\n\n", i, j,
        pProduct[i][j].codigo,
        pProduct[i][j].nome,
        pProduct[i][j].preco
      );
    }
  }

  return 0;
}

/*int main(void) //topicos a e b
{
  struct Produto product[MATRIX_COL_SIZE][MATRIX_ROW_SIZE];

  for(int i = 0; i < MATRIX_COL_SIZE; i++)
  {
    for(int j = 0; j < MATRIX_ROW_SIZE; j++)
    {
      strcpy(product[0][j].nome, "Pe de Moleque");
      product[0][j].codigo     = 13205;
      product[0][j].preco      = 0.20;

      strcpy(product[1][j].nome, "Cocada Baiana");
      product[1][j].codigo     = 15202;
      product[1][j].preco      = 0.50;
    }
  }

  return 0;
}*/
