#include <stdio.h>

void fibonacciSerie(int iN);

int main(void)
{
  int iTermN = 0;

  printf("Number of terms: ");
  scanf("%d", &iTermN);

  fibonacciSerie(iTermN);

  return 0;
}

void fibonacciSerie(int iN)
{
  int iFirstNumber  = 0;
  int iSecondNumber = 1;
  int iNextTerm     = iFirstNumber + iSecondNumber;

  printf("Serie of %d: \n%d, ", iN, iSecondNumber);

  for(int i = 1; i < iN; i++)
  {
    if(i != (iN - 1))
      printf("%d, ", iNextTerm);
    else
      printf("%d\n", iNextTerm);

    iFirstNumber  = iSecondNumber;
    iSecondNumber = iNextTerm;
    iNextTerm     = iFirstNumber + iSecondNumber;
  }
}

