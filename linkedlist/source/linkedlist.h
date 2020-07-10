#include <stdio.h>
#include <stdlib.h>


/* Private data structure */
typedef struct node Node;

/**
 * Pointer to node, represents the root of the data structure.
 */
typedef struct list {
	Node *first;
	Node *last;
	long listSize;
} List;
/**
 * @return
 */
List *newList();
/**
 * @param element
 * @param nextNode
 * @return
 */
Node * newNode(void *element, Node *nextNode);
/**
 *
 * @param element
 * @return 0 on success, otherwise if failure.
 */
int add(List *list, void *element);
/**
 *
 * @param index
 * @return
 */
void * get(List *list, int index);
/**
 *
 * @param list
 * @param index
 * @param deleteElement
 * @return
 */
int removeByIndex(List *list, int index, void (*deleteElement) (void *));
/**
 *
 * @param list
 * @param element
 * @param element_size
 * @param deleteElement
 * @return
 */
int removeByElement(List *list, void *element, size_t element_size, void (*deleteElement) (void *));
/**
 *
 * @param element
 * @param element_size
 * @return
 */
int indexOf(List *list, void *element, size_t element_size);
/**
 *
 * @param list
 * @return
 */
void destroyList(List *list, void (*deleteElement) (void *));
