#if !defined(LIST_H)
#define LIST_H
#include <pthread.h>
#include <stdbool.h>

/**
 * @author      Giulio Terigi https://github.com/GTerigi
 * 
 * @doc         Simple Generic Linked List implementation.
 */

// Structure of one node.
// Generic Data and a pointer to the next node
typedef struct node_
{
    void *data;
    struct node_ *next;
} node;

// Struct of the wrapper of the list.
// Keeps in memory the list's length and the pointer to the list's head.
typedef struct LinkedList
{
    int lenght;
    node *List;
} LinkedList;

/**
 * @param list      Pointer to the linked List structure
 * @return int      List's length
 */
int LL_getLength(LinkedList *list);

/**
 * Create a new empty List, with length equal to 0
 * 
 * @return LinkedList pointer
 */
LinkedList *LL_Create();

/**
 * Add the new Data in the list following the order described in the function passed as argument.
 * 
 * @param list      Pointer to the linked List structure
 * @param data      Data that you want to store inside the node
 * @param comp      Function Handler that specify sorting order
 * 
 * @return true if the data is correctly inserted in the list, false otherwise
 */
bool LL_AddOrder(LinkedList *list, void *data, int (*comp)(void *, void *));

/**
 * Remove the required Data.
 * 
 * @param list      Pointer to the linked List structure
 * @param data      Data that you want to remove from the list
 * @param comp      Function Handler that specify when 2 void* are equals
 * @return true if the data is correctly removed from the list, false otherwise
 */
bool LL_removeData(LinkedList *list, void *data, int (*comp)(void *, void *));

/**
 * Remove the required Data.
 * 
 * @param list      Pointer to the linked List structure
 * @param index      index that you want to remove from the list
 * 
 * @return void* data removed from the list, NULL otherwise
 */
void *LL_removeIndex(LinkedList *list, int index);

/**
 * Get the data at the specified index
 * 
 * @param list      Pointer to the linked List structure
 * @param index     Index of the node containing the Data
 * 
 * @return void* data from index, NULL on error || index> list->length || list is NULL
 */
void *LL_GetIndexData(LinkedList *list, int index);

/**
 * Utility function that prints out the list. The print pattern of the function is specified by the user.
 * 
 * @param list      Pointer to the linked List structure
 * @param print     Function that take a void* data and prints it
 */
void LL_Print(LinkedList *list, void (*print)(void *data));

/**
 * Deallocate each node on the list and then the Struct itself.
 * @param list      Pointer to the linked List structure
 */
void LL_Destroy(LinkedList *list);

#endif
