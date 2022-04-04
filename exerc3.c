#include <stdio.h>
#include <string.h>

#define SIZE_OF_STRING 100

void swapValue(char *sValue1, char *sValue2);

int main(void)
{
  char sUserInput1[SIZE_OF_STRING];
  char sUserInput2[SIZE_OF_STRING];

  char *psUserInput1;
  char *psUserInput2;

  printf("String1: ");
  scanf("%s", sUserInput1);
  printf("String2: ");
  scanf("%s", sUserInput2);

  psUserInput1 = sUserInput1;
  psUserInput2 = sUserInput2;

  printf("Antes: %s e %s\n", psUserInput1, psUserInput2);
  swapValue(psUserInput1, psUserInput2);
  printf("Depois: %s e %s\n", psUserInput1, psUserInput2);

  return 0;
}

void swapValue(char *sValue1, char *sValue2)
{
  char sSwapAux[SIZE_OF_STRING];

  strcpy(sSwapAux, sValue1);
  strcpy(sValue1, sValue2);
  strcpy(sValue2, sSwapAux);
}
