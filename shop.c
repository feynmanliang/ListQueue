/*
 * shop.c -- regression test for queue module
 */
#include <stdio.h>
#include <stdlib.h>

#include "./myQueue.h"
#define MAX_LENGTH 100 /* longest line allowed */

typedef struct _Entry {
  char name[MAX_LENGTH-sizeof(int)];
  int amount;
} Entry;

void printAndDeallocate(void* element) {
    Entry* currentEntry;

    currentEntry = (Entry*) element;
    printf("%s %i\n", currentEntry->name, currentEntry->amount);
    free(currentEntry);
    currentEntry = NULL;
}

public int main(int argc, char *argv[]) {
  void *shoppingList;
  Entry *currentEntry;

  shoppingList = qopen();	

  if (argc > 1) {
    int i;
    int numEntries;

    numEntries = atoi(argv[1]);

    for (i = 0; i < numEntries; i++) {
      currentEntry = (Entry *) malloc(sizeof (Entry));
      scanf("%s %i", currentEntry->name, &currentEntry->amount);
      qput(shoppingList, (void*) currentEntry);
    }
    printf("\n");
  }

  else {
    int res = 2;
    while (res == 2) {
      char buff[MAX_LENGTH];

      currentEntry = (Entry *) malloc(sizeof (Entry));
      fgets(buff, sizeof(buff), stdin);
      res = sscanf(buff, "%s %i", currentEntry->name, &currentEntry->amount);
      if (res == 2)
        qput(shoppingList, (void*) currentEntry);
    }
  }

  printf("First Item: ");
  printAndDeallocate(qget(shoppingList));

  printf("Rest of list:\n");
  qapply(shoppingList, printAndDeallocate);

  qclose(shoppingList);
  return EXIT_SUCCESS;
}

