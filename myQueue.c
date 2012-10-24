/*
 * myQueue.c - Linked list impementation of a queue
 */
#include <stdlib.h>
#include <stdio.h>


typedef struct _Node {
  void *data;
  struct _Node *next;
} Node;

typedef struct _List {
  Node *first;
  Node *last;
} List;

/* create an empty queue */
void* qopen(void) {
  List * listp;

  listp = malloc(sizeof(List));
  listp->first = listp->last = 0;
  return (void *) listp;
}

/* deallocate a queue, assuming every element has been removed and deallocated */
void qclose(void *qp) {
  free(qp);
}

/* put element at end of queue */
void qput(void *qp, void *elementp) {
  List * listp;
  Node * newNode;

  listp = (List *) qp;
  newNode = malloc (sizeof (Node));
  newNode->next = 0;
  newNode->data = elementp;

  if (listp->last) {
    listp->last->next = newNode;
    listp->last = newNode;
  }
  else {
    listp->first = newNode;
    listp->last = newNode;
  }
}

/* get first element from a queue */
void* qget(void *qp) {
  List * listp;
  Node * first;
  void * elementp;
  Node * next;

  listp = (List *) qp;
  first = listp->first;
  next = first->next;

  elementp = first->data;

  if (next) {
    listp->first = next;
  }
  else {
    listp->first = 0;
    listp->last = 0;
  }
  free(first);

  return elementp;
}

/* apply a void function (e.g. a printing fn) to every element of a queue */
void qapply(void *qp, void (*fn)(void* elementp)) {
  Node * nodep;
  List * listp;

  listp = (List *) qp;
  for (nodep = listp->first; nodep; nodep = nodep->next) {
    fn((void *) nodep->data);
  }
}
