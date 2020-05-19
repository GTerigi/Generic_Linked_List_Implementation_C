# Generic Linked List Implementation C

## Description
This is a simple implementation of a C style Linked List. Nothing fancy, it store generic data type, so everything convertible to void*

## Documentation

### Structure
```
typedef struct node_
{
    void *data;
    struct node_ *next;
} node;

typedef struct LinkedList
{
    int lenght;
    node *List;
} LinkedList;
```
As simple as it can get. Every node points to the next one and the LinkedList structure contains the length of the list and a pointer to the head.

### Creation of the list
```
LinkedList *my_list = LL_Create();
``` 
Create and empty list, the first node is empty and length is set to 0

### Insert data inside the List
```
bool LL_AddOrder(LinkedList *list, void *data, int (*comp)(void *, void *));

...
// Example
LL_AddOrder(List, (void *)(&SomeInt), YourSortingFunction);
```
Add the new Data in the list following the order described in the function passed as argument.
**Return**  _true_ if the data is correctly inserted in the list, _false_ otherwise

### Removing From the List
There are 2 ways to remove an element from the list.
The first one remove the node in the index position and return the data of the node.
```
// Removing the first node of the List
a = *((int *)LL_removeIndex(my_list, 0));
// Removing the fifth node of the List
a = *((int *)LL_removeIndex(my_list, 4));
// Removing the last node of the list
// Removing the first node of the List
a = *((int *)LL_removeIndex(my_list, my_list->lenght-1));
```

The second one remove the node witch contain a certain Data
```
// Removing the node where node->data equals tmp
// You have to specify when 2 entities are equals (YourSortingFunction has to return 0 when they are equals)
LL_removeData(my_list, (void *)&tmp, YourSortingFunction)
```

### Get some Data from specific Index 
```
a = *((int *)LL_GetIndexData(my_list, someIndex));
printf("%d is Data from %dth node of the List\n",someIndex, a);
```

### Deallocate Memory
You can deallocate the List memory with LL_Destroy
```
LL_Destroy(my_list);
```


### Conclusion
It's simple, but if you want to contribute somehow Push a request and we can improve this mediocre Structure
 
