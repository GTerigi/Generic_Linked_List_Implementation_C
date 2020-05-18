#include "./list.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 25

int NumberCompare(void *, void *);
void NumberPrint(void *);

int main(int argc, char const *argv[]) {
  int randomNumber[] = {176, 39,  105, 200, 100, 12,  183, 217, 80,
                        189, 187, 204, 193, 220, 118, 23,  56,  145,
                        58,  166, 16,  115, 187, 175, 210};

  LinkedList *my_list = LL_Create(NULL);

  // Print out the empty list
  LL_Print(my_list, NumberPrint);

  printf("\n\tLL_AddOrder\n\n");

  // Add all of the numbers
  for (size_t i = 0; i < ARRAY_SIZE; i++)
    LL_AddOrder(my_list, (void *)(&randomNumber[i]), NumberCompare);

  // Print out list of sorted numbers
  LL_Print(my_list, NumberPrint);
  int a;

  printf("\n\tLL_removeIndex\n\n");

  // Remove first five numbers
  for (size_t i = 0; i < 5; i++) {
    a = *((int *)LL_removeIndex(my_list, 0));
    if (a == NULL) {
      fprintf(stderr, "DATA is NULL\n");
      return EXIT_FAILURE;
    }
    printf("%d was removed from the List\n", a);
  }

  // Print list again
  LL_Print(my_list, NumberPrint);

  printf("\n\tLL_removeData\n\n");

  // Remove number 100
  int tmp = 100;
  if (LL_removeData(my_list, (void *)&tmp, NumberCompare)) {
    printf("100 removed Correctly\n");
  } else {
    fprintf(stderr, "Error removing 100\n");
  }
  // Print list again
  LL_Print(my_list, NumberPrint);

  printf("\n\tLL_GetIndexData\n\n");

  // Get Data from node n.15
  a = *((int *)LL_GetIndexData(my_list, 15));
  if (a == NULL) {
    fprintf(stderr, "DATA is NULL\n");
    return EXIT_FAILURE;
  }
  printf("%d is Data from 15th node of the List\n\n\n", a);
  // Print list again
  LL_Print(my_list, NumberPrint);
  // Free the list
  LL_Destroy(my_list);

  return 0;
}

int NumberCompare(void *a, void *b) {
  if (*(int *)a < *(int *)b)
    return -1;
  if (*(int *)a > *(int *)b)
    return 1;

  return 0;
}

void NumberPrint(void *num) {
  int *n = (int *)num;
  if (n == NULL)
    return;
  printf("%d\t", *n);
}
