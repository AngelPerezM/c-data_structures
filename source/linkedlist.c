#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

/**
 * Node structure:
 */
typedef struct node {
	void *element;
	struct node *nextNode;
} Node;

List *newList() {
	List *list = calloc(1, sizeof(List));
	// list->first = calloc(1, sizeof(Node));
	list->last = list->first = NULL;
	list->listSize =0;
	return list;
}
Node * newNode(void *element, Node *nextNode) {
	Node *node_p = (Node *) calloc(1, sizeof(Node));
	if(node_p != NULL) {
		node_p->element = element;
		node_p->nextNode = nextNode;
	}
	return node_p;
}
int add(List *list, void *element) {
	if (list == NULL) {
		return 1;
	} else {
		Node *nuevoNodo = newNode(element, NULL);
		if (nuevoNodo != NULL) {
			if (list->listSize == 0) {
				list->first = nuevoNodo;
			} else {
				list->last->nextNode = nuevoNodo;
			}
			list->last = nuevoNodo;
		}
		list->listSize++;
		return (nuevoNodo == NULL);
	}
}
void * get(List *list, int index) {
	if (list == NULL) {
		return NULL;
	} else {
		Node *it = NULL;
		int i = 0;
		for (it = list->first; ((it != NULL) && (i < index)); (it = it->nextNode)) {
			i++;
		}
		return ((it != NULL) && (index >= 0)) ? (it->element) : (NULL);
	}
}
int removeByIndex(List *list, int index, void (*deleteElement) (void *)) {
	if (list == NULL) {
		return 0;
	} else {
		Node *it = NULL;
		Node *prev_it = NULL;
		int i = 0;
		for (it = list->first; ((it != NULL) && (i < index)); (it = it->nextNode)) {
			i++;
			prev_it = it;
		}
		int found = (it != NULL) && (index >= 0);
		if (found) {
			if(list->first == list->last) { // Lista con un solo elemento
				list->first = list->last = NULL;
			} else if(it == list->first) {   // Piden eliminar el primer elemento
				list->first = it->nextNode;
			} else if(it == list->last) {   // Piden eliminar el último elemento
				prev_it->nextNode = NULL;
			} else {                        // Piden eliminar un elemento cualquiera
				prev_it->nextNode = it->nextNode;
			}
			if(deleteElement)
				(*deleteElement)(it->element);
			free(it);
			list->listSize--;
		}
		return found;
	}
}
int removeByElement(List *list, void *element, size_t element_size, void (*deleteElement) (void *)) {
	int removed = 0;
	if(list && (list->listSize > 0)) {
		Node *it = NULL;
		Node *prev_it = NULL;
		for (it = list->first; ((it != NULL) && !removed); (it = it->nextNode)){
			if(memcmp(it->element, element, element_size) == 0) {   // encontrado
				if(list->first == list->last) { // Lista con un solo elemento
					list->first = list->last = NULL;
				} else if(it == list->first) {   // Piden eliminar el primer elemento
					list->first = it->nextNode;
				} else if(it == list->last) {   // Piden eliminar el último elemento
					prev_it->nextNode = NULL;
				} else {                        // Piden eliminar un elemento cualquiera
					prev_it->nextNode = it->nextNode;
				}
				if(deleteElement)
					(*deleteElement)(it->element);
				free(it);
				removed = 1;
				list->listSize--;
			} else {
				prev_it = it;
			}
		}
	}
	return removed;
}
int indexOf(List *list, void *element, size_t element_size) {
	if(list == NULL) {
		return -1;
	} else {
		long listSize = list->listSize;
		Node *it = NULL;
		int i = 0;
		for (it = list->first;
		     ((it != NULL) && (memcmp(it->element, element, element_size) != 0));
		     (it = it->nextNode)) {
			i++;
		}
		return (i < listSize) ? (i) : (-1);
	}
}
void destroyList(List *list, void (*deleteElement) (void *)) {
	if(list != NULL) {
		Node *it = NULL;
		// int i = 0;
		for (it = list->first; (it != NULL);) {
			Node *del = it;
			it = it->nextNode;
			if (del) {
				if((deleteElement != NULL) && (del->element != NULL)) {
					(*deleteElement)(del->element);
					// printf("Se han borrado un elemento\n");
				}
				free(del);
			}
			// printf("Se han borrado %d elementos\n", ++i);
		}
		list->first = list->last = NULL;
		list->listSize = 0;
		list = NULL;    //???
	}
}
