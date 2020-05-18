#include "./list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *LL_Create() {
  // Allocate space for the Linked List
  LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));
  newList->lenght = 0;

  // Allocate space for the first Node and initializing the attributes to NULL
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = NULL;
  new_node->next = NULL;

  // Assign the head of the list to the empty node.
  newList->List = new_node;
  return newList;
}

int LL_getLength(LinkedList *list) { return list->lenght; }

bool LL_AddOrder(LinkedList *list, void *data, int (*comp)(void *, void *)) {
  node *new_node;
  node *curr;
  node *prev = NULL;

  // Check the structure
  if (list == NULL || list->List == NULL) {
    fprintf(stderr, "LL_AddOrder: LinkedList is NULL\n");
    return false;
  }

  if (data == NULL) {
    fprintf(stderr, "LL_AddOrder: data is NULL\n");
    return false;
  }

  curr = list->List;

  // The List is empty and the head->data is equal to NULL
  if (curr->data == NULL && list->lenght == 0) {
    list->lenght = list->lenght + 1;
    curr->data = data;
    return true;
  }

  new_node = (node *)malloc(sizeof(node));
  new_node->data = data;

  // Iterate the LinkedList until it find the correct position of the new Data
  while (curr != NULL && curr->data != NULL && comp(curr->data, data) < 0) {
    prev = curr;
    curr = curr->next;
  }
  new_node->next = curr;

  if (prev == NULL)
    list->List = new_node;
  else
    prev->next = new_node;
  list->lenght = list->lenght + 1;
  return true;
}

bool LL_removeData(LinkedList *list, void *data, int (*comp)(void *, void *)) {
  node *prev = NULL;
  node *curr = list->List;

  // Check the structure
  if (curr == NULL || curr->data == NULL || list->lenght == 0) {
    fprintf(stderr, "LL_removeData: LinkedList is NULL\n");
    return false;
  }

  if (data == NULL) {
    fprintf(stderr, "LL_removeData: data is NULL\n");
    return false;
  }

  // Iterate the structure until it find the correct node with data
  while (curr != NULL && curr->data != NULL && comp(curr->data, data) != 0) {
    prev = curr;
    curr = curr->next;
  }

  // Check if it actualy find the data and then remove it
  if (comp(curr->data, data) == 0) {
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
    list->lenght = list->lenght - 1;
    return true;
  } else {
    fprintf(stderr, "LL_removeData: Data not inside List\n");
    return false;
  }
}

void *LL_removeIndex(LinkedList *list, int index) {
  node *prev = NULL;
  node *curr = list->List;

  // Check the structure
  if (curr == NULL || curr->data == NULL) {
    fprintf(stderr, "LL_removeIndex: LinkedList is NULL\n");
    return NULL;
  }

  if (list->lenght < index) {
    fprintf(stderr, "LL_removeIndex: Index is higher than List lenght\n");
    return NULL;
  }

  int count = 0;
  if (index == 0) {
    void *Data = curr->data;

    prev = curr->next;
    curr->next = NULL;
    free(curr);
    list->List = prev;
    list->lenght = list->lenght - 1;
    return Data;
  }
  // Iterate the structure until it find the node of position equal index
  while (curr != NULL && curr->data != NULL && count < index) {
    prev = curr;
    curr = curr->next;
    count++;
  }

  // Check that it loop exacly index time
  if (count == index) {
    void *Data = curr->data;
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
    list->lenght = list->lenght - 1;
    return Data;
  } else { // List was shorter than index or some node->data was NULL
    fprintf(stderr, "LL_removeIndex: Loop exacly %d of %d times\n", count,
            index);
    return NULL;
  }
}

void *LL_GetIndexData(LinkedList *list, int index) {
  node *prev = NULL;
  node *curr = list->List;

  // Check the structure
  if (curr == NULL || curr->data == NULL) {
    fprintf(stderr, "LL_GetIndexData: LinkedList is NULL\n");
    return NULL;
  }
  if (list->lenght < index) {
    fprintf(stderr, "LL_GetIndexData: Index is higher than List lenght\n");
    return NULL;
  }

  int count = 0;
  // Iterate the structure until it find the node of position equal index
  while (curr != NULL && curr->data != NULL && count < index) {
    prev = curr;
    curr = curr->next;
    count++;
  }

  // Check that it loop exacly index time
  if (count == index) {
    void *Data = curr->data;
    return Data;
  } else { // List was shorter than index or some node->data was NULL
    fprintf(stderr, "LL_removeIndex: Loop exacly %d of %d times\n", count,
            index);
    return NULL;
  }
}

void LL_Destroy(LinkedList *list) {
  node *curr = list->List;
  node *next;
  // Deallocate all node of the list.
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  // Deallocate the List.
  free(list);
}

void LL_Print(LinkedList *list, void (*print)(void *data)) {
  printf("List is %d items long\n", list->lenght);

  // For each node, it pass the data to (*print)(void *data)
  node *curr = list->List;
  while (curr != NULL) {
    print(curr->data);
    curr = curr->next;
  }
  putchar('\n');
}