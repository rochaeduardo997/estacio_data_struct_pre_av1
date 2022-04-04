#include <stdio.h>

void cleaningValues(int *piValue1, int *piValue2);

int main(void)
{
  int iUserInput1 = 0;
  int iUserInput2 = 0;

  int *piUserInput1;
  int *piUserInput2;

  printf("Valor 1: ");
  scanf("%d", &iUserInput1);
  printf("Valor 2: ");
  scanf("%d", &iUserInput2);

  piUserInput1 = &iUserInput1;
  piUserInput2 = &iUserInput2;

  printf("Antes: %d e %d", *piUserInput1, *piUserInput2);
  cleaningValues(piUserInput1, piUserInput2);
  printf("Depois: %d e %d", *piUserInput1, *piUserInput2);

  return 0; 
}

void cleaningValues(int *piValue1, int *piValue2)
{
  *piValue1 = 0;
  *piValue2 = 0;
}
