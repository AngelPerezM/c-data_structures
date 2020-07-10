#include <stdio.h>
#include "linkedlist.h"
#include <string.h>

int main() {
	printf("Creating new list:\n");
	List *lista= newList();
	char a[] = "angel"; char b[] = "joel"; char c[] = "maribel";
	add(lista, a);
	add(lista, b);
	add(lista, c);

	int i = 0;
	printf("Tamaño de lista %ld\n", lista->listSize);
	for(i = 0; i < lista->listSize; i++) {
		printf("Elemento %i de lista = %s\n", i, (char *) get(lista, i));
	}
	printf("Elemento %i de lista (Error expected) = %s\n", 55, (char *) get(lista, 55));
	printf("Elemento angel es el (%d)-ésimo\n", indexOf(lista, "angel", strlen("angel")));
	printf("Elemento maribel es el (%d)-ésimo\n", indexOf(lista, "maribel", strlen("maribel")));
	printf("Elemento joel es el (%d)-ésimo\n", indexOf(lista, "joel", strlen("joel")));
	printf("Eliminando el elemento \"angel\": result = %d\n", removeByElement(lista, "angel", strlen("angel"), NULL));
	printf("Eliminando el elemento (%d)-ésimo: result = %d\n", 0, removeByIndex(lista, 0, NULL));
	printf("Eliminando el elemento (%d)-ésimo: result = %d (Error expected)\n", 4, removeByIndex(lista, 4, NULL));
	printf("Lista después de la eliminación:\n");
	for(i = 0; i < lista->listSize; i++) {
		printf("Elemento %i de lista = %s\n", i, (char *) get(lista, i));
	}

	printf("\nCreating new list:\n");
	List *lista2= newList();
	int ai = 100; int bi = 200; int ci = 300;
	add(lista2, &ai);
	add(lista2, &bi);
	add(lista2, &ci);

	printf("Tamaño de lista %ld\n", lista2->listSize);
	for(i = 0; i < lista2->listSize; i++) {
		printf("Elemento %i de lista = %d\n", i, (int) *((int *) get(lista2, i)));
	}
	// printf("Elemento %i de lista2 = %d\n", 55, (int) *((int *) get(lista2, 55)));
	int numbers [4] = {100, 200, 300, 400};
	printf("Elemento 100 es el (%d)-ésimo\n", indexOf(lista2, &numbers[0], sizeof(int)));
	printf("Elemento 200 es el (%d)-ésimo\n", indexOf(lista2, &numbers[1], sizeof(int)));
	printf("Elemento 300 es el (%d)-ésimo\n", indexOf(lista2, &numbers[2], sizeof(int)));
	printf("Elemento 400 es el (%d)-ésimo (Error expected)\n", indexOf(lista2, &numbers[3], sizeof(int)));
	// printf("Eliminando el elemento 100: result = %d\n", removeElement(lista2, &numbers[0], sizeof(int), NULL));
	// printf("Eliminando el elemento 200: result = %d\n", removeElement(lista2, &numbers[1], sizeof(int), NULL));
	printf("Eliminando el elemento 300: result = %d\n", removeByElement(lista2, &numbers[2], sizeof(int), NULL));
	printf("Eliminando el elemento 400: result = %d (Error expected)\n", removeByElement(lista2, &numbers[3], sizeof(int), NULL));
	printf("Eliminando el elemento (%d)-ésimo: result = %d\n", 1, removeByIndex(lista2, 1, NULL));
	printf("Eliminando el elemento (%d)-ésimo: result = %d (Error expected)\n", 4, removeByIndex(lista2, 4, NULL));
	for(i = 0; i < lista2->listSize; i++) {
		printf("Elemento %i de lista = %d\n", i, (int) *((int *) get(lista2, i)));
	}

	destroyList(lista, NULL);
	destroyList(lista2, NULL);

	return 0;
}

