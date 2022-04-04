#include <stdio.h>
#include <stdlib.h>

void scanMatrixSize(int *piRow, int *piCol);
void readMatrixValues(int **piMatrix, int iRow, int iCol);
void scanMatrixValues(int **piMatrix, int iRow, int iCol);
int ** matrixAllocation(int *piRow, int *piCol);
void verifyIfCanMult(int iRow1, int iRow2, int iCol1, int iCol2);
int ** multiplyMatrix(int **piMatrix1, int **piMatrix2, int *iRow1, int *iCol1) ;

int main(void)
{
  int iRow1  = 0;
  int iCol1  = 0;

  int iRow2  = 0;
  int iCol2  = 0;

  int **piMatrix1;
  int **piMatrix2;

  printf("Primeira matriz\n");
  int *piRow = &iRow1;
  int *piCol = &iCol1;
  //leitura do tamanho da matriz
  scanMatrixSize(piRow, piCol);
  //alocacao dinamica da matriz
  piMatrix1 = matrixAllocation(piRow, piCol);
  //leitura dos valores de cada indice da matriz
  scanMatrixValues(piMatrix1, iRow1, iCol1);

  printf("\nSegunda matriz\n");
  piRow = &iRow2;
  piCol = &iCol2;
  //leitura do tamanho da matriz
  scanMatrixSize(piRow, piCol);
  //alocacao dinamica da matriz
  piMatrix2 = matrixAllocation(piRow, piCol);
  //leitura dos valores de cada indice da matriz
  scanMatrixValues(piMatrix2, iRow2, iCol2);

  //teste para verificar se a matrix pode ser multiplicada
  verifyIfCanMult(iRow1, iRow2, iCol1, iCol2);

  //multiplicacao e alocacao da nova matriz com os valores multiplicados
  //tambem faz a liberacao do espaco alocado para as matrizes anterioes
  int **piNewMatrix = multiplyMatrix(piMatrix1, piMatrix2, piRow, piCol);

  //leitura dos valores multiplicados
  readMatrixValues(piNewMatrix, iRow1, iCol1);

  return 0;
}

void scanMatrixSize(int *piRow, int *piCol)
{
  printf("Linhas: ");
  scanf("%d", piRow);
  printf("Colunas: ");
  scanf("%d", piCol);
}

void readMatrixValues(int **piMatrix, int iRow, int iCol)
{
  printf("\n");
  for(int i = 0; i < iRow; i++)
  {
    for(int j = 0; j < iCol; j++)
    {
      printf("Indice [%d][%d]: %d\n", i, j, piMatrix[i][j]);
    }
  }
}

void scanMatrixValues(int **piMatrix, int iRow, int iCol)
{
  for(int i = 0; i < iRow; i++)
  {
    for(int j = 0; j < iCol; j++)
    {
      printf("Indice [%d][%d]: ", i, j);
      scanf("%d", &piMatrix[i][j]);
    }
  }
}

int ** matrixAllocation(int *piRow, int *piCol)
{
  int **piMatrix = (int**) calloc(*piRow, sizeof(int));
  for(int i = 0; i < *piRow; i++)
  {
    piMatrix[i] = (int*) calloc(*piCol, sizeof(int));
  }

  return piMatrix;
}

void verifyIfCanMult(int iRow1, int iRow2, int iCol1, int iCol2)
{
  if(iRow1 != iRow2){
    printf("Cannot multiply\n");
    exit(0);
  }
  if(iCol1 != iCol2){
    printf("Cannot multiply\n");
    exit(0);
  }
}

int ** multiplyMatrix(int **piMatrix1, int **piMatrix2, int *iRow1, int *iCol1) 
{
  int **piNewMatrix = matrixAllocation(iRow1, iCol1);

  for(int i = 0; i < *iRow1; i++)
  {
    for(int j = 0; j < *iCol1; j++)
    {
      piNewMatrix[i][j] = piMatrix1[i][j] * piMatrix2[i][j];
    }
  }

  free(piMatrix1);
  free(piMatrix2);

  return piNewMatrix;
}

