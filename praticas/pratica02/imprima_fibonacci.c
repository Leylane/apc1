#include <stdio.h>

int main() {
  printf("%9i %i \n", 1, 1);
  printf("%8i %i %i \n", 1, 2, 1);
  printf("%6i %i %i %i %i \n", 1, 2, 3, 2, 1);
  printf("%4i %i %i %i %i %i %i \n", 1, 2, 3, 5, 3, 2, 1);
  printf("%2i %i %i %i %i %i %i %i %i \n", 1, 2, 3, 5, 8, 5, 3, 2, 1);
    
  return 0;
}